#ifndef OPEN_ADDRESSING_HASH_TABLE_HPP
#define OPEN_ADDRESSING_HASH_TABLE_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <optional>
#include <utility>
#include <algorithm>

template <typename K, typename V>
class HashTable {
private:
    // Entry states
    enum class EntryState { EMPTY, OCCUPIED, DELETED };
    
    // Each slot contains a key-value pair and its state
    struct Entry {
        std::pair<K, V> pair;
        EntryState state;
        
        Entry() : state(EntryState::EMPTY) {}
    };
    
    std::vector<Entry> table;
    size_t numItems;
    float maxLoadFactor;
    
    // Find the index for a key (returns index if found, or first empty/deleted position if not)
    size_t findIndex(const K& key) const {
        size_t index = std::hash<K>{}(key) % table.size();
        size_t firstDeleted = table.size(); // Marker for first deleted position
        
        // Linear probing
        for (size_t i = 0; i < table.size(); ++i) {
            size_t currentIndex = (index + i) % table.size();
            
            // If slot is empty, key is not in table
            if (table[currentIndex].state == EntryState::EMPTY) {
                return (firstDeleted < table.size()) ? firstDeleted : currentIndex;
            }
            
            // If slot is occupied and key matches, return this index
            if (table[currentIndex].state == EntryState::OCCUPIED && 
                table[currentIndex].pair.first == key) {
                return currentIndex;
            }
            
            // Keep track of first deleted position (for insertion)
            if (table[currentIndex].state == EntryState::DELETED && 
                firstDeleted == table.size()) {
                firstDeleted = currentIndex;
            }
        }
        
        // Table is full of occupied/deleted slots and key not found
        return (firstDeleted < table.size()) ? firstDeleted : index;
    }
    
    // Rehash the table when load factor exceeds threshold
    void rehash() {
        size_t newSize = table.size() * 2;
        std::vector<Entry> newTable(newSize);
        
        for (const auto& entry : table) {
            if (entry.state == EntryState::OCCUPIED) {
                size_t index = std::hash<K>{}(entry.pair.first) % newSize;
                
                // Linear probing
                for (size_t i = 0; i < newSize; ++i) {
                    size_t currentIndex = (index + i) % newSize;
                    if (newTable[currentIndex].state == EntryState::EMPTY) {
                        newTable[currentIndex].pair = entry.pair;
                        newTable[currentIndex].state = EntryState::OCCUPIED;
                        break;
                    }
                }
            }
        }
        
        table = std::move(newTable);
    }
    
public:
    HashTable(size_t initialSize = 16, float loadFactor = 0.75)
        : table(initialSize), numItems(0), maxLoadFactor(loadFactor) {}
    
    // Insert a key-value pair
    void insert(const K& key, const V& value) {
        // Check if we need to resize
        float currentLoad = static_cast<float>(numItems + 1) / table.size();
        if (currentLoad > maxLoadFactor) {
            rehash();
        }
        
        // Find index for insertion
        size_t index = findIndex(key);
        
        // Update if key exists, insert if not
        if (table[index].state == EntryState::OCCUPIED && 
            table[index].pair.first == key) {
            // Update existing key
            table[index].pair.second = value;
        } else {
            // Insert new key-value pair
            table[index].pair = std::make_pair(key, value);
            table[index].state = EntryState::OCCUPIED;
            numItems++;
        }
    }
    
    // Find a value by key
    bool find(const K& key, V& value) const {
        size_t index = findIndex(key);
        
        if (table[index].state == EntryState::OCCUPIED && 
            table[index].pair.first == key) {
            value = table[index].pair.second;
            return true;
        }
        
        return false;
    }
    
    // Remove a key-value pair
    bool remove(const K& key) {
        size_t index = findIndex(key);
        
        if (table[index].state == EntryState::OCCUPIED && 
            table[index].pair.first == key) {
            // Mark as deleted
            table[index].state = EntryState::DELETED;
            numItems--;
            return true;
        }
        
        return false;
    }
    
    // Get the value associated with a key (with [] operator)
    V& operator[](const K& key) {
        // Check if we need to resize
        float currentLoad = static_cast<float>(numItems + 1) / table.size();
        if (currentLoad > maxLoadFactor) {
            rehash();
        }
        
        size_t index = findIndex(key);
        
        if (table[index].state == EntryState::OCCUPIED && 
            table[index].pair.first == key) {
            return table[index].pair.second;
        }
        
        // If key doesn't exist, insert a default value
        table[index].pair = std::make_pair(key, V());
        table[index].state = EntryState::OCCUPIED;
        numItems++;
        
        return table[index].pair.second;
    }
    
    // Check if the table contains a key
    bool contains(const K& key) const {
        size_t index = findIndex(key);
        return (table[index].state == EntryState::OCCUPIED && 
                table[index].pair.first == key);
    }
    
    // Get the current number of items
    size_t size() const {
        return numItems;
    }
    
    // Check if the hash table is empty
    bool isEmpty() const {
        return numItems == 0;
    }
    
    // Clear the hash table
    void clear() {
        for (auto& entry : table) {
            entry.state = EntryState::EMPTY;
        }
        numItems = 0;
    }
    
    // Print the contents of the hash table (for debugging)
    void print() const {
        for (size_t i = 0; i < table.size(); i++) {
            std::cout << "Slot " << i << ": ";
            if (table[i].state == EntryState::OCCUPIED) {
                std::cout << "[" << table[i].pair.first << ":" 
                          << table[i].pair.second << "]";
            } else if (table[i].state == EntryState::DELETED) {
                std::cout << "<DELETED>";
            } else {
                std::cout << "<EMPTY>";
            }
            std::cout << std::endl;
        }
    }
};

#endif // OPEN_ADDRESSING_HASH_TABLE_HPP