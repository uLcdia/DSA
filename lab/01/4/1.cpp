// https://github.com/uLcdia/DSA/tree/main/lab/01/4

#include <iostream>
#include <list>
#include <string>
#include <sstream>

bool uniqueEmplaceBack(std::list<int>& list, int num) {
    if (list.empty() || list.back() != num) {
        list.emplace_back(num);
        return true;
    }
    return false;
}

void print(const std::list<int>& list) {
    for (const auto& num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> targetList {};


    // Get input
    std::string line {};
    int num {};

    std::list<int> firstList {};
    std::getline(std::cin, line);
    std::istringstream iss1(line);
    while (iss1 >> num) {
        firstList.emplace_back(num);
    }

    std::list<int> secondList {};
    std::getline(std::cin, line);
    std::istringstream iss2(line);
    while (iss2 >> num) {
        secondList.emplace_back(num);
    }


    // Combine lists
    auto it1 = firstList.begin();
    auto it2 = secondList.begin();

    while (it1 != firstList.end() || it2 != secondList.end()) {
        if (it1 != firstList.end() && (it2 == secondList.end() || *it1 <= *it2)) {
            uniqueEmplaceBack(targetList, *it1);
            ++it1;
        } else if (it2 != secondList.end()) {
            uniqueEmplaceBack(targetList, *it2);
            ++it2;
        }
    }


    // Print target list
    print(targetList);

    return 0;
}