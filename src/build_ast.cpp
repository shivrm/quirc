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

    std::unique_ptr<Program> program;
    program->body=nodes;

    return program;
}

std::unique_ptr<Definition> convert_definition(parse_tree_node *node) {
    std::string node_type  = node->value;
    std::unique_ptr<Definition> result_node;

    parse_tree_node* child = node->children[0];
    
    if (child->value == "struct_definition") {
        // Get the struct's name and all its attributes
        std::string name = child->children[1]->value;
        std::vector<std::pair<std::string, Type>> ast_struct_attr_list;
        parse_tree_node* struct_attr_list = child->children[3];

        for (int i = 0; i < struct_attr_list->num_children; i++) {
            std::pair<std::string, Type> struct_attribute;
            parse_tree_node* struct_attr_name = struct_attr_list->children[i]->children[0];
            parse_tree_node* struct_attr_type = struct_attr_list->children[i]->children[2]->children[0];

            struct_attribute =  {struct_attr_name->value, convert_type(struct_attr_type)};
            ast_struct_attr_list.push_back(struct_attribute);
        }
        
        result_node = std::make_unique<StructDefn>(name, ast_struct_attr_list);
    } else if (child->value == "function_definition") {
        std::string name = child->children[1]->value;
        std::vector<std::pair<std::string, Type>> ast_func_param_list;
        parse_tree_node* func_param_list_opt = child->children[3];

        // If the function has parameters, take them in
        if (func_param_list_opt->num_children != 0) {
            parse_tree_node* func_param_list = func_param_list_opt->children[0];

            for (int i = 0; i < func_param_list->num_children; i++) {
                std::pair<std::string, Type> func_param;
                // TODO: complete this function_definition block
            }
        }
    }

    return result_node;
}

Type convert_type(parse_tree_node *node) {
    if (strcmp(node->children[0]->value, "[") == 0) {
        ArrayType type = {
            .element_type = std::make_unique<Type>(convert_type(node->children[1]))
        };
        return type;
    } else {
        AtomType type = {
            .name = std::string(node->children[0]->value)
        };
        return type;
    }
}