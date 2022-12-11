cmake_minimum_required(VERSION 3.16)
project(DataStructures)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.1.1)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

add_executable(task1 Prep1/src/task1.cpp)


# Automatically register all tests
#include(CTest)
#include(Catch)
#catch_discover_tests(unit-tests)
