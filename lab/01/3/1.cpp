// https://github.com/uLcdia/DSA/tree/main/lab/01/3

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> freq {};
    int elem {};

    // First element
    std::cin >> elem;
    int maxFreq {1};
    int maxFreqElem {elem};
    freq[elem] = 1;

    int n {1};
    while (std::cin >> elem) {
        int currentFreq = ++freq[elem];

        if (currentFreq > maxFreq) {
            maxFreq = currentFreq;
            maxFreqElem = elem;
        }

        n++;
    }

    std::cout << (maxFreq> (n / 2) ? maxFreqElem : -1);

    return 0;
}