cmake_minimum_required(VERSION 3.19)
project(internal_template)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_library(internal_template SHARED
        src/dllmain.cpp
        src/utils/hook_mgr.h
        src/process/hooks/example_hook.h
        src/utils/pattern_scan.h
        src/process/structs/example_struct_t.h
        src/features/feature_t.h
        src/features/example_feature_t.h src/utils/log_t.h)
target_link_libraries(internal_template PRIVATE libMinHook-x86-v141-md)