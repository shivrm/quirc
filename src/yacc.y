%language "c++"       /* tell bison to use C++ mode */
%require "3.2"
%skeleton "lalr1.cc"

%define api.namespace {yy}
%define api.token.constructor
%define api.value.type variant

%define parse.error verbose

%define api.prefix {yy}   // optional, good to avoid naming conflicts

%{
#include <iostream>
#include <fstream>
#include <string>
#include "parse_tree.hpp"
%}

%code requires {
#include <string>
#include "parse_tree.hpp"
}

// tells bison that the scanner is external
%code {
yy::parser::symbol_type yylex(yy::parser::semantic_type* yylval,
                              yy::parser::location_type* yylloc);
}

%locations

/* Operator precedence */
%left OR                // lowest precedence
%left AND
%left BITOR
%left BITXOR
%left BITAND
%nonassoc EQ NEQ        // comparison operators
%nonassoc LT LE GT GE
%left SHL SHR
%left PLUS MINUS
%left MUL DIV MOD
%right NOT UPLUS UMINUS  // unary operators
%left POSTFIX

/* Keywords and symbols */
%token STRUCT FN LET IF ELSE WHILE FOR IN BREAK CONTINUE RETURN
%token NEWLINE

%token ASSIGN ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ
%token BITAND_EQ BITOR_EQ BITXOR_EQ BITNOT_EQ
%token SHR_EQ SHL_EQ
%token BITAND BITOR BITXOR BITNOT

%token EQ NEQ LT LE GT GE

%token COMMA COLON SEMI ARROW

%token LPAREN RPAREN
%token LBRACKET RBRACKET
%token LBRACE RBRACE   /* { } */
%token DOT

/* Token types for semantic values */
%token <int> INT_LITERAL
%token <double> FLOAT_LITERAL
%token <std::string> STRING_LITERAL
%token <std::string> IDENT

/* Nonterminals producing parse_tree_node* */
%type <parse_tree_node*> 
    program
    declaration_list
    declaration
    struct_definition
    struct_field_list
    struct_field
    function_definition
    parameter_list_optional
    parameter_list
    parameter
    return_type_optional
    variable_definition
    block
    statement_list
    statement
    variable_decl_stmt
    assignment_stmt
    assignment_op
    conditional_stmt
    else_clause_optional
    while_loop_stmt
    for_loop_stmt
    break_stmt
    continue_stmt
    return_stmt
    expression_optional
    expression
    unary_expression
    postfix_expression
    primary_expression
    literal
    argument_list_optional
    argument_list
    type_optional
    type
    array_size_optional
    numeric

%%
program
    : declaration_list {
        $$ = new parse_tree_node("program");
        $$->add_child($1);
    }
    ;

declaration_list
    : /* empty */ {
        $$ = new parse_tree_node("declaration_list");
    }
    | declaration_list declaration {
        $$ = new parse_tree_node("declaration_list");
        $$->add_child($1);
    }
    ;

declaration
    : struct_definition {
        $$ = new parse_tree_node("declaration");
        $$->add_child($1);
    }
    | function_definition {
        $$ = new parse_tree_node("declaration");
        $$->add_child($1);
    }
    | variable_definition {
        $$ = new parse_tree_node("declaration");
        $$->add_child($1);
    }
    ;


/* Structs */
struct_definition
    : STRUCT IDENT LBRACE struct_field_list RBRACE {
        $$ = new parse_tree_node("struct_definition");
        $$->add_child(new parse_tree_node("STRUCT"));
        $$->add_child(new parse_tree_node($2));       // wrap IDENT string
        $$->add_child(new parse_tree_node("{"));
        $$->add_child($4);                             // struct_field_list is already a node
        $$->add_child(new parse_tree_node("}"));
    }
    ;


struct_field_list
    : 
      { $$ = new parse_tree_node("struct_field_list"); }  // empty list
    | struct_field_list struct_field {
        if ($2) $1->add_child($2);  // attach new field as child
        $$ = $1;                     // list itself is the parent
    }
    ;

struct_field
    : IDENT COLON type {
        $$ = new parse_tree_node("struct_field");
        $$->add_child(new parse_tree_node($1));
        $$->add_child(new parse_tree_node(":"));
        if ($3) $$->add_child($3);
    }
    ;
