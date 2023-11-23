cmake_minimum_required(VERSION 3.5)

project(skytech LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(skytech main.cpp checkbitmask.h checkbitmask.cpp tree.h tree.cpp)
