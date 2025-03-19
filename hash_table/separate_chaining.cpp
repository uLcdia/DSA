#include <iostream>
#include <string>
#include "separate_chaining.hpp"

int main() {
    // Create a hash table mapping strings to integers
    HashTable<std::string, int> scores;
    
    // Insert some data
    scores.insert("Alice", 95);
    scores.insert("Bob", 89);
    scores.insert("Charlie", 92);
    
    // Use the [] operator
    scores["David"] = 78;
    scores["Alice"] = 97;  // Update Alice's score
    
    // Look up values
    int value;
    if (scores.find("Alice", value)) {
        std::cout << "Alice's score: " << value << std::endl;
    }
    
    // Check if a key exists
    if (scores.contains("Bob")) {
        std::cout << "Bob's score: " << scores["Bob"] << std::endl;
    }
    
    // Remove an entry
    scores.remove("Charlie");
    
    std::cout << "Hash table size: " << scores.size() << std::endl;
    
    // Print the entire hash table
    std::cout << "\nHash table contents:" << std::endl;
    scores.print();
    
    return 0;
}
