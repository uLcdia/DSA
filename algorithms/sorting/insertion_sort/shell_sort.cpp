#include <iostream>
#include <vector>
#include "../../../utils/print_array.hpp"
#include "../../../utils/generate_array.hpp"

template <typename T>
void shell_sort(std::vector<T>& arr) {
    size_t n = arr.size();
    size_t gap = n / 2;

    while (gap > 0) {
        std::cout << "\ngap = " << gap << '\n';
        print_array(arr);

        for (size_t i = gap; i < n; i++) {
            T current_value = arr[i];

            size_t j = i;
            while (j >= gap && arr[j - gap] > current_value) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = current_value;
        }

        gap /= 2;
    }
}

int main() {
    std::vector<int> arr = generate_random_array<int>(10, 0, 100);

    std::cout << "Before sorting:\n";
    print_array(arr);

    shell_sort(arr);

    std::cout << "\nAfter sorting:\n";
    print_array(arr);
}