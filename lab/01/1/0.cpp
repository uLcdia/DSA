#include <iostream>
#include <list>

int main() {
    int n {};
    std::cin >> n;

    int firstNumber {};
    std::cin >> firstNumber;

    if (n == 1) {
        std::cout << firstNumber;
        return 0;
    } else if (n == 2) {
        int secondNumber {};
        std::cin >> secondNumber;
        if (firstNumber > secondNumber) {
            std::cout << secondNumber << ' ' << firstNumber;
        } else {
            std::cout << firstNumber << ' ' << secondNumber;
        }
        return 0;
    }

    std::list<int> list {};

    bool pastFirst {};

    for (int i = 0; i < n - 1; i++) {
        int newNumber {};
        std::cin >> newNumber;

        if (pastFirst || newNumber < firstNumber) {
            list.emplace_back(newNumber);
        } else {
            list.emplace_back(firstNumber);
            list.emplace_back(newNumber);
            pastFirst = true;
        }
    }

    for (int num : list) {
        std::cout << num << ' ';
    }

    return 0;
}