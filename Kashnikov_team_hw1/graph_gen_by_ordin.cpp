#include "graph_gen_by_ordin.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<vector<int> > generateBipartiteGraphMatrix(const int n1, const int n2) {
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


void generateGraphvizFile(std::vector<std::vector<int> >& matrix, string fileName) {
    ofstream file(fileName);
    file << "graph G {\n";
    for(size_t i = 0; i < matrix.size(); i++) {
        for(size_t q = i; q < matrix[i].size(); q++) {
            if (matrix[i][q] != 0) {
                file << (char)'a'+i << "--" << (char)'a'+q << '\n'; 
            }
        }
    }
    file << '}';
    file.close();

}
