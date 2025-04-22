## Task Description

The task is to determine if the brackets in a given arithmetic expression are correctly paired and nested. The expression can contain three types of brackets:
*   Parentheses: `(` and `)`
*   Square brackets: `[` and `]`
*   Curly braces: `{` and `}`

These brackets can be nested in any order. The expression itself is assumed to be stored as a sequence of characters. All brackets are half-width characters.

The program should output `1` if all brackets are correctly matched and nested, and `0` otherwise.

## Input Format

The input consists of a single line containing the arithmetic expression with brackets.

```
arithmetic_expression
```

## Output Format

The output should be a single line containing either `1` (if brackets are balanced) or `0` (if brackets are not balanced).

```
1 or 0
```

## Example

**Input:**

```
3+(44*[5-{6*[7*(45-10)]}])
```

**Output:**

```
1
```

**Explanation:**

Bracket matching involves checking two aspects:
1.  The total number of opening brackets of each type must match the total number of closing brackets of the same type.
2.  The nesting order must be correct. For example, `([)]` is invalid because the closing square bracket `]` appears before the closing parenthesis `)`. The sequence `3+(44*[5-{6*[7*(45-10)]}])` has correctly matched and nested brackets.

## Grading Criteria

*   Correctly reads the input expression.
*   Correctly identifies opening and closing brackets.
*   Correctly verifies that each closing bracket has a corresponding opening bracket of the same type.
*   Correctly verifies the nesting order of the brackets.
*   Outputs `1` for correctly matched expressions and `0` otherwise.
