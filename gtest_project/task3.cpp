#include "task3.h"

#include <string>

namespace {
void parse_side(const std::string& s, int& coeff_x, int& constant) {
    int sign = 1;
    int i = 0;
    const int n = static_cast<int>(s.size());

    while (i < n) {
        if (s[i] == '+') {
            sign = 1;
            ++i;
            continue;
        }
        if (s[i] == '-') {
            sign = -1;
            ++i;
            continue;
        }

        int value = 0;
        bool has_number = false;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            has_number = true;
            value = value * 10 + (s[i] - '0');
            ++i;
        }

        if (i < n && s[i] == 'x') {
            coeff_x += sign * (has_number ? value : 1);
            ++i;
        } else {
            constant += sign * value;
        }
    }
}
}  // namespace

std::string solve_equation(const std::string& equation) {
    const std::size_t eq_pos = equation.find('=');
    const std::string left = equation.substr(0, eq_pos);
    const std::string right = equation.substr(eq_pos + 1);

    int left_x = 0;
    int left_c = 0;
    int right_x = 0;
    int right_c = 0;

    parse_side(left, left_x, left_c);
    parse_side(right, right_x, right_c);

    const int x_coeff = left_x - right_x;
    const int constant = right_c - left_c;

    if (x_coeff == 0) {
        if (constant == 0) {
            return "Infinite";
        }
        return "NO";
    }

    return "x=" + std::to_string(constant / x_coeff);
}
