cmake_minimum_required(VERSION 3.26)
project(M2OEP_sgmalik)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M2OEP_sgmalik
        category.cpp
        course.cpp
        gpaCalculator.cpp
        main.cpp
)

add_executable(test
        category.cpp
        course.cpp
        gpaCalculator.cpp
        testing.cpp
)

