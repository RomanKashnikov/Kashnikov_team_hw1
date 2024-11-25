#ifndef _GRAPH_GEN_BY_ORDIN_
#define _GRAPH_GEN_BY_ORDIN_

#include <vector>
#include <string>

#define PROBABILITY 0.1

std::vector<std::vector<int> > generateBipartiteGraphMatrix(const int n1, const int n2);

void generateGraphvizFile(std::vector<std::vector<int> >& matrix, std::string fileName);

#endif // _GRAPH_GEN_BY_ORDIN_
