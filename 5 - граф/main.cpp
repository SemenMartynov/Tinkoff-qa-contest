
#include <iostream>
#include <vector>
#include <queue>

int bfs (int u, int v, const std::vector<std::vector<int>>& graph) {
    std::queue<int> q;
    q.push(u);
    const int max_dist = 999999;
    std::vector<bool> used(graph.size(), false);
    std::vector<int>  dist(graph.size(), max_dist);
    used[u] = true;
    dist[u] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int neighbor: graph[cur]) {
            if (!used[neighbor]) {
                q.push(neighbor);
                used[neighbor] = true;
                if (dist[neighbor] > dist[cur] + 1)
                    dist[neighbor] = dist[cur] + 1;
            }
        }
    }

    return dist[v] == max_dist ? -1: dist[v];
}

int main(int argc, char** argv) {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph;
    graph.resize(n);

    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0; //номера вершин, соединённых очередным ребром
        std::cin >> u >> v;
        u--, v--;

        graph[u].push_back(v); // граф не ориентированный
        graph[v].push_back(u);
    }

    int q = 0;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        u--, v--;
        std::cout << bfs(u, v, graph) << std::endl;
    }
}