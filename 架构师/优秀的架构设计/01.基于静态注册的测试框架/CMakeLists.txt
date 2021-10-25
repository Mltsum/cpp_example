cmake_minimum_required(VERSION 3.17)
project(cppDemo)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

# 无效
#MATH(EXPR stack_size "2*1024*1024")
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(cppDemo main.cpp TestSuite.cpp ./module1/TestCase1.cpp ./module2/TestCase2.cpp)