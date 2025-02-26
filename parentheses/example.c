#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../stack/stack.h"

bool isValidParentheses(const char *s) {
    Stack stack;
    if (!initStack(&stack, strlen(s))) {
        return false; // Memory allocation failed
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            if (!push(&stack, c)) {
                destroyStack(&stack);  // Clean up before returning on failure
                return false; // Push failed (likely realloc failure)
            }
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&stack)) {
                destroyStack(&stack);
                return false; // Closing bracket without a matching opening one
            }

            ElemType top;
            if (!pop(&stack, &top)) {  // This should never happen since we checked for empty above
                destroyStack(&stack);
                return false;
            }

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                destroyStack(&stack);
                return false; // Mismatched brackets
            }
        }
        // Ignore other characters
    }

    bool result = isEmpty(&stack);
    destroyStack(&stack);
    return result; // Valid if the stack is empty at the end
}

int main() {
    // Test cases
    char *test1 = "()";
    char *test2 = "()[]{}";
    char *test3 = "(]";
    char *test4 = "([)]";
    char *test5 = "{[]}";
    char *test6 = ""; // Empty string
    char *test7 = "(("; // Unmatched opening
    char *test8 = "))"; // Unmatched closing
    char *test9 = "a(b[c]d)e";  // with other chars
    char *test10 = "(){}}{"; // Multiple errors
     char *test11 = "(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((())))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))";
    printf("\"%s\" is %s\n", test1, isValidParentheses(test1) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test2, isValidParentheses(test2) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test3, isValidParentheses(test3) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test4, isValidParentheses(test4) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test5, isValidParentheses(test5) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test6, isValidParentheses(test6) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test7, isValidParentheses(test7) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test8, isValidParentheses(test8) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test9, isValidParentheses(test9) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test10, isValidParentheses(test10) ? "valid" : "invalid");
    printf("\"%s\" is %s\n", test11, isValidParentheses(test11) ? "valid" : "invalid");

    return 0;
}