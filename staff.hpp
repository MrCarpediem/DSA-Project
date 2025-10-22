#pragma once
#include "BSTTree.hpp"
#include "Hashtable.hpp"
#include <fstream>
#include <iostream>
using namespace std;

void staff()
{
    BSTTree t;
    Hashtable h;
    int condition = 0;

    while (condition != 5)
    {
        cout << "welcome STAFF" << endl;
        cout << "choose the following please" << endl;
        cout << "press 1 to see transaction history" << endl;
        cout << "press 2 to transfer" << endl;
        cout << "press 3 to withdraw" << endl;
        cout << "press 4 to deposit" << endl;
        cout << "press 5 to exit" << endl;
        cin >> condition;

        if (condition == 1)
        {
            ifstream read("transaction.txt");
            if (!read) {
                cout << "No transactions found!" << endl;
            } else {
                cout << "--- Transaction History ---" << endl;
                int acc, amt;
                while (read >> acc >> amt) {
                    cout << "Account: " << acc 
                         << " | Amount: " << amt << endl;
                }
            }
            read.close();
        }
        else if (condition == 2)
        {
            int senderaccountno = 0, amount = 0, recieveraccountno = 0;
            cout << "please enter sender account number" << endl;
            cin >> senderaccountno;
            cout << "please enter receiver account number" << endl;
            cin >> recieveraccountno;
            cout << "please enter amount" << endl;
            cin >> amount;
            t.transfer(senderaccountno, recieveraccountno, amount);
            cout << "Transfer successful!" << endl;
        }
        else if (condition == 3)  // withdraw
        {
            int accountno = 0, amount = 0;
            cout << "please enter account number" << endl;
            cin >> accountno;
            cout << "please enter amount" << endl;
            cin >> amount;
            t.withdraw(accountno, amount);
            cout << "Withdrawal successful!" << endl;
        }
        else if (condition == 4)  // deposit
        {
            int accountno = 0, amount = 0;
            cout << "please enter account number" << endl;
            cin >> accountno;
            cout << "please enter amount" << endl;
            cin >> amount;
            t.deposit(accountno, amount);
            cout << "Deposit successful!" << endl;
        }
        else if (condition == 5)
        {
            cout << "Exiting staff menu..." << endl;
        }
        else
        {
            cout << "Invalid option!" << endl;
        }
    }
}
