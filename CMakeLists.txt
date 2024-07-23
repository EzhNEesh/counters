cmake_minimum_required(VERSION 3.15)

project(counters LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(counters ${CMAKE_SOURCE_DIR}/src/main.cpp
)

include(GNUInstallDirs)
install(TARGETS counters
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(counters gtest::gtest)
