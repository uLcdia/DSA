#include <iostream>
#include <vector>
#include <algorithm>

class VectorBinarySearch {
private:
    std::vector<int> data;
    
    // Binary search implementation (iterative)
    int binarySearch(int target) const {
        int left = 0;
        int right = data.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (data[mid] == target) {
                return mid;  // Found
            } else if (data[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;  // Not found
    }

public:
    // Insert while maintaining sorted order (O(n) time)
    void insert(int value) {
        if (data.empty()) {
            data.push_back(value);
            return;
        }
        
        // Find insertion point using upper_bound (O(log n) search + O(n) insertion)
        auto it = std::upper_bound(data.begin(), data.end(), value);
        data.insert(it, value);
    }

    // Delete element (O(n) time)
    bool remove(int value) {
        int index = binarySearch(value);
        if (index == -1) return false;
        
        data.erase(data.begin() + index);
        return true;
    }

    // Search (O(log n) time)
    bool contains(int value) const {
        return binarySearch(value) != -1;
    }

    // Get elements in sorted order (O(1) access)
    const std::vector<int>& getSortedData() const {
        return data;
    }

    // Range queries (O(log n + k) time for k elements in range)
    std::vector<int> rangeQuery(int low, int high) const {
        auto lowIt = std::lower_bound(data.begin(), data.end(), low);
        auto highIt = std::upper_bound(data.begin(), data.end(), high);
        return std::vector<int>(lowIt, highIt);
    }
};

// Key differences from Binary Search Tree:
// 1. Memory Layout:
//    - Vector: Contiguous memory, better cache locality
//    - BST: Fragmented nodes with pointers, worse cache performance

// 2. Insertion/Deletion Complexity:
//    - Vector: O(n) time due to shifting elements
//    - BST: O(log n) average case for insert/delete

// 3. Search Complexity:
//    - Both have O(log n) average case, but vector has better constants
//    - BST can degrade to O(n) if unbalanced

// 4. Ordered Operations:
//    - Vector: Natural ordering, easy range queries
//    - BST: Requires in-order traversal for ordered access

// 5. Memory Overhead:
//    - Vector: No per-element overhead
//    - BST: Per-node pointers (left/right) overhead

// 6. Dynamic Operations:
//    - Vector: Insert/delete expensive, good for static data
//    - BST: Efficient updates, good for dynamic data

int main() {
    VectorBinarySearch vbs;
    
    // Insert elements (maintains sorted order)
    vbs.insert(5);
    vbs.insert(3);
    vbs.insert(7);
    vbs.insert(2);
    vbs.insert(4);
    vbs.insert(6);
    vbs.insert(8);

    // Display sorted data
    std::cout << "Vector contents: ";
    for (int num : vbs.getSortedData()) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // Search tests
    std::cout << "Contains 3: " << std::boolalpha << vbs.contains(3) << "\n";
    std::cout << "Contains 9: " << vbs.contains(9) << "\n\n";

    // Range query
    auto range = vbs.rangeQuery(4, 7);
    std::cout << "Elements between 4-7: ";
    for (int num : range) std::cout << num << " ";
    std::cout << "\n\n";

    // Delete tests
    vbs.remove(3);
    vbs.remove(8);
    vbs.remove(5);

    std::cout << "After deletions: ";
    for (int num : vbs.getSortedData()) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
