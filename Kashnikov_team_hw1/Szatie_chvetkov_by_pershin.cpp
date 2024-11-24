#include <vector>
#include <string>

using namespace std;



//vector<vector<int>> m = { массив над которым работал
//	{0,0,0,1,1,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{1,0,0,0,0,0},{1,1,0,0,0,0},{0,0,1,0,0,0} 
//};


void opr_vector(const vector<vector<int>>& m, vector<vector<int>>& mas_vector) {
	for (int i = 0; i < size(m); i++) { // определение размера массива
		for (int j = 0; j < size(m[0]); j++) {
			if (i < j) {
				if (m[i][j] == 1) {
					mas_vector.push_back({ i + 1, j + 1 });
				}
			}
		}
	}
}

void opr_edinich(vector<vector<int>>& mas_vector, int& edinich) {
	int diapozon = 0;
	for (vector<int> m1 : mas_vector) {
		int counter = 0;
		for (vector<int> m : mas_vector) {
			if (m1[0] == m[0] && m1[1] == m[1]) continue;
			if (m1[0] == m[0] || m1[1] == m[1]) counter++;
		}
		if (counter == 0) {
			edinich++;
			mas_vector.erase(mas_vector.begin() + diapozon);
		}
		diapozon++;
	}
}


void delete_incsid(vector<vector<int>>& mas_vector, const vector<int>& rebro) {
	int counter = 0;
	for (vector<int> mas : mas_vector) {
		if (mas[0] == rebro[0] || mas[1] == rebro[1]) {
			mas_vector.erase(mas_vector.begin() + counter);
		}
		counter++;
	}
}


void postroenie_parosoch(vector<vector<int>>& mas_vector, vector<vector<int>>& parosoch) {
	for (vector<int> mas : mas_vector) {
		parosoch.push_back(mas);
		delete_incsid(mas_vector, mas);
	}
}


int Szatie_chvetkov_by_pershin(const vector<vector<int>>& m) {
	vector<vector<int>> mas_vector; // количество ребер в массиве и какие они
	opr_vector(m, mas_vector);
	int edinich = 0;
	opr_edinich(mas_vector, edinich); // определение "единичных" ребер , которые не будут учавствовать 

	vector<int> start = mas_vector[0]; // начало цепи
	vector <vector<int>> parosoch;
	parosoch.push_back(start);
	mas_vector.erase(mas_vector.begin());
	delete_incsid(mas_vector, parosoch[0]);
	postroenie_parosoch(mas_vector, parosoch);


	int end = size(parosoch);

	/*for (vector<int> m : mas_vector) {
		for (int i : m) {
			cout << i << endl;
		}
	}*/
	return edinich + end;
}