#include "global.hpp"

//  custome data type
struct temp {
  int first_state;
  std::string transaction;
  std::string register_name;
  int next_state;
};


//get data from file for transition
temp get_data(std::string& hold,std::string automata_name){
    std::stringstream sub_ss(hold);
    temp temp_data;
    sub_ss >> temp_data.first_state;
    sub_ss >> temp_data.transaction;
    if(automata_name=="ra"||automata_name=="RA")
    {
     sub_ss >> temp_data.register_name;
    }
    sub_ss >> temp_data.next_state;
    return temp_data;
}



//actual function
void put_data(data &init ,std::map<std::pair<int, std::string>, int> &register_update_pair,automata_data_type &transition_pair) {

  
std::fstream file("/home/asikul/7th sem/project/check.txt");
if (file.is_open()) {

    file >> init.automata_name;
    file >> init.states;
    file >> init.init_state;

    if( init.automata_name=="ra"||init.automata_name=="RA"){
       file>>init.no_register;
    }
      std::string hold;   
      std::getline(file,hold,'\n'); 
      std::getline(file,hold,'\n'); 
      std::stringstream ss(hold);  
      
      int number;
      while (ss>>number) {
        init.final_state.push_back(number);
      }

   while (!file.eof() && std::getline(file,hold,'\n')) {
       if(init.automata_name=="ra"||init.automata_name=="RA")
       {
         if(hold[0]=='{')
         {
            hold = hold.substr(1, hold.size() - 2);
            std::stringstream temp(hold);
            int a;
            std::string b;
            int c;
            temp>>a>>b>>c;
            register_update_pair.insert({{a,b},c});
         }
         else{
         temp hold_data=get_data(hold,init.automata_name);
         transition_pair.ra_pair.insert({{hold_data.first_state,hold_data.transaction},{hold_data.register_name,hold_data.next_state}});
         }
       }
       else
       {
        temp hold_data=get_data(hold,init.automata_name);
         transition_pair.dfa_nfa_pair.insert({{hold_data.first_state,hold_data.transaction},hold_data.next_state});
       }
   }
    file.close();
 } 
 else {
    std::cout << "there is an error to open file" << std::endl;
  }
}