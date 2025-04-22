// https://github.com/uLcdia/DSA/tree/main/lab/02/5

#include <iostream>
#include <list>

int greatestPairDiff(std::list<int> nums) {
    int greatestDiff {};
    for (auto itOut = nums.begin(); itOut != nums.end(); ++itOut) {
        int numCompared = *itOut;
        for (auto itIn = std::next(itOut); itIn != nums.end(); ++itIn) {
            int diff = numCompared - *itIn;
            greatestDiff = std::max(diff, greatestDiff);
        }
    }

    return greatestDiff;
}

std::list<int> handleInput() {
    std::list<int> nums {};
    int num {};
    while (std::cin >> num) {
        nums.emplace_back(num);
    }

    return nums;
}

int main() {
    std::list<int> nums = handleInput();
    std::cout << greatestPairDiff(nums);

    return 0;
}