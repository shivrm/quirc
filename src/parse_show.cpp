extern "C" {
#include "parse_tree.h"
}

//#include "ast.hpp"
#include <vector>
#include "build_ast.cpp"

extern "C" parse_tree_node *get_parse_tree();
extern "C" int yyparse();

int main(void) {
    int result = yyparse();
    parse_tree_node *root = get_parse_tree();
    if (root) {
        print_tree(root);
        free_tree(root);
    }
    return result;
}