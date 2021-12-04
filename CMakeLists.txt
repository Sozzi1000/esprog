cmake_minimum_required(VERSION 3.16)
project(SIR_Simulation VERSION 0.1.0)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(SIR_Simulation.out main.cpp)
target_compile_options(SIR_Simulation.out PRIVATE -Wall -Wextra -fsanitize=address -g)
target_link_libraries(SIR_Simulation.out PRIVATE sfml-graphics)
target_link_options(SIR_Simulation.out PRIVATE -fsanitize=address)