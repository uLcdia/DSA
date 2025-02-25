#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct {
    ElemType *base;
    ElemType *top;
    int capacity;
} Stack;

bool initStack(Stack* stack, const int size) {
    if (size <= 0) {
        fprintf(stderr, "Error: Invalid stack size.\n");
        return false;
    }

    stack->base = (ElemType*) malloc(size * sizeof(ElemType));
    if (stack->base == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return false;
    }
    stack->top = stack->base;
    stack->capacity = size;
    return true;
}

void destroyStack(Stack* stack) {
    if (stack->base != NULL) {
        free(stack->base);
        stack->top = NULL;
        stack->base = NULL;
        stack->capacity = 0;
    }
}

void clearStack(Stack* stack) {
    stack->top = stack->base;
}

bool isEmpty(const Stack* stack) {
    return stack->top == stack->base;
}

int length(const Stack* stack) {
    return (int) (stack->top - stack->base);
}

bool peek(const Stack* stack, ElemType* e) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: Stack is empty (peek).\n");
        return false;
    }
    *e = *(stack->top - 1);
    return true;
}

bool push(Stack* stack, const ElemType e) {
    if (length(stack) >= stack->capacity) {
        int newCapacity = stack->capacity * 2;
        fprintf(stdout, "Warning: Stack overflow, new capacity: %d", newCapacity);
        fflush(stdout);
        ElemType* newBase = (ElemType*) realloc(stack->base, newCapacity * sizeof(ElemType));
        if (newBase == NULL) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            return false;
        }
        stack->base = newBase;
        stack->capacity = newCapacity;
    }
    *(stack->top) = e;
    stack->top++;
    return true;
}

bool pop(Stack* stack, ElemType* e) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: Stack underflow.\n");
        return false;
    }
    stack->top--;
    *e = *(stack->top);
    return true;
}

void traverse(const Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack elements (bottom to top):\n");
    for (ElemType *p = stack->base; p < stack->top; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}


int main() {
    Stack myStack;
    int stackSize = 5;

    if (!initStack(&myStack, stackSize)) {
        return 1;  // Error during initialization
    }

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    traverse(&myStack);  // Output: 10 20 30

    ElemType poppedValue;
    if (pop(&myStack, &poppedValue)) {
        printf("Popped value: %d\n", poppedValue); // Output: Popped value: 30
    }
    traverse(&myStack);
    
    ElemType peekedValue;
    if (peek(&myStack, &peekedValue)) {
        printf("Peeked value: %d\n", peekedValue); // Output: Peeked value: 20
    }

    if (push(&myStack, 40) && push(&myStack, 50) ) {
        printf("Pushed 40, 50\n");
    }
    traverse(&myStack);

    if (push(&myStack, 60)) {
        printf("Push successful\n");
    } else {
        printf("Push failed\n"); // Now it won't overflow
    }
    
    
    clearStack(&myStack);
    printf("Stack cleared.  Is empty: %s\n", isEmpty(&myStack) ? "true" : "false");  // Output: Stack cleared.  Is empty: true

    if (pop(&myStack, &poppedValue)) {  // try to underflow
        printf("Pop successful\n");
    } else {
        printf("Pop failed (stack underflow as expected)\n");
    }
    
    push(&myStack, 60);
    traverse(&myStack);
    printf("Stack length: %d\n", length(&myStack)); // output: 1

    destroyStack(&myStack);
    printf("Stack destroy\n");
    // Attempting to use myStack after destroyStack is undefined behavior.

    return 0;
}
