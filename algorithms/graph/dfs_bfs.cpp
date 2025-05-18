#include "utils/generate_adj.hpp"
#include "utils/print_adj.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

void dfs(const std::vector<std::vector<bool>> &adj, std::vector<bool> &visited,
         std::size_t row) {
    if (visited[row]) {
        return;
    }
    visited[row] = true;
    std::cout << row << " ";

    for (std::size_t col{}; col < adj.size(); ++col) {
        if (row == col) {
            continue;
        }
        if (adj[row][col]) {
            dfs(adj, visited, col);
        }
    }
}

void dfsRecursive(const std::vector<std::vector<bool>> &adj) {
    std::size_t n{adj.size()};
    std::vector<bool> visited(n, false);

    for (std::size_t row{}; row < n; ++row) {
        dfs(adj, visited, row);
    }

    // Replace the for loop
    // Only if the graph is connected
    // Can start from any node
    // dfs(adj, visited, 0);
}

void dfsIterative(const std::vector<std::vector<bool>> &adj) {
    std::size_t n{adj.size()};
    std::vector<bool> visited(n, false);
    std::stack<std::size_t> stack{};

    for (std::size_t row{}; row < n; ++row) {
        if (visited[row]) {
            continue;
        }
        stack.emplace(row);

        while (!stack.empty()) {
            std::size_t currentRow{stack.top()};
            stack.pop();

            if (visited[currentRow]) {
                continue;
            }
            visited[currentRow] = true;
            std::cout << currentRow << " ";

            // Or use decrement to maintain the same order as recursive
            for (std::size_t col{}; col < n; ++col) {
                if (adj[currentRow][col] && !visited[col] &&
                    currentRow != col) {
                    stack.emplace(col);
                }
            }
        }
    }
}

void bfsIterative(const std::vector<std::vector<bool>> &adj) {
    std::size_t n{adj.size()};
    std::vector<bool> visited(n, false);
    std::queue<std::size_t> queue{};

    for (std::size_t row{}; row < n; ++row) {
        if (visited[row]) {
            continue;
        }
        queue.emplace(row);

        while (!queue.empty()) {
            std::size_t currentRow{queue.front()};
            queue.pop();

            if (visited[currentRow]) {
                continue;
            }
            visited[currentRow] = true;
            std::cout << currentRow << " ";

            for (std::size_t col{}; col < n; ++col) {
                if (adj[currentRow][col] && !visited[col] &&
                    currentRow != col) {
                    queue.emplace(col);
                }
            }
        }
    }
}

int main() {
    auto adj{utils::generate_random_adj(7, 0.6)};
    utils::print_adj(adj);

    dfsRecursive(adj);
    std::cout << std::endl;
    dfsIterative(adj);

    std::cout << std::endl;
    bfsIterative(adj);

    return 0;
}