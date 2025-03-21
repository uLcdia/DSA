#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils/print_array.hpp"
#include "../utils/generate_array.hpp"

template <typename T>
void binary_insertion_sort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        std::cout << "\ni = " << i << '\n';
        print_array(arr);
        T current_value = arr[i];

        // Binary search to find the insertion point
        auto insertion_point = std::upper_bound(arr.begin(), arr.begin() + i, current_value);
        size_t insertion_index = std::distance(arr.begin(), insertion_point);

        for (size_t j = i; j > insertion_index; j--) {
            arr[j] = arr[j - 1];
            print_array(arr);
        }
        arr[insertion_index] = current_value;
        print_array(arr);
    }
}

int main() {
    std::vector<int> arr = generate_random_array<int>(10, 0, 100);

    std::cout << "Before sorting:\n";
    print_array(arr);

    binary_insertion_sort(arr);

    std::cout << "\nAfter sorting:\n";
    print_array(arr);
}