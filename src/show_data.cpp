#include "global.hpp"


void show_data(data &init,automata_data_type &transition_pair)
{
  std::cout<< "Specific Automata name : "<<init.automata_name<<std::endl;
  std::cout << "Total Number of States : " << init.states << std::endl;
  std::cout << "Initial State : q" << init.init_state << std::endl;
   std::cout << "Final State :"  << std::endl;
        for (int i = 0; i < init.final_state.size(); i++) {
            std::cout << "q" << init.final_state[i] << std::endl;
        }

  if(init.automata_name=="ra"||init.automata_name=="RA" && !transition_pair.ra_pair.empty())
  {
    std::cout<<"Number of register :"<<init.no_register<<std::endl;
    std::cout << std::endl<< "Transactions : " << std::endl;
    std::cout << "First State\t"<< "Input\t"<< "Register\t"<< "Next state\t" << std::endl<< std::endl;
      for (auto it = transition_pair.ra_pair.begin(); it != transition_pair.ra_pair.end(); it++) {
      std::cout << "q" << it->first.first << " -> " << it->first.second<< " -> "<< it->second.first << " = q" << it->second.second << std::endl;
    }
  }
  else{
    std::cout << std::endl<< "Transactions :" << std::endl;
    std::cout << "First State\t"<< "Input\t"<< "Next state\t" << std::endl<< std::endl;
      for (auto it = transition_pair.dfa_nfa_pair.begin(); it != transition_pair.dfa_nfa_pair.end(); it++) {
      std::cout << "q" << it->first.first << " -> " << it->first.second << " = q" << it->second << std::endl;
    }
  }
}