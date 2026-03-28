#include "global.hpp"



bool check_dfa_nfa(std::string user_input,int initial_state,data init,automata_data_type transition_pair) {
  if (user_input.empty()) {
    if (std::find(init.final_state.begin(), init.final_state.end(), initial_state) !=
        init.final_state.end())
      return true;

    auto eps = transition_pair.dfa_nfa_pair.equal_range({initial_state, "@"});
    for (auto it = eps.first; it != eps.second; ++it) {
      if (check_dfa_nfa("", it->second, init, transition_pair))
        return true;
    }
    return false;
  }
  auto eps = transition_pair.dfa_nfa_pair.equal_range({initial_state, "@"});
  for (auto it = eps.first; it != eps.second; ++it) {
    if (check_dfa_nfa(user_input, it->second, init, transition_pair))
      return true;
  }
  std::string sym = std::string() + user_input[0];
  auto range = transition_pair.dfa_nfa_pair.equal_range({initial_state, sym});

  for (auto it = range.first; it != range.second; ++it) {
    std::string rest = user_input.substr(1);
    if (check_dfa_nfa(rest, it->second, init, transition_pair))
      return true;
  }

  return false;
}
