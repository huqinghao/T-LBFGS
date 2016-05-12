cmake_minimum_required(VERSION 3.3)
project(TLBFGS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp lbfgs.cpp)
add_executable(TLBFGS ${SOURCE_FILES})

add_library(STATIC_TLBFGS STATIC ${SOURCE_FILES})