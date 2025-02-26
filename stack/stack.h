#ifndef STACK_H
#define STACK_H

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

#endif