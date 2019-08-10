# cmake_minimum_required(VERSION <specify CMake version here>)
project(Freaking_summer_camp)

set(CMAKE_CXX_STANDARD 17)

add_executable(color_machine cola_machine.cc)
add_executable(cheat cheat.cc)
add_executable(pancake pancake.cc)
add_executable(dungeon_crawl dungeon_crawl.cc)
add_executable(random_number random_number.cc)
add_executable(number_revert number_revert.cc)
add_executable(guess_number guess_number.cc)

add_library(big_int big_int/big_int.cc big_int/big_int.h)
target_link_libraries(number_revert big_int)