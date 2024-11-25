#include <queue>
#include <cstring>
#include <vector>


using namespace std;

const int MAXN = 500; // Максимальное количество вершин

vector<int> adj[MAXN]; // Список смежности графа
int match[MAXN];       // Матчинг для каждой вершины
int parent[MAXN];      // Родительская вершина в пути
int base[MAXN];        // База для каждой вершины
bool used[MAXN];       // Использованные вершины
bool blossom[MAXN];    // Флаг для цветков

// Функция для нахождения LCA (наименьшего общего предка)
int findLCA(int u, int v) {
    static bool visited[MAXN];
    memset(visited, 0, sizeof(visited));
    while (true) {
        u = base[u];
        visited[u] = true;
        if (match[u] == -1) break;
        u = parent[match[u]];
    }
    while (true) {
        v = base[v];
        if (visited[v]) return v;
        v = parent[match[v]];
    }
}

// Помечаем путь при сжатии цветка
void markPath(int u, int lca, int child) {
    while (base[u] != lca) {
        blossom[base[u]] = blossom[base[match[u]]] = true;
        parent[u] = child;
        child = match[u];
        u = parent[match[u]];
    }
}

// Сжимаем цветок
void contract(int u, int v, int n) {
    int lca = findLCA(u, v);
    memset(blossom, 0, sizeof(blossom));
    markPath(u, lca, v);
    markPath(v, lca, u);
    for (int i = 0; i < n; ++i) {
        if (blossom[base[i]]) {
            base[i] = lca;
            if (!used[i]) {
                used[i] = true;
                parent[i] = v;
            }
        }
    }
}

// BFS для поиска увеличивающего пути
bool bfs(int n) {
    memset(used, 0, sizeof(used));
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < n; ++i) base[i] = i;

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (match[i] == -1) {
            q.push(i);
            used[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (base[u] == base[v] || match[u] == v) continue;
            if (match[v] == -1) {
                parent[v] = u;
                return true;
            }
            else if (!used[match[v]]) {
                parent[v] = u;
                used[match[v]] = true;
                q.push(match[v]);
            }
            else if (used[v] && base[u] != base[v]) {
                contract(u, v, n);
            }
        }
    }
    return false;
}

// Увеличиваем паросочетание
void augmentPath(int v) {
    while (v != -1) {
        int pv = parent[v];
        int ppv = match[pv];
        match[v] = pv;
        match[pv] = v;
        v = ppv;
    }
}

// Главная функция для поиска максимального паросочетания
int maximumMatching(int n) {
    memset(match, -1, sizeof(match));
    int matching = 0;
    while (bfs(n)) {
        for (int i = 0; i < n; ++i) {
            if (match[i] == -1 && parent[i] != -1) {
                augmentPath(i);
                matching++;
            }
        }
    }
    return matching;
}

// Обработка матрицы смежности
int Szatie_chvetkov_by_pershin(const vector<vector<int>>& adj_matrix, const int& n, const int& m) {
    for (int i = 0; i < n + m; i++) {
        for (int j = 0; j < n + m; j++) {
            if (adj_matrix[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    int max_matching = maximumMatching(n + m);

    for (int i = 0; i < n + m; ++i) {
        adj[i].clear(); // Очищаем каждый вектор в массиве g
    }

    return max_matching;
}