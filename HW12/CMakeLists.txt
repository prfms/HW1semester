cmake_minimum_required(VERSION 3.27)
project(HW12 C)

set(CMAKE_C_STANDARD 11)

add_executable(HW12
        main.c
        lexicalAnalyzer.c
        lexicalAnalyzer.h
        lexicalAnalyzerTest.c
        lexicalAnalyzerTest.h
)