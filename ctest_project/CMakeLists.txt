add_library(task2_lib task2.cpp)
target_include_directories(task2_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_subdirectory(tests)
