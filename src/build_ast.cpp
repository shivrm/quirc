extern "C" {
#include "parse_tree.h"
}
#include "ast.hpp"
#include <vector>

std::unique_ptr<Program> convert_program(parse_tree_node *node);
std::unique_ptr<Definition> convert_definition(parse_tree_node *node);
Type convert_type(parse_tree_node *node);
std::vector<std::unique_ptr<Statement>> convert_block(parse_tree_node* func_block);
std::unique_ptr<Statement> convert_stmt(parse_tree_node* stmt_type);
std::unique_ptr<Statement> convert_stmt_conditional(parse_tree_node* cond_stmt);
std::unique_ptr<Expr> convert_expression(parse_tree_node* expr);
std::unique_ptr<Expr> convert_expression_unary(parse_tree_node* expr_type);
enum AssignmentOp OperandToBinaryOp(std::string value);



std::unique_ptr<Program> convert_program(parse_tree_node *node) {
    std::vector<std::unique_ptr<Definition>> nodes;

    auto defn_list = node->children[0];
    for (int i = 0; i < defn_list->num_children; i++) {
        auto child = defn_list->children[i];
        nodes.push_back(convert_definition(child));
    }   

    Program p;
    p.body = std::move(nodes);
    return std::make_unique<Program>(std::move(p));
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
            std::pair<std::string, Type> ast_struct_attribute;
            parse_tree_node* struct_attr_name = struct_attr_list->children[i]->children[0];
            parse_tree_node* struct_attr_type = struct_attr_list->children[i]->children[2]->children[0];

            ast_struct_attribute =  {struct_attr_name->value, convert_type(struct_attr_type)};
            ast_struct_attr_list.push_back(ast_struct_attribute);
        }

        // Fill in the Struct Definition node
        StructDefn s;
        s.name = name;
        s.fields= std::move(ast_struct_attr_list);
        result_node = std::make_unique<StructDefn>(std::move(s));

    } else if (child->value == "function_definition") {
        
        // Get the function name and parameters
        std::string name = child->children[1]->value;
        std::vector<std::pair<std::string, Type>> ast_func_param_list;
        parse_tree_node* func_param_list_opt = child->children[3];

        // If the function has parameters, take them in
        if (func_param_list_opt->num_children != 0) {
            parse_tree_node* func_param_list = func_param_list_opt->children[0];

            for (int i = 0; i < func_param_list->num_children; i++) {
                std::pair<std::string, Type> ast_func_param;
                parse_tree_node* func_param_name = func_param_list->children[i]->children[0];
                parse_tree_node* func_param_type = func_param_list->children[i]->children[2];

                ast_func_param = {func_param_name->value, convert_type(func_param_type)};
                ast_func_param_list.push_back(ast_func_param);
            }
        }

        // Get function return type
        std::optional<Type> ast_return_type;
        if (child->children[5]->num_children != 0) {
            ast_return_type = convert_type(child->children[5]->children[1]);
        }

        // Get the function's internal block of statements
        std::vector<std::unique_ptr<Statement>> ast_func_block = convert_block(child->children[6]);

        FunctionDefn s;
        s.name = name;
        s.args = ast_func_param_list;
        s.return_type = ast_return_type;
        s.body = ast_func_block;
        result_node = std::make_unique<FunctionDefn>(std::move(s));

    } // Todo: variable definition

    return result_node;
}


/*** Helper Functions ***/


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

std::vector<std::unique_ptr<Statement>> convert_block(parse_tree_node* block) {
    std::vector<std::unique_ptr<Statement>> ast_block;

    parse_tree_node* stmt_list = block->children[1];

    for (int i = 0; i < stmt_list->num_children; i++) {
        std::string stmt_type = stmt_list->children[i]->children[0]->value;
    }

    return ast_block;
}

