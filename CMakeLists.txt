cmake_minimum_required(VERSION 3.15)

project(counters LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(counters ${CMAKE_SOURCE_DIR}/src/main.cpp
    src/pcmreader.h src/pcmreader.cpp
)

include( GoogleTest )
enable_testing()
file( GLOB TestSources ${CMAKE_SOURCE_DIR}/test/*.cpp )

add_executable( ${PROJECT_NAME}-test ${TestSources} )

target_link_libraries(${PROJECT_NAME}-test gtest::gtest)
gtest_discover_tests( ${PROJECT_NAME}-test WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

file(COPY ${CMAKE_SOURCE_DIR}/test/data_raw_32_rand_ch_offs DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data_raw_32_rand_ch_offs)
file(COPY ${CMAKE_SOURCE_DIR}/test/data_raw_32_rand_ch_offs_break DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data_raw_32_rand_ch_offs_break)
