#include <iostream>
#include <vector>
#include <unordered_map>

class UnionFind {
private:
    std::vector<int> parent;  // Parent of each element
    std::vector<int> rank;    // Rank (approximate height) of each set
    int count;                // Number of disjoint sets

public:
    // Initialize with n elements (0 to n-1)
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initially, each element is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find the root of the set containing element x
    // Uses path compression for efficiency
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    // Union (merge) the sets containing elements x and y
    // Uses union by rank for efficiency
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // Already in the same set
        if (rootX == rootY) return;
        
        // Union by rank: attach smaller rank tree under root of higher rank tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // If ranks are the same, make one the root and increment its rank
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        count--;  // Decrease the number of disjoint sets
    }
    
    // Check if two elements are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    // Get the number of disjoint sets
    int getCount() const {
        return count;
    }
};

// Example usage with string elements
class StringUnionFind {
private:
    UnionFind uf;
    std::unordered_map<std::string, int> stringToId;
    std::vector<std::string> idToString;
    int nextId;

public:
    StringUnionFind() : uf(0), nextId(0) {}
    
    // Add a new string if it doesn't exist
    void addString(const std::string& s) {
        if (stringToId.find(s) == stringToId.end()) {
            stringToId[s] = nextId;
            idToString.push_back(s);
            
            // Resize the UnionFind if needed
            if (nextId >= uf.getCount()) {
                UnionFind newUf(nextId + 1);
                for (int i = 0; i < nextId; i++) {
                    for (int j = i + 1; j < nextId; j++) {
                        if (uf.connected(i, j)) {
                            newUf.unionSets(i, j);
                        }
                    }
                }
                uf = newUf;
            }
            
            nextId++;
        }
    }
    
    // Find the representative string for a set
    std::string find(const std::string& s) {
        if (stringToId.find(s) == stringToId.end()) {
            return s;  // Not found, return itself
        }
        int id = stringToId[s];
        int rootId = uf.find(id);
        return idToString[rootId];
    }
    
    // Union two sets
    void unionSets(const std::string& s1, const std::string& s2) {
        addString(s1);
        addString(s2);
        uf.unionSets(stringToId[s1], stringToId[s2]);
    }
    
    // Check if two strings are in the same set
    bool connected(const std::string& s1, const std::string& s2) {
        if (stringToId.find(s1) == stringToId.end() || 
            stringToId.find(s2) == stringToId.end()) {
            return s1 == s2;  // If either not found, they're connected only if identical
        }
        return uf.connected(stringToId[s1], stringToId[s2]);
    }
};

int main() {
    // Example with integers
    UnionFind uf(10);
    
    // Connect some elements
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);
    uf.unionSets(6, 7);
    uf.unionSets(8, 9);
    uf.unionSets(0, 2);
    uf.unionSets(4, 6);
    uf.unionSets(0, 4);
    
    // Check connections
    std::cout << "Number of disjoint sets: " << uf.getCount() << std::endl;
    std::cout << "Are 1 and 5 connected? " << (uf.connected(1, 5) ? "Yes" : "No") << std::endl;
    std::cout << "Are 7 and 9 connected? " << (uf.connected(7, 9) ? "Yes" : "No") << std::endl;
    
    // Example with strings
    StringUnionFind suf;
    
    // Connect some strings
    suf.unionSets("apple", "banana");
    suf.unionSets("cherry", "date");
    suf.unionSets("banana", "cherry");
    
    // Check connections
    std::cout << "\nRepresentative of 'apple': " << suf.find("apple") << std::endl;
    std::cout << "Representative of 'date': " << suf.find("date") << std::endl;
    std::cout << "Are 'apple' and 'date' connected? " 
              << (suf.connected("apple", "date") ? "Yes" : "No") << std::endl;
    
    return 0;
}
