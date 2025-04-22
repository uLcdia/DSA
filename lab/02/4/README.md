## Task Description

The task is to implement an algorithm that converts a given infix expression into its corresponding postfix expression (also known as Reverse Polish Notation - RPN).

The infix expression will contain:
*   Uppercase letters (A-Z) as operands.
*   The four standard arithmetic operators: `+`, `-`, `*`, `/`.
*   Parentheses: `(` and `)`.
*   All symbols are half-width characters.

The input expression is terminated by a `#` character.

## Input Format

The input consists of a single line containing the infix expression, ending with the `#` character.

```
infix_expression#
```

## Output Format

The output should be a single line containing the corresponding postfix expression.

```
postfix_expression
```

## Example

**Input:**

```
A*(B-C)/D+E#
```

**Output:**

```
ABC-*D/E+
```

## Grading Criteria

*   Correctly reads the infix expression until the `#` character.
*   Correctly handles operator precedence (`*`, `/` have higher precedence than `+`, `-`).
*   Correctly handles parentheses to override precedence.
*   Correctly handles associativity (left-to-right for `+`, `-`, `*`, `/`).
*   Correctly outputs the equivalent postfix expression.
