cmake_minimum_required(VERSION 3.16)
project(Practise7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

add_subdirectory(assert_project)
add_subdirectory(ctest_project)
add_subdirectory(gtest_project)
