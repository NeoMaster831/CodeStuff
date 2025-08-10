cmake_minimum_required(VERSION 3.15)
project(km-module CXX)

find_package(WDK REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

wdk_add_driver(km-module)

target_include_directories(km-module PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_sources(km-module PRIVATE ${SOURCES} ${HEADERS})

