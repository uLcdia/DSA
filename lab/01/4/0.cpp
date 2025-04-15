// https://github.com/uLcdia/DSA/tree/main/lab/01/4

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

bool uniqueEmplaceBack(std::vector<int>& array, int num) {
    if (array.empty() || array[array.size() - 1] != num) {
        array.emplace_back(num);
        return true;
    }
    return false;
}

void printArray(const std::vector<int>& array) {
    for (const auto& num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> targetArray {};


    // Get input
    std::string line {};
    int num {};

    std::vector<int> firstArray {};
    std::getline(std::cin, line);
    std::istringstream iss1(line);
    while (iss1 >> num) {
        firstArray.emplace_back(num);
    }

    std::vector<int> secondArray {};
    std::getline(std::cin, line);
    std::istringstream iss2(line);
    while (iss2 >> num) {
        secondArray.emplace_back(num);
    }


    // Combine arrays
    auto it1 = firstArray.begin();
    auto it2 = secondArray.begin();

    while (it1 != firstArray.end() || it2 != secondArray.end()) {
        if (it1 != firstArray.end() && (it2 == secondArray.end() || *it1 <= *it2)) {
            uniqueEmplaceBack(targetArray, *it1);
            ++it1;
        } else if (it2 != secondArray.end()) {
            uniqueEmplaceBack(targetArray, *it2);
            ++it2;
        }
    }


    // Print target array
    printArray(targetArray);

    return 0;
}