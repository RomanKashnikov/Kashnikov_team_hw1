#include "Alg_gavela_hakimi_by_shakin.h"
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

// Проверка, является ли последовательность графической
bool isGraphicalSequence(vector<int>& sequence) {
    // Удаляем нули
    sequence.erase(remove(sequence.begin(), sequence.end(), 0), sequence.end());

    // Сортируем по убыванию
    sort(sequence.rbegin(), sequence.rend());

    while (!sequence.empty()) {
        int d = sequence[0];
        sequence.erase(sequence.begin());

        if (d < 0 || d > static_cast<int>(sequence.size())) {
            return false;
        }

        // Уменьшаем первые d элементов на 1
        for (int i = 0; i < d; ++i) {
            sequence[i]--;
            if (sequence[i] < 0) {
                return false;
            }
        }

        // Удаляем нули и сортируем оставшуюся часть
        sequence.erase(remove(sequence.begin(), sequence.end(), 0), sequence.end());
        sort(sequence.rbegin(), sequence.rend());
    }
    return true;
}

// Главная функция для проверки графа по матрице смежности
int Alg_gavela_hakimi_by_shakin(const vector<vector<int>>& adjacencyMatrix) {
    vector<int> leftDegrees;
    vector<int> rightDegrees;

    size_t rows = adjacencyMatrix.size();
    if (rows == 0) return 0; // Если матрица пустая, возвращаем 0

    size_t cols = adjacencyMatrix[0].size();

    // Подсчёт степеней для левой и правой долей
    for (size_t i = 0; i < rows; ++i) {
        int degree = accumulate(adjacencyMatrix[i].begin(), adjacencyMatrix[i].end(), 0);
        leftDegrees.push_back(degree);
    }

    for (size_t j = 0; j < cols; ++j) {
        int degree = 0;
        for (size_t i = 0; i < rows; ++i) {
            degree += adjacencyMatrix[i][j];
        }
        rightDegrees.push_back(degree);
    }

    // Проверяем равенство сумм степеней
    if (accumulate(leftDegrees.begin(), leftDegrees.end(), 0) !=
        accumulate(rightDegrees.begin(), rightDegrees.end(), 0)) {
        return 0;
    }

    // Проверяем графичность обеих последовательностей
    if (isGraphicalSequence(leftDegrees) && isGraphicalSequence(rightDegrees)) {
        return 1; // Граф можно построить
    }

    return 0; // Граф нельзя построить
}