std::unique_ptr<Statement> convert_stmt(parse_tree_node* stmt_type) {
    std::unique_ptr<Statement> ast_stmt;
    
    if (stmt_type->value == "variable_decl_stmt") {
        LetStmt s;
        s.name = stmt_type->children[1]->value;
        if (stmt_type->children[2]->num_children != 0) s.type = convert_type(stmt_type->children[2]->children[0]);
        s.value = convert_expression(stmt_type->children[4]);
        ast_stmt = std::make_unique<LetStmt>(std::move(s));
    } else if (stmt_type->value == "assignment_stmt") {
        AsgnStmt s;
        s.name = stmt_type->children[0]->value;
        s.op = OperandToBinaryOp(stmt_type->children[1]->children[0]->value);
        ast_stmt = std::make_unique<AsgnStmt>(std::move(s));
    } else if (stmt_type->value == "conditional_stmt") {
        /*IfElse s;
        s.condition = convert_expression(stmt_type->children[1]);
        s.body = convert_block(stmt_type->children[2]);
        if (stmt_type->children[3] != NULL) {
            if (stmt_type->children[3]->children[1]->value == "block") s.else_body = convert_block(stmt_type->children[3]->children[1]);
            else {
                parse_tree_node* cond_stmt = stmt_type->children[3]->children[1];
                AsgnStmt r;
                r.name = cond_stmt->children[0]->value;
                r.op = OperandToBinaryOp(cond_stmt->children[1]->children[0]->value);
                s.else_body = std::make_unique<>
            }
        }*/
        ast_stmt = convert_stmt_conditional(stmt_type);
    } else if (stmt_type->value == "while_loop_stmt") {
        WhileLoop s;
        s.condition = convert_expression(stmt_type->children[1]);
        s.body = convert_block(stmt_type->children[2]);
        ast_stmt = std::make_unique<LetStmt>(std::move(s));
    } else if (stmt_type->value == "for_loop_stmt") {
        ForLoop s;
        s.var = stmt_type->children[1]->value;
        s.condition = convert_expression(stmt_type->children[3]);
        s.body = convert_block(stmt_type->children[4]);
        ast_stmt = std::make_unique<LetStmt>(std::move(s));
    } else if (stmt_type->value == "BREAK") {
        BreakStmt s;
        ast_stmt = std::make_unique<LetStmt>(std::move(s));
    } else if (stmt_type->value == "CONTINUE") {
        ContinueStmt s;
        ast_stmt = std::make_unique<LetStmt>(std::move(s));
    } else if (stmt_type->value == "RETURN") {
        ReturnStmt s;
        ast_stmt = std::make_unique<LetStmt>(std::move(s));
    } else {
        // No match (error(?)) (Todo: fill this accordingly)
    }

    return ast_stmt;
}

std::unique_ptr<Statement> convert_stmt_conditional(parse_tree_node* cond_stmt) {
    IfElse s;
    s.condition = convert_expression(cond_stmt->children[1]);
    s.body = convert_block(cond_stmt->children[2]);
    if (cond_stmt->children[3] != NULL) {
        if (cond_stmt->children[3]->children[1]->value == "block") s.else_body = convert_block(cond_stmt->children[3]->children[1]);
        else {
            s.else_body.push_back(convert_stmt_conditional(cond_stmt->children[3]->children[1]));
        }
    }

    std::unique_ptr<Statement> stmt_res = std::make_unique<IfElse>(std::move(s));
    return stmt_res;
}

std::unique_ptr<Expr> convert_expression(parse_tree_node* expr) {
    // Take in "expression"s and convert them accordingly

    if (expr->value == "unary_expression") {
        // Todo: check if this is the correct way to do this
        
        UnaryExpr s;
        s.operand = convert_expression_unary(expr);
        std::unique_ptr<Expr> expr_res = std::make_unique<UnaryExpr>(std::move(s));
        return expr_res;
    }

    BinaryExpr s;   // It could also be the unary operator, but that's just one case
    std::unique_ptr<Expr> expr_res;

    s.left = convert_expression(expr->children[0]);
    s.right = convert_expression(expr->children[2]);

    expr_res = std::make_unique<BinaryExpr>(s);
    return expr_res;
}

std::unique_ptr<Expr> convert_expression_unary(parse_tree_node* expr) {
    // Todo: take in a certain "unary_expression" type, and return that type of expression AST node
    // Check if this is the correct way to do this

    if (expr->value == "postfix_expression") {
        // Todo
    }

    UnaryExpr s;
    s.operand = convert_expression(expr->children[1]);

    if (expr->value == "unary_plus") s.op = PLUS;
    else if (expr->value == "unary_minus") s.op = MINUS;
    else s.op = NOT;

    std::unique_ptr<Expr> expr_res = std::make_unique<UnaryExpr>(std::move(s));
    return expr_res;
}

enum AssignmentOp OperandToBinaryOp(std::string value) {
    // Takes values like "=", "+=", converts then to their respective AssignmentOps
    if (value == "=") return ASSIGN;
    else if (value == "+=") return ADD_EQ;
    else if (value == "-=") return SUB_EQ;
    else if (value == "*=") return MUL_EQ;
    else if (value == "/=") return DIV_EQ;
    else if (value == "%=") return MOD_EQ;
    else if (value == "&=") return BITAND_EQ;
    else if (value == "|=") return BITOR_EQ;
    else if (value == "^=") return BITXOR_EQ;
    else return BITNOT_EQ;   // if "~="
}



extern "C" parse_tree_node *get_parse_tree();
extern "C" int yyparse();

/*int main(void) {
    int result = yyparse();
    parse_tree_node *root = get_parse_tree();
    if (root) {
        print_tree(root);
        free_tree(root);
    }
    return result;
}*/