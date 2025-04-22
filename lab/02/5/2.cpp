// https://github.com/uLcdia/DSA/tree/main/lab/02/5

#include <iostream>
#include <list>
#include <limits>

int greatestPairDiff(std::list<int> nums) {
    if (nums.empty()) {
        throw std::runtime_error("Empty list");
    }

    int greatestDiff {std::numeric_limits<int>::min()};
    int maxValue {*nums.begin()};

    for (auto it = std::next(nums.begin()); it != nums.end(); ++it) {
        int diff {maxValue - *it};
        greatestDiff = std::max(greatestDiff, diff);
        maxValue = std::max(maxValue, *it);
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
    std::list<int> nums {handleInput()};
    std::cout << greatestPairDiff(nums);

    return 0;
}