// https://github.com/uLcdia/DSA/tree/main/lab/01/5

#include <iostream>
#include <list>

int main() {
    int k {};
    std::cin >> k;

    std::list<int> list {};
    auto slowIt = list.begin();
    auto fastIt = list.begin();

    int num {};
    int count{};
    int stepsBehind {1};

    while (std::cin >> num) {
        list.emplace_back(num);
        fastIt++;
        count++;
        if (stepsBehind < k) {
            stepsBehind++;
        } else {
            slowIt++;
        }
    }

    if (count >= k && k > 0) {
        std::cout << *slowIt << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}