cmake_minimum_required(VERSION 3.19)
project(internal_template)

set(CMAKE_CXX_STANDARD 20)

add_library(internal_template SHARED src/dllmain.cpp src/utils/hook_mgr.h)