#include <iostream>
#include <vector>
#include "utils/generate_array.hpp"
#include "utils/print_array.hpp"

class MergeSort {
public:
    void sort(std::vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
    }

private:
    void mergeSort(std::vector<int>& arr, size_t left, size_t right) {
        std::cout << "\nmergeSort(" << left << ", " << right << ")\n";
        utils::print_array(arr);
        
        if (left < right) {
            // Find the middle point
            size_t mid = left + (right - left) / 2;
            
            // Sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }
    
    void merge(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
        std::cout << "  Merging: [" << left << ".." << mid << "] and [" 
                  << (mid + 1) << ".." << right << "]\n";
        
        // Create temporary arrays
        std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
        
        std::cout << "  Left array: ";
        utils::print_array(leftArr);
        std::cout << "  Right array: ";
        utils::print_array(rightArr);
        
        // Initial indices for left, right and merged arrays
        size_t i = 0;
        size_t j = 0;
        size_t k = left;
        
        // Merge the temp arrays back into arr[left..right]
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        // Copy the remaining elements of leftArr, if there are any
        while (i < leftArr.size()) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        
        // Copy the remaining elements of rightArr, if there are any
        while (j < rightArr.size()) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
        
        std::cout << "  After merge: ";
        utils::print_array(arr);
    }
};

int main() {
    MergeSort ms = MergeSort();
    std::vector<int> arr = utils::generate_random_array<int>(10, 0, 100);

    std::cout << "Before sorting:\n";
    utils::print_array(arr);

    ms.sort(arr);

    std::cout << "\nAfter sorting:\n";
    utils::print_array(arr);
}