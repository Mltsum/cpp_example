cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        ./
)

aux_source_directory(./ SRC_LIST)

add_executable(test main.cpp ${SRC_LIST})

