#include <iostream>
#include <memory> // For std::unique_ptr in alternative implementation

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int value) {
        if (!node) return nullptr;
        
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node found - handle deletion
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Node with two children: get inorder successor
            // smallest in right subtree
            // can also get largest in left subtree
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    void inOrder(Node* node) const {
        if (!node) return;
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}
    ~BST() {
        destroyTree(root);
    }

    // Disable copy constructor and assignment operator
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) const {
        Node* current = root;
        while (current) {
            if (value == current->data) return true;
            current = value < current->data ? current->left : current->right;
        }
        return false;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void printInOrder() const {
        std::cout << "In-order traversal: ";
        inOrder(root);
        std::cout << "\n";
    }

    // Additional utility functions
    void printPreOrder() const {
        std::cout << "Pre-order traversal: ";
        preOrder(root);
        std::cout << "\n";
    }

    void printPostOrder() const {
        std::cout << "Post-order traversal: ";
        postOrder(root);
        std::cout << "\n";
    }

private:
    void preOrder(Node* node) const {
        if (!node) return;
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) const {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }
};

int main() {
    BST tree;
    
    // Insert values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Traversals
    tree.printInOrder();   // 20 30 40 50 60 70 80
    tree.printPreOrder();  // 50 30 20 40 70 60 80
    tree.printPostOrder(); // 20 40 30 60 80 70 50

    // Search
    std::cout << "Contains 40: " << std::boolalpha << tree.contains(40) << "\n"; // true
    std::cout << "Contains 45: " << std::boolalpha << tree.contains(45) << "\n"; // false

    // Delete
    tree.remove(20); // Leaf node
    tree.remove(30); // Node with one child
    tree.remove(50); // Node with two children

    tree.printInOrder();   // 40 60 70 80

    return 0;
} 