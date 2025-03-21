#include <vector>
#include <iostream>
#include "../../../utils/print_array.hpp"
#include "../../../utils/generate_array.hpp"

template <typename T>
void insertion_sort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        std::cout << "\ni = " << i << '\n';
        print_array(arr);

        for (size_t j = 0; j < i; j++) {
            if (arr.at(j) > arr.at(i)) {
                T temp = arr.at(i);
                for (size_t k = i; k > j; k--) {
                    arr.at(k) = arr.at(k - 1);
                    print_array(arr);
                }
                arr.at(j) = temp;
                print_array(arr);
                break;
            }
        }
    }
}

template <typename T>
void insertion_sort_optimized(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        std::cout << "\ni = " << i << '\n';
        print_array(arr);

        T current_value = arr[i];
        size_t j = i;

        // Shift elements greater than current_value to the right
        while (j > 0 && arr[j - 1] > current_value) {
            arr[j] = arr[j - 1];
            print_array(arr);
            --j;
        }
        arr[j] = current_value; // Insert current_value at the correct position
        print_array(arr);
    }
}

int main() {
    std::vector<int> arr = generate_random_array<int>(10, 0, 100);

    std::cout << "Before sorting:\n";
    print_array(arr);

    insertion_sort_optimized(arr);

    std::cout << "\nAfter sorting:\n";
    print_array(arr);
}