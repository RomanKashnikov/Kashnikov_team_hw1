#include "hopcrofta_carpa_by_Saitov.h"
#include <queue>

const int INF = 1e9;  // Бесконечность для инициализации расстояний

// Глобальные переменные для хранения паросочетаний и расстояний
vector<int> pairU, pairV, dist;
int n, m;

int hopcrofta_carpa_by_Saitov(const vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();

    // Инициализация массивов для паросочетаний
    pairU.assign(n, -1);
    pairV.assign(m, -1);
    dist.assign(n, INF);

    int number_of_matchings = 0;

    // Повторяем, пока есть пути для улучшения паросочетаний
    while (bfs(matrix)) {
        for (int u = 0; u < n; ++u) {
            if (pairU[u] == -1 && dfs(u, matrix)) {
                ++number_of_matchings;
            }
        }
    }

    return number_of_matchings/2;
}

// Вспомогательная функция для поиска путей с помощью BFS
bool bfs(const vector<vector<int>>& matrix) {
    queue<int> q;
    bool foundAugmentingPath = false;

    // Инициализация всех паросочетаний для U с -1 и расстояний с бесконечностью
    for (int u = 0; u < n; ++u) {
        if (pairU[u] == -1) {
            dist[u] = 0;
            q.push(u);
        }
        else {
            dist[u] = INF;
        }
    }

    // BFS для нахождения пути
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] < INF) {
            for (int v = 0; v < m; ++v) {
                if (matrix[u][v] == 1) {
                    int pairV_U = pairV[v];
                    if (pairV_U == -1) {
                        foundAugmentingPath = true;
                    }
                    else if (dist[pairV_U] == INF) {
                        dist[pairV_U] = dist[u] + 1;
                        q.push(pairV_U);
                    }
                }
            }
        }
    }

    return foundAugmentingPath;
}

// Вспомогательная функция для поиска пути с помощью DFS
bool dfs(int u, const vector<vector<int>>& matrix) {
    for (int v = 0; v < m; ++v) {
        if (matrix[u][v] == 1) {
            int pairV_U = pairV[v];
            if (pairV_U == -1 || (dist[pairV_U] == dist[u] + 1 && dfs(pairV_U, matrix))) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}
