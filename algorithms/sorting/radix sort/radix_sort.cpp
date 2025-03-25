#include <iostream>
#include <vector>
#include <algorithm>
#include "utils/generate_array.hpp"
#include "utils/print_array.hpp"

class RadixSort {
public:
    void sort(std::vector<int>& arr) {
        if (arr.empty()) {
            return;
        }
        
        // Find the maximum number to know the number of digits
        int max = *std::max_element(arr.begin(), arr.end());
        
        // Do counting sort for every digit
        // Starting from least significant digit to most significant digit
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }

private:
    // A function to do counting sort based on the digit at exp's place
    void countingSort(std::vector<int>& arr, int exp) {
        std::vector<int> output(arr.size());
        std::vector<int> count(10, 0); // Count of digits 0-9
        
        std::cout << "\nSorting by digit at place value " << exp << ":\n";
        utils::print_array(arr);
        
        // Store count of occurrences in count[]
        for (size_t i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }
        
        // Change count[i] so that count[i] contains actual
        // position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build the output array
        for (size_t i = arr.size() - 1; i >= 0; i--) {
            size_t digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        
        // Copy the output array to arr[] so that arr[] contains
        // sorted numbers according to current digit
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
        
        std::cout << "After sorting: ";
        utils::print_array(arr);
    }
};

int main() {
    RadixSort rs = RadixSort();
    std::vector<int> arr = utils::generate_random_array<int>(10, 0, 1000);
    
    std::cout << "Before sorting:\n";
    utils::print_array(arr);
    
    rs.sort(arr);
    
    std::cout << "\nAfter sorting:\n";
    utils::print_array(arr);
}