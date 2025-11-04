extern "C" {
#include "parse_tree.h"
}

//#include "ast.hpp"
#include <vector>
#include "build_ast.cpp"
#include <iostream>

extern "C" parse_tree_node *get_parse_tree();
extern "C" int yyparse();

int main(void) {
    int result = yyparse();
    parse_tree_node *root = get_parse_tree();
    if (root) {
        print_tree(root);
        auto ast = convert_program(root);
        PrintVisitor printer(std::cout);
        ast->accept(printer);
        free_tree(root);
    }
    return result;
}