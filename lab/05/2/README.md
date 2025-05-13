## Task Description

The task is to simulate a sequence of student queue adjustments. Initially, students are lined up in order of their student numbers from 1 to n. Each adjustment moves a student with a given number forward or backward by a specified number of positions. After all adjustments, output the final order of student numbers in the queue.

## Input Format

- The first line contains an integer n, the number of students (student numbers are 1 to n).
- The second line contains an integer m, the number of adjustments.
- The next m lines each contain two integers p and q:
    - If q > 0, student p moves backward by q positions.
    - If q < 0, student p moves forward by -q positions.

All moves are valid and within the queue bounds.

## Output Format

- Output a single line with n integers, the final order of student numbers in the queue, separated by spaces.

## Example

**Input:**
```
8
3
3 2
8 -3
3 -2
```

**Output:**
```
1 2 4 3 5 8 6 7
```

## Grading Criteria

* Correctly simulates the queue and all adjustments.
* Correctly outputs the final order of student numbers after all adjustments.
* Handles all valid input cases as specified.