/* Functions */

function_definition
    : FN IDENT LPAREN parameter_list_optional RPAREN return_type_optional block {
        $$ = new parse_tree_node("function_definition");
        $$->add_child(new parse_tree_node("FN"));
        $$->add_child(new parse_tree_node($2));
        $$->add_child(new parse_tree_node("("));
        if ($4) $$->add_child($4);
        $$->add_child(new parse_tree_node(")"));
        if ($6) $$->add_child($6);
        if ($7) $$->add_child($7);
    }
    ;

parameter_list_optional
    : 
      { $$ = new parse_tree_node("parameter_list_optional"); } // empty list
    | parameter_list {
        $$ = new parse_tree_node("parameter_list_optional");
        if ($1) $$->add_child($1);  // attach the existing parameter list
    }
    ;

parameter_list
    : parameter {
        $$ = new parse_tree_node("parameter_list");
        if ($1) $$->add_child($1);
    }
    | parameter_list COMMA parameter {
        $$ = $1;               // reuse the existing list node
        if ($3) $$->add_child($3); // attach new parameter
    }
    ;

parameter
    : IDENT COLON type {
        $$ = new parse_tree_node("parameter");
        $$->add_child(new parse_tree_node($1));
        $$->add_child(new parse_tree_node(":"));
        if ($3) $$->add_child($3);
    }
    ;

return_type_optional
    : 
      { $$ = new parse_tree_node("return_type_optional"); }  // empty return type
    | ARROW type {
        $$ = new parse_tree_node("return_type_optional");
        $$->add_child(new parse_tree_node("ARROW"));
        if ($2) $$->add_child($2);
    }
    ;

/* Variables */
variable_definition
    : LET IDENT type_optional ASSIGN expression SEMI {
        $$ = new parse_tree_node("variable_definition");
        $$->add_child(new parse_tree_node("LET"));
        $$->add_child(new parse_tree_node($2));
        if ($3) $$->add_child($3);
        $$->add_child(new parse_tree_node("="));
        if ($5) $$->add_child($5);
        $$->add_child(new parse_tree_node(";"));
    }
    ;
    
block
    : LBRACE statement_list RBRACE {
        $$ = new parse_tree_node("block");
        $$->add_child(new parse_tree_node("{"));
        if ($2) $$->add_child($2);
        $$->add_child(new parse_tree_node("}"));
    }
    ;

/* Statements */
statement_list
    : 
      { $$ = new parse_tree_node("statement_list"); }  // empty list
    | statement_list statement {
        $$ = $1;  // $1 is already the statement_list node
        if ($2) $$->add_child($2);
    }
    ;


