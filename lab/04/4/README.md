## Task Description

The task is to determine the number of connected components in an undirected graph, given its adjacency matrix. The solution must use either breadth-first search (BFS) or depth-first search (DFS) traversal algorithms.

## Input Format

- The first line contains an integer n, the number of nodes in the graph.
- The next n lines each contain n integers, representing the adjacency matrix A of the graph. A[i][j] = 1 indicates an edge between node i and node j; A[i][j] = 0 indicates no edge. The diagonal elements are always 0.

## Output Format

- Output a single integer: the number of connected components in the graph.

## Example

**Input:**
```
5
0 1 1 0 0
1 0 1 0 0
1 1 0 0 0
0 0 0 0 1
0 0 0 1 0
```

**Output:**
```
2
```

**Explanation:**
- The adjacency matrix describes a graph with 5 nodes. There are two connected components: one containing nodes 0, 1, 2 and another containing nodes 3, 4.

## Grading Criteria

* Correctly parses the adjacency matrix input.
* Correctly implements BFS or DFS to find all connected components.
* Outputs the correct number of connected components.
* Solutions not using BFS or DFS will not receive credit.
