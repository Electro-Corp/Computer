cmake_minimum_required(VERSION 3.12)
# Compiler settings

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(VM)

include_directories(src)

add_executable(VM
    src/pugixml/pugixml.cpp
    src/Memory.cpp
    src/CPU.cpp
    src/VGA.cpp
    src/computer.cpp
    src/main.cpp
)

#-fpermissive -Wno-c++11-narrowing

target_compile_options(VM PUBLIC -g -O0)

project(VM_DISP)

add_executable(VM_DISP
    src/vmDisplay/main.cpp
)

target_compile_options(VM_DISP PUBLIC -g -O0)
