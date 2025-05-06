## Task Description

The task is to validate the results of several "24 Game" expressions. Each game consists of 4 digits (from 1 to 9) and 3 arithmetic operators (+, -, x, /), with no parentheses and no other characters. Operators are placed between the digits, and the evaluation follows the standard operator precedence (multiplication and division before addition and subtraction). Division is integer division.

For each game, determine if the result of the expression is 24.

## Input Format

- The first line contains an integer n, the number of games.
- The next n lines each contain a string of length 7, representing a 24 Game expression (e.g., `1+2x3/4`).
- Each string contains 4 digits (1-9) and 3 operators (+, -, x, /), with operators between the digits. The format is guaranteed to be valid.

## Output Format

- Output n lines.
- For each game, output `Yes` if the result is 24, otherwise output `No`.

## Example

**Input:**
```
3
8x3/1+0
2x3x4+0
9-2x3x1
```

**Output:**
```
Yes
Yes
No
```

## Grading Criteria

* Correctly parses and evaluates each 24 Game expression according to operator precedence and integer division.
* Outputs `Yes` if the result is 24, otherwise `No`, for each game.
