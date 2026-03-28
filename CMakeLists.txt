cmake_minimum_required(VERSION 3.10)

file(GLOB SRC "./src/*.cpp") 
set( SOURCE ./main.cpp ${SRC} ) 
add_executable(infinite_Automata_Tool ${SOURCE})

target_include_directories(infinite_Automata_Tool PRIVATE ./header)