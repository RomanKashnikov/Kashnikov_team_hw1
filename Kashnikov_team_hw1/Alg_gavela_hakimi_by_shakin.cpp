#include "Alg_gavela_hakimi_by_shakin.h"
#include <algorithm>
#include <numeric>
#include <iostream>

// Функция проверки, является ли последовательность графической
bool isGraphicalSequence(std::vector<int>& sequence) {
    // Удаляем все нули
    sequence.erase(std::remove(sequence.begin(), sequence.end(), 0), sequence.end());

    // Сортируем по убыванию
    std::sort(sequence.rbegin(), sequence.rend());

    while (!sequence.empty()) {
        // Берем первый элемент (максимальную степень)
        int d = sequence[0];
        sequence.erase(sequence.begin());

        if (d < 0 || d >= static_cast<int>(sequence.size())) {
            return false;
        }

        // Уменьшаем первые d элементов на 1
        for (int i = 0; i < d; ++i) {
            sequence[i]--;
            if (sequence[i] < 0) {
                return false;
            }
        }

        // Удаляем нули и сортируем
        sequence.erase(std::remove(sequence.begin(), sequence.end(), 0), sequence.end());
        std::sort(sequence.rbegin(), sequence.rend());
    }
    return true;
}

// Функция проверки, можно ли построить двудольный граф
bool isBipartiteGraphical(std::vector<int> leftDegrees, std::vector<int> rightDegrees) {
    // Сумма степеней левого и правого множества должна совпадать
    int leftSum = std::accumulate(leftDegrees.begin(), leftDegrees.end(), 0);
    int rightSum = std::accumulate(rightDegrees.begin(), rightDegrees.end(), 0);

    if (leftSum != rightSum) {
        return false;
    }

    // Проверяем каждую последовательность на графичность
    if (!isGraphicalSequence(leftDegrees) || !isGraphicalSequence(rightDegrees)) {
        return false;
    }

    return true;
}

int main() {
    // Пример последовательностей
    std::vector<int> leftDegrees = { 3, 2, 2, 1 };
    std::vector<int> rightDegrees = { 2, 2, 2, 2 };

    if (isBipartiteGraphical(leftDegrees, rightDegrees)) {
        std::cout << "Двудольный граф возможен!\n";
    }
    else {
        std::cout << "Двудольный граф невозможен.\n";
    }

    return 0;
}
