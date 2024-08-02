cmake_minimum_required(VERSION 3.15)

project(counters LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(counters ${CMAKE_SOURCE_DIR}/src/main.cpp
    src/pcmreader.h src/pcmreader.cpp
)

add_subdirectory(test)
