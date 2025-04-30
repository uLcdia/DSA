// https://github.com/uLcdia/DSA/tree/main/lab/03/4

#include <iostream>
#include <string>
#include <unordered_map>

void printPreOrderHelper(
    const std::string& inTree, const std::string& postTree,
    std::size_t inStart, std::size_t inEnd,
    std::size_t postStart, std::size_t postEnd,
    const std::unordered_map<char, std::size_t>& inOrderMap
) {

    if (inStart > inEnd || postStart > postEnd ||
        inEnd >= inTree.size() || postEnd >= postTree.size()) {
        return;
    }

    char root {postTree[postEnd]};

    std::size_t inRootIndex {inOrderMap.at(root)};

    std::size_t leftSize {inRootIndex - inStart};

    std::cout << root;
    printPreOrderHelper(
        inTree, postTree,
        inStart, inRootIndex - 1,
        postStart, postStart + leftSize - 1,
        inOrderMap
    );
    printPreOrderHelper(
        inTree, postTree,
        inRootIndex + 1, inEnd,
        postStart + leftSize, postEnd - 1,
        inOrderMap
    );
}

void printPreOrder(const std::string& inTree, const std::string& postTree) {
    if (inTree.size() != postTree.size()) {
        throw std::invalid_argument("The length of the input strings must be equal.");
    }
    std::size_t size {inTree.size()};
    if (size == 0) {
        return;
    }

    std::unordered_map<char, std::size_t> inOrderMap;
    for (std::size_t i = 0; i < size; ++i) {
        inOrderMap[inTree[i]] = i;
    }

    printPreOrderHelper(
        inTree, postTree,
        0, size - 1,
        0, size - 1,
        inOrderMap
    );
}

int main() {
    std::string inTree {};
    std::string postTree {};

    std::cin >> inTree >> postTree;

    printPreOrder(inTree, postTree);

    return 0;
}