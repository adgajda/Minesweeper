cmake_minimum_required(VERSION 3.22)

project(Minesweeper)

set(CMAKE_CXX_STANDARD 17)

set(GCC_WARNINGS
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wpedantic
    -Wsign-conversion
    -Wnull-dereference
    -Wdouble-promotion
    -Wimplicit-fallthrough
    -Wmisleading-indentation
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wuseless-cast
)

add_compile_options(-Werror ${GCC_WARNINGS} -O2)

add_subdirectory(src)
