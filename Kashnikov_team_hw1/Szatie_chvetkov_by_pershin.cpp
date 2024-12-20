#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 500; // ������������ ���������� ������

vector<int> adj[MAXN]; // ������ ��������� �����
int match[MAXN];       // ������� ��� ������ �������
int parent[MAXN];      // ������������ ������� � ����
int base[MAXN];        // ���� ��� ������ �������
bool used[MAXN];       // �������������� �������
bool blossom[MAXN];    // ���� ��� �������

// ������� ��� ���������� LCA (����������� ������ ������)
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

// �������� ���� ��� ������ ������
void markPath(int u, int lca, int child) {
    while (base[u] != lca) {
        blossom[base[u]] = blossom[base[match[u]]] = true;
        parent[u] = child;
        child = match[u];
        u = parent[match[u]];
    }
}

// ������� ������
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

// BFS ��� ������ �������������� ����
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

    int iteration_limit = n * n; // ����������� �� ���������� ��������
    int iteration_count = 0;

    while (!q.empty()) {
        if (++iteration_count > iteration_limit) {
            // ���� �� ��������� ����� ��������, ���������� false, ����� ������������� ����������� ����.
            cerr << "Error: Algorithm entered an infinite loop. Stopping BFS." << endl;
            return false;
        }

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

// ����������� �������������
void augmentPath(int v) {
    while (v != -1) {
        int pv = parent[v];
        int ppv = match[pv];
        match[v] = pv;
        match[pv] = v;
        v = ppv;
    }
}

// ������� ������� ��� ������ ������������� �������������
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

// ��������� ������� ���������
int Szatie_chvetkov_by_pershin(const vector<vector<int>>& adj_matrix) {
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix.size(); j++) {
            if (adj_matrix[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    int max_matching = maximumMatching(adj_matrix.size());

    for (int i = 0; i < adj_matrix.size(); ++i) {
        adj[i].clear(); // ������� ������ ������ � ������� g
    }

    return max_matching;
}