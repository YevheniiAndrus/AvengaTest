cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(FrameLoader)
set(HEADERS 
    IFrameLoader.h
    FrameLoader.h
    FrameLoaderFactory.h
)
set (SOURCE
    FrameLoader.cpp
    FrameLoaderFactory.cpp
)

add_library(FrameLoader ${SOURCE} ${HEADERS})
target_include_directories(FrameLoader PRIVATE ${CMAKE_CURRENT_SOURCE_DIR/common})