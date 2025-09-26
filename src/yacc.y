%language "c++"       /* tell bison to use C++ mode */
%require "3.2"
%skeleton "lalr1.cc"

%{
    #include <iostream>
    #include <fstream>
    #include <string>
%}

%code requires {
    #include <string>
}

//tells yacc that the scanner is external
%code {
    static yy::Parser::symbol_type yylex(yy::Parser::semantic_type* yylval,
                                         yy::Parser::location_type* yylloc);
}

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

%token IDENT

%token <int> INT_LITERAL
%token <double> FLOAT_LITERAL
%token <std::string> STRING_LITERAL

%%
program
    : declaration_list
    ;

declaration_list
    :
    | declaration_list declaration
    ;

declaration
    : struct_definition
    | function_definition
    | variable_definition
    ;


/* Structs */
struct_definition
    : STRUCT IDENT LBRACE struct_field_list RBRACE
    ;

struct_field_list
    : 
    | struct_field_list struct_field
    ;

struct_field
    : IDENT COLON type
    ;


/* Functions */
function_definition
    : FN IDENT LPAREN parameter_list_optional RPAREN return_type_optional block
    ;

parameter_list_optional
    : 
    | parameter_list
    ;

parameter_list
    : parameter
    | parameter_list COMMA parameter
    ;

parameter
    : IDENT COLON type
    ;

return_type_optional
    :  
    | ARROW type
    ;

/* Variables */
variable_definition
    : LET IDENT type_optional ASSIGN expression SEMI
    ;


block
    : LBRACE statement_list RBRACE
    ;


/* Statements */
statement_list
    : 
    | statement_list NEWLINE statement
    ; 

statement
    : variable_decl_stmt
    | assignment_stmt
    | conditional_stmt
    | while_loop_stmt
    | for_loop_stmt
    | return_stmt
    | break_stmt
    | continue_stmt
    | block
    | expression
    ;


variable_decl_stmt
    : LET IDENT type_optional ASSIGN expression
    ; 


assignment_stmt
    : IDENT assignment_op expression
    ;

assignment_op
    : ASSIGN
    | ADD_EQ
    | SUB_EQ
    | MUL_EQ
    | DIV_EQ
    | MOD_EQ
    | BITAND_EQ
    | BITOR_EQ
    | BITXOR_EQ
    | BITNOT_EQ
    ;


conditional_stmt
    : IF expression block else_clause_optional
    ;

else_clause_optional
    :
    | ELSE block
    | ELSE conditional_stmt
    ;


while_loop_stmt
    : WHILE expression block
    ;


for_loop_stmt
    : FOR IDENT IN expression block
    ;


break_stmt
    : BREAK
    ;

continue_stmt
    : CONTINUE
    ;

return_stmt
    : RETURN expression_optional
    ;

expression_optional
    : expression
    ;


expression
    : expression OR expression
    | expression AND expression
    | expression BITOR expression
    | expression BITXOR expression
    | expression BITAND expression
    | expression EQ expression
    | expression NEQ expression
    | expression LT expression
    | expression LE expression
    | expression GT expression
    | expression GE expression
    | expression SHL expression
    | expression SHR expression
    | expression PLUS expression
    | expression MINUS expression
    | expression MUL expression
    | expression DIV expression
    | expression MOD expression
    | unary_expression
    ;

unary_expression
    : PLUS expression %prec UPLUS
    | MINUS expression %prec UMINUS
    | NOT expression
    | postfix_expression
    ;

postfix_expression
    : primary_expression
    | postfix_expression LPAREN argument_list_optional RPAREN %prec POSTFIX
    | postfix_expression LBRACKET expression RBRACKET %prec POSTFIX
    | postfix_expression DOT IDENT %prec POSTFIX
    ;

primary_expression
    : literal
    | LPAREN expression RPAREN
    ;

literal
    : INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    ;

argument_list_optional
    :
    | argument_list
    ;

argument_list
    : expression
    | argument_list COMMA expression
    ;

type_optional
    :
    | type
    ; 

type
    : IDENT
    | LBRACKET type array_size_optional RBRACKET
    ;

array_size_optional
    :
    | SEMI numeric
    ;
    
numeric
    : INT_LITERAL
    | IDENT
    ;
%%

int main() {
    yy:Parser parser;
    return parser.parse();
}

int yyerror(const std::string &msg) {
    std::cerr << "Error: " << msg << "\n";
    return 0;
}