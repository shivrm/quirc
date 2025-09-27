#pragma once // to ensure that this header is included only once per file

#include <string>
#include <vector>
#include <iostream>

class parse_tree_node {
public:
    std::string value; //actual label 
    std::vector<parse_tree_node*> children;

    parse_tree_node(const std::string& val) : value(val) {}

    ~parse_tree_node() {
        for (auto child : children) {
            delete child;
        }
    }

    void add_child(parse_tree_node* child) 
    {
        children.push_back(child);
    }

    void print(int depth = 0) 
    {
        for (int i = 0; i < depth; i++) std::cout << "  ";
        std::cout << value << "\n";
        for (auto child : children) {
            child->print(depth + 1);
        }
    }
};