statement
    : variable_decl_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | assignment_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | conditional_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | while_loop_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | for_loop_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | return_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | break_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | continue_stmt {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | block {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    | expression {
        $$ = new parse_tree_node("statement");
        if ($1) $$->add_child($1);
    }
    ;


variable_decl_stmt
    : LET IDENT type_optional ASSIGN expression {
        $$ = new parse_tree_node("variable_decl_stmt");
        $$->add_child(new parse_tree_node("LET"));
        $$->add_child(new parse_tree_node($2));
        if ($3) $$->add_child($3);
        $$->add_child(new parse_tree_node("="));
        if ($5) $$->add_child($5);
    }
    ;

assignment_stmt
    : IDENT assignment_op expression {
        $$ = new parse_tree_node("assignment_stmt");
        $$->add_child(new parse_tree_node($1));
        if ($2) $$->add_child($2);
        if ($3) $$->add_child($3);
    }
    ;

assignment_op
    : ASSIGN     { $$ = new parse_tree_node("="); }
    | ADD_EQ     { $$ = new parse_tree_node("+="); }
    | SUB_EQ     { $$ = new parse_tree_node("-="); }
    | MUL_EQ     { $$ = new parse_tree_node("*="); }
    | DIV_EQ     { $$ = new parse_tree_node("/="); }
    | MOD_EQ     { $$ = new parse_tree_node("%="); }
    | BITAND_EQ  { $$ = new parse_tree_node("&="); }
    | BITOR_EQ   { $$ = new parse_tree_node("|="); }
    | BITXOR_EQ  { $$ = new parse_tree_node("^="); }
    | BITNOT_EQ  { $$ = new parse_tree_node("~="); }
    ;

conditional_stmt
    : IF expression block else_clause_optional {
        $$ = new parse_tree_node("conditional_stmt");
        $$->add_child(new parse_tree_node("IF"));
        if ($2) $$->add_child($2);
        if ($3) $$->add_child($3);
        if ($4) $$->add_child($4);
    }
    ;

else_clause_optional
    :   {$$ = nullptr;}
    | ELSE block {
        $$ = new parse_tree_node("else_clause_optional");
        $$->add_child(new parse_tree_node("ELSE"));
        if ($2) $$->add_child($2);
    }
    | ELSE conditional_stmt {
        $$ = new parse_tree_node("else_clause_optional");
        $$->add_child(new parse_tree_node("ELSE"));
        if ($2) $$->add_child($2);
    }
    ;

while_loop_stmt
    : WHILE expression block {
        $$ = new parse_tree_node("while_loop_stmt");
        $$->add_child(new parse_tree_node("WHILE"));
        if ($2) $$->add_child($2);
        if ($3) $$->add_child($3);
    }
    ;

for_loop_stmt
    : FOR IDENT IN expression block {
        $$ = new parse_tree_node("for_loop_stmt");
        $$->add_child(new parse_tree_node("FOR"));
        $$->add_child(new parse_tree_node($2));
        $$->add_child(new parse_tree_node("IN"));
        if ($4) $$->add_child($4);
        if ($5) $$->add_child($5);
    }
    ;

break_stmt
    : BREAK { $$ = new parse_tree_node("BREAK"); }
    ;

continue_stmt
    : CONTINUE { $$ = new parse_tree_node("CONTINUE"); }
    ;

return_stmt
    : RETURN expression_optional {
        $$ = new parse_tree_node("RETURN");
        if ($2) $$->add_child($2);
    }
    ;

expression_optional
    :   {$$ = nullptr;}
    | expression { 
        $$ = new parse_tree_node("expression_optional");
        $$->add_child($1); 
    }
    ;

expression
    : expression OR expression {
        $$ = new parse_tree_node("or");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("OR"));
        if ($3) $$->add_child($3);
    }
    | expression AND expression {
        $$ = new parse_tree_node("and");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("AND"));
        if ($3) $$->add_child($3);
    }
    | expression BITOR expression {
        $$ = new parse_tree_node("bitor");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("|"));
        if ($3) $$->add_child($3);
    }
    | expression BITXOR expression {
        $$ = new parse_tree_node("bitxor");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("^"));
        if ($3) $$->add_child($3);
    }
    | expression BITAND expression {
        $$ = new parse_tree_node("bitand");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("&"));
        if ($3) $$->add_child($3);
    }
    | expression EQ expression {
        $$ = new parse_tree_node("eq");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("=="));
        if ($3) $$->add_child($3);
    }
    | expression NEQ expression {
        $$ = new parse_tree_node("neq");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("!="));
        if ($3) $$->add_child($3);
    }
    | expression LT expression {
        $$ = new parse_tree_node("lt");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("<"));
        if ($3) $$->add_child($3);
    }
    | expression LE expression {
        $$ = new parse_tree_node("le");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("<="));
        if ($3) $$->add_child($3);
    }
    | expression GT expression {
        $$ = new parse_tree_node("gt");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node(">"));
        if ($3) $$->add_child($3);
    }
    | expression GE expression {
        $$ = new parse_tree_node("ge");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node(">="));
        if ($3) $$->add_child($3);
    }
    | expression SHL expression {
        $$ = new parse_tree_node("shl");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("<<"));
        if ($3) $$->add_child($3);
    }
    | expression SHR expression {
        $$ = new parse_tree_node("shr");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node(">>"));
        if ($3) $$->add_child($3);
    }
    | expression PLUS expression {
        $$ = new parse_tree_node("add");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("+"));
        if ($3) $$->add_child($3);
    }
    | expression MINUS expression {
        $$ = new parse_tree_node("sub");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("-"));
        if ($3) $$->add_child($3);
    }
    | expression MUL expression {
        $$ = new parse_tree_node("mul");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("*"));
        if ($3) $$->add_child($3);
    }
    | expression DIV expression {
        $$ = new parse_tree_node("div");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("/"));
        if ($3) $$->add_child($3);
    }
    | expression MOD expression {
        $$ = new parse_tree_node("mod");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("%"));
        if ($3) $$->add_child($3);
    }
    | unary_expression { $$ = $1; }
    ;

