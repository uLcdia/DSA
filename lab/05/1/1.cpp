// https://github.com/uLcdia/DSA/tree/main/lab/05/1

#include <iostream>
#include <list>
#include <vector>

class Window {
  public:
    Window(int x1, int y1, int x2, int y2, std::size_t id)
        : x1(x1), y1(y1), x2(x2), y2(y2), id(id) {}

    bool isWithin(int x, int y) const {
        return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
    }

    std::size_t getId() const { return id; }

  private:
    int x1{};
    int y1{};
    int x2{};
    int y2{};
    std::size_t id{};
};

class WindowManager {
  public:
    void addWindow(int x1, int y1, int x2, int y2) {
        windows.emplace_front(x1, y1, x2, y2, count);
        ++count;
    }

    int clickOn(int x, int y) {
        auto it{windows.begin()};
        while (it != windows.end()) {
            if (it->isWithin(x, y)) {
                std::swap(*it, *windows.begin());
                return windows.begin()->getId();
            }
            ++it;
        }
        return -1;
    }

  private:
    std::list<Window> windows{};
    int count{1};
};

void addWindows(int count, WindowManager &windowManager) {
    for (int i = 0; i < count; ++i) {
        int x1{}, y1{}, x2{}, y2{};
        std::cin >> x1 >> y1 >> x2 >> y2;
        windowManager.addWindow(x1, y1, x2, y2);
    }
}

void printFocusedWindow(int x, int y, WindowManager &windowManager) {
    int id{windowManager.clickOn(x, y)};
    if (id == -1) {
        std::cout << "IGNORED\n";
    } else {
        std::cout << id << '\n';
    }
}

int main() {
    int count{};
    std::cin >> count;

    int clicks{};
    std::cin >> clicks;

    WindowManager windowManager{};
    addWindows(count, windowManager);

    for (int i{}; i < clicks; ++i) {
        int x{};
        int y{};
        std::cin >> x >> y;
        printFocusedWindow(x, y, windowManager);
    }

    return 0;
}