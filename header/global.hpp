#ifndef GLOBAL_HPP
#define GLOBAL_HPP



#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <filesystem>
#include <stack>
#include <utility>
#include <vector>
#include <variant>
#include <algorithm>

// user defined data types
struct data {
  std::string automata_name="";
  int states = 0;
  int init_state = 0;
  int no_register=0;
  std::vector<int> final_state;
};

struct automata_data_type {
  
   std::map<std::pair<int, std::string>, std::pair<std::string, int>> ra_pair;
   std::map<std::pair<int, std::string>, int> dfa_nfa_pair;
    automata_data_type() {}
   ~automata_data_type() {}
};

void put_data(data &,automata_data_type &);
void show_data(data &,automata_data_type &);
void entry_point();
bool check_dfa_nfa(std::string,int,data ,automata_data_type);
bool check_register_automata(std::string,int,data ,automata_data_type);
#endif