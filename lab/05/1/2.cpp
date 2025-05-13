#include <iostream>
#include <vector>

struct Window {
    int x1, y1, x2, y2;
    int id; // Original input order (1-based)
};

bool isInside(const Window &win, int x, int y) {
    return x >= win.x1 && x <= win.x2 && y >= win.y1 && y <= win.y2;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    // Read windows, store in input order (bottom to top initially)
    std::vector<Window> windows(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> windows[i].x1 >> windows[i].y1 >> windows[i].x2 >>
            windows[i].y2;
        windows[i].id = i + 1; // 1-based index
    }

    // Stack represents current stacking order, topmost at the end
    std::vector<int> stack(N);
    for (int i = 0; i < N; ++i) {
        stack[i] = i; // Index into windows vector
    }

    // Process each click
    for (int click = 0; click < M; ++click) {
        int x, y;
        std::cin >> x >> y;

        // Check from top to bottom (reverse stack order)
        bool found = false;
        for (int i = N - 1; i >= 0; --i) {
            int winIdx = stack[i];
            if (isInside(windows[winIdx], x, y)) {
                // Found the topmost window containing the point
                std::cout << windows[winIdx].id << std::endl;

                // Move this window to the top of the stack
                int selected = stack[i];
                for (int j = i; j < N - 1; ++j) {
                    stack[j] = stack[j + 1];
                }
                stack[N - 1] = selected;
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "IGNORED" << std::endl;
        }
    }

    return 0;
}