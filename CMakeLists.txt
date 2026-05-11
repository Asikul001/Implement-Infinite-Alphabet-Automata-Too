cmake_minimum_required(VERSION 3.10)

project(infinite_Automata_Tool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

file(GLOB SRC "./src/*.cpp")

add_executable(infinite_Automata_Tool main.cpp ${SRC})

target_include_directories(infinite_Automata_Tool PRIVATE ./header)

if(WIN32)
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")
endif()

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

target_link_libraries(infinite_Automata_Tool
    PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
