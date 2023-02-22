#include <iostream>
#include "open.h"
#include "ordered.h"
using namespace std;

int main()
{

    string cmd;
    int N = 0;
    int P = 0;
    int PID = 0;
    int ADDR = 0;
    int x = 0;
    int m = 0;
    string mode;
    int hashMode{ 0 };
    while (cin >> mode) {
        if (mode == "OPEN") {
            hashMode = 0;
        }
        else if (mode == "ORDERED") {
            hashMode = 1;
        }
        break;
    }
    while (cin >> cmd) {
        if (hashMode ==0) {
            Open* table;
            if (cmd == "M") {
                cin >> N;
                cin >> P;
                table = new Open(N, P);
                cout << "success" << endl;
            }
            else if (cmd == "INSERT") {
                cin >> PID;
                if (table->insert(PID) == false) {
                    cout << "failure" << endl;
                }
                else {
                    cout << "success" << endl;
                }
            }
            else if (cmd == "SEARCH") {
                cin >> PID;
                if (table->search(PID) == -1) {
                    cout << "not found" << endl;
                }
                else {
                    cout << "found " << PID << " in " << table->search(PID) << endl;
                }
            }
            else if (cmd == "WRITE") {
                cin >> PID;
                cin >> ADDR;
                cin >> x;
                if (table->write(PID, ADDR, x) == false) {
                    cout << "failure" << endl;
                }
                else {
                    cout << "success" << endl;
                }
            }
            else if (cmd == "READ") {
                cin >> PID;
                cin >> ADDR;
                    table->read(PID, ADDR);
            }
            else if (cmd == "DELETE") {
                cin >> PID;
                if (table->delet(PID) == false) {
                    cout << "failure" << endl;
                }
                else {
                    cout << "success" << endl;
                }
            }
            else if (cmd == "END") {
                delete table;
                break;
            }
        }
        else if (hashMode == 1) {
            Ordered* hash;
            if (cmd == "M") {
                cin >> N;
                cin >> P;
                hash = new Ordered(N, P);
                cout << "success" << endl;
            }
            else if (cmd == "INSERT") {
                cin >> PID;
                if (hash->insert(PID) == false) {
                    cout << "failure" << endl;
                }
                else {
                    cout << "success" << endl;
                }
            }
            else if (cmd == "SEARCH") {
                cin >> PID;
                if (hash->search(PID) == -1) {
                    cout << "not found" << endl;
                }
                else {
                    cout << "found " << PID << " in " << hash->search(PID) << endl;
                }
            }
            else if (cmd == "WRITE") {
                cin >> PID;
                cin >> ADDR;
                cin >> x;
                if (hash->write(PID, ADDR, x) == false) {
                    cout << "failure" << endl;
                }
                else {
                    cout << "success" << endl;
                }
            }
            else if (cmd == "READ") {
                cin >> PID;
                cin >> ADDR;
                hash->read(PID, ADDR);
            }
            else if (cmd == "DELETE") {
                cin >> PID;
                if (hash->delet(PID) == false) {
                    cout << "failure" << endl;
                }
                else {
                    cout << "success" << endl;
                }
            }
            else if (cmd == "PRINT") {
                cin >> m;
                hash->print(m);

            }
            else if (cmd == "END") {
                delete hash;
                break;
            }
        }
    }

 
    return 0;
}