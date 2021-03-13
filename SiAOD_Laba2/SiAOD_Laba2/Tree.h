#pragma once
#include <iostream>
#include <vector>
#include <string>

class Tree {
private:
    struct Node;
public:
    ~Tree();
    void push(std::string& key, int data);
    void print_tree(std::vector<int>& vec);
    bool check_tree_rec();
    bool check_tree_no_rec();
private:
    Node* move_on_tree(std::string& key);
    void create_leaf_tree(Node* currentElement, std::string& key, int data);

    void check_tree_rec(Node* currentElement, bool& flag, int& data);
    void check_tree_no_rec(Node* currentElement, std::vector<int>& vec);

    void delete_tree(Node* currentElement);

    struct Node {
        int _data;
        Node* _pRight = nullptr;
        Node* _pLeft = nullptr;
    };
    Node* _head = nullptr;
};