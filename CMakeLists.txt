cmake_minimum_required(VERSION 3.19)
project(internal_template)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_library(internal_template SHARED
        src/dllmain.cpp
        src/utils/c_hook_mgr.h
        src/process/hooks/hooks.h
        src/utils/pattern_scan.h
        src/process/structs/example_struct_t.h
        src/features/c_feature.h
        src/features/features.h src/utils/c_log.h src/utils/c_hook_mgr.cpp src/utils/c_log.cpp src/process/hooks/example_hook.cpp src/features/c_feature.cpp src/features/c_example_feature.cpp src/utils/c_feature_mgr.cpp src/utils/c_feature_mgr.h src/utils/pattern_scan.cpp)
target_link_libraries(internal_template PRIVATE libMinHook-x86-v141-md)