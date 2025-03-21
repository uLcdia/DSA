#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Define the element type. Must be comparable.
typedef int ElemType;

// Structure for a tree node
typedef struct TreeNode {
    ElemType data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Structure to represent the binary tree
typedef struct {
    TreeNode* root;
    int size;
} BinaryTree;

// Function prototypes
BinaryTree* createTree();
void destroyTreeHelper(TreeNode* node);
void destroyTree(BinaryTree* tree);
bool isEmpty(const BinaryTree* tree);
int size(const BinaryTree* tree);
bool setRoot(BinaryTree* tree, ElemType value);
TreeNode* findNode(TreeNode* node, ElemType parentValue);
bool setLeft(BinaryTree* tree, ElemType parentValue, ElemType value);
bool setRight(BinaryTree* tree, ElemType parentValue, ElemType value);
bool getRoot(const BinaryTree* tree, ElemType* value);
bool getLeft(const BinaryTree* tree, ElemType parentValue, ElemType* value);
bool getRight(const BinaryTree* tree, ElemType parentValue, ElemType* value);
void deleteSubtree(TreeNode* node);
bool deleteNode(BinaryTree* tree, ElemType value);
void printTreeHelper(const TreeNode* node, int level);
void printTree(const BinaryTree* tree);

// Create a new binary tree
BinaryTree* createTree() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (tree == NULL) {
        perror("Error: Memory allocation failed (tree struct)");
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

// Helper function to recursively destroy the tree
void destroyTreeHelper(TreeNode* node) {
    if (node != NULL) {
        destroyTreeHelper(node->left);
        destroyTreeHelper(node->right);
        free(node);
    }
}

// Destroy the tree and free memory
void destroyTree(BinaryTree* tree) {
    if (tree != NULL) {
        destroyTreeHelper(tree->root);
        free(tree);
    }
}

// Check if the tree is empty
bool isEmpty(const BinaryTree* tree) {
    return tree == NULL || tree->root == NULL;
}

// Get the current size of the tree
int size(const BinaryTree* tree) {
    return tree != NULL ? tree->size : 0;
}

// Set the root node
bool setRoot(BinaryTree* tree, ElemType value) {
    if (tree == NULL) return false;
    
    if (tree->root == NULL) {
        tree->root = (TreeNode*)malloc(sizeof(TreeNode));
        if (tree->root == NULL) return false;
        tree->root->data = value;
        tree->root->left = NULL;
        tree->root->right = NULL;
        tree->size++;
    } else {
        tree->root->data = value;
    }
    return true;
}

// Helper function to find a node with a specific value
TreeNode* findNode(TreeNode* node, ElemType parentValue) {
    if (node == NULL || node->data == parentValue) {
        return node;
    }
    
    TreeNode* left = findNode(node->left, parentValue);
    if (left != NULL) return left;
    
    return findNode(node->right, parentValue);
}

// Set the left child of a node
bool setLeft(BinaryTree* tree, ElemType parentValue, ElemType value) {
    if (tree == NULL || tree->root == NULL) return false;
    
    TreeNode* parent = findNode(tree->root, parentValue);
    if (parent == NULL) return false;
    
    if (parent->left == NULL) {
        parent->left = (TreeNode*)malloc(sizeof(TreeNode));
        if (parent->left == NULL) return false;
        parent->left->data = value;
        parent->left->left = NULL;
        parent->left->right = NULL;
        tree->size++;
    } else {
        parent->left->data = value;
    }
    return true;
}

// Set the right child of a node
bool setRight(BinaryTree* tree, ElemType parentValue, ElemType value) {
    if (tree == NULL || tree->root == NULL) return false;
    
    TreeNode* parent = findNode(tree->root, parentValue);
    if (parent == NULL) return false;
    
    if (parent->right == NULL) {
        parent->right = (TreeNode*)malloc(sizeof(TreeNode));
        if (parent->right == NULL) return false;
        parent->right->data = value;
        parent->right->left = NULL;
        parent->right->right = NULL;
        tree->size++;
    } else {
        parent->right->data = value;
    }
    return true;
}

// Get the root value
bool getRoot(const BinaryTree* tree, ElemType* value) {
    if (tree == NULL || tree->root == NULL) return false;
    *value = tree->root->data;
    return true;
}

// Get the left child value
bool getLeft(const BinaryTree* tree, ElemType parentValue, ElemType* value) {
    if (tree == NULL || tree->root == NULL) return false;
    
    TreeNode* parent = findNode(tree->root, parentValue);
    if (parent == NULL || parent->left == NULL) return false;
    
    *value = parent->left->data;
    return true;
}

// Get the right child value
bool getRight(const BinaryTree* tree, ElemType parentValue, ElemType* value) {
    if (tree == NULL || tree->root == NULL) return false;
    
    TreeNode* parent = findNode(tree->root, parentValue);
    if (parent == NULL || parent->right == NULL) return false;
    
    *value = parent->right->data;
    return true;
}

// Helper function to delete a subtree
void deleteSubtree(TreeNode* node) {
    if (node != NULL) {
        deleteSubtree(node->left);
        deleteSubtree(node->right);
        free(node);
    }
}

// Delete a node and its subtree
bool deleteNode(BinaryTree* tree, ElemType value) {
    if (tree == NULL || tree->root == NULL) return false;
    
    // Special case for root
    if (tree->root->data == value) {
        deleteSubtree(tree->root);
        tree->root = NULL;
        tree->size = 0;
        return true;
    }
    
    // Find parent of the node to delete
    TreeNode* current = tree->root;
    TreeNode* parent = NULL;
    bool isLeft = false;
    
    while (current != NULL && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
            isLeft = true;
        } else {
            current = current->right;
            isLeft = false;
        }
    }
    
    if (current == NULL) return false;
    
    // Count nodes in subtree
    int subtreeSize = 0;
    TreeNode* temp = current;
    countNodes(temp, &subtreeSize);
    
    // Delete the subtree
    if (isLeft) {
        deleteSubtree(parent->left);
        parent->left = NULL;
    } else {
        deleteSubtree(parent->right);
        parent->right = NULL;
    }
    
    tree->size -= subtreeSize;
    return true;
}

// Helper function to count nodes in a subtree
void countNodes(TreeNode* node, int* count) {
    if (node != NULL) {
        (*count)++;
        countNodes(node->left, count);
        countNodes(node->right, count);
    }
}

// Helper function to print the tree recursively
void printTreeHelper(const TreeNode* node, int level) {
    if (node == NULL) return;
    
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d\n", node->data);
    
    printTreeHelper(node->left, level + 1);
    printTreeHelper(node->right, level + 1);
}

// Print the tree
void printTree(const BinaryTree* tree) {
    if (tree == NULL) {
        printf("Tree: (NULL)\n");
        return;
    }
    
    printf("Binary Tree:\n");
    printTreeHelper(tree->root, 0);
    printf("Size: %d\n", tree->size);
}

// Example usage
int main() {
    BinaryTree* tree = createTree();
    assert(tree != NULL);
    assert(isEmpty(tree));

    // Create a simple tree
    setRoot(tree, 1);
    setLeft(tree, 1, 2);
    setRight(tree, 1, 3);
    setLeft(tree, 2, 4);
    setRight(tree, 2, 5);

    printf("After creating tree:\n");
    printTree(tree);

    // Test getting values
    ElemType value;
    assert(getRoot(tree, &value) && value == 1);
    assert(getLeft(tree, 1, &value) && value == 2);
    assert(getRight(tree, 1, &value) && value == 3);

    // Test deletion
    deleteNode(tree, 2);  // Delete node with value 2 and its subtree
    printf("\nAfter deleting node with value 2:\n");
    printTree(tree);

    destroyTree(tree);
    printf("Tree destroyed\n");

    return 0;
}
