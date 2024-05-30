cmake_minimum_required(VERSION 3.26)
project(Number_Guessing_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Number_Guessing_Game main.cpp
        GenerateNumber.cpp
        GenerateNumber.h
)
