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

    std::string current_label="", current_value="", current_string="", remianing_string="";

    std::stringstream ss(user_input);
    std::getline(ss, current_string, '(');
    std::getline(ss, current_string, ')');

    std::stringstream ss_again(current_string);
    std::getline(ss_again, current_label, ',');
    std::getline(ss_again, current_value);

    std::getline(ss, remianing_string);

    auto range = transition_pair.ra_pair.equal_range({current_state, current_label});

    for (auto it = range.first; it != range.second; ++it)
    {
        auto all_new_register_value = all_register_value;
        auto update = register_update_pair.find({current_state, current_label});
        // std::cout<<current_state<<" "<<all_new_register_value[1]<<" "<<all_new_register_value[2]<<std::endl;
        if (current_value == all_new_register_value[it->second.first])
        {
            if (check_register_automata(remianing_string,
                all_new_register_value,
                register_update_pair,
                it->second.second,
                init,
                transition_pair))
            {
                return true;
            }
        }
        else
        {
            if (update != register_update_pair.end())
            {
                all_new_register_value[update->second] = current_value;

                if (check_register_automata(remianing_string,
                    all_new_register_value,
                    register_update_pair,
                    it->second.second,
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