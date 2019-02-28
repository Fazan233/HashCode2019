cmake_minimum_required(VERSION 3.13)
project(untitled2 C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)


add_executable(untitled2 main.c stack_operation.c slide.h compare_tags.c)
target_include_directories(untitled2 PUBLIC ./includes)
target_link_libraries(untitled2 LIBFT)