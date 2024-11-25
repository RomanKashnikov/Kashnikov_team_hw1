#pragma once
#include "Alg_gavela_hakimi_by_shakin.h"
#include "hopcrofta_carpa_by_Saitov.h"
#include "kun_by_vasileva.h"
#include "Szatie_chvetkov_by_pershin.h"
#include "graph_gen_by_ordin.h"
#include <chrono>


using namespace std;

template <typename matrix, typename function>
double time(matrix adj_matrix, function funct) {
    auto start = chrono::high_resolution_clock::now();
    int result = funct(adj_matrix);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Max matching:  " << result << endl << endl;

    return duration.count();
}