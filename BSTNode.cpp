#include "BSTNode.hpp"

BSTNode::BSTNode() {
    left = nullptr;
    right = nullptr;
    name = "";
    adress = "";
    account_number = 0;
    password = 0;
    balance = 0;
}

BSTNode::BSTNode(std::string name, std::string adress, int accountno, int password, int balance) {
    left = nullptr;
    right = nullptr;
    this->name = name;
    this->account_number = accountno;
    this->adress = adress;
    this->balance = balance;
    this->password = password;
}
