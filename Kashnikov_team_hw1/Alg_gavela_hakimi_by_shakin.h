#ifndef ALG_GAVELA_HAKIMI_BY_SHAKIN_H
#define ALG_GAVELA_HAKIMI_BY_SHAKIN_H

#include <vector>

// Функция проверки, является ли последовательность графической
bool isGraphicalSequence(std::vector<int>& sequence);

// Функция проверки, можно ли построить двудольный граф
bool isBipartiteGraphical(std::vector<int> leftDegrees, std::vector<int> rightDegrees);

#endif // ALG_GAVELA_HAKIMI_BY_SHAKIN_H
