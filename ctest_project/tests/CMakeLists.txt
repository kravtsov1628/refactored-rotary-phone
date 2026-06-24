add_executable(test_task2_1 test_task2_1.cpp)
target_link_libraries(test_task2_1 PRIVATE task2_lib)
add_test(NAME test_task2_1 COMMAND test_task2_1)

add_executable(test_task2_2 test_task2_2.cpp)
target_link_libraries(test_task2_2 PRIVATE task2_lib)
add_test(NAME test_task2_2 COMMAND test_task2_2)

add_executable(test_task2_3 test_task2_3.cpp)
target_link_libraries(test_task2_3 PRIVATE task2_lib)
add_test(NAME test_task2_3 COMMAND test_task2_3)
