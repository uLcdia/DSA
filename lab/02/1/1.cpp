// https://github.com/uLcdia/DSA/tree/main/lab/02/1

#include <iostream>
#include <stack>
#include <string>

bool isPalindrome(std::string_view str) {
    std::stack<char> stk {};
    size_t len = str.length();
    size_t mid = len / 2;

    for (size_t i = 0; i < mid; i++) {
        stk.emplace(str[i]);
    }

    for (size_t i = len - mid; i < len; i++) {
        if (stk.top() != str[i]) {
            return false;
        }
        stk.pop();
    }

    return stk.empty();
}

int main() {
    std::string str {};
    std::cin >> str;

    std::cout << (isPalindrome(str) ? "yes" : "no");

    return 0;
}