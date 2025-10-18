#include <parse_tree.h>
#include "ast.hpp"
#include <vector>

std::unique_ptr<Program> convert_program(parse_tree_node *node) {
    std::vector<std::unique_ptr<Definition>> nodes;

    auto defn_list = node->children[0];
    for (int i = 0; i < defn_list->num_children; i++) {
        auto child = defn_list->children[i];
        nodes.push_back(convert_definition(child));
    }   

    return Program(nodes);
}

std::unique_ptr<Definition> convert_definition(parse_tree_node *node) {

}