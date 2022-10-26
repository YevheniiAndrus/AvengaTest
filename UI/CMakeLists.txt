cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(UI)
set(HEADERS 
    BoxRenderer.h
    MetadataRenderer.h
    Renderer.h
)
set (SOURCE
    BoxRenderer.cpp
    Renderer.cpp
)

add_library(UI ${SOURCE} ${HEADERS})
target_include_directories(UI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR/common})