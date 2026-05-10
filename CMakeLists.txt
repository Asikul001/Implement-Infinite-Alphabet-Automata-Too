cmake_minimum_required(VERSION 3.10)

file(GLOB SRC "./src/*.cpp") 
set( SOURCE ./main.cpp ${SRC} ) 
add_executable(infinite_Automata_Tool ${SOURCE})

target_include_directories(infinite_Automata_Tool PRIVATE ./header )

target_include_directories(infinite_Automata_Tool PRIVATE./SFML/include)

target_link_directories(infinite_Automata_Tool PRIVATE./SFML/lib)

target_link_libraries( infinite_Automata_Tool sfml-graphics sfml-window sfml-system)