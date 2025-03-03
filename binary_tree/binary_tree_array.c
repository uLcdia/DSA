#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Define the element type. Must be comparable.
typedef int ElemType;

// Define the maximum size of the tree
#define MAX_SIZE 100

// Structure to represent the binary tree
typedef struct {
    ElemType* data;      // Array to store the tree elements
    bool* used;          // Array to track which positions are used
    int capacity;        // Maximum capacity of the tree
    int size;           // Current number of nodes in the tree
} BinaryTree;

// Function prototypes
BinaryTree* createTree(int capacity);
void destroyTree(BinaryTree* tree);
bool isEmpty(const BinaryTree* tree);
int size(const BinaryTree* tree);
bool setRoot(BinaryTree* tree, ElemType value);
bool setLeft(BinaryTree* tree, int parentIndex, ElemType value);
bool setRight(BinaryTree* tree, int parentIndex, ElemType value);
bool getRoot(const BinaryTree* tree, ElemType* value);
bool getLeft(const BinaryTree* tree, int parentIndex, ElemType* value);
bool getRight(const BinaryTree* tree, int parentIndex, ElemType* value);
bool deleteNode(BinaryTree* tree, int index);
void printTree(const BinaryTree* tree);

// Helper function to check if an index is valid
static bool isValidIndex(const BinaryTree* tree, int index) {
    return index >= 0 && index < tree->capacity;
}

// Create a new binary tree
BinaryTree* createTree(int capacity) {
    if (capacity <= 0) {
        fprintf(stderr, "Error: Capacity must be positive.\n");
        return NULL;
    }

    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (tree == NULL) {
        perror("Error: Memory allocation failed (tree struct)");
        return NULL;
    }

    tree->data = (ElemType*)malloc(capacity * sizeof(ElemType));
    tree->used = (bool*)calloc(capacity, sizeof(bool));  // Initialize all to false
    
    if (tree->data == NULL || tree->used == NULL) {
        perror("Error: Memory allocation failed (arrays)");
        free(tree->data);
        free(tree->used);
        free(tree);
        return NULL;
    }

    tree->capacity = capacity;
    tree->size = 0;
    return tree;
}

// Destroy the tree and free memory
void destroyTree(BinaryTree* tree) {
    if (tree != NULL) {
        free(tree->data);
        free(tree->used);
        free(tree);
    }
}

// Check if the tree is empty
bool isEmpty(const BinaryTree* tree) {
    return tree == NULL || tree->size == 0;
}

// Get the current size of the tree
int size(const BinaryTree* tree) {
    return tree != NULL ? tree->size : 0;
}

// Set the root node
bool setRoot(BinaryTree* tree, ElemType value) {
    if (tree == NULL) return false;
    
    tree->data[0] = value;
    if (!tree->used[0]) {
        tree->used[0] = true;
        tree->size++;
    }
    return true;
}

// Set the left child of a node
bool setLeft(BinaryTree* tree, int parentIndex, ElemType value) {
    if (tree == NULL || !isValidIndex(tree, parentIndex) || !tree->used[parentIndex]) {
        return false;
    }

    int leftIndex = 2 * parentIndex + 1;
    if (!isValidIndex(tree, leftIndex)) {
        return false;
    }

    tree->data[leftIndex] = value;
    if (!tree->used[leftIndex]) {
        tree->used[leftIndex] = true;
        tree->size++;
    }
    return true;
}

// Set the right child of a node
bool setRight(BinaryTree* tree, int parentIndex, ElemType value) {
    if (tree == NULL || !isValidIndex(tree, parentIndex) || !tree->used[parentIndex]) {
        return false;
    }

    int rightIndex = 2 * parentIndex + 2;
    if (!isValidIndex(tree, rightIndex)) {
        return false;
    }

    tree->data[rightIndex] = value;
    if (!tree->used[rightIndex]) {
        tree->used[rightIndex] = true;
        tree->size++;
    }
    return true;
}

// Get the root value
bool getRoot(const BinaryTree* tree, ElemType* value) {
    if (tree == NULL || tree->size == 0 || !tree->used[0]) {
        return false;
    }
    *value = tree->data[0];
    return true;
}

// Get the left child value
bool getLeft(const BinaryTree* tree, int parentIndex, ElemType* value) {
    if (tree == NULL || !isValidIndex(tree, parentIndex) || !tree->used[parentIndex]) {
        return false;
    }

    int leftIndex = 2 * parentIndex + 1;
    if (!isValidIndex(tree, leftIndex) || !tree->used[leftIndex]) {
        return false;
    }

    *value = tree->data[leftIndex];
    return true;
}

// Get the right child value
bool getRight(const BinaryTree* tree, int parentIndex, ElemType* value) {
    if (tree == NULL || !isValidIndex(tree, parentIndex) || !tree->used[parentIndex]) {
        return false;
    }

    int rightIndex = 2 * parentIndex + 2;
    if (!isValidIndex(tree, rightIndex) || !tree->used[rightIndex]) {
        return false;
    }

    *value = tree->data[rightIndex];
    return true;
}

// Delete a node (and its subtree)
bool deleteNode(BinaryTree* tree, int index) {
    if (tree == NULL || !isValidIndex(tree, index) || !tree->used[index]) {
        return false;
    }

    // Recursively delete children
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    if (isValidIndex(tree, leftIndex) && tree->used[leftIndex]) {
        deleteNode(tree, leftIndex);
    }
    if (isValidIndex(tree, rightIndex) && tree->used[rightIndex]) {
        deleteNode(tree, rightIndex);
    }

    // Delete the current node
    tree->used[index] = false;
    tree->size--;
    return true;
}

// Print the tree (level by level)
void printTree(const BinaryTree* tree) {
    if (tree == NULL) {
        printf("Tree: (NULL)\n");
        return;
    }

    printf("Binary Tree (level-order):\n");
    for (int i = 0; i < tree->capacity; i++) {
        if (tree->used[i]) {
            printf("[%d]: %d\n", i, tree->data[i]);
        }
    }
    printf("Size: %d, Capacity: %d\n", tree->size, tree->capacity);
}

// Example usage
int main() {
    BinaryTree* tree = createTree(10);
    assert(tree != NULL);
    assert(isEmpty(tree));

    // Create a simple tree
    setRoot(tree, 1);
    setLeft(tree, 0, 2);
    setRight(tree, 0, 3);
    setLeft(tree, 1, 4);
    setRight(tree, 1, 5);

    printf("After creating tree:\n");
    printTree(tree);

    // Test getting values
    ElemType value;
    assert(getRoot(tree, &value) && value == 1);
    assert(getLeft(tree, 0, &value) && value == 2);
    assert(getRight(tree, 0, &value) && value == 3);

    // Test deletion
    deleteNode(tree, 1);  // Delete node with value 2 and its subtree
    printf("\nAfter deleting node at index 1:\n");
    printTree(tree);

    destroyTree(tree);
    printf("Tree destroyed\n");

    return 0;
}
