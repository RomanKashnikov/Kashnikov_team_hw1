#ifndef HOPCROFTA_CARPA_BY_SAITOV_H
#define HOPCROFTA_CARPA_BY_SAITOV_H

#include <vector>

using namespace std;

// ������� ��� ���������� ������������� �������������
int hopcrofta_carpa_by_Saitov(const vector<vector<int>>& matrix);

// ��������������� �������
bool bfs(const vector<vector<int>>& matrix);
bool dfs(int u, const vector<vector<int>>& matrix);

// ���������� ���������� ��� ������������� � ����������
extern vector<int> pairU, pairV, dist;
extern int n, m;

#endif // HOPCROFTA_CARPA_BY_SAITOV_H
