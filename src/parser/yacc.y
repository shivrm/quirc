%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_tree.h"

extern int yylex(void);
extern int yylineno;
extern char* yytext;

// extern parse_tree_node *create_node(char*);
// extern void add_child(parse_tree_node*, parse_tree_node*);
// extern void print_tree(parse_tree_node*);
// extern void free_tree(parse_tree_node*);

void yyerror(const char *msg);

parse_tree_node* root = NULL;

parse_tree_node *get_parse_tree() {
    return root;
}

%}

%union {
    int int_val;
    double float_val;
    char* string_val;
    struct parse_tree_node* node;
}

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
%token LBRACE RBRACE
%token DOT
%token AND OR NOT
%token PLUS MINUS MUL DIV MOD
%token SHL SHR

/* Token types with semantic values */
%token <int_val> INT_LITERAL
%token <float_val> FLOAT_LITERAL
%token <string_val> STRING_LITERAL
%token <string_val> IDENT

/* Nonterminals producing parse_tree_parse_tree_node* */
%type <node> program
%type <node> declaration_list
%type <node> declaration
%type <node> struct_definition
%type <node> struct_field_list_optional
%type <node> struct_field_list
%type <node> struct_field
%type <node> function_definition
%type <node> parameter_list_optional
%type <node> parameter_list
%type <node> parameter
%type <node> return_type_optional
%type <node> variable_definition
%type <node> block
%type <node> statement_list
%type <node> statement
%type <node> variable_decl_stmt
%type <node> assignment_stmt
%type <node> assignment_op
%type <node> conditional_stmt
%type <node> else_clause_optional
%type <node> while_loop_stmt
%type <node> for_loop_stmt
%type <node> break_stmt
%type <node> continue_stmt
%type <node> return_stmt
%type <node> expression_optional
%type <node> expression
%type <node> unary_expression
%type <node> postfix_expression
%type <node> primary_expression
%type <node> literal
%type <node> argument_list_optional
%type <node> argument_list
%type <node> type_optional
%type <node> type
%type <node> array_size_optional
%type <node> numeric

/* Operator precedence */
%left OR
%left AND
%left BITOR
%left BITXOR
%left BITAND
%nonassoc EQ NEQ
%nonassoc LT LE GT GE
%left SHL SHR
%left PLUS MINUS
%left MUL DIV MOD
%right NOT UPLUS UMINUS
%left POSTFIX

%%

program
    : declaration_list {
        $$ = create_node("program");
        add_child($$, $1);
        root = $$;
    }
    ;

declaration_list
    : /* empty */ {
        $$ = create_node("declaration_list");
    }
    | declaration_list declaration {
        $$ = $1;
        add_child($$, $2);
    }
    ;

declaration
    : struct_definition {
        $$ = create_node("declaration");
        add_child($$, $1);
    }
    | function_definition {
        $$ = create_node("declaration");
        add_child($$, $1);
    }
    | variable_definition {
        $$ = create_node("declaration");
        add_child($$, $1);
    }
    ;

/* Structs */
struct_definition
    : STRUCT IDENT LBRACE struct_field_list_optional RBRACE {
        $$ = create_node("struct_definition");
        add_child($$, create_node("STRUCT"));
        add_child($$, create_node($2));
        add_child($$, create_node("{"));
        add_child($$, $4);
        add_child($$, create_node("}"));
        free($2);
    }
    ;

struct_field_list_optional
    : /* empty */ {
        $$ = create_node("struct_field_list");
    }
    | struct_field_list {
        $$ = $1;
    }
    ;

struct_field_list
    : struct_field {
        $$ = create_node("struct_field_list");
        if ($1) add_child($$, $1);
    }
    | struct_field_list COMMA struct_field {
        $$ = $1;
        if ($3) add_child($$, $3);
    }
    ;

struct_field
    : IDENT COLON type {
        $$ = create_node("struct_field");
        add_child($$, create_node($1));
        add_child($$, create_node(":"));
        if ($3) add_child($$, $3);
        free($1);
    }
    ;

/* Functions */
function_definition
    : FN IDENT LPAREN parameter_list_optional RPAREN return_type_optional block {
        $$ = create_node("function_definition");
        add_child($$, create_node("FN"));
        add_child($$, create_node($2));
        add_child($$, create_node("("));
        if ($4) add_child($$, $4);
        add_child($$, create_node(")"));
        if ($6) add_child($$, $6);
        if ($7) add_child($$, $7);
        free($2);
    }
    ;

