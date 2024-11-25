#include "Alg_ford_fulkerson_by_shakin.h"
#include <queue>
#include <iostream>
#include <vector>

using namespace std;


// Функция для поиска увеличивающего пути с помощью BFS
int bfs(const vector<vector<int>>& residualGraph, vector<int>& parent, int source, int sink) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                if (v == sink) return 1;
            }
        }
    }
    return 0;
}

// Основная функция алгоритма Форда-Фалкерсона
int fordFulkerson(const vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(n, -1);

    int maxFlow = 0;

    // Пока есть увеличивающий путь
    while (bfs(residualGraph, parent, source, sink)) {
        // Находим минимальную пропускную способность вдоль пути
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Обновляем остаточную сеть
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int Alg_ford_fulkerson_by_shakin(const vector<vector<int>>& adjacencyMatrix) {
    int leftSize = adjacencyMatrix.size();
    int rightSize = adjacencyMatrix[0].size();

    int totalSize = leftSize + rightSize + 2; // Источник + сток + вершины

    vector<vector<int>> graph(totalSize, vector<int>(totalSize, 0));

    // Добавляем рёбра от источника к левой доле
    for (int i = 0; i < leftSize; ++i) {
        graph[0][i + 1] = 1; // Пропускная способность 1
    }

    // Добавляем рёбра от правой доли к стоку
    for (int i = 0; i < rightSize; ++i) {
        graph[leftSize + i + 1][totalSize - 1] = 1; // Пропускная способность 1
    }

    // Добавляем рёбра между левой и правой долей
    for (int i = 0; i < leftSize; ++i) {
        for (int j = 0; j < rightSize; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                graph[i + 1][leftSize + j + 1] = 1; // Пропускная способность 1
            }
        }
    }

    // Источник - 0, сток - totalSize-1
    return fordFulkerson(graph, 0, totalSize - 1) / 2;
}