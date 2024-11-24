#ifndef HOPCROFTA_CARPA_BY_SAITOV_H
#define HOPCROFTA_CARPA_BY_SAITOV_H

#include <vector>

using namespace std;

// Функция для вычисления максимального паросочетания
int hopcrofta_carpa_by_Saitov(const vector<vector<int>>& matrix);

// Вспомогательные функции
bool bfs(const vector<vector<int>>& matrix);
bool dfs(int u, const vector<vector<int>>& matrix);

// Глобальные переменные для паросочетаний и расстояний
extern vector<int> pairU, pairV, dist;
extern int n, m;

#endif // HOPCROFTA_CARPA_BY_SAITOV_H
