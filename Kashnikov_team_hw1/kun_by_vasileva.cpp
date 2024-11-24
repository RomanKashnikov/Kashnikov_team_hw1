#include "kun_by_vasileva.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int MAXN = 1000;



vector<int> g[MAXN];
int mt[MAXN];
bool used[MAXN];

bool try_kuhn(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
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
        fill(used, used + n, false);
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

int kun_by_vasileva(vector<vector<int>> adj_matrix, int n, int m) {
    for (int i = 0; i < n + m; ++i) {
        g[i].clear(); // Очищаем каждый вектор в массиве g
    }
    for (int i = 0; i < n + m; i++) {
        for (int j = 0; j < n + m; j++) {
            if (adj_matrix[i][j] == 1) {
                g[i].push_back(j);
            }
        }
    }

    int max_matching = kuhn(n + m);

    return max_matching;
}
