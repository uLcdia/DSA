#include <iostream>
#include <stack>
#include <sstream>

// Shunting Yard Algorithm
// https://en.wikipedia.org/wiki/Shunting_yard_algorithm
class RPNConverter {
public:
    std::string infixToRPN(const std::string& infix) {
        std::stringstream rpn;
        std::stack<char> operators;

        for (char c : infix) {
            if (isOperand(c)) {
                // If opperand, add to the RPN
                rpn << c << ' ';
            } else if (c == '(') {
                // If '(', add to the stack
                operators.emplace(c);
            } else if (c == ')') {
                // If ')', pop from the stack until '(' is found
                while (!operators.empty() && operators.top() != '(') {
                    rpn << operators.top() << ' ';
                    operators.pop();
                }
                if (!operators.empty()) {
                    operators.pop(); // Remove the '(' from the stack
                } else {
                    throw std::invalid_argument("Mismatched parentheses");
                }
            } else if (isOperator(c)) {
                // If operator, handle precedence
                while (!operators.empty() && 
                       ((c != '^' && precedence(c) <= precedence(operators.top())) ||
                        (c == '^' && precedence(c) < precedence(operators.top())))) {
                    // Pop operators with higher precedence (or equal precedence for left-associative operators)
                    rpn << operators.top() << ' ';
                    operators.pop();
                }
                // Add the current operator to the stack
                operators.emplace(c);
            } else if (isspace(c)) {
                // Ignore whitespace
                continue;
            } else {
                throw std::invalid_argument("Invalid input");
            }
        }

        // Add any remaining operators to the RPN
        while (!operators.empty()) {
            if (operators.top() == '(') {
                throw std::invalid_argument("Mismatched parentheses");
            }
            rpn << operators.top() << ' ';
            operators.pop();
        }

        return rpn.str();
    }


private:
    // Helper function to check if a character is an operand (alphanumeric)
    bool isOperand(char c) {
        return std::isalnum(c); // Check if it's a letter or a digit
    }

    // Helper function to check if a character is an operator
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    // Helper function to get the precedence of an operator
    int precedence(char op) {
        if (op == '^') {
            return 3; // Highest precedence
        } else if (op == '*' || op == '/') {
            return 2;
        } else if (op == '+' || op == '-') {
            return 1;
        } else {
            return -1; // Lowest precedence (for '(')
        }
    }
};

int main() {
    RPNConverter converter;
    std::string infixExpression;

    // Get infix expression from the user
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    try {
        std::string rpnExpression = converter.infixToRPN(infixExpression);
        std::cout << "RPN expression: " << rpnExpression << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
