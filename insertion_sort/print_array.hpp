#ifndef PRINT_ARRAY_HPP
#define PRINT_ARRAY_HPP

#include <iostream>
#include <vector>

template <typename T>
void print_array(const std::vector<T>& arr) {
    std::cout << '[';
    for (size_t i = 0; i < arr.size() - 1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[arr.size() - 1] << "]\n";
}

#endif // PRINT_ARRAY_HPP