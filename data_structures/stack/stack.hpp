#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;
    int capacity;

public:
    Stack(int size) : capacity(size) {
        data.reserve(size);
    }

    ~Stack() {}

    void clear() {
        data.clear();
    }

    bool isEmpty() const {
        return data.empty();
    }

    int length() const {
        return data.size();
    }

    T peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty (peek).\n";
            return T(); // Return a default constructed T
        }
        return data.back();
    }

    void push(const T& e) {
        if (length() >= capacity) {
            capacity *= 2;
            std::cout << "Warning: Stack overflow, new capacity: " << capacity << std::endl;
            data.reserve(capacity);
        }
        data.push_back(e);
    }

    T pop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack underflow.\n";
            return T(); // Return a default constructed T
        }
        T e = data.back();
        data.pop_back();
        return e;
    }

    void traverse() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }

        std::cout << "Stack elements (bottom to top):\n";
        for (const T& element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

#endif