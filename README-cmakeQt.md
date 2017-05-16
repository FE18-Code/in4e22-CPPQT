# Cmake Qt

Example of cmake enabling to use Qt in your code easily (qt sources required)


`
cmake_minimum_required(VERSION 3.6)

project(proj_exe)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui) # examples, put here Qt components you plan to use

set(SOURCE_FILES main.cpp x.cpp x.h)

add_executable(proj_exe ${SOURCE_FILES})

target_link_libraries(proj_exe Qt5::Core Qt5::Widgets Qt5::Gui) # link all required qt components
`

