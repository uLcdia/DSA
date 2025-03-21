#include <iostream>
#include <stack>
#include <vector>

// Node structure for binary tree
template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Recursive traversals
template<typename T>
void inorderRecursive(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    inorderRecursive(root->left);
    std::cout << root->data << " ";
    inorderRecursive(root->right);
}

template<typename T>
void preorderRecursive(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    std::cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

template<typename T>
void postorderRecursive(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    std::cout << root->data << " ";
}

// Iterative traversals
template<typename T>
void inorderIterative(TreeNode<T>* root) {
    std::stack<TreeNode<T>*> stack;
    TreeNode<T>* current = root;
    
    while (current != nullptr || !stack.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        
        // Current is now nullptr, pop an element from stack
        current = stack.top();
        stack.pop();
        
        std::cout << current->data << " ";
        
        // Move to the right subtree
        current = current->right;
    }
}

/*

1.  **Initialization:**
    *   `std::stack<TreeNode<T>*> stack;`: A stack is created to hold pointers to tree nodes.  This stack will keep track of the nodes we need to visit later.
    *   `TreeNode<T>* current = root;`:  `current` is a pointer that initially points to the root of the tree.  This pointer will move through the tree during the traversal.

2.  **Outer `while` Loop:**
    *   `while (current != nullptr || !stack.empty())`: This loop continues as long as either `current` is pointing to a valid node OR the stack is not empty.  This means we have either nodes to explore directly (through `current`) or nodes we've saved for later (on the stack).

3.  **Inner `while` Loop (Go Left):**
    *   `while (current != nullptr)`: This loop repeatedly pushes the `current` node onto the stack and moves `current` to its left child.  This effectively traverses down the leftmost path of the current subtree.  We push onto the stack because we *will* need to visit these nodes later (after we've finished their left subtrees).
    *   `stack.push(current);`: Push the current node onto the stack.
    *   `current = current->left;`: Move to the left child.

4.  **Process Node (Pop and Print):**
    *   `current = stack.top();`:  Once the inner loop finishes, `current` is `nullptr`.  This means we've reached the leftmost node of a subtree (or a leaf's left child, which is null). We now retrieve the last node we pushed onto the stack (which is the node *before* we hit the null left child).
    *   `stack.pop();`: Remove the top element from the stack (we're done with it now).
    *   `std::cout << current->data << " ";`: Print the data of the node we just popped. This is the "visit" part of the inorder traversal.

5.  **Move to Right Subtree:**
    *   `current = current->right;`: After visiting a node, we move to its right subtree. This sets up the next iteration of the outer loop to process the right subtree.  If the right subtree is not null, the inner while loop will handle going all the way left in that subtree, and so forth.

*/



template<typename T>
void preorderIterative(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    std::stack<TreeNode<T>*> stack;
    stack.push(root);
    
    while (!stack.empty()) {
        TreeNode<T>* current = stack.top();
        stack.pop();
        
        std::cout << current->data << " ";
        
        // Push right child first so that left is processed first
        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }
}

template<typename T>
void postorderIterative(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    std::stack<TreeNode<T>*> s1, s2;
    s1.push(root);
    
    while (!s1.empty()) {
        TreeNode<T>* current = s1.top();
        s1.pop();
        s2.push(current);
        
        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }
    
    while (!s2.empty()) {
        std::cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    
    std::cout << "Recursive Traversals:\n";
    std::cout << "Inorder: ";
    inorderRecursive(root);
    std::cout << "\nPreorder: ";
    preorderRecursive(root);
    std::cout << "\nPostorder: ";
    postorderRecursive(root);
    
    std::cout << "\n\nIterative Traversals:\n";
    std::cout << "Inorder: ";
    inorderIterative(root);
    std::cout << "\nPreorder: ";
    preorderIterative(root);
    std::cout << "\nPostorder: ";
    postorderIterative(root);
    
    // Clean up memory (in practice, use smart pointers)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
