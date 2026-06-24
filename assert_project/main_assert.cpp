#include <cassert>
#include <iostream>

#include "task1.h"

void test_zero_time() {
    assert(get_mop_holder(5, 0) == 1);
}

void test_forward_pass() {
    assert(get_mop_holder(5, 3) == 4);
}

void test_backward_pass() {
    assert(get_mop_holder(5, 6) == 3);
}

int main() {
    std::cout << "Running assert tests...\n";
    test_zero_time();
    test_forward_pass();
    test_backward_pass();
    std::cout << "All assert tests passed successfully.\n";
    return 0;
}
