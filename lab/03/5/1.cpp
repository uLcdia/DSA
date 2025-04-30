// https://github.com/uLcdia/DSA/tree/main/lab/03/5

#include <iostream>
#include <string>
#include <vector>
#include <limits>

bool isValid(
    const std::vector<int>& postTree,
    int start, int end,
    int lowerBound, int upperBound
) {
    // Empty tree
    if (start > end) {
        return true;
    }

    int root = postTree[end];
    if (root < lowerBound || root > upperBound) {
        // Invalid BST
        return false;
    }

    // Find start of right subtree
    int i {start - 1};
    while (i < end && postTree[i] < root) {
        ++i;
    }

    return isValid(postTree, start, i - 1, lowerBound, root - 1) &&
           isValid(postTree, i, end - 1, root + 1, upperBound);
}

int main() {
    std::vector<int> postTree {};
    int num {};
    while (std::cin >> num) {
        postTree.emplace_back(num);
    }

    std::cout << std::boolalpha <<
        isValid(postTree, 0, postTree.size() - 1, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    return 0;
}