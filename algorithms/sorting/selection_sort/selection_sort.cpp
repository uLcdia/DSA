#include <iostream>
#include <vector>
#include "utils/generate_array.hpp"
#include "utils/print_array.hpp"

template <typename T>
void selection_sort(std::vector<T>& arr) {
    size_t n = arr.size();

    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;

        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main() {
    std::vector<int> arr = generate_random_array<int>(10, 0, 100);

    std::cout << "Before sorting:\n";
    print_array(arr);

    selection_sort(arr);

    std::cout << "\nAfter sorting:\n";
    print_array(arr);
}