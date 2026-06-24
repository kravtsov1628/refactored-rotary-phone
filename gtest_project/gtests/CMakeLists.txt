add_executable(gtests_runner tests.cpp)
target_link_libraries(gtests_runner PRIVATE tasks_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(gtests_runner)
