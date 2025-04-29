## Task Description

The task is to perform a bottom-up level-order traversal of a binary tree. The binary tree is represented using a generalized list notation, where each node contains an integer value greater than 0. The traversal should visit nodes level by level, starting from the bottom-most level to the root, and within each level, nodes should be visited from left to right. Each level's values should be printed on a separate line.

## Input Format

The input is a single string representing the binary tree in generalized list notation. The string contains no spaces.

```
root(left_subtree,right_subtree)
```

where:

*   `root` is the integer value of the root node.
*   `left_subtree` and `right_subtree` are the generalized list representations of the left and right subtrees, respectively. If a subtree is empty, it is omitted.

## Output Format

The output consists of multiple lines, each containing the values of the nodes at a specific level, starting from the bottom-most level to the root. The values in each line are separated by spaces, and the levels are printed in order from bottom to top.

```
level_k_values
level_k-1_values
...
level_1_values
```

## Example

**Input:**

```
1(2(3(4,5)),6(7,8(9,10)))
```

**Output:**

```
4 5 9 10
3 7 8
2 6
1
```

**Explanation:**

1.  The input represents the following binary tree:

```
        1
      /   \
     2     6
    /     / \
   3     7   8
  / \         / \
 4   5       9  10
```

2.  The bottom-up level-order traversal visits the nodes level by level, starting from the bottom-most level to the root:
    *   Level 4: `4 5 9 10`
    *   Level 3: `3 7 8`
    *   Level 2: `2 6`
    *   Level 1: `1`

3.  The output is:

```
4 5 9 10
3 7 8
2 6
1
```

## Grading Criteria

*   Correctly parses the input string to construct the binary tree.
*   Correctly implements the bottom-up level-order traversal algorithm.
*   Outputs the node values level by level, starting from the bottom-most level to the root, with values in each level printed from left to right.
*   Each level's values are printed on a separate line, and the levels are printed in order from bottom to top.