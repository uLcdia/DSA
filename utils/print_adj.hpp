#ifndef UTILS_PRINT_ADJ_HPP
#define UTILS_PRINT_ADJ_HPP

#include <iostream>
#include <vector>

namespace utils {

template <typename T> void print_adj(const std::vector<std::vector<T>> &adj) {
    for (const auto &row : adj) {
        std::cout << '[';
        for (size_t i = 0; i < row.size() - 1; i++) {
            std::cout << row[i] << ", ";
        }
        std::cout << row[row.size() - 1] << "]\n";
    }
}

} // namespace utils

#endif // UTILS_PRINT_ADJ_HPP