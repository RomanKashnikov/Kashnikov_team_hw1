#include "Alg_gavela_hakimi_by_shakin.h"
#include <algorithm>
#include <numeric>
#include <iostream>

// ������� ��������, �������� �� ������������������ �����������
bool isGraphicalSequence(std::vector<int>& sequence) {
    // ������� ��� ����
    sequence.erase(std::remove(sequence.begin(), sequence.end(), 0), sequence.end());

    // ��������� �� ��������
    std::sort(sequence.rbegin(), sequence.rend());

    while (!sequence.empty()) {
        // ����� ������ ������� (������������ �������)
        int d = sequence[0];
        sequence.erase(sequence.begin());

        if (d < 0 || d >= static_cast<int>(sequence.size())) {
            return false;
        }

        // ��������� ������ d ��������� �� 1
        for (int i = 0; i < d; ++i) {
            sequence[i]--;
            if (sequence[i] < 0) {
                return false;
            }
        }

        // ������� ���� � ���������
        sequence.erase(std::remove(sequence.begin(), sequence.end(), 0), sequence.end());
        std::sort(sequence.rbegin(), sequence.rend());
    }
    return true;
}

// ������� ��������, ����� �� ��������� ���������� ����
bool isBipartiteGraphical(std::vector<int> leftDegrees, std::vector<int> rightDegrees) {
    // ����� �������� ������ � ������� ��������� ������ ���������
    int leftSum = std::accumulate(leftDegrees.begin(), leftDegrees.end(), 0);
    int rightSum = std::accumulate(rightDegrees.begin(), rightDegrees.end(), 0);

    if (leftSum != rightSum) {
        return false;
    }

    // ��������� ������ ������������������ �� �����������
    if (!isGraphicalSequence(leftDegrees) || !isGraphicalSequence(rightDegrees)) {
        return false;
    }

    return true;
}

int main() {
    // ������ �������������������
    std::vector<int> leftDegrees = { 3, 2, 2, 1 };
    std::vector<int> rightDegrees = { 2, 2, 2, 2 };

    if (isBipartiteGraphical(leftDegrees, rightDegrees)) {
        std::cout << "���������� ���� ��������!\n";
    }
    else {
        std::cout << "���������� ���� ����������.\n";
    }

    return 0;
}
