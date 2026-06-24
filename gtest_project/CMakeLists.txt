include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(tasks_lib
    task3.cpp
    task4.cpp
    task5.cpp
    task6.cpp
    task7.cpp
    task8.cpp
)
target_include_directories(tasks_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_subdirectory(gtests)
