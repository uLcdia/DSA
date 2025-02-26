#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for a stack node
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

// Structure for the stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create a new stack node
StackNode* newNode(char data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to initialize an empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, char data) {
    StackNode* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow!\n");
        exit(EXIT_FAILURE); // Or return a special value
    }
    StackNode* temp = stack->top;
    char popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

// Function to peek at the top element of the stack without removing it
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';  // Return null character if stack is empty
    }
    return stack->top->data;
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0; // For parentheses and other characters
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to Reverse Polish Notation (RPN)
char* infixToRPN(const char* infix) {
    Stack* stack = createStack();
    int len = strlen(infix);
    char* rpn = (char*)malloc((len * 2 + 1) * sizeof(char));  // Allocate extra space for RPN (worst-case) and null terminator
    if (!rpn) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    int rpnIndex = 0;

    for (int i = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') { // Skip spaces and tabs
            continue;
        } else if (isalnum(infix[i])) { // Operand (letter or digit)
            rpn[rpnIndex++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                rpn[rpnIndex++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack); // Discard the '('
            } else {
                fprintf(stderr, "Mismatched parentheses!\n");
                free(rpn);
                free(stack); // Important: Clean up memory before exiting
                exit(EXIT_FAILURE);
            }
        } else if (isOperator(infix[i])) {  // Operator
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                rpn[rpnIndex++] = pop(stack);
            }
            push(stack, infix[i]);
        } else {
            fprintf(stderr, "Invalid character in expression: %c\n", infix[i]);
            free(rpn);
            free(stack);
            exit(EXIT_FAILURE);
        }
        rpn[rpnIndex++] = ' '; // Add a space after each token (operand or operator)
    }


    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        if (peek(stack) == '(') {  // Handle unclosed parentheses
            fprintf(stderr, "Mismatched parentheses!\n");
             free(rpn);
             free(stack);
             exit(EXIT_FAILURE);
        }
        rpn[rpnIndex++] = ' ';
        rpn[rpnIndex++] = pop(stack);

    }

    rpn[rpnIndex] = '\0'; // Null-terminate the RPN string

    //Shrink the allocated memory to the actual size used
    rpn = realloc(rpn, (rpnIndex + 1) * sizeof(char));
        if (!rpn && rpnIndex > 0) {
           fprintf(stderr, "Memory reallocation failed.\n"); //realloc can fail. check it!
           free(rpn);  // Free the previously allocated block if realloc fails.
           free(stack);
           exit(EXIT_FAILURE);
        }

    free(stack); // Free the stack
    return rpn;
}



int main() {
    char infix[100];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin); // Read input using fgets for safety
    infix[strcspn(infix, "\n")] = 0;     // Remove trailing newline

    char* rpn = infixToRPN(infix);
    printf("RPN: %s\n", rpn);

    free(rpn); // Don't forget to free the allocated memory!

    return 0;
}
