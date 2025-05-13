## Task Description

The task is to simulate the process of clicking on windows in a graphical operating system. There are N windows, each represented as a rectangle aligned with the coordinate axes. Windows have a stacking order; in overlapping regions, only the topmost window is visible. When a point is clicked, the topmost window containing that point is selected and moved to the top of the stack. If no window contains the point, the click is ignored.

## Input Format

- The first line contains two positive integers N and M (1 ≤ N ≤ 10, 1 ≤ M ≤ 10), the number of windows and the number of clicks.
- The next N lines describe the windows from bottom to top. Each line contains four non-negative integers x1, y1, x2, y2 (x1 < x2, y1 < y2), representing the coordinates of two opposite corners of the window.
- The next M lines each contain two non-negative integers x, y, representing the coordinates of a mouse click.

## Output Format

- Output M lines. For each click, if a window is selected, output its number (windows are numbered from 1 in input order); otherwise, output `IGNORED`.

## Example

**Input:**
```
3 4
0 0 4 4
1 1 5 5
2 2 6 6
1 1
0 0
4 4
0 5
```

**Output:**
```
2
1
1
IGNORED
```

## Explanation

- The first click (1,1) is inside windows 1 and 2; window 2 is on top, so it is selected and moved to the top.
- The second click (0,0) is only inside window 1, so window 1 is selected and moved to the top.
- The third click (4,4) is inside all three windows; the current topmost window is 1, so it is selected.
- The last click (0,5) is not inside any window, so the output is `IGNORED`.

## Grading Criteria

* Correctly parses the input and maintains the stacking order of windows.
* Correctly determines which window (if any) is selected for each click.
* Correctly updates the stacking order after each click.
* Outputs the correct result for each click, as specified.
