#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
