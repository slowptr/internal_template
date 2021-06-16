cmake_minimum_required(VERSION 3.19)
project(internal_template)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_library(internal_template SHARED src/dllmain.cpp src/utils/hook_mgr.h)
target_link_libraries(internal_template PRIVATE libMinHook-x86-v141-md)