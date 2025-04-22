// https://github.com/uLcdia/DSA/tree/main/lab/02/4

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPNConverter {
public:
    std::string infixToRPN(const std::string& infix) {
        std::ostringstream rpn {};
        std::stack<char> operators {};

        for (char ch : infix) {
            if (isOperand(ch)) {
                rpn << ch;
            } else if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    rpn << operators.top();
                    operators.pop();
                }
                if (!operators.empty()) {
                    operators.pop(); // Remove the '('
                } else {
                    throw std::runtime_error("Mismatched parentheses.");
                }
            } else if (isOperator(ch)) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                    rpn << operators.top();
                    operators.pop();
                }
                operators.push(ch);
            } else if (isspace(ch)) {
                continue;
            } else if (ch == '#') {
                break;
            } else {
                throw std::invalid_argument("Invalid character in expression: " + std::string(1, ch));
            }
        }

        while (!operators.empty()) {
            rpn << operators.top();
            operators.pop();
        }

        return rpn.str();
    }

private:
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    bool isOperand(char ch) {
        return isalnum(ch);
    }

    int precedence(char op) {
        if (op == '*' || op == '/') {
            return 1;
        } else if (op == '+' || op == '-') {
            return 0;
        } else {
            return -1; // Parentheses
            // throw std::invalid_argument("Invalid operator: " + std::string(1, op));
        }
    }
};

int main() {
    std::string infix {};
    std::cin >> infix;

    RPNConverter rpnConverter {};

    std::cout << rpnConverter.infixToRPN(infix);

    return 0;
}