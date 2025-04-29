// https://github.com/uLcdia/DSA/tree/main/lab/03/1

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

typedef std::priority_queue<int, std::vector<int>, std::greater<int>> min_priority_queue;

void printQueue(min_priority_queue numbers) {
    while (!numbers.empty()) {
        std::cout << numbers.top() << " ";
        numbers.pop();
    }
    std::cout << std::endl;
}

min_priority_queue getInput() {
    min_priority_queue numbers {};

    int n {};
    std::cin >> n;

    for (int i {}; i < n; ++i) {
        int number {};
        std::cin >> number;
        numbers.emplace(number);
    }

    return numbers;
}

int getWpl(min_priority_queue numbers) {
    int wpl {};
    while (numbers.size() >= 2) {
        int firstNum {numbers.top()};
        numbers.pop();

        int secondNum {numbers.top()};
        numbers.pop();

        int sum {firstNum + secondNum};
        wpl += sum;

        numbers.emplace(sum);
    }
    return wpl;
}

int main() {
    auto q = getInput();

    std::cout << getWpl(q);

    return 0;
}
