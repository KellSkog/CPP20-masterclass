cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE gcc-11.1.cmake)
project(Master-CPP20)

add_compile_options(-Wall -Wextra -pedantic -Werror)
add_subdirectory(Section2)
add_subdirectory(Section3)
add_subdirectory(Section5)
add_subdirectory(Section6)
add_subdirectory(Section7)
add_subdirectory(Section8)
add_subdirectory(Section9)
add_subdirectory(Section10)
add_subdirectory(Section11)
add_subdirectory(Section12)
add_subdirectory(Kattis)
add_subdirectory(Section13)
add_subdirectory(Section14)
add_subdirectory(Section15)
add_subdirectory(Section16)
add_subdirectory(Section17)
add_subdirectory(Section18)
add_subdirectory(Section19)

# add_custom_command(
#         TARGET foo POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy
#                 ${CMAKE_SOURCE_DIR}/test/input.txt
#                 ${CMAKE_CURRENT_BINARY_DIR}/input.txt)

#I want to add "cmake add SectionN" which creates the SectionN folder,
# Copies exercise files and main.cpp to it