cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(ExternalDrive)
set(HEADERS 
    ExternalDrive.h
)
set (SOURCE
    ExternalDrive.cpp
)

add_library(ExternalDrive ${SOURCE} ${HEADERS})
target_include_directories(ExternalDrive PRIVATE ${CMAKE_CURRENT_SOURCE_DIR/common})