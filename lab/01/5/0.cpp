// https://github.com/uLcdia/DSA/tree/main/lab/01/5

#include <iostream>
#include <list>

int main() {
    // (n - k + 1)-th element of the list to be printed
    int k {};
    std::cin >> k;

    std::list<int> list {};

    int num {};
    int size {};
    while (std::cin >> num) {
        list.emplace_back(num);
        size++;
    }

    if (size < k) {
        std::cout << "Not Found";
        return 1;
    }

    // iterate to the (n - k + 1)-th element
    auto it = list.begin();
    for (int i = 0; i < size - k; i++) {
        it++;
    }
    std::cout << *it;

    return 0;
}