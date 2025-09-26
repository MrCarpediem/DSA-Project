#pragma once

#include <iostream>
#include <string>
#include "BSTTree.hpp"
#include "Hashtable.hpp"

using namespace std;

void customer()
{
    BSTTree t;
    Hashtable h;
    int condition = 0;

    while (condition != 3)
    {
        cout << "\nWelcome CUSTOMER" << endl;
        cout << "Choose one of the following options:" << endl;
        cout << "1. See account details" << endl;
        cout << "2. See transaction history" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> condition;

        if (condition == 1)
        {
            int accountno;
            cout << "\nPlease enter your account number: ";
            cin >> accountno;

            // Load data from file before searching
            t.load_Server();

            BSTNode* temp = t.search(t.Root, accountno);

            if (temp != nullptr)
            {
                cout << "\n===== Account Details =====\n";
                cout << "Name: " << temp->name << endl;
                cout << "Address: " << temp->adress << endl;
                cout << "Account Number: " << temp->account_number << endl;
                cout << "Password: " << temp->password << endl;
                cout << "Balance: " << temp->balance << endl;
            }
            else
            {
                cout << "\nAccount not found!\n";
            }
        }
        else if (condition == 2)
        {
            cout << "\nFeature: Transaction history will be displayed here (TODO)\n";
            // You can later add a function like: t.show_transaction_history(accountno);
        }
        else if (condition == 3)
        {
            cout << "\nExiting customer portal...\n";
        }
        else
        {
            cout << "\nInvalid option! Please try again.\n";
        }
    }
}
