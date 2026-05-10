#include "global.hpp"


void show_data(
    data &init,
    std::map<std::pair<int,
    std::string>, int>
    &register_update_pair,
    automata_data_type &transition_pair,
    sf::Text &showAutomataRule
)
{
    std::string output;

    output +="Specific Automata name : "+ init.automata_name + "\n";
    output +="Total Number of States : "+ std::to_string(init.states)+ "\n";
    output +="Initial State : q"+ std::to_string(init.init_state)+ "\n";
    output +="Final State : ";

    for (int i = 0;i < init.final_state.size();i++)
    {
        output +="q"+ std::to_string(init.final_state[i])+ " ";
    }
    output += "\n\n";

    if ((init.automata_name== "ra" ||init.automata_name== "RA")&&!transition_pair.ra_pair.empty())
    {
        output +="Number of register : "+ std::to_string(init.no_register)+ "\n\n";
        output += "Update Register :\n";
        for (auto it =register_update_pair.begin();it !=register_update_pair.end();it++)
        {
            output += "q" + std::to_string(it->first.first)+ " -> " + it->first.second+ " = r"+ std::to_string(it->second)+ "\n";
        }

        output +="\nTransactions :\n";
        output +="First State\t""Input\t""Register\t""Next State\n\n";
        for (auto it =transition_pair.ra_pair.begin();it !=transition_pair.ra_pair.end();it++)
        {
            output +="q"+ std::to_string(it->first.first)+ " -> " + it->first.second+ " -> "+ std::to_string(it->second.first)+ " = q"
                     + std::to_string(it->second.second)+ "\n";
        }
    }
    else
    {
        output +="Transactions :\n";
        output +="First State\t""Input\t""Next State\n\n";
        for (auto it =transition_pair.dfa_nfa_pair.begin();it !=transition_pair.dfa_nfa_pair.end();it++)
        {
            output +="q" + std::to_string(it->first.first)+ " -> " + it->first.second+ " = q"+ std::to_string(it->second)+ "\n";
        }
    }
    showAutomataRule.setString(
        output
    );
}