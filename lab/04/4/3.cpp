// https://github.com/uLcdia/DSA/tree/main/lab/04/4

#include <iostream>
#include <stack>
#include <vector>

// https://github.com/uLcdia/DSA/blob/main/data_structures/union_find/example.cpp
class UnionFind {
  private:
    std::vector<int> parent; // Parent of each element
    std::vector<int> rank;   // Rank (approximate height) of each set
    std::size_t count;       // Number of disjoint sets

  public:
    // Initialize with n elements (0 to n-1)
    UnionFind(std::size_t n) {
        count = n;
        parent.resize(n);
        rank.resize(n, 0);

        // Initially, each element is its own parent
        for (std::size_t i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the root of the set containing element x
    // Uses path compression for efficiency
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union (merge) the sets containing elements x and y
    // Uses union by rank for efficiency
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // Already in the same set
        if (rootX == rootY)
            return;

        // Union by rank: attach smaller rank tree under root of higher rank
        // tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // If ranks are the same, make one the root and increment its rank
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        count--; // Decrease the number of disjoint sets
    }

    // Check if two elements are in the same set
    bool connected(int x, int y) { return find(x) == find(y); }

    // Get the number of disjoint sets
    std::size_t getCount() const { return count; }
};

// Union Find
std::size_t componentsCount(const std::vector<std::vector<int>> &matrix) {
    std::size_t n{matrix.size()};
    std::vector<bool> visited(n, false);
    UnionFind components{n};

    for (std::size_t row{0}; row < n; ++row) {
        if (visited[row])
            continue;

        for (std::size_t col{0}; col < n; ++col) {
            if (matrix[row][col] == 1 && !visited[col]) {
                components.unionSets(row, col);
            }
        }
    }

    return components.getCount();
}

std::vector<std::vector<int>> getMatrixFromInput(int n) {
    std::vector<std::vector<int>> matrix{};
    for (int i{0}; i < n; ++i) {
        std::vector<int> row{};
        for (int j{0}; j < n; ++j) {
            int num{};
            std::cin >> num;
            row.emplace_back(num);
        }
        matrix.emplace_back(row);
    }
    return matrix;
}

int main() {
    int n{};
    std::cin >> n;

    auto matrix{getMatrixFromInput(n)};

    std::cout << componentsCount(matrix);

    return 0;
}