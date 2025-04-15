## Task Description

The task requires you to create a singly linked list to store student course score information (student ID and score). You need to read the corresponding score data to complete the creation of the student score information list. Then, output each student's score information line by line.

## Input Format

The input consists of one line, containing the score information (student ID, score) for 3 students. Student ID and score are separated by a comma `,`, and adjacent students' score information is separated by a space. The student ID takes the last three digits, and the score is an integer.

```
id1,score1 id2,score2 id3,score3
```

## Output Format

The output consists of 3 lines, with each student's score information occupying one line. Student ID and score are separated by a comma `,`, with the student ID showing only the last three digits.

```
[num=id1,score=score1]
[num=id2,score=score2]
[num=id3,score=score3]
```

## Example

**Input:**
```
201,98 202,94 203,89
```

**Output:**
```
[num=201,score=98]
[num=202,score=94]
[num=203,score=89]
```

**Explanation:**
1. The input provides score data for three students.
2. A singly linked list is created with these student score information.
3. Each node in the list contains a student ID and their score.
4. The program outputs the information for each student line by line in the required format.

## Grading Criteria

* The storage structure must use a singly linked list, otherwise, a score of zero will be given.
* Correctly creates a singly linked list from the input data.
* Correctly outputs each student's score information in the required format.