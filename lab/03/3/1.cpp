// https://github.com/uLcdia/DSA/tree/main/lab/03/3

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

void print(const std::string& str) {
    std::stack<char> s {};
    std::vector<std::deque<int>> levels {};
    int currentDepth {-1};

    for (size_t i {}; i < str.length(); ++i) {
        char ch {str[i]};
        if (ch == '(') {
            ++currentDepth;
            s.emplace(ch);
            if (levels.size() <= static_cast<size_t>(currentDepth)) {
                levels.emplace_back(std::deque<int>());
            }
        } else if (ch == ')') {
            std::deque<int> groupNums {};
            while (!s.empty()) {
                int num {};
                int power {1};
                while (s.top() != '(' && s.top() != ',') {
                    num += (s.top() - '0') * power;
                    power *= 10;
                    s.pop();
                }
                groupNums.emplace_front(num);
                if (s.top() == '(') {
                    break;
                } else {
                    s.pop(); // Pops ','
                }
            }
            s.pop(); // Pops '('

            while (!groupNums.empty()) {
                levels.at(currentDepth).emplace_back(groupNums.front());
                groupNums.pop_front();
            }

            --currentDepth;
        } else {
            s.emplace(ch);
        }
    }

    int root {};
    int power {1};
    while (!s.empty()) {
        root += (s.top() - '0') * power;
        power *= 10;
        s.pop();
    }

    for (int i {static_cast<int>(levels.size() - 1)}; i >= 0; --i) {
        for (int num : levels.at(i)) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    std::cout << root;
}

int main() {
    std::string str {};

    std::getline(std::cin, str);

    print(str);

    return 0;
}