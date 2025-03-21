#ifndef GENERATE_ARRAY_HPP
#define GENERATE_ARRAY_HPP

#include <random>
#include <vector>

template <typename T>
std::vector<T> generate_random_array(size_t size, T min_value, T max_value) {
    std::vector<T> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(min_value, max_value);

    for (size_t i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }

    return arr;
}

#endif // GENERATE_ARRAY_HPP