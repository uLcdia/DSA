// https://github.com/uLcdia/DSA/tree/main/lab/01/3

#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> freq {};
    int mostFreqInt {};

    int elem {};
    int n {};
    while (std::cin >> elem) {
        freq[elem]++;
        mostFreqInt = (freq[elem] > freq[mostFreqInt] ? elem : mostFreqInt);
        n++;
    }

    std::cout << (freq[mostFreqInt] > (n / 2) ? mostFreqInt : -1);

    return 0;
}