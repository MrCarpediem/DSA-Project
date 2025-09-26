// BSTNode.hpp
#pragma once
#include <string>

class BSTNode {
public:
    std::string name;
    std::string adress;   // (spelling repo me "adress" hi tha, agar "address" karna ho to dono jagah change karna padega)
    int account_number;
    int password;
    int balance;
    BSTNode* left;
    BSTNode* right;

    BSTNode();
    BSTNode(std::string name, std::string adress, int accountno, int password, int balance);
};
