// https://github.com/uLcdia/DSA/tree/main/lab/01/1

#include <iostream>
#include <list>

void printList(std::list<int>& list) {
    for (int num : list) {
        std::cout  << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    int n {};
    std::cin >> n;

    int firstNumber {};
    std::cin >> firstNumber;

    std::list<int> list {};
    for (int i = 1; i < n; i++) {
        int number {};
        std::cin >> number;
        list.emplace_back(number);
    }

    auto it = list.begin();
    while (it != list.end() && *it < firstNumber) {
        it++;
    }

    list.insert(it, firstNumber);

    printList(list);

    return 0;
}