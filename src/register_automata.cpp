#include "global.hpp"

bool check_register_automata(std::string user_input,int initial_state,data init,automata_data_type transition_pair) {
     std::vector<std::string> registers(init.no_register, "");
   // 🔹 Base case
    if (user_input.empty()) {
        return std::find(init.final_state.begin(),init.final_state.end(),initial_state) != init.final_state.end();
    }

    std::string sym(1, user_input[0]);

    auto range = transition_pair.ra_pair.equal_range({initial_state, sym});

    for (auto it = range.first; it != range.second; ++it) {

        std::string op = it->second.first;
        int next_state = it->second.second;
      
        // 🔹 copy registers (important for branching)
        std::vector<std::string> new_registers = registers;

        // 🔸 Case 1: Assign (r1=)
        if (op.size() >= 3 && op[0] == 'r' && op.back() == '=') {
            int reg_index = op[1] - '1';

            if (reg_index >= 0 && reg_index < new_registers.size()) {
                new_registers[reg_index] = sym;

                if (check_register_automata(
                        user_input.substr(1),
                        next_state,
                        init,
                        transition_pair))
                    return true;
            }
        }

        // 🔸 Case 2: Compare (r1==)
        else if (op.find("==") != std::string::npos) {
            int reg_index = op[1] - '1';

            if (reg_index >= 0 && reg_index < new_registers.size()) {
                if (new_registers[reg_index] == sym) {

                    if (check_register_automata(
                            user_input.substr(1),
                            next_state,
                            init,
                            transition_pair))
                        return true;
                }
            }
        }

        // 🔸 Case 3: Normal transition (*)
        else if (op == "*") {
            if (check_register_automata(
                    user_input.substr(1),
                    next_state,
                    init,
                    transition_pair))
                return true;
        }
    }

    return false;
}