// https://github.com/uLcdia/DSA/tree/main/lab/04/3

#include <array>
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Expression {
    std::list<int> operands{};
    std::list<char> operators{};
};

// Apparently the test set requires int here
// `6x4+4/5`: `Yes`
int evaluate(const Expression &expr) {
    std::list<int> tempOperands{expr.operands};
    std::list<char> tempOperators{expr.operators};

    // First Pass: Handle multiplication and division
    auto itOperand{tempOperands.begin()};
    auto itOperator{tempOperators.begin()};
    for (std::size_t i{0}; i < 3; ++i) {
        if (*itOperator == 'x' || *itOperator == '/') {
            int result{};
            auto itOperandNext{std::next(itOperand)};
            if (*itOperator == 'x') {
                result = *itOperand * *itOperandNext;
            } else {
                if (*itOperandNext == 0) {
                    throw std::runtime_error("Division by zero");
                }
                result = *itOperand / *itOperandNext;
            }
            // Merge the result into the current operand
            *itOperand = result;
            // And erase the next operand and operator
            tempOperands.erase(itOperandNext);
            auto itErased{itOperator};
            ++itOperator;
            tempOperators.erase(itErased);
        } else {
            ++itOperand;
            ++itOperator;
        }
    }

    // Second Pass: Handle addition and subtraction
    itOperand = tempOperands.begin();
    itOperator = tempOperators.begin();
    int result{*itOperand};
    ++itOperand;
    while (itOperator != tempOperators.end()) {
        if (*itOperator == '+') {
            result += *itOperand;
        } else if (*itOperator == '-') {
            result -= *itOperand;
        } else {
            throw std::runtime_error("Invalid operator");
        }

        ++itOperand;
        ++itOperator;
    }
    return result;
}

std::vector<Expression> getExpressionsFromInput(int n) {
    std::vector<Expression> expressions{};
    for (int i{0}; i < n; ++i) {
        int num{};
        Expression newExpression{};

        // Add the first operand
        std::cin >> num;
        newExpression.operands.emplace_back(num);

        for (std::size_t j{0}; j < 3; ++j) {
            char newOperator{};
            std::cin >> newOperator;
            newExpression.operators.emplace_back(newOperator);
            std::cin >> num;
            newExpression.operands.emplace_back(num);
        }

        expressions.emplace_back(newExpression);
    }
    return expressions;
}

void printResults(const std::vector<Expression> &expressions) {
    for (auto expr : expressions) {
        std::cout << (evaluate(expr) == 24 ? "Yes\n" : "No\n");
    }
}

int main() {
    int n{};
    std::cin >> n;

    std::vector<Expression> expressions{getExpressionsFromInput(n)};

    printResults(expressions);

    return 0;
}