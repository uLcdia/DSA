## Task Description

The task is to reconstruct a binary tree from its given in-order and post-order traversal sequences and then compute the pre-order traversal sequence of the tree. The input sequences consist of lowercase letters with no duplicates.

## Input Format

The input consists of two strings separated by a space:

```
inorder postorder
```

where:

*   `inorder` is the in-order traversal sequence of the binary tree.
*   `postorder` is the post-order traversal sequence of the binary tree.

## Output Format

The output is a single string representing the pre-order traversal sequence of the binary tree.

```
preorder
```

## Example

**Input:**

```
dbeafcg debfgca
```

**Output:**

```
abdecfg
```

**Explanation:**

1.  The input provides the in-order sequence `dbeafcg` and the post-order sequence `debfgca`.
2.  Using these sequences, the binary tree is reconstructed as follows:

```
        a
      /   \
     b     c
    / \   / \
   d   e f   g
```

3.  The pre-order traversal of this tree is `abdecfg`.
4.  The output is the pre-order sequence `abdecfg`.

## Grading Criteria

*   Correctly parses the input in-order and post-order sequences.
*   Correctly reconstructs the binary tree from the given sequences.
*   Correctly computes the pre-order traversal sequence of the reconstructed tree.
*   Outputs the pre-order traversal sequence as a single string.