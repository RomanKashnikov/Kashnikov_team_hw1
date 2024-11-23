#include <iostream>
#include <vector>
#include <string>

#include "graph_gen_by_ordin.h"
#include "kun_by_vasileva.h"
#include "hopcrofta_carpa_by_Saitov.h"
#include "Szatie_chvetkov_by_pershin.h"
#include "Alg_gavela_hakimi_by_shakin.h"



using namespace std;


int input_validation(const string& message, const int& min, const int& max) {
    int value;

    cout << message;
    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min || value > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Try another value:  ";
    }
    cin.clear();
    cin.ignore(10000, '\n');
    return value;
}


void vivod(vector<vector<int>> &matrix) {
    cout << "Adjacency matrix:" << endl;
    for (auto& row: matrix) {
        for (auto& value: row) {
            cout << value << " ";
        }
        cout << endl;
    }
}


void menu() {
    cout << "Menu" << endl << endl;
    cout << "1 - Generate bipartite graph" << endl << endl;
    cout << "Methods for finding the number of matchings:" << endl;
    cout << "2 - Kun" << endl;
    cout << "3 - Hopcrofta Carpa" << endl;
    cout << "4 - Gavela Hakimi" << endl;
    cout << "5 - Szatie chvetkov" << endl << endl;
    cout << "0 - Exit" << endl << endl;
}


int main()
{
    int first_set;
    int second_set;

    vector<vector<int>> matrix;
    
    vector<vector<int>> test_matrix = vector<vector<0, 0, 1, 1, 0, 0>,
                                             vector<0, 0, 0, 1, 1, 1>,
                                             vector<1, 0, 0, 0, 0, 0>,
                                             vector<1, 1, 0, 0, 0, 0>,
                                             vector<0, 1, 0, 0, 0, 0>,
                                             vector<0, 1, 0, 0, 0, 0>>

    while (1) {
        menu();

        int option;
        option = input_validation("Choose the option:  ", 0, 5);
        system("cls");

        switch (option) {
        case 0:
            cout << "App is closed" << endl;
            return 0;
        case 1:
            cout << "Enter amount of peaks" << endl << endl;

            first_set = input_validation("In first set:  ", 0, 10000000);
            second_set = input_validation("In second set:  ", 0, 10000000);

            matrix = generateBipartiteGraphMatrix(first_set, second_set);

            vivod(matrix);
            break;
        case 2:
            //cout << "Your value: " << kun_by_vasileva(test_matrix) << endl;
            cout << endl << "True value: 4" << endl;
            break;
        case 3:
            //cout << "Your value: " << hopcrofta_carpa_by_Saitov(test_matrix) << endl;
            cout << endl << "True value: 4" << endl;
            break;
        case 4:
            //cout << "Your value: " << Alg_gavela_hakimi_by_shakin(test_matrix) << endl;
            cout << endl << "True value: 4" << endl;
            break;
        case 5:
            //cout << "Your value: " << Szatie_chvetkov_by_pershin(test_matrix) << endl;
            cout << endl << "True value: 4" << endl;
            break;
        }
        cout << endl;
        system("pause");
        system("cls");
    }
}
