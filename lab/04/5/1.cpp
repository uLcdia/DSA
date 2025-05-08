// https://github.com/uLcdia/DSA/tree/main/lab/04/5

#include <iostream>
#include <vector>

void printSequence(const std::vector<int> &arr,
                   const std::vector<std::size_t> &searchSequence) {
    std::size_t n{searchSequence.size()};
    for (std::size_t i{0}; i < n - 1; ++i) {
        std::cout << arr[searchSequence[i]] << ",";
    }
    std::cout << arr[searchSequence[n - 1]];
    std::cout << std::endl;
}

std::size_t find(const std::vector<int> &arr, int value,
                 std::vector<std::size_t> &searchSequence) {
    std::size_t low{0};
    std::size_t high{arr.size() - 1};

    while (low <= high) {
        std::size_t mid{low + (high - low) / 2};
        searchSequence.emplace_back(mid);
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return arr.size();
}

std::vector<int> getArrayFromInput(int n) {
    std::vector<int> array{};
    int num{};
    for (int i{0}; i < n - 1; ++i) {
        char comma{};
        std::cin >> num >> comma;
        array.emplace_back(num);
    }
    std::cin >> num;
    array.emplace_back(num);
    return array;
}

int main() {
    int n{};
    std::cin >> n;

    auto array{getArrayFromInput(n)};

    int value{};
    std::cin >> value;

    std::vector<std::size_t> searchSequence{};
    auto index = find(array, value, searchSequence);

    if (index == array.size()) {
        std::cout << "no\n";
    } else {
        std::cout << index << '\n';
    }

    printSequence(array, searchSequence);

    return 0;
}