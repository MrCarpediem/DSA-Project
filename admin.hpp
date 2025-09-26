#pragma once
#include <iostream>
#include <string>
#include "BSTTree.hpp"
#include "Hashtable.hpp"

using namespace std;

void admin()
{
    BSTTree t;
    Hashtable h;
    int condition = 0;

    while (condition != 6)
    {
        cout << "Welcome ADMIN" << endl;
        cout << "Choose one of the following options:" << endl;
        cout << "1. Add account" << endl;
        cout << "2. Delete account" << endl;
        cout << "3. View all accounts" << endl;
        cout << "4. View passwords" << endl;
        cout << "5. Edit account" << endl;
        cout << "6. Exit" << endl;

        cin >> condition;

        if (condition == 1)
        {
            string name, address;
            int acc, pass, balance;

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter address: ";
            cin >> address;
            cout << "Enter account number: ";
            cin >> acc;
            cout << "Enter password: ";
            cin >> pass;
            cout << "Enter balance: ";
            cin >> balance;

            t.add_Account(name, address, acc, pass, balance);
        }
        else if (condition == 2)
        {
            int acc = 0;
            cout << "Enter account number: ";
            cin >> acc;

            t.load_Server();
            t.Root = t.delete_Account(t.Root, acc);
            h.delete_password(acc);
            t.update_server(t.Root);

            cout << "Account deleted successfully!" << endl;
        }
        else if (condition == 3)
        {
            t.load_Server();
            t.printoinfo(t.Root);
        }
        else if (condition == 4)
        {
            h.displayPasswords();
        }
        else if (condition == 5)
        {
            cout << "Edit feature coming soon..." << endl;
        }
        else if (condition == 6)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice! Try again." << endl;
        }
    }
}
