#include "global.hpp"

void entry_point()
{
 
  data init;
  automata_data_type transition_pair;
  std::map<std::pair<int, std::string>, int> register_update_pair;

  put_data(init,register_update_pair, transition_pair);
  show_data(init,register_update_pair, transition_pair);

  std::string user_input;
  std::cout << std::endl<< "Enter String" << std::endl;


  while (std::cin >> user_input && user_input != "exit")
  {
        if (init.automata_name == "ra" || init.automata_name == "RA")
        {
          if (!transition_pair.ra_pair.empty())
          {
            std::vector<std::string> register_value(init.no_register,"$");
             if(check_register_automata(user_input,register_value,register_update_pair,init.init_state,init,transition_pair))
            {
                std::cout << "String is Accepted" << std::endl;
            }
            else
            {
              std::cout << "String is rejected" << std::endl;
            }
          }
          else
          {
            std::cout << "Please enter Transition" << std::endl;
            exit(1);
          }
        }
  else
  {
          if (!transition_pair.dfa_nfa_pair.empty())
          {
            if(check_dfa_nfa(user_input,init.init_state,init,transition_pair))
            {
                std::cout << "String is Accepted" << std::endl;
            }
            else
            {
              std::cout << "String is rejected" << std::endl;
            }
          }
          else
          {
            std::cout << "Here is No Transition " << std::endl;
            exit(1);
          }
  }


    std::cout << "Enter String" << std::endl;
  }
}