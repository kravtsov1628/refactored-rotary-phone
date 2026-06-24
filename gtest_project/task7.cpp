#include "task7.h"

#include <array>

std::uint64_t count_without_consecutive_ones(unsigned int n) {
    std::array<std::uint64_t, 32> fib{};
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < 32; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    std::uint64_t answer = 0;
    int prev_bit = 0;

    for (int bit = 30; bit >= 0; --bit) {
        if ((n & (1u << bit)) != 0) {
            answer += fib[bit];
            if (prev_bit == 1) {
                return answer;
            }
            prev_bit = 1;
        } else {
            prev_bit = 0;
        }
    }

    return answer + 1;
}
