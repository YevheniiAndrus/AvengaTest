cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(BlackBox)
set(HEADERS 
    BlackBox.h
)
set (SOURCE
    BlackBox.cpp
)

add_library(BlackBox ${SOURCE} ${HEADERS})
target_include_directories(BlackBox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR/common})