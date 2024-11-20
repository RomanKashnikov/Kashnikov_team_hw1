#include <iostream>

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


int main()
{
    while (1) {
        menu();

        int option;
        option = input_validation<int>("Choose the option:  ", 0, 7);
    }
}
