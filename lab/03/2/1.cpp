// https://github.com/uLcdia/DSA/tree/main/lab/03/2

#include <iostream>

class BST {
private:
    struct Node {
        int data {};
        Node* left {};
        Node* right {};

        Node(int data, Node* left = nullptr, Node* right = nullptr)
            : data(data), left(left), right(right) {}
    };

    void printInOrder(const Node* tree) {
        if (tree == nullptr) {
            return;
        }

        printInOrder(tree->left);
        std::cout << tree->data << ' ';
        printInOrder(tree->right);
    }

public:
    Node* root {};

    void insert(int num) {
        Node* newNode = new Node(num, nullptr, nullptr);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (num < current->data) {
                current = current->left;
            } else if (num > current->data) {
                current = current->right;
            } else {
                current = current->left;
                // throw std::runtime_error("Duplicate value");
            }
        }

        if (num < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void printInOrder() {
        printInOrder(root);
    }

    void createFromInput() {
        int n {};
        std::cin >> n;

        for (int i {}; i < n; ++i) {
            int num {};
            std::cin >> num;
            insert(num);
        }
    }
};

int main() {
    BST bst {};
    bst.createFromInput();
    bst.printInOrder();

    return 0;
}