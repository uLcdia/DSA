#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;

typedef struct TreeNode {
    ElemType data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
    int size;
} BinarySearchTree;

// Function prototypes
BinarySearchTree* createBST();
void destroyBSTHelper(TreeNode* node);
void destroyBST(BinarySearchTree* tree);
bool isEmptyBST(const BinarySearchTree* tree);
int sizeBST(const BinarySearchTree* tree);
bool insertBST(BinarySearchTree* tree, ElemType value);
bool searchBST(const BinarySearchTree* tree, ElemType value);
TreeNode* findMin(TreeNode* node);
bool deleteBST(BinarySearchTree* tree, ElemType value);
void printInOrderHelper(const TreeNode* node);
void printInOrder(const BinarySearchTree* tree);
void printPreOrderHelper(const TreeNode* node);
void printPreOrder(const BinarySearchTree* tree);
void printPostOrderHelper(const TreeNode* node);
void printPostOrder(const BinarySearchTree* tree);

// Create a new empty BST
BinarySearchTree* createBST() {
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if (tree == NULL) {
        perror("Error: Memory allocation failed (BST struct)");
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

// Recursive helper to destroy BST
void destroyBSTHelper(TreeNode* node) {
    if (node != NULL) {
        destroyBSTHelper(node->left);
        destroyBSTHelper(node->right);
        free(node);
    }
}

// Destroy BST and free memory
void destroyBST(BinarySearchTree* tree) {
    if (tree != NULL) {
        destroyBSTHelper(tree->root);
        free(tree);
    }
}

// Check if BST is empty
bool isEmptyBST(const BinarySearchTree* tree) {
    return tree == NULL || tree->root == NULL;
}

// Get number of nodes in BST
int sizeBST(const BinarySearchTree* tree) {
    return tree != NULL ? tree->size : 0;
}

// Insert a value into BST (non-recursive implementation)
bool insertBST(BinarySearchTree* tree, ElemType value) {
    if (tree == NULL) return false;

    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) return false;
    newNode->data = value;
    newNode->left = newNode->right = NULL;

    if (tree->root == NULL) {
        tree->root = newNode;
        tree->size++;
        return true;
    }

    TreeNode* current = tree->root;
    while (true) {
        if (value < current->data) {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            }
            current = current->left;
        } else if (value > current->data) {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            }
            current = current->right;
        } else {
            // Value already exists in BST
            free(newNode);
            return false;
        }
    }
    tree->size++;
    return true;
}

// Search for a value in BST (non-recursive)
bool searchBST(const BinarySearchTree* tree, ElemType value) {
    if (tree == NULL) return false;

    TreeNode* current = tree->root;
    while (current != NULL) {
        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

// Find minimum value node in subtree
TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Delete a value from BST (recursive implementation)
TreeNode* deleteHelper(TreeNode* node, ElemType value, int* size) {
    if (node == NULL) return NULL;

    if (value < node->data) {
        node->left = deleteHelper(node->left, value, size);
    } else if (value > node->data) {
        node->right = deleteHelper(node->right, value, size);
    } else {
        // Node found
        (*size)--;
        // Case 1: No child
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        // Case 2: One child
        else if (node->left == NULL) {
            TreeNode* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            TreeNode* temp = node->left;
            free(node);
            return temp;
        }
        // Case 3: Two children
        else {
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data, size);
        }
    }
    return node;
}

// Public delete function
bool deleteBST(BinarySearchTree* tree, ElemType value) {
    if (tree == NULL) return false;
    int originalSize = tree->size;
    tree->root = deleteHelper(tree->root, value, &tree->size);
    return originalSize != tree->size;
}

// In-order traversal helper
void printInOrderHelper(const TreeNode* node) {
    if (node == NULL) return;
    printInOrderHelper(node->left);
    printf("%d ", node->data);
    printInOrderHelper(node->right);
}

void printInOrder(const BinarySearchTree* tree) {
    if (tree == NULL) return;
    printf("In-order: ");
    printInOrderHelper(tree->root);
    printf("\n");
}

// Pre-order traversal helper
void printPreOrderHelper(const TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreOrderHelper(node->left);
    printPreOrderHelper(node->right);
}

void printPreOrder(const BinarySearchTree* tree) {
    if (tree == NULL) return;
    printf("Pre-order: ");
    printPreOrderHelper(tree->root);
    printf("\n");
}

// Post-order traversal helper
void printPostOrderHelper(const TreeNode* node) {
    if (node == NULL) return;
    printPostOrderHelper(node->left);
    printPostOrderHelper(node->right);
    printf("%d ", node->data);
}

void printPostOrder(const BinarySearchTree* tree) {
    if (tree == NULL) return;
    printf("Post-order: ");
    printPostOrderHelper(tree->root);
    printf("\n");
}

// Example usage
int main() {
    BinarySearchTree* bst = createBST();
    assert(bst != NULL);
    assert(isEmptyBST(bst));

    // Insert values
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
        assert(insertBST(bst, values[i]));
    }
    printf("After insertions:\n");
    printInOrder(bst);
    printPreOrder(bst);
    printPostOrder(bst);
    printf("Size: %d\n\n", sizeBST(bst));

    // Search tests
    assert(searchBST(bst, 5));
    assert(searchBST(bst, 3));
    assert(!searchBST(bst, 9));

    // Delete tests
    assert(deleteBST(bst, 3));  // Delete node with two children
    printf("After deleting 3:\n");
    printInOrder(bst);
    printf("Size: %d\n\n", sizeBST(bst));

    assert(deleteBST(bst, 8));  // Delete leaf node
    printf("After deleting 8:\n");
    printInOrder(bst);
    printf("Size: %d\n\n", sizeBST(bst));

    assert(deleteBST(bst, 5));  // Delete root
    printf("After deleting root (5):\n");
    printInOrder(bst);
    printf("Size: %d\n\n", sizeBST(bst));

    destroyBST(bst);
    printf("BST destroyed\n");
    return 0;
} 