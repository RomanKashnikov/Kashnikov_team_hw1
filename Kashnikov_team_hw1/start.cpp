#include <iostream>
#include <vector>
#include <string>

#include "graph_gen_by_ordin.h"
#include "kun_by_vasileva.h"


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
    for (auto& row: matrix) {
        cout << endl;
        for (auto& value: row) {
            cout << value << " ";
        }
    }
}


void menu() {
    cout << "Menu" << endl << endl;
    cout << "1 - Generate bipartite graph" << endl << endl;
    cout << "Methods for finding the number of matchings:" << endl;
    cout << "2 - " << endl;
    cout << "3 - " << endl;
    cout << "4 - " << endl;
    cout << "5 - " << endl << endl;
    cout << "0 - Exit" << endl << endl;
}


int main()
{
    int first_set;
    int second_set;

    vector<vector<int>> matrix;
    


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
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
        cout << endl;
        system("pause");
        system("cls");
    }
}
