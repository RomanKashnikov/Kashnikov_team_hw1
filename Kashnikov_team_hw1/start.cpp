#include <iostream>
#include <vector>

#include "graph_gen_by_ordin.h"

#include "kun_by_vasileva.h"


using namespace std;


template <typename T>
T input_validation(const string message, const int min, const int max) {
    T value;

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
    cerr << value << endl;
    return value;
}


void vivod(vector<vector<int> > &matrix ) {
    for (int u = 0; u < n1; ++u) {
        cout << endl;
        for (int v = 0; v < n2; ++v) {
            cout << matrix[u][v] << " ";
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
    cout << "5 - " << endl;
    cout << "0 - Exit" << endl << endl;
}

    cout << ""
}


int main()
{
    int first_set;
    int second_set;




    while (1) {
        menu();

        int option;
        option = input_validation<int>("Choose the option:  ", 0, 5);
        system("cls");

        switch (option) {
        case 0:
            cout << "App is closed" << endl;
            return 0;
        case 1:
            cout << "Enter amount of peaks" << endl << endl;
            first_set = input_validation<int>("In first set:  ", 0, 10000000);
            second_set = input_validation<int>("In second set:  ", 0, 10000000);
            generateBipartiteGraphMatrix(first_set, second_set);
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
