#include "BSTTree.hpp"
#include "Hashtable.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>   // for remove, rename
using namespace std;

BSTTree::BSTTree() {
    Root = nullptr;
}

// ---------------------- Add Account ----------------------
void BSTTree::add_Account(string name, string adress, int accountno, int password, int balance) {
    h.add(accountno, password);

    ofstream write("server.txt", ios::app);
    write << name << endl << adress << endl << accountno << endl << password << endl << balance << endl;
    write.close();

    BSTNode* temp = new BSTNode(name, adress, accountno, password, balance);

    if (Root == nullptr) {
        Root = temp;
    } else {
        BSTNode* current = Root;
        while (true) {
            if (accountno < current->account_number) {
                if (current->left == nullptr) {
                    current->left = temp;
                    break;
                }
                current = current->left;
            } else if (accountno > current->account_number) {
                if (current->right == nullptr) {
                    current->right = temp;
                    break;
                }
                current = current->right;
            } else {
                break; // account already exists
            }
        }
    }
}

// ---------------------- Delete Account ----------------------
BSTNode* BSTTree::delete_Account(BSTNode* root, int accountno) {
    if (root == nullptr) {
        cout << "Tree is empty or account not found" << endl;
        return nullptr;
    }
    else if (accountno < root->account_number)
        root->left = delete_Account(root->left, accountno);
    else if (accountno > root->account_number)
        root->right = delete_Account(root->right, accountno);
    else {
        if (root->left && root->right) {
            findMax(root->left);
            root->account_number = v.back();
            root->left = delete_Account(root->left, root->account_number);
        } else {
            BSTNode* temp = root;
            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
            delete temp;
        }
    }
    return root;
}

// ---------------------- Update Transaction File ----------------------
void BSTTree::update_transaction(int accountno, int amount) {
    ifstream read("transaction.txt"); // read only
    vector<int> data;
    int line = 0;

    while (read >> line) {
        data.push_back(line);
        if (line == accountno) {
            data.push_back(amount);
        }
    }
    read.close();

    ofstream write("temp.txt");
    for (int val : data) {
        write << val << endl;
    }
    write.close();

    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");
}

// ---------------------- Withdraw ----------------------
void BSTTree::withdraw(int accountno, int amount) {
    load_Server();
    BSTNode* temp = search(Root, accountno);
    if (!temp) {
        cout << "Account not found" << endl;
        return;
    }
    if (temp->balance < amount) {
        cout << "Insufficient balance" << endl;
        return;
    }

    temp->balance -= amount;
    update_transaction(accountno, -amount);
    update_server(Root);
}

// ---------------------- Deposit ----------------------
void BSTTree::deposit(int accountno, int amount) {
    load_Server();
    BSTNode* temp = search(Root, accountno);
    if (!temp) {
        cout << "Account not found" << endl;
        return;
    }

    temp->balance += amount;
    update_transaction(accountno, amount);
    update_server(Root);
}

// ---------------------- Transfer ----------------------
void BSTTree::transfer(int sender_accountno, int receiver_accountno, int sender_amount) {
    load_Server();
    BSTNode* sender = search(Root, sender_accountno);
    BSTNode* receiver = search(Root, receiver_accountno);

    if (!sender || !receiver) {
        cout << "Invalid account number(s)" << endl;
        return;
    }
    if (sender->balance < sender_amount) {
        cout << "Insufficient balance" << endl;
        return;
    }

    sender->balance -= sender_amount;
    receiver->balance += sender_amount;

    update_server(Root);

    update_transaction(sender_accountno, -sender_amount);
    update_transaction(receiver_accountno, sender_amount);
}

// ---------------------- Find Max ----------------------
void BSTTree::findMax(BSTNode* root) {
    if (root) {
        findMax(root->left);
        v.push_back(root->account_number);
        findMax(root->right);
    }
}

// ---------------------- Load Server ----------------------
void BSTTree::load_Server() {
    ifstream read("server.txt"); // just input

    string name, adress;
    int accountno, password, balance;

    while (getline(read, name)) {
        getline(read, adress);
        read >> accountno >> password >> balance;
        read.ignore(); // consume newline

        if (!name.empty() && !adress.empty() && accountno != 0 && password != 0) {
            BSTNode* temp = new BSTNode(name, adress, accountno, password, balance);
            if (Root == nullptr) {
                Root = temp;
            } else {
                BSTNode* current = Root;
                while (true) {
                    if (accountno < current->account_number) {
                        if (current->left == nullptr) {
                            current->left = temp;
                            break;
                        }
                        current = current->left;
                    } else if (accountno > current->account_number) {
                        if (current->right == nullptr) {
                            current->right = temp;
                            break;
                        }
                        current = current->right;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    read.close();
}

// ---------------------- Update Server ----------------------
void BSTTree::update_server(BSTNode* root) {
    static bool cleared = false;
    if (!cleared) {
        remove("server.txt");
        cleared = true;
    }

    if (!root) return;

    update_server(root->left);

    ofstream write("server.txt", ios::app);
    write << root->name << endl;
    write << root->adress << endl;
    write << root->account_number << endl;
    write << root->password << endl;
    write << root->balance << endl;
    write.close();

    update_server(root->right);
}

// ---------------------- Search ----------------------
BSTNode* BSTTree::search(BSTNode* root, int accountno) {
    if (!root) return nullptr;
    if (accountno < root->account_number)
        return search(root->left, accountno);
    else if (accountno > root->account_number)
        return search(root->right, accountno);
    return root;
}

// ---------------------- Print Info ----------------------
void BSTTree::printoinfo(BSTNode* root) {
    if (root) {
        printoinfo(root->left);
        cout << root->name << endl;
        cout << root->adress << endl;
        cout << root->account_number << endl;
        cout << root->password << endl;
        cout << root->balance << endl;
        printoinfo(root->right);
    }
}
