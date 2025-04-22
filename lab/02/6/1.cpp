// https://github.com/uLcdia/DSA/tree/main/lab/02/6

#include <iostream>
#include <vector>

int getSequenceEnd(int num, int start) {
    while (num > 0) {
        num -= start++;
    }
    if (num == 0) {
        return start;
    } else {
        return -1;
    }
}

std::vector<std::pair<int, int>> findSequence(int num) {
    int mid {num / 2};
    std::vector<std::pair<int, int>> vec {};
    for (int i = 1; i <= mid; ++i) {
        int end {getSequenceEnd(num, i)};
        if (end != -1) {
            vec.emplace_back(i, end);
        }
    }

    return vec;
}

void printSequences(const std::vector<std::pair<int, int>>& sequences) {
    for (auto sequence : sequences) {
        for (int i = sequence.first; i < sequence.second; ++i) {
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