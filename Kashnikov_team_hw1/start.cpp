#include <iostream>
#include <vector>
#include <string>

#include "time.h"
#include "graph_gen_by_ordin.h"
#include "kun_by_vasileva.h"
#include "hopcrofta_carpa_by_Saitov.h"
#include "Szatie_chvetkov_by_pershin.h"
#include "Alg_gavela_hakimi_by_shakin.h"
#include "Alg_ford_fulkerson_by_shakin.h"



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
    cout << endl << "Adjacency matrix:" << endl;
    for (auto& row: matrix) {
        for (auto& value: row) {
            cout << value << " ";
        }
        cout << endl;
    }
}


void menu() {
    cout << "Menu" << endl << endl;
    cout << "1 - Generate bipartite graph" << endl;
    cout << "2 - Existence check by method Gavela Hakimi" << endl;
    cout << "3 - Veiw adjacency matrix" << endl << endl;
    cout << "Methods for finding the number of matchings:" << endl;
    cout << "4 - Kun" << endl;
    cout << "5 - Hopcrofta Carpa" << endl;
    cout << "6 - Ford Fulkerson" << endl;
    cout << "7 - Szatie chvetkov" << endl << endl;
    cout << "0 - Exit" << endl << endl;
}


int main()
{
    int left_half;
    int right_half;

    vector<vector<int>> matrix;
    /*
    vector<vector<int>> test_1 = { {0, 0, 0, 1, 1, 0},
                                   {0, 0, 0, 0, 1, 0},
                                   {0, 0, 0, 0, 0, 1},
                                   {1, 0, 0, 0, 0, 0},
                                   {1, 1, 0, 0, 0, 0},
                                   {0, 0, 1, 0, 0, 0} };

    vector<vector<int>> test_2 = { {0, 0, 0, 1, 0, 0, 0},
                                   {0, 0, 0, 1, 0, 0, 0},
                                   {0, 0, 0, 1, 1, 1, 1},
                                   {1, 1, 1, 0, 0, 0, 0},
                                   {0, 0, 1, 0, 0, 0, 0},
                                   {0, 0, 1, 0, 0, 0, 0},
                                   {0, 0, 1, 0, 0, 0, 0} };

    vector<vector<int>> test_3 = { {0, 0, 1, 1, 0, 1},
                                   {0, 0, 0, 1, 1, 0},
                                   {1, 0, 0, 0, 0, 0},
                                   {1, 1, 0, 0, 0, 0},
                                   {0, 1, 0, 0, 0, 0},
                                   {1, 0, 0, 0, 0, 0} };
    */
    
    while (1) {
        menu();

        int option;
        option = input_validation("Choose the option:  ", 0, 7);
        system("cls");

        switch (option) {
        case 0:
            cout << "App is closed" << endl;
            return 0;
        case 1:
            cout << "Enter amount of peaks" << endl << endl;

            left_half = input_validation("In first set:  ", 0, 10000000);
            right_half = input_validation("In second set:  ", 0, 10000000);

            matrix = generateBipartiteGraphMatrix(left_half, right_half);
            break;
        }
        if (Alg_gavela_hakimi_by_shakin(matrix)) {
            switch (option) {
            case 2:
                cout << "Time:  " << time("Existence check (1-Yes/0-No):  ", matrix, Alg_gavela_hakimi_by_shakin) * 1000 << " ms" << endl;
                break;
            case 3:
                vivod(matrix);
                break;
            case 4:
                cout << "Time:  " << time("Max matching:  ", matrix, kun_by_vasileva) * 1000 << " ms" << endl;
                break;
            case 5:
                cout << "Time:  " << time("Max matching:  ", matrix, hopcrofta_carpa_by_Saitov) * 1000 << " ms" << endl;
                break;
            case 6:
                cout << "Time:  " << time("Max matching:  ", matrix, Alg_ford_fulkerson_by_shakin) * 1000 << " ms" << endl;
                break;
            case 7:
                cout << "Time:  " << time("Max matching:  ", matrix, Szatie_chvetkov_by_pershin) * 1000 << " ms" << endl;
                break;
            }
        }
        else {
            cout << "Matrix was not created" << endl << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
    }
}
