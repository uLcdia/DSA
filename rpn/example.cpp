#include <iostream>
#include <bits/stdc++.h>

class RPNConverter {
public:
    // Converts infix expression to RPN (Reverse Polish Notation)
    std::string infixToRPN(const std::string& infix) {
        std::string rpn;
        std::stack<char> operators;

        for (char c : infix) {
            if (isOperand(c)) {
                rpn += c;
            } else if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    rpn += operators.top();
                    operators.pop();
                }
                if (!operators.empty()) { // Remove the '('
                    operators.pop();
                }
                //  else {
                //     throw std::runtime_error("Mismatched parentheses."); // Optional error handling
                //  }
            } else if (isOperator(c)) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    rpn += operators.top();
                    operators.pop();
                }
                operators.push(c);
            } else if (isspace(c)) {
                //Ignore whitespace
                continue;
            }
            else
            {
                //  throw std::invalid_argument("Invalid character in expression: " + std::string(1, c)); // or handle
                return "ERROR: INVALID INPUT"; // Return error message, or throw exception, or handle invalid characters differently.
            }
        }

        // Add remaining operators to RPN
        while (!operators.empty()) {
            if (operators.top() == '(') {
                // throw std::runtime_error("Mismatched parentheses.");  // Optional error handling.
                return "ERROR: MISMATCHED PARENTHESES"; // Return error message
            }

            rpn += operators.top();
            operators.pop();
        }

        return rpn;
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