#include <iostream>
#include <vector>
#include <cassert>

// Structure to represent a tower
struct Tower {
    std::vector<unsigned int> disks;
};

// Function to move a disk from one tower to another
void moveDisk(Tower& from, Tower& to) {
    if (from.disks.empty()) {
        //  In a real system, throw an exception;  for a benchmark, a hard
        //  failure is acceptable, and the assertions at the end will catch
        //  the error, since we're not timing the assert at the end.
        std::cerr << "Error: Attempting to move from an empty tower!" << std::endl;
        std::exit(1);
    }
    unsigned int disk = from.disks.back();
    from.disks.pop_back();
    to.disks.push_back(disk);
}

// Recursive Hanoi function
void hanoi(unsigned int numDisks, Tower& source, Tower& auxiliary, Tower& destination) {
    if (numDisks == 1) {
        moveDisk(source, destination);
    } else {
        hanoi(numDisks - 1, source, destination, auxiliary);
        moveDisk(source, destination);
        hanoi(numDisks - 1, auxiliary, source, destination);
    }
}

// Function to create a tower with disks
Tower createTower(unsigned int numDisks) {
    Tower tower;
    for (unsigned int i = numDisks; i >= 1; --i) {
        tower.disks.push_back(i);
    }
    return tower;
}

int main() {
    unsigned int numDisks = 32;

    Tower source = createTower(numDisks);
    Tower auxiliary;
    Tower destination;

    // Call the hanoi function (no timing inside). Timing done externally
    hanoi(numDisks, source, auxiliary, destination);

    // Correctness check (optional, can be removed for pure benchmarking)
    assert(source.disks.empty());
    assert(auxiliary.disks.empty());
    assert(destination.disks.size() == numDisks);
    for (unsigned int i = 0; i < numDisks; ++i) {
        assert(destination.disks[i] == numDisks - i);
    }
    return 0;
}