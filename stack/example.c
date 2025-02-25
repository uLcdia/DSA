#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int ElemType;

// Structure for the stack
typedef struct {
    ElemType *base;  // Pointer to the base of the stack array
    ElemType *top;   // Pointer to the top of the stack
    int stackSize;   // Maximum size of the stack
} Stack;


// Initialize the stack
bool initStack(Stack *s, int size) {
    if (size <= 0) {
        fprintf(stderr, "Error: Invalid stack size.\n");
        return false;
    }

    s->base = (ElemType *)malloc(size * sizeof(ElemType));
    if (s->base == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return false;
    }
    s->top = s->base;  // Initially, top points to the base
    s->stackSize = size;
    return true;
}


// Destroy the stack (free allocated memory)
void destroyStack(Stack *s) {
    if (s->base != NULL) {
        free(s->base);
        s->base = NULL;
        s->top = NULL;  // Important: Reset top pointer
        s->stackSize = 0;
    }
}


// Clear the stack (reset it to empty, but keep allocated memory)
void clearStack(Stack *s) {
    s->top = s->base; // Just move the top pointer to the base.
}


// Check if the stack is empty
bool isEmpty(const Stack *s) {
    return s->top == s->base;
}


// Get the number of elements in the stack (its length)
int length(const Stack *s) {
    return (int)(s->top - s->base);
}


// Peek at the top element without removing it
bool peek(const Stack *s, ElemType *e) {
    if (isEmpty(s)) {
        fprintf(stderr, "Error: Stack is empty (peek).\n");
        return false;
    }
    *e = *(s->top - 1);  // Dereference to get the value, assign to *e
    return true;
}


// Push an element onto the stack
bool push(Stack *s, ElemType e) {
    if (length(s) == s->stackSize) {
        fprintf(stderr, "Error: Stack overflow.\n");
        return false;
    }
    *(s->top) = e;   // Store the element
    s->top++;        // Increment top pointer
    return true;
}


// Pop an element from the stack
bool pop(Stack *s, ElemType *e) {
    if (isEmpty(s)) {
        fprintf(stderr, "Error: Stack underflow.\n");
        return false;
    }
    s->top--;          // Decrement top pointer *first*
    *e = *(s->top);    // Get the element
    return true;
}


// Traverse the stack and print its elements (from bottom to top)
void traverse(const Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (bottom to top):\n");
    for (ElemType *p = s->base; p < s->top; p++) {
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

    if (push(&myStack, 40) && push(&myStack, 50) ){
        printf("Pushed 40, 50\n");
    }
    traverse(&myStack);

    if(push(&myStack, 60)){  //try to overflow
        printf("Push successful\n");
    }else{
        printf("Push failed (stack overflow as expected)\n");
    }
    
    
    clearStack(&myStack);
    printf("Stack cleared.  Is empty: %s\n", isEmpty(&myStack) ? "true" : "false");  // Output: Stack cleared.  Is empty: true

    if(pop(&myStack, &poppedValue)){  //try to underflow
        printf("Pop successful\n");
    }else{
        printf("Pop failed (stack underflow as expected)\n");
    }
    
     push(&myStack, 60);
     traverse(&myStack);
     printf("Stack length: %d\n", length(&myStack)); //output :1

    destroyStack(&myStack);
    printf("stack destroy\n");
     // Attempting to use myStack after destroyStack is undefined behavior.

    return 0;
}
