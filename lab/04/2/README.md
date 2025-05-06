## Task Description

The task is to define a sequential list (array/list) to store book information, where each book has an ISBN, a title, and a price. The program should read the book data, create the book list, and then find and output the information of the book(s) with the highest price.

## Input Format

The input consists of n+1 lines:

1. The first line contains an integer n, the number of books.
2. The next n lines each contain the information for one book: ISBN (string), title (string), and price (float), separated by spaces. There is no space after the price.

```
n
ISBN1 Title1 Price1
ISBN2 Title2 Price2
...
ISBNn Titlen Pricen
```

## Output Format

The output consists of m+1 lines:

1. The first line contains an integer m, the number of books with the highest price (there may be more than one).
2. The next m lines each contain the information for one of the most expensive books: ISBN, title, and price (with two decimal places), separated by spaces.

```
m
ISBNx Titlex Pricex
...
```

## Example

**Input:**

```
6
9787302257646 程序设计基础 25.00
9787302164340 程序设计基础（第2版） 20.00
9787302219972 单片机技术及应用 32.00
9787302203513 单片机原理及应用技术 26.00
9787810827430 工业计算机控制技术——原理与应用 29.00
9787811234923 汇编语言程序设计教程 32.00
```

**Output:**

```
2
9787302219972 单片机技术及应用 32.00
9787811234923 汇编语言程序设计教程 32.00
```

## Grading Criteria

* Correctly defines a sequential list to store book information.
* Correctly reads and stores all book data.
* Correctly finds all books with the highest price.
* Outputs the number of most expensive books and their information, with prices formatted to two decimal places.
