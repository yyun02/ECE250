#include <iostream>
#include "calculator.h"
using namespace std;

int main()
{
    LinkedList* list = nullptr;

    string cmd;
    string name;
    string name2;
    string name3;
    int capacity;
    double val;

    while (cin >> cmd) {
        if (cmd == "CRT") {
            cin >> capacity;
            list = new LinkedList(capacity);
            cout << "success" << endl;
        }
        else if (cmd == "DEF") {
            cin >> name;
            cin >> val;
            if (list->def(name, val) == false) {
                cout << "failure" << endl;
            }
            else {
                cout << "success" << endl;
            }
        }
        else if (cmd == "ADD") {
            cin >> name >> name2 >> name3;
            if (list->add(name, name2, name3) == true) {
                cout << "success" << endl;
            }
            else {
                cout << "failure" << endl;
            }

        }
        else if (cmd == "SUB") {
            cin >> name >> name2 >> name3;
            if (list->sub(name, name2, name3) == true) {
                cout << "success" << endl;
            }
            else {
                cout << "failure" << endl;
            }

        }
        else if (cmd == "REM") {
            cin >> name;
            if (list->rem(name) == true) {
                cout << "success" << endl;
            }
            else {
                cout << "failure" << endl;
            }

        }
        else if (cmd == "PRT") {
            cin >> name;
            list->prt(name);
        }
        else if (cmd == "END") {
            break;
        }
    }
    delete list;
    list = nullptr;
    return 0;
}
