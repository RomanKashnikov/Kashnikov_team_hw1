#include "graph_gen_by_ordin.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<vector<int> > generateBipartiteGraphMatrix(int n1, int n2) {
    vector<vector<int> > adjacencyMatrix(n1 + n2, vector<int>(n1 + n2, 0));
    srand(time(0));

    for (int u = 0; u < n1; ++u) {
        for (int v = 0; v < n2; ++v) {
            double prob = (double)(rand()) / RAND_MAX;
            if (prob < PROBABILITY) {
                adjacencyMatrix[u][n1 + v] = 1;
                adjacencyMatrix[n1 + v][u] = 1;
            }
        }
    }

    return adjacencyMatrix;
}
