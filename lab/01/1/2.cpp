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

    if (n <= 0) {
        return 0;
    }

    int firstNumber {};
    std::cin >> firstNumber;

    std::list<int> list {};
    auto insertPos = list.begin();
    bool positionFound = false;

    for (int i = 1; i < n; i++) {
        int number {};
        std::cin >> number;

        if (!positionFound && number > firstNumber) {
            insertPos = list.insert(list.end(), number);
            list.insert(insertPos, firstNumber);
            positionFound = true;
        } else {
            list.push_back(number);
        }
    }

    if (!positionFound) {
        list.push_back(firstNumber);
    }

    printList(list);

    return 0;
}