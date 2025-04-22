// https://github.com/uLcdia/DSA/tree/main/lab/02/6

#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::pair<int, int>> findSequence(int num) {
    std::vector<std::pair<int, int>> vec {};
    if (num <= 0) return vec;

    // Iterate over possible lengths of sequences (k)
    // k can be at most around sqrt(2*num) because sum = k*(2*start + k - 1)/2
    int maxK = static_cast<int>(std::sqrt(2.0 * num)) + 1;
    for (int k = maxK; k >= 2; --k) {
        // From the sum formula: k*(2*start + k - 1)/2 = num
        // => 2*start + k - 1 = (2*num)/k
        // => 2*start = (2*num)/k - k + 1
        // => start = [(2*num)/k - k + 1] / 2
        long long numerator = 2LL * num;
        if (numerator % k != 0) continue; // Ensure integer division
        long long temp = (numerator / k) - k + 1;
        if (temp % 2 != 0 || temp <= 0) continue; // start must be a positive integer
        int start = static_cast<int>(temp / 2);
        if (start > 0) {
            int end = start + k - 1;
            vec.emplace_back(start, end);
        }
    }

    return vec;
}

void printSequences(const std::vector<std::pair<int, int>>& sequences) {
    for (auto sequence : sequences) {
        for (int i = sequence.first; i <= sequence.second; ++i) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int num {};
    std::cin >> num;

    std::vector<std::pair<int, int>> sequences {findSequence(num)};

    if (!sequences.empty()) {
        printSequences(sequences);
    }

    return 0;
}