parameter_list_optional
    : /* empty */ {
        $$ = create_node("parameter_list_optional");
    }
    | parameter_list {
        $$ = create_node("parameter_list_optional");
        if ($1) add_child($$, $1);
    }
    ;

parameter_list
    : parameter {
        $$ = create_node("parameter_list");
        if ($1) add_child($$, $1);
    }
    | parameter_list COMMA parameter {
        $$ = $1;
        if ($3) add_child($$, $3);
    }
    ;

parameter
    : IDENT COLON type {
        $$ = create_node("parameter");
        add_child($$, create_node($1));
        add_child($$, create_node(":"));
        if ($3) add_child($$, $3);
        free($1);
    }
    ;

return_type_optional
    : /* empty */ {
        $$ = create_node("return_type_optional");
    }
    | ARROW type {
        $$ = create_node("return_type_optional");
        add_child($$, create_node("ARROW"));
        if ($2) add_child($$, $2);
    }
    ;

/* Variables */
variable_definition
    : LET IDENT type_optional ASSIGN expression SEMI {
        $$ = create_node("variable_definition");
        add_child($$, create_node("LET"));
        add_child($$, create_node($2));
        if ($3) add_child($$, $3);
        add_child($$, create_node("="));
        if ($5) add_child($$, $5);
        add_child($$, create_node(";"));
        free($2);
    }
    ;

block
    : LBRACE statement_list RBRACE {
        $$ = create_node("block");
        add_child($$, create_node("{"));
        if ($2) add_child($$, $2);
        add_child($$, create_node("}"));
    }
    ;

/* Statements */
statement_list
    : /* empty */ {
        $$ = create_node("statement_list");
    }
    | statement_list statement {
        $$ = $1;
        if ($2) add_child($$, $2);
    }
    ;

