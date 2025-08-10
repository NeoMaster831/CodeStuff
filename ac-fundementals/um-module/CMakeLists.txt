cmake_minimum_required(VERSION 3.15)

project(AcUmModule)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(um_module SHARED
    src/dllmain.cpp
    src/module/page_check.cpp
    src/module/vtable_sanity.cpp
    src/module/stolen_bytes_call.cpp
    src/module/veh_detection.cpp
    src/idle.cpp
    src/vobject.cpp
)

add_executable(test_app
    src/app/main.cpp
)

add_library(hack SHARED
    src/hack/dllmain.cpp
    src/hack/vobject_change.cpp
)