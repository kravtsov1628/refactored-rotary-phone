#include "task6.h"

#include <cctype>
#include <stack>

int evaluate_expression(const std::string& expression) {
    long long result = 0;
    long long current_number = 0;
    int sign = 1;
    std::stack<int> sign_stack;
    sign_stack.push(1);

    for (std::size_t i = 0; i < expression.size(); ++i) {
        const char ch = expression[i];
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            current_number = current_number * 10 + (ch - '0');
        } else if (ch == '+' || ch == '-') {
            result += sign * current_number;
            current_number = 0;
            sign = sign_stack.top() * (ch == '+' ? 1 : -1);
        } else if (ch == '(') {
            sign_stack.push(sign);
        } else if (ch == ')') {
            result += sign * current_number;
            current_number = 0;
            sign_stack.pop();
            sign = sign_stack.top();
        }
    }

    result += sign * current_number;
    return static_cast<int>(result);
}