statement
    : variable_decl_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | assignment_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | conditional_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | while_loop_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | for_loop_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | return_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | break_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | continue_stmt {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | block {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    | expression {
        $$ = create_node("statement");
        if ($1) add_child($$, $1);
    }
    ;

variable_decl_stmt
    : LET IDENT type_optional ASSIGN expression {
        $$ = create_node("variable_decl_stmt");
        add_child($$, create_node("LET"));
        add_child($$, create_node($2));
        if ($3) add_child($$, $3);
        add_child($$, create_node("="));
        if ($5) add_child($$, $5);
        free($2);
    }
    ;

assignment_stmt
    : IDENT assignment_op expression {
        $$ = create_node("assignment_stmt");
        add_child($$, create_node($1));
        if ($2) add_child($$, $2);
        if ($3) add_child($$, $3);
        free($1);
    }
    ;

assignment_op
    : ASSIGN        { $$ = create_node("="); }
    | ADD_EQ        { $$ = create_node("+="); }
    | SUB_EQ        { $$ = create_node("-="); }
    | MUL_EQ        { $$ = create_node("*="); }
    | DIV_EQ        { $$ = create_node("/="); }
    | MOD_EQ        { $$ = create_node("%="); }
    | BITAND_EQ     { $$ = create_node("&="); }
    | BITOR_EQ      { $$ = create_node("|="); }
    | BITXOR_EQ     { $$ = create_node("^="); }
    | BITNOT_EQ     { $$ = create_node("~="); }
    ;

conditional_stmt
    : IF expression block else_clause_optional {
        $$ = create_node("conditional_stmt");
        add_child($$, create_node("IF"));
        if ($2) add_child($$, $2);
        if ($3) add_child($$, $3);
        if ($4) add_child($$, $4);
    }
    ;

else_clause_optional
    : /* empty */ { $$ = NULL; }
    | ELSE block {
        $$ = create_node("else_clause_optional");
        add_child($$, create_node("ELSE"));
        if ($2) add_child($$, $2);
    }
    | ELSE conditional_stmt {
        $$ = create_node("else_clause_optional");
        add_child($$, create_node("ELSE"));
        if ($2) add_child($$, $2);
    }
    ;

while_loop_stmt
    : WHILE expression block {
        $$ = create_node("while_loop_stmt");
        add_child($$, create_node("WHILE"));
        if ($2) add_child($$, $2);
        if ($3) add_child($$, $3);
    }
    ;

for_loop_stmt
    : FOR IDENT IN expression block {
        $$ = create_node("for_loop_stmt");
        add_child($$, create_node("FOR"));
        add_child($$, create_node($2));
        add_child($$, create_node("IN"));
        if ($4) add_child($$, $4);
        if ($5) add_child($$, $5);
        free($2);
    }
    ;

break_stmt
    : BREAK { $$ = create_node("BREAK"); }
    ;

continue_stmt
    : CONTINUE { $$ = create_node("CONTINUE"); }
    ;

return_stmt
    : RETURN expression_optional {
        $$ = create_node("RETURN");
        if ($2) add_child($$, $2);
    }
    ;

expression_optional
    : expression {
        $$ = create_node("expression_optional");
        add_child($$, $1);
    }
    ;

expression
    : expression OR expression {
        $$ = create_node("or");
        if ($1) add_child($$, $1);
        add_child($$, create_node("OR"));
        if ($3) add_child($$, $3);
    }
    | expression AND expression {
        $$ = create_node("and");
        if ($1) add_child($$, $1);
        add_child($$, create_node("AND"));
        if ($3) add_child($$, $3);
    }
    | expression BITOR expression {
        $$ = create_node("bitor");
        if ($1) add_child($$, $1);
        add_child($$, create_node("|"));
        if ($3) add_child($$, $3);
    }
    | expression BITXOR expression {
        $$ = create_node("bitxor");
        if ($1) add_child($$, $1);
        add_child($$, create_node("^"));
        if ($3) add_child($$, $3);
    }
    | expression BITAND expression {
        $$ = create_node("bitand");
        if ($1) add_child($$, $1);
        add_child($$, create_node("&"));
        if ($3) add_child($$, $3);
    }
    | expression EQ expression {
        $$ = create_node("eq");
        if ($1) add_child($$, $1);
        add_child($$, create_node("=="));
        if ($3) add_child($$, $3);
    }
    | expression NEQ expression {
        $$ = create_node("neq");
        if ($1) add_child($$, $1);
        add_child($$, create_node("!="));
        if ($3) add_child($$, $3);
    }
    | expression LT expression {
        $$ = create_node("lt");
        if ($1) add_child($$, $1);
        add_child($$, create_node("<"));
        if ($3) add_child($$, $3);
    }
    | expression LE expression {
        $$ = create_node("le");
        if ($1) add_child($$, $1);
        add_child($$, create_node("<="));
        if ($3) add_child($$, $3);
    }
    | expression GT expression {
        $$ = create_node("gt");
        if ($1) add_child($$, $1);
        add_child($$, create_node(">"));
        if ($3) add_child($$, $3);
    }
    | expression GE expression {
        $$ = create_node("ge");
        if ($1) add_child($$, $1);
        add_child($$, create_node(">="));
        if ($3) add_child($$, $3);
    }
    | expression SHL expression {
        $$ = create_node("shl");
        if ($1) add_child($$, $1);
        add_child($$, create_node("<<"));
        if ($3) add_child($$, $3);
    }
    | expression SHR expression {
        $$ = create_node("shr");
        if ($1) add_child($$, $1);
        add_child($$, create_node(">>"));
        if ($3) add_child($$, $3);
    }
    | expression PLUS expression {
        $$ = create_node("add");
        if ($1) add_child($$, $1);
        add_child($$, create_node("+"));
        if ($3) add_child($$, $3);
    }
    | expression MINUS expression {
        $$ = create_node("sub");
        if ($1) add_child($$, $1);
        add_child($$, create_node("-"));
        if ($3) add_child($$, $3);
    }
    | expression MUL expression {
        $$ = create_node("mul");
        if ($1) add_child($$, $1);
        add_child($$, create_node("*"));
        if ($3) add_child($$, $3);
    }
    | expression DIV expression {
        $$ = create_node("div");
        if ($1) add_child($$, $1);
        add_child($$, create_node("/"));
        if ($3) add_child($$, $3);
    }
    | expression MOD expression {
        $$ = create_node("mod");
        if ($1) add_child($$, $1);
        add_child($$, create_node("%"));
        if ($3) add_child($$, $3);
    }
    // | unary_expression { $$ = $1; }
    // Note: this modification was made at AST conversion time, if needed revert to the old 
    // grammar after modifying the corresponding AST conversion code
    | unary_expression {
        $$ = create_node("unary_expression");
        if ($1) add_child($$, $1);
    }
    ;

unary_expression
    : PLUS expression %prec UPLUS {
        $$ = create_node("unary_plus");
        if ($2) add_child($$, $2);
    }
    | MINUS expression %prec UMINUS {
        $$ = create_node("unary_minus");
        if ($2) add_child($$, $2);
    }
    | NOT expression {
        $$ = create_node("unary_not");
        if ($2) add_child($$, $2);
    }
    // | postfix_expression { $$ = $1; }
    // Note: this modification was made at AST conversion time, if needed revert to the old 
    // grammar after modifying the corresponding AST conversion code
    | postfix_expression {
        $$ = $1;
        // $$ = create_node("postfix_expression");
        // if ($1) add_child($$, $1);
    }
    ;

postfix_expression
    : primary_expression {
        $$ = create_node("postfix_expression");
        if ($1) add_child($$, $1);
    }
    | postfix_expression LPAREN argument_list_optional RPAREN %prec POSTFIX {
        $$ = create_node("postfix_expression");
        if ($1) add_child($$, $1);
        add_child($$, create_node("("));
        if ($3) add_child($$, $3);
        add_child($$, create_node(")"));
    }
    | postfix_expression LBRACKET expression RBRACKET %prec POSTFIX {
        $$ = create_node("postfix_expression");
        if ($1) add_child($$, $1);
        add_child($$, create_node("["));
        if ($3) add_child($$, $3);
        add_child($$, create_node("]"));
    }
    | postfix_expression DOT IDENT %prec POSTFIX {
        $$ = create_node("postfix_expression");
        if ($1) add_child($$, $1);
        add_child($$, create_node("."));
        add_child($$, create_node($3));
        free($3);
    }
    ;

primary_expression
    : literal {
        $$ = create_node("primary_expression");
        if ($1) add_child($$, $1);
    }
    | IDENT {
        $$ = create_node("primary_expression");
        add_child($$, create_node($1));
        free($1);
    }
    | LPAREN expression RPAREN {
        $$ = create_node("primary_expression");
        add_child($$, create_node("("));
        if ($2) add_child($$, $2);
        add_child($$, create_node(")"));
    }
    ;

literal
    : INT_LITERAL { 
        $$ = create_node("INT_LITERAL");
        char buffer[32];
        sprintf(buffer, "%d", $1);
        add_child($$, create_node(buffer)); 
    }
    | FLOAT_LITERAL { 
        $$ = create_node("FLOAT_LITERAL");
        char buffer[32];
        sprintf(buffer, "%f", $1);
        add_child($$, create_node(buffer)); 
    }
    | STRING_LITERAL { 
        $$ = create_node("STRING_LITERAL");
        add_child($$, create_node($1)); 
        free($1);
    }
    ;

argument_list_optional
    : /* empty */ { $$ = NULL; }
    | argument_list {
        $$ = create_node("argument_list_optional");
        if ($1) add_child($$, $1);
    }
    ;

argument_list
    : expression {
        $$ = create_node("argument_list");
        if ($1) add_child($$, $1);
    }
    | argument_list COMMA expression {
        $$ = $1;
        add_child($$, create_node(","));
        if ($3) add_child($$, $3);
    }
    ;

type_optional
    : /* empty */ { $$ = NULL; }
    | COLON type {
        $$ = create_node("type_optional");
        if ($2) add_child($$, $2);
    }
    ;

type
    : IDENT {
        $$ = create_node("type");
        add_child($$, create_node($1));
        free($1);
    }
    | LBRACKET type array_size_optional RBRACKET {
        $$ = create_node("type");
        add_child($$, create_node("["));
        if ($2) add_child($$, $2);
        if ($3) add_child($$, $3);
        add_child($$, create_node("]"));
    }
    ;

array_size_optional
    : /* empty */ { $$ = NULL; }
    | SEMI numeric {
        $$ = create_node("array_size_optional");
        add_child($$, create_node(";"));
        if ($2) add_child($$, $2);
    }
    ;

numeric
    : INT_LITERAL { 
        char buffer[32];
        sprintf(buffer, "%d", $1);
        $$ = create_node(buffer); 
    }
    | IDENT { 
        $$ = create_node($1);
        free($1);
    }
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
}