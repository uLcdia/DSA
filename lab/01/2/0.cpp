// https://github.com/uLcdia/DSA/tree/main/lab/01/2

#include <iostream>
#include <list>
#include <utility>

std::istream& operator>>(std::istream& is, std::pair<int, int>& pair) {
    char comma;
    is >> pair.first >> comma >> pair.second;
    return is;
}

void printStudentInfoList(std::list<std::pair<int, int>>& list) {
    for (auto& studentInfo : list) {
        printf("[num=%03d,score=%d]\n",
                studentInfo.first % 1000,
                studentInfo.second);
    }
}

int main() {
    std::list<std::pair<int, int>> studentInfoList {};

    std::pair<int, int> studentInfo {};

    for (int i = 0; i < 3; i++) {
        std::cin >> studentInfo;
        studentInfoList.emplace_back(studentInfo);
    }

    printStudentInfoList(studentInfoList);

    return 0;
}