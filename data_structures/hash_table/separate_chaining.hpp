#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <utility>
#include <algorithm>

template <typename K, typename V>
class HashTable {
private:
    // Each bucket contains a list of key-value pairs
    std::vector<std::list<std::pair<K, V>>> buckets;
    size_t numItems;
    float maxLoadFactor;

    // Helper function to find an item in a bucket
    typename std::list<std::pair<K, V>>::iterator findInBucket(const K& key, size_t bucketIndex) {
        auto& bucket = buckets[bucketIndex];
        return std::find_if(bucket.begin(), bucket.end(),
                          [&key](const std::pair<K, V>& item) {
                              return item.first == key;
                          });
    }

    // Rehash the table when load factor exceeds threshold
    void rehash() {
        size_t newSize = buckets.size() * 2;
        std::vector<std::list<std::pair<K, V>>> newBuckets(newSize);
        
        for (auto& bucket : buckets) {
            for (auto& pair : bucket) {
                size_t newIndex = std::hash<K>{}(pair.first) % newSize;
                newBuckets[newIndex].emplace_back(pair);
            }
        }
        
        buckets = std::move(newBuckets);
    }

public:
    HashTable(size_t initialSize = 16, float loadFactor = 0.75) 
        : buckets(initialSize), numItems(0), maxLoadFactor(loadFactor) {}
    
    // Insert a key-value pair
    void insert(const K& key, const V& value) {
        // Check if we need to resize
        float currentLoad = static_cast<float>(numItems + 1) / buckets.size();
        if (currentLoad > maxLoadFactor) {
            rehash();
        }
        
        // Find the bucket for this key
        size_t index = std::hash<K>{}(key) % buckets.size();
        auto it = findInBucket(key, index);
        
        // If key already exists, update the value
        if (it != buckets[index].end()) {
            it->second = value;
        } else {
            // Otherwise, insert a new key-value pair
            buckets[index].emplace_back(std::make_pair(key, value));
            numItems++;
        }
    }
    
    // Find a value by key
    bool find(const K& key, V& value) const {
        size_t index = std::hash<K>{}(key) % buckets.size();
        const auto& bucket = buckets[index];
        
        auto it = std::find_if(bucket.begin(), bucket.end(),
                            [&key](const std::pair<K, V>& item) {
                                return item.first == key;
                            });
        
        if (it != bucket.end()) {
            value = it->second;
            return true;
        }
        return false;
    }
    
    // Remove a key-value pair
    bool remove(const K& key) {
        size_t index = std::hash<K>{}(key) % buckets.size();
        auto it = findInBucket(key, index);
        
        if (it != buckets[index].end()) {
            buckets[index].erase(it);
            numItems--;
            return true;
        }
        return false;
    }
    
    // Get the value associated with a key (with [] operator)
    V& operator[](const K& key) {
        size_t index = std::hash<K>{}(key) % buckets.size();
        auto it = findInBucket(key, index);
        
        if (it != buckets[index].end()) {
            return it->second;
        }
        
        // If key doesn't exist, insert a default value
        buckets[index].emplace_back(std::make_pair(key, V()));
        numItems++;
        
        // Return a reference to the newly inserted value
        return buckets[index].back().second;
    }
    
    // Check if the table contains a key
    bool contains(const K& key) const {
        size_t index = std::hash<K>{}(key) % buckets.size();
        const auto& bucket = buckets[index];
        
        return std::any_of(bucket.begin(), bucket.end(),
                         [&key](const std::pair<K, V>& item) {
                             return item.first == key;
                         });
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
        for (auto& bucket : buckets) {
            bucket.clear();
        }
        numItems = 0;
    }
    
    // Print the contents of the hash table (for debugging)
    void print() const {
        for (size_t i = 0; i < buckets.size(); i++) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : buckets[i]) {
                std::cout << "[" << pair.first << ":" << pair.second << "] ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // HASH_TABLE_HPP 