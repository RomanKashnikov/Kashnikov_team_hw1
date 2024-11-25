#include "kun_by_vasileva.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int MAXN = 1000;



vector<int> g[MAXN];
int mt[MAXN];
bool used_vertexs[MAXN];

bool try_kuhn(int v) {
    if (used_vertexs[v]) {
        return false;
    }
    used_vertexs[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int kuhn(int n) {
    fill(mt, mt + n, -1);
    for (int v = 0; v < n; v++) {
        fill(used_vertexs, used_vertexs + n, false);
        try_kuhn(v);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mt[i] != -1) {
            ans++;
        }
    }

    return ans / 2;
}

int kun_by_vasileva(const vector<vector<int>>& adj_matrix) {
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix.size(); j++) {
            if (adj_matrix[i][j] == 1) {
                g[i].push_back(j);
            }
        }
    }

    int max_matching = kuhn(adj_matrix.size());

    for (int i = 0; i < adj_matrix.size(); ++i) {
        g[i].clear(); // Очищаем каждый вектор в массиве g
    }

    return max_matching;
}
