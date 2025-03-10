#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a disjoint set
typedef struct {
    int *parent;  // Array to store parent pointers
    int *rank;    // Array to store the rank (approximate height) of each set
    int size;     // Number of elements in the disjoint set
} DisjointSet;

/**
 * Creates a new disjoint set with n elements.
 * Each element is initially in its own set (parent points to itself).
 * 
 * @param n Number of elements
 * @return Pointer to the newly created DisjointSet
 */
DisjointSet* createDisjointSet(int n) {
    if (n <= 0) {
        fprintf(stderr, "Error: Size must be positive.\n");
        return NULL;
    }

    DisjointSet* ds = (DisjointSet*)malloc(sizeof(DisjointSet));
    if (ds == NULL) {
        perror("Error: Memory allocation failed (disjoint set struct)");
        return NULL;
    }

    ds->parent = (int*)malloc(n * sizeof(int));
    ds->rank = (int*)malloc(n * sizeof(int));
    
    if (ds->parent == NULL || ds->rank == NULL) {
        perror("Error: Memory allocation failed (arrays)");
        free(ds->parent);
        free(ds->rank);
        free(ds);
        return NULL;
    }

    ds->size = n;

    // Initialize: each element is in its own set
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;  // Each element is its own parent
        ds->rank[i] = 0;    // Initial rank is 0
    }

    return ds;
}

/**
 * Destroys a disjoint set and frees allocated memory.
 * 
 * @param ds Pointer to the DisjointSet to be destroyed
 */
void destroyDisjointSet(DisjointSet* ds) {
    if (ds != NULL) {
        free(ds->parent);
        free(ds->rank);
        free(ds);
    }
}

/**
 * Finds the representative (root) of the set containing element x.
 * Uses path compression for optimization.
 * 
 * @param ds Pointer to the DisjointSet
 * @param x Element to find the representative for
 * @return The representative of the set containing x
 */
int find(DisjointSet* ds, int x) {
    if (ds == NULL || x < 0 || x >= ds->size) {
        fprintf(stderr, "Error: Invalid element or disjoint set.\n");
        return -1;
    }

    // Path compression: make every examined node point directly to the root
    if (ds->parent[x] != x) {
        ds->parent[x] = find(ds, ds->parent[x]);
    }
    
    return ds->parent[x];
}

/**
 * Merges the sets containing elements x and y.
 * Uses union by rank for optimization.
 * 
 * @param ds Pointer to the DisjointSet
 * @param x First element
 * @param y Second element
 * @return true if the merge was successful, false otherwise
 */
bool unionSets(DisjointSet* ds, int x, int y) {
    if (ds == NULL || x < 0 || x >= ds->size || y < 0 || y >= ds->size) {
        return false;
    }

    int rootX = find(ds, x);
    int rootY = find(ds, y);

    // If x and y are already in the same set
    if (rootX == rootY) {
        return true;
    }

    // Union by rank: attach the smaller rank tree under the root of the higher rank tree
    if (ds->rank[rootX] < ds->rank[rootY]) {
        ds->parent[rootX] = rootY;
    } else if (ds->rank[rootX] > ds->rank[rootY]) {
        ds->parent[rootY] = rootX;
    } else {
        // If ranks are the same, make one as root and increment its rank
        ds->parent[rootY] = rootX;
        ds->rank[rootX]++;
    }

    return true;
}

/**
 * Checks if two elements are in the same set.
 * 
 * @param ds Pointer to the DisjointSet
 * @param x First element
 * @param y Second element
 * @return true if x and y are in the same set, false otherwise
 */
bool isSameSet(DisjointSet* ds, int x, int y) {
    if (ds == NULL || x < 0 || x >= ds->size || y < 0 || y >= ds->size) {
        return false;
    }
    
    return find(ds, x) == find(ds, y);
}

/**
 * Gets the number of elements in the disjoint set.
 * 
 * @param ds Pointer to the DisjointSet
 * @return The number of elements
 */
int getSize(DisjointSet* ds) {
    return ds != NULL ? ds->size : 0;
}

/**
 * Counts the number of distinct sets in the disjoint set.
 * 
 * @param ds Pointer to the DisjointSet
 * @return The number of distinct sets
 */
int countSets(DisjointSet* ds) {
    if (ds == NULL) {
        return 0;
    }
    
    int count = 0;
    for (int i = 0; i < ds->size; i++) {
        if (ds->parent[i] == i) {
            count++;
        }
    }
    
    return count;
}

/**
 * Prints the disjoint set structure.
 * 
 * @param ds Pointer to the DisjointSet
 */
void printDisjointSet(DisjointSet* ds) {
    if (ds == NULL) {
        printf("DisjointSet: (NULL)\n");
        return;
    }
    
    printf("DisjointSet:\n");
    printf("Element\tParent\tRank\n");
    for (int i = 0; i < ds->size; i++) {
        printf("%d\t%d\t%d\n", i, ds->parent[i], ds->rank[i]);
    }
    printf("Number of distinct sets: %d\n", countSets(ds));
}

// Example usage
int main() {
    // Create a disjoint set with 10 elements
    DisjointSet* ds = createDisjointSet(10);
    if (ds == NULL) {
        return 1;
    }
    
    printf("Initial state:\n");
    printDisjointSet(ds);
    
    // Perform some unions
    unionSets(ds, 0, 1);
    unionSets(ds, 2, 3);
    unionSets(ds, 4, 5);
    unionSets(ds, 6, 7);
    unionSets(ds, 8, 9);
    
    printf("\nAfter initial unions:\n");
    printDisjointSet(ds);
    
    // Merge some of the sets
    unionSets(ds, 1, 3);
    unionSets(ds, 5, 7);
    unionSets(ds, 7, 9);
    
    printf("\nAfter more unions:\n");
    printDisjointSet(ds);
    
    // Check if elements are in the same set
    printf("\nIs 0 and 3 in the same set? %s\n", 
           isSameSet(ds, 0, 3) ? "Yes" : "No");
    printf("Is 4 and 9 in the same set? %s\n", 
           isSameSet(ds, 4, 9) ? "Yes" : "No");
    printf("Is 1 and 8 in the same set? %s\n", 
           isSameSet(ds, 1, 8) ? "Yes" : "No");
    
    // Clean up
    destroyDisjointSet(ds);
    printf("\nDisjoint set destroyed\n");
    
    return 0;
}
