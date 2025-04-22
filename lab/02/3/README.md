## Task Description

The task is to write a program that converts a given non-negative decimal integer into its equivalent octal representation.

The program must first validate the input to ensure it is a non-negative decimal integer. If the input is invalid (e.g., negative or not an integer), it should prompt the user with an error message and ask for input again until a valid non-negative integer is provided.

## Input Format

The input consists of a single line containing a non-negative decimal integer.

```
decimal_integer
```

## Output Format

The output should be a single line containing the octal representation of the input decimal integer.

If the initial input is invalid, an error message should be displayed, and the program should re-prompt for input. The final output should only be the octal number corresponding to the first valid input received.

```
octal_integer
```

## Example

**Input:**

```
5548
```

**Output:**

```
12654
```

**Example with Invalid Input:**

**Input:**

```
-10
```

**(Error message displayed, program prompts again)**

**Input:**

```
abc
```

**(Error message displayed, program prompts again)**

**Input:**

```
5548
```

**Output:**

```
12654
```

## Grading Criteria

*   Correctly validates the input to ensure it is a non-negative decimal integer.
*   Handles invalid input by displaying an error message and re-prompting.
*   Correctly converts the valid non-negative decimal integer to its octal equivalent.
*   Correctly outputs the resulting octal integer.
