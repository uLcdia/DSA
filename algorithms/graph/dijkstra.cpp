#include "utils/generate_adj.hpp"
#include "utils/print_adj.hpp"
#include "utils/print_array.hpp"
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

struct NodeDistance {
    std::size_t node{};
    int distance{};

    bool operator>(const NodeDistance &other) const {
        return distance > other.distance;
    }
};

std::vector<int> dijkstra(const std::vector<std::vector<int>> &adj) {
    std::size_t n{adj.size()};
    std::vector<int> distances(n, std::numeric_limits<int>::max());
    distances[0] = 0;

    std::priority_queue<NodeDistance, std::vector<NodeDistance>,
                        std::greater<NodeDistance>>
        pq{};
    pq.emplace(0, 0);

    while (!pq.empty()) {
        std::size_t u{pq.top().node};
        int distance{pq.top().distance};
        pq.pop();

        if (distance > distances[u]) {
            continue;
        }

        for (std::size_t v{}; v < n; ++v) {
            if (u == v || adj[u][v] == std::numeric_limits<int>::max()) {
                continue;
            }

            int weight{adj[u][v]};
            int newDistance{distances[u] + weight};
            if (distances[u] + weight < distances[v]) {
                distances[v] = newDistance;
                pq.emplace(v, newDistance);
            }
        }
    }

    return distances;
}

std::vector<int> dijkstraAlt(const std::vector<std::vector<int>> &adj) {
    std::size_t n{adj.size()};
    std::vector<bool> visited(n, false);
    std::vector<int> distances(n, std::numeric_limits<int>::max());
    distances[0] = 0;

    while (true) {
        bool notAllVisited{};
        std::size_t u{};
        int minDistance{std::numeric_limits<int>::max()};
        for (std::size_t i{}; i < n; ++i) {
            if (!visited[i]) {
                notAllVisited = true;
                if (distances[i] < minDistance) {
                    u = i;
                    minDistance = distances[i];
                }
            }
        }
        if (!notAllVisited) {
            break;
        }
        visited[u] = true;

        for (std::size_t v{}; v < n; ++v) {
            if (u == v || adj[u][v] == std::numeric_limits<int>::max()) {
                continue;
            }
            int weight{adj[u][v]};
            int newDistance{distances[u] + weight};
            distances[v] = std::min(distances[v], newDistance);
        }
    }

    return distances;
}

int main() {
    auto adj{utils::generate_weighted_directed_adj(5, 0.5, 1, 10)};
    utils::print_adj(adj);

    std::cout << std::endl;
    utils::print_array(dijkstra(adj));

    std::cout << std::endl;
    utils::print_array(dijkstraAlt(adj));

    return 0;
}