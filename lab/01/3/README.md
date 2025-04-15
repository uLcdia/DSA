## Task Description

The task requires you to find the main element in an integer sequence. An element is considered the main element if it appears more than N/2 times in the sequence of length N.

For example, in the sequence `0 5 5 3 5 7 5 5`, the main element is `5` because it appears 5 times, which is more than 8/2 = 4.

In the sequence `0 5 5 3 5 1 5 7`, there is no main element.

Assuming the elements are stored in a one-dimensional array, you need to design an algorithm that is as efficient as possible to find the main element. If a main element exists, output that element; otherwise, output `-1`.

## Input Format

The input is a single line containing an integer sequence:

```
a1 a2 a3 ... an
```

where `a1, a2, a3, ..., an` are the integers in the sequence.

## Output Format

The output should be a single integer representing the main element. If no main element exists, output `-1`.

```
x
```

where `x` is the main element or `-1`.

## Example

**Input:**

```
0 5 5 3 5 7 5 5
```

**Output:**

```
5
```

**Explanation:**

1. The input `0 5 5 3 5 7 5 5` is a sequence of 8 integers.
2. The element `5` appears 5 times in the sequence.
3. Since 5 > 8/2 (5 > 4), the element `5` is the main element.
4. The output is `5`.

## Grading Criteria

* Correctly determines if a main element exists in the given sequence.
* Correctly identifies the main element when it exists.
* Correctly outputs `-1` when no main element exists.
* Implements an efficient algorithm to find the main element.