## Task Description

Given n transportation hubs in city A, with hub 1 and hub n being especially important, the city plans to build a subway line from hub 1 to hub n. The subway consists of several tunnel segments, each connecting two hubs. There are m candidate tunnels, each with a construction time, and at most one candidate tunnel between any two hubs. No tunnel connects a hub to itself.

There are n construction companies, each of which can build at most one tunnel, and all companies take the same number of days to build a tunnel. All companies start construction at the same time. You may select any subset of the candidate tunnels to build the subway line from hub 1 to hub n. What is the minimum number of days required to complete the subway line from hub 1 to hub n?

## Input Format

- The first line contains two integers n and m, separated by a space, representing the number of hubs and the number of candidate tunnels.
- The next m lines each contain three integers a, b, c, indicating a tunnel can be built between hub a and hub b, taking c days to complete.

## Output Format

- Output a single integer: the minimum number of days required to complete the subway line from hub 1 to hub n.

## Example

**Input:**
```
6 6
1 2 4
2 3 4
3 6 7
1 4 2
4 5 5
5 6 6
```

**Output:**
```
6
```

**Explanation:**
- There are two possible routes:
    - 1 → 2 → 3 → 6, with tunnel times 4, 4, 7; the total time is 7 days (the slowest tunnel).
    - 1 → 4 → 5 → 6, with tunnel times 2, 5, 6; the total time is 6 days (the slowest tunnel).
- The minimum required days is 6.

## Grading Criteria

* Correctly parses the input and constructs the graph.
* Correctly finds the path from hub 1 to hub n that minimizes the maximum tunnel construction time along the path.
* Outputs the minimum number of days required.
