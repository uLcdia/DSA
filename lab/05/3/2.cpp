// https://github.com/uLcdia/DSA/tree/main/lab/05/3

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class Graph {
  private:
    int numHubs{};
    std::vector<std::vector<std::pair<int, int>>>
        adjList{}; // {neighbor, construction_time}

  public:
    explicit Graph(int n) : numHubs(n) { adjList.resize(n + 1); }

    void addEdge(int a, int b, int c) {
        adjList[a].emplace_back(b, c);
        adjList[b].emplace_back(a, c);
    }

    bool canReachWithBottleneck(int start, int end, int maxTime) {
        std::vector<bool> visited(numHubs + 1, false);
        std::queue<int> q{};
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current{q.front()};
            q.pop();
            if (current == end) {
                return true;
            }
            for (const auto &edge : adjList[current]) {
                int nextHub{edge.first};
                int time{edge.second};
                if (!visited[nextHub] && time <= maxTime) {
                    visited[nextHub] = true;
                    q.push(nextHub);
                }
            }
        }
        return false;
    }
};

int findMinBottleneckTime(int numHubs, int numTunnels, Graph &graph) {
    // Find the range for binary search (min and max possible bottleneck times)
    int low{1};
    int high{std::numeric_limits<int>::max()};

    int result{-1};
    while (low <= high) {
        int mid{low + (high - low) / 2};
        if (graph.canReachWithBottleneck(1, numHubs, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

void addEdges(int numTunnels, Graph &graph) {
    for (int i{}; i < numTunnels; ++i) {
        int hub1{};
        int hub2{};
        int time{};
        std::cin >> hub1 >> hub2 >> time;

        graph.addEdge(hub1, hub2, time);
    }
}

int main() {
    int numHubs{}, numTunnels{};
    std::cin >> numHubs >> numTunnels;

    Graph graph{numHubs};
    addEdges(numTunnels, graph);

    int result = findMinBottleneckTime(numHubs, numTunnels, graph);
    std::cout << result << std::endl;

    return 0;
}