#ifndef UTILS_GENERATE_ADJ_HPP
#define UTILS_GENERATE_ADJ_HPP

#include <limits>
#include <random>
#include <vector>

namespace utils {

std::vector<std::vector<bool>> generate_random_adj(std::size_t size,
                                                   double density = 0.5) {
    std::vector<std::vector<bool>> adj(size, std::vector<bool>(size, false));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(density);
    for (std::size_t i{}; i < size; ++i) {
        for (std::size_t j{i + 1}; j < size; ++j) {
            if (d(gen)) {
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }
    return adj;
}

std::vector<std::vector<int>>
generate_weighted_directed_adj(std::size_t size, double density = 0.5,
                               int min_weight = 1, int max_weight = 10) {
    std::vector<std::vector<int>> adj(
        size, std::vector<int>(size, std::numeric_limits<int>::max()));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weight_dist(min_weight, max_weight);
    std::bernoulli_distribution d(density);
    for (std::size_t i{}; i < size; ++i) {
        for (std::size_t j{}; j < size; ++j) {
            if (d(gen) && i != j) {
                adj[i][j] = weight_dist(gen);
            } else if (i == j) {
                adj[i][j] = 0;
            }
        }
    }
    return adj;
}

} // namespace utils

#endif // UTILS_GENERATE_ADJ_HPP