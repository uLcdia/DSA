## Task Description

Given a sequence of positive integers separated by spaces, the task is to construct a Huffman tree using these integers as the weights for the leaf nodes. After constructing the tree, calculate and output its Weighted Path Length (WPL).

## Input Format

The input consists of two lines:

1.  The first line contains a single positive integer *n*, representing the number of integers (leaf node weights) that follow. It is guaranteed that *n* will not exceed 10.
2.  The second line contains *n* positive integers, separated by spaces, representing the weights of the leaf nodes.

```
n
w1 w2 w3 ... wn
```

where:

*   *n* is the number of integers.
*   *w1, w2, w3, ..., wn* are the positive integer weights.

## Output Format

Output a single integer representing the calculated Weighted Path Length (WPL) of the constructed Huffman tree.

```
WPL
```

## Example

**Input:**

```
5
4 5 6 7 8
```

**Output:**

```
69
```

**Explanation:**

1.  The input indicates 5 integer weights: 4, 5, 6, 7, 8.
2.  These weights are used to build a Huffman tree. The construction involves repeatedly merging the two nodes (or subtrees) with the smallest current weights.
3.  The Weighted Path Length (WPL) is the sum of the products of each leaf node's weight and its depth in the tree. Alternatively, it can be calculated by summing the weights of all the internal nodes created during the construction.
    *   Initial weights: {4, 5, 6, 7, 8}
    *   Merge 4 and 5 (cost 9): {6, 7, 8, 9}
    *   Merge 6 and 7 (cost 13): {8, 9, 13}
    *   Merge 8 and 9 (cost 17): {13, 17}
    *   Merge 13 and 17 (cost 30): {30}
    *   WPL = Sum of internal node weights = 9 + 13 + 17 + 30 = 69.
4.  The output is the calculated WPL, which is 69.

## Grading Criteria

*   Correctly reads the input count and weights.
*   Correctly implements the Huffman tree construction algorithm (e.g., using a priority queue).
*   Correctly calculates the Weighted Path Length (WPL) of the resulting tree.
*   Outputs the single integer result in the correct format.
