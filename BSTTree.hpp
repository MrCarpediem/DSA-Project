#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "BSTNode.hpp"
#include "Hashtable.hpp"

using namespace std;

class BSTTree {
    vector<int> v;  // used in findMax
public:
    BSTTree();
    Hashtable h;
    BSTNode* Root = nullptr;

    // Function declarations
    void add_Account(string name, string address, int accountno, int password, int balance);
    BSTNode* delete_Account(BSTNode* root, int accountno);
    void withdraw(int accountno, int amount);
    void deposit(int accountno, int amount);
    void editaccount_byAdmin();
    void transfer(int sender_accountno, int receiver_accountno, int sender_amount);
    void transaction_history();
    void findMax(BSTNode* root);
    void load_Server();
    void update_server(BSTNode* root);
    BSTNode* search(BSTNode* root, int accountno);
    void printoinfo(BSTNode* root);

    //line add
    void update_transaction(int accountno, int amount);
};