unary_expression
    : PLUS expression %prec UPLUS {
        $$ = new parse_tree_node("unary_plus");
        if ($2) $$->add_child($2);
    }
    | MINUS expression %prec UMINUS {
        $$ = new parse_tree_node("unary_minus");
        if ($2) $$->add_child($2);
    }
    | NOT expression {
        $$ = new parse_tree_node("unary_not");
        if ($2) $$->add_child($2);
    }
    | postfix_expression { $$ = $1; }
    ;

postfix_expression
    : primary_expression {
        $$ = new parse_tree_node("postfix_expression");
        if ($1) $$->add_child($1);
    }
    | postfix_expression LPAREN argument_list_optional RPAREN %prec POSTFIX {
        $$ = new parse_tree_node("postfix_expression");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("("));
        if ($3) $$->add_child($3);
        $$->add_child(new parse_tree_node(")"));
    }
    | postfix_expression LBRACKET expression RBRACKET %prec POSTFIX {
        $$ = new parse_tree_node("postfix_expression");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node("["));
        if ($3) $$->add_child($3);
        $$->add_child(new parse_tree_node("]"));
    }
    | postfix_expression DOT IDENT %prec POSTFIX {
        $$ = new parse_tree_node("postfix_expression");
        if ($1) $$->add_child($1);
        $$->add_child(new parse_tree_node(".")); 
        $$->add_child(new parse_tree_node($3));
    }
    ;

primary_expression
    : literal {
        $$ = new parse_tree_node("primary_expression");
        if ($1) $$->add_child($1);
    }
    | LPAREN expression RPAREN {
        $$ = new parse_tree_node("primary_expression");
        $$->add_child(new parse_tree_node("("));
        if ($2) $$->add_child($2);
        $$->add_child(new parse_tree_node(")"));
    }
    ;

literal
    : INT_LITERAL { $$ = new parse_tree_node(std::to_string($1)); }
    | FLOAT_LITERAL { $$ = new parse_tree_node(std::to_string($1)); }
    | STRING_LITERAL { $$ = new parse_tree_node($1); }
    ;

argument_list_optional
    :   {$$ = nullptr;}
    | argument_list {
        $$ = new parse_tree_node("argument_list_optional");
        if ($1) $$->add_child($1);
    }
    ;

argument_list
    : expression {
        $$ = new parse_tree_node("argument_list");
        if ($1) $$->add_child($1);
    }
    | argument_list COMMA expression {
        $$ = $1;
        $$->add_child(new parse_tree_node(","));
        if ($3) $$->add_child($3);
    }
    ;

type_optional
    :   {$$ = nullptr;}
    | type {
        $$ = new parse_tree_node("type_optional");
        if ($1) $$->add_child($1);
    }
    ;

type
    : IDENT {
        $$ = new parse_tree_node("type");
        $$->add_child(new parse_tree_node($1));
    }
    | LBRACKET type array_size_optional RBRACKET {
        $$ = new parse_tree_node("type");
        $$->add_child(new parse_tree_node("["));
        if ($2) $$->add_child($2);
        if ($3) $$->add_child($3);
        $$->add_child(new parse_tree_node("]"));
    }
    ;

array_size_optional
    :   {$$ = nullptr;}
    | SEMI numeric {
        $$ = new parse_tree_node("array_size_optional");
        $$->add_child(new parse_tree_node(";"));
        if ($2) $$->add_child($2);
    }
    ;

numeric
    : INT_LITERAL { $$ = new parse_tree_node(std::to_string($1)); }
    | IDENT { $$ = new parse_tree_node($1); }
    ;
%%

int main() {
    yy::parser parser;
    parse_tree_node* root = nullptr;
    int res = parser.parse();
    if (root) root->print();
    return res;
}

int yyerror(const std::string &msg) {
    std::cerr << "Error: " << msg << "\n";
    return 0;
}