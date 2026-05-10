cmake_minimum_required(VERSION 3.10)

project(infinite_Automata_Tool)

file(GLOB SRC "./src/*.cpp")

set(SOURCE
    ./main.cpp
    ${SRC}
)

add_executable(
    infinite_Automata_Tool
    ${SOURCE}
)

# Include folders
target_include_directories(
    infinite_Automata_Tool
    PRIVATE
    ./header
    ./SFML/include
)

# Local library folder
target_link_directories(
    infinite_Automata_Tool
    PRIVATE
    ./SFML/lib
)

# Link libraries
target_link_libraries(
    infinite_Automata_Tool
    sfml-graphics
    sfml-window
    sfml-system
)