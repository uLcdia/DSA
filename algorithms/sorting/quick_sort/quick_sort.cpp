#include <iostream>
#include <vector>
#include "utils/generate_array.hpp"
#include "utils/print_array.hpp"

class QuickSort {
public:
    void sort(std::vector<int>& arr) {
        quickSort(arr, 0, arr.size() - 1);
    }

private:
    void quickSort(std::vector<int>& arr, int low, int high) {
        std::cout << "\nquickSort(" << low << ", " << high << ")\n";
        utils::print_array(arr);
        if (low < high) {
            // pi is partitioning index
            int pi = partition(arr, low, high);

            // Recursively sort elements before partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Hoare's partitioning scheme    
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[low];  // Using first element as pivot
        
        std::cout << "  Partition: low=" << low << ", high=" << high << ", pivot=" << pivot << "\n";
        
        int i = low - 1;
        int j = high + 1;
        while (true) {
            // Find the next element greater than or equal to the pivot
            // From the left
            do {
                i++;
            } while (arr[i] < pivot);

            // Find the next element less than or equal to the pivot
            // From the right
            do {
                j--;
            } while (arr[j] > pivot);

            // If left and right pointers cross, we are done
            if (i >= j) {
                std::cout << "  Partition returns: " << j << "\n";
                return j;
            }

            // Otherwise, swap the elements at the left and right pointers
            std::cout << "  Swap: arr[" << i << "]=" << arr[i] << " and arr[" << j << "]=" << arr[j] << "\n";
            std::swap(arr[i], arr[j]);
        }
    }
};

int main() {
    QuickSort qs = QuickSort();
    std::vector<int> arr = utils::generate_random_array<int>(10, 0, 100);

    std::cout << "Before sorting:\n";
    utils::print_array(arr);

    qs.sort(arr);

    std::cout << "\nAfter sorting:\n";
    utils::print_array(arr);
}
