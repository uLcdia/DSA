// https://github.com/uLcdia/DSA/tree/main/lab/04/1

#include <iostream>
#include <vector>

void printArray(const std::vector<int> &arr) {
    for (const auto &i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int> &arr) {
    // Starting at the 2nd element, assume the first element is sorted
    for (size_t i{1}; i < arr.size(); ++i) {
        // Placing currentValue to the correct position
        int currentValue{arr[i]};
        size_t j{i};

        // Finding the correct position
        // Either the prior element is smaller than currentValue
        // or the current element is the smallest
        while (j > 0 && arr[j - 1] > currentValue) {
            // Move the larger element to the right
            arr[j] = arr[j - 1];
            --j;
        }
        // Insert currentValue at the correct position
        arr[j] = currentValue;

        printArray(arr);
    }
}

std::vector<int> getArrayFromInput(int n) {
    std::vector<int> array{};
    for (int i{0}; i < n; ++i) {
        int num{};
        std::cin >> num;
        array.emplace_back(num);
    }
    return array;
}

int main() {
    int n{};
    std::cin >> n;

    auto array{getArrayFromInput(n)};
    insertionSort(array);

    return 0;
}