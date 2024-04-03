cmake_minimum_required(VERSION 3.27)
project(HW6 C)

set(CMAKE_C_STANDARD 11)

add_executable(HW6
        main.c
        OperationTree.c
        OperationTree.h
        OperationTreeTest.c
        OperationTreeTest.h
        input.txt
)
