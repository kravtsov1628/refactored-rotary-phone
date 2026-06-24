add_executable(assert_tests
    task1.cpp
    main_assert.cpp
)

add_test(NAME assert_tests COMMAND assert_tests)
