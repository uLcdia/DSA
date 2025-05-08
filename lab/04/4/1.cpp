// https://github.com/uLcdia/DSA/tree/main/lab/04/4

#include <deque>
#include <iostream>
#include <vector>

// BFS
int componentsCount(const std::vector<std::vector<int>> &matrix) {
    int count{};
    std::size_t n{matrix.size()};
    std::vector<bool> visited(n, false);

    for (std::size_t startRow{0}; startRow < n; ++startRow) {
        if (visited[startRow]) {
            continue;
        }
        std::deque<std::size_t> rows{};
        rows.emplace_back(startRow);
        while (!rows.empty()) {
            std::size_t row{rows.front()};
            rows.pop_front();
            if (visited[row]) {
                continue;
            }
            visited[row] = true;
            for (std::size_t col{0}; col < n; ++col) {
                if (col == row) {
                    // Skip diagonal
                    continue;
                }
                // If unvisited and connected
                if (matrix[row][col] == 1 && !visited[col]) {
                    rows.emplace_back(col);
                }
            }
        }
        ++count;
    }

    return count;
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