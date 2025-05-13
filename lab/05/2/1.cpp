// https://github.com/uLcdia/DSA/tree/main/lab/05/2

#include <iostream>
#include <list>
#include <unordered_map>

class StudentQueue {
  public:
    explicit StudentQueue(int num) {
        for (int i{1}; i < num + 1; ++i) {
            queue.emplace_back(i);
            posMap[i] = std::prev(queue.end());
        }
    }

    void move(int id, int offset) {
        if (offset == 0) {
            return;
        }

        auto it{posMap[id]};
        auto newIt{std::next(it, offset)};

        if (offset > 0) {
            newIt = std::next(newIt); // Insert after the new position
        }

        queue.erase(it);
        posMap.erase(id);
        posMap[id] = queue.insert(newIt, id);
    }

    std::list<int> getQueue() const { return queue; }

  private:
    std::list<int> queue{};
    std::unordered_map<int, std::list<int>::iterator> posMap{};
};

template <typename T> void printList(const std::list<T> &list) {
    for (const auto &item : list) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void handleMoves(int moves, StudentQueue &studentQueue) {
    for (int i{}; i < moves; ++i) {
        int id{};
        int offset{};
        std::cin >> id >> offset;

        studentQueue.move(id, offset);
    }
}

int main() {
    int count{};
    std::cin >> count;

    int moves{};
    std::cin >> moves;

    StudentQueue studentQueue{count};

    handleMoves(moves, studentQueue);

    printList(studentQueue.getQueue());

    return 0;
}