#include <iostream>
#include <vector>
#include "utils/generate_array.hpp"
#include "utils/print_array.hpp"

class HeapSort {
public:
    void sort(std::vector<int>& arr) {
        int n = arr.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        std::cout << "\nHeap built:\n";
        utils::print_array(arr);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]); // Move current root to end
            heapify(arr, i, 0); // call max heapify on the reduced heap
        }
    }

private:
    void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left child index
        int right = 2 * i + 2; // right child index

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
};

int main() {
    HeapSort hs = HeapSort();
    std::vector<int> arr = utils::generate_random_array<int>(10, 0, 100);

    std::cout << "Before sorting:\n";
    utils::print_array(arr);

    hs.sort(arr);

    std::cout << "\nAfter sorting:\n";
    utils::print_array(arr);
}
