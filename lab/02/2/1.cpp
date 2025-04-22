// https://github.com/uLcdia/DSA/tree/main/lab/02/2

#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>

bool isParenthesesValid(std::string_view str) {
    static const std::unordered_set<char> OPEN_BRACKETS {'(', '[', '{'};
    static const std::unordered_map<char, char> CLOSE_BRACKETS_MAP {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    std::stack<char> stk {};

    for (char ch : str) {
        if (OPEN_BRACKETS.count(ch)) {
            stk.push(ch);
        } else if (CLOSE_BRACKETS_MAP.count(ch)) {
            if (stk.top() != CLOSE_BRACKETS_MAP.at(ch)) {
                return false;
            } else {
                stk.pop();
            }
        }
    }

    return stk.empty();
}

int main() {
    std::string str {};
    std::cin >> str;

    std::cout << (isParenthesesValid(str) ? 1 : 0);

    return 0;
}