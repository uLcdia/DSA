#ifndef UTILS_GENERATE_ADJ_HPP
#define UTILS_GENERATE_ADJ_HPP

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

} // namespace utils

#endif // UTILS_GENERATE_ADJ_HPP