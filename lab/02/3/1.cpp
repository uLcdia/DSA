// https://github.com/uLcdia/DSA/tree/main/lab/02/3

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

std::string decimalToOctal(int decimal) {
    std::stack<int> stk {};

    while (decimal >= 8) {
        stk.push(decimal % 8);
        decimal /= 8;
    }
    stk.push(decimal);

    std::ostringstream oss {};
    while (!stk.empty()) {
        oss << stk.top();
        stk.pop();
    }

    return oss.str();
}

int main() {
    int decimal {};

    while (true) {
        try {
            std::cin >> decimal;
            if (decimal < 0) {
                throw std::invalid_argument("Negative number");
            }
            break;
        } catch (std::exception& e) {
            std::cout << "Invalid input. Please enter a non-negative integer: ";
        }
    }

    // std::cout << std::oct << decimal;

    std::cout << decimalToOctal(decimal);

    return 0;
}