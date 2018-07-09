cmake_minimum_required(VERSION 3.9)
project(TOP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp main.h step1.cpp step2/step2.cpp step2/step2.h)
add_executable(TOP ${SOURCE_FILES} main.h step1.cpp step2/step2.cpp step2/step2.h)