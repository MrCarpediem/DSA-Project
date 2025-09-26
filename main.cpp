#include <iostream>
#include <string>
#include "Hashtable.hpp"
#include "BSTTree.hpp"
#include "admin.hpp"
#include "staff.hpp"
#include "customer.hpp"
using namespace std;

void boot() {
    Hashtable H;  // pass table size
    BSTTree T;
    H.starthash();
    T.load_Server();
}

int main() {
    boot();  // actually call boot()

    int condition = 0;
    while (condition != 4) {
        cout << "YOU want to login as:" << endl << endl;
        cout << "1 - ADMIN" << endl;
        cout << "2 - STAFF" << endl;
        cout << "3 - CUSTOMER" << endl;
        cout << "4 - EXIT" << endl;
        cin >> condition;

        if (condition == 1) {
            admin();
        }
        if (condition == 2) {
            staff();
        }
        if (condition == 3) {
            customer();
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}
