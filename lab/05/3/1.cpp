// https://github.com/uLcdia/DSA/tree/main/lab/05/3

#include <iostream>
#include <limits>
#include <vector>

class Graph {
  private:
    int numHubs{};
    std::vector<std::vector<int>> adjList{};
    std::vector<bool> visited{};
    int minBottleneck{};

    void dfs(int current, int target, int currentMaxTime) {
        if (current == target) {
            minBottleneck = std::min(minBottleneck, currentMaxTime);
            return;
        }
        for (int nextHub{1}; nextHub <= numHubs; ++nextHub) {
            if (!visited[nextHub] &&
                adjList[current][nextHub] != std::numeric_limits<int>::max()) {
                visited[nextHub] = true;
                dfs(nextHub, target,
                    std::max(currentMaxTime, adjList[current][nextHub]));
                visited[nextHub] = false;
            }
        }
    }

  public:
    Graph(int n) : numHubs(n), minBottleneck(std::numeric_limits<int>::max()) {
        // Initialize adjacency matrix with MAX_INT for no connection
        adjList.assign(
            n + 1, std::vector<int>(n + 1, std::numeric_limits<int>::max()));
    }

    void addEdge(int a, int b, int c) {
        adjList[a][b] = c;
        adjList[b][a] = c;
    }

    int findMinBottleneckTime(int start, int end) {
        visited.assign(numHubs + 1, false);
        visited[start] = true;
        dfs(start, end, 0);
        return minBottleneck == std::numeric_limits<int>::max() ? -1
                                                                : minBottleneck;
    }
};

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

    int result = graph.findMinBottleneckTime(1, numHubs);
    std::cout << result << std::endl;

    return 0;
}