#include "global.hpp"

bool check_register_automata(
    std::string user_input,
    std::vector<std::string> all_register_value,
    std::map<std::pair<int, std::string>, int> register_update_pair,
    int current_state,
    data init,
    automata_data_type transition_pair)
{
    if (user_input.empty())
    {
        return std::find(init.final_state.begin(),
                         init.final_state.end(),
                         current_state) != init.final_state.end();
    }

    std::string current_label = "", current_value = "";
    std::string current_string = "", remaining_string = "";

    std::stringstream ss(user_input);
    std::getline(ss, current_string, '(');
    std::getline(ss, current_string, ')');

    std::stringstream ss_again(current_string);
    std::getline(ss_again, current_label, ',');
    std::getline(ss_again, current_value);

    std::getline(ss, remaining_string);

    auto range = transition_pair.ra_pair.equal_range({current_state, current_label});
    for (auto it = range.first; it != range.second; ++it)
    {
        //std::cout<<"matched"<<std::endl;
        int reg = it->second.first;    
        int next_state = it->second.second;
        int idx = reg - 1;

        if (idx >= 0 && idx < all_register_value.size())
        {
            if (all_register_value[idx] == current_value)
            {
                if (check_register_automata(
                        remaining_string,
                        all_register_value,   
                        register_update_pair,
                        next_state,
                        init,
                        transition_pair))
                {
                    return true;
                }
            }
        }
    }

    auto update = register_update_pair.find({current_state, current_label});

    if (update != register_update_pair.end())
    {
        int j = update->second;   
        int idx = j - 1;          

        for (auto it = range.first; it != range.second; ++it)
        {
            int reg = it->second.first;
            int next_state = it->second.second;

            if (reg == j)
            {
                auto new_registers = all_register_value;

                if (idx >= 0 && idx < new_registers.size())
                {
                    new_registers[idx] = current_value;
                }

                if (check_register_automata(
                        remaining_string,
                        new_registers,
                        register_update_pair,
                        next_state,
                        init,
                        transition_pair))
                {
                    return true;
                }
            }
        }
    }

    return false;
}