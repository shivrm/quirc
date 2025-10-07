%option c++
%option yylineno
%option noyywrap

%{
#include <iostream>
#include <fstream>
#include <string>
#include "yacc.hpp"

#define TAB_WIDTH 4

int yylineno = 1;
int yycolumn = 1;

/* Updates the position of the of the lexer in the input */
static void update_position(const char* text, int length,
                            int& start_line, int& start_col,
                            int& end_line, int& end_col) {
    start_line = yylineno;
    start_col  = yycolumn;

    for (int i = 0; i < length; i++) {
        if (text[i] == '\n') {
            yylineno++;
            yycolumn = 1;
        } else if (text[i] == '\t') {
            yycolumn += TAB_WIDTH;
        } else {
            yycolumn++;
        }
    }

    end_line = yylineno;
    end_col  = yycolumn - 1;
}

// Macro for emitting a token.
// Updates position and prints the token.
// TODO: When a parser is added, return token instead of printing it (done)
#define TOKEN(name) do { \
    int sl, sc, el, ec; \
    update_position(yytext, yyleng, sl, sc, el, ec); \
    if (strcmp(#name, "NEWLINE") == 0) { \
        yytext = (char*)"\\n"; \
    } \
    printf("%-10s %-10s (%d:%d-%d:%d)\n", #name, yytext, sl, sc, el, ec); \
    return yy::parser::token::name; \
} while(0)
%}

DIGIT      [0-9]
ID         [A-Za-z_][A-Za-z0-9_]*

%%
 /* Keywords */
"let"           { return yy::parser::make_LET(LET); }
"if"            { return yy::parser::make_IF(); }
"else"          { return yy::parser::make_ELSE(); }
"for"           { return yy::parser::make_FOR(); }
"in"            { return yy::parser::make_IN(); }
"break"         { return yy::parser::make_BREAK(); }
"continue"      { return yy::parser::make_CONTINUE(); }
"return"        { return yy::parser::make_RETURN(); }
"fn"            { return yy::parser::make_FN(); }
"struct"        { return yy::parser::make_STRUCT(); }
"and"           { return yy::parser::make_AND(); }
"or"            { return yy::parser::make_OR(); }
"not"           { return yy::parser::make_NOT(); }

 /* Multi-character tokens */
"->"            { return yy::parser::make_ARROW(); }
"=="            { return yy::parser::make_EQ(); }
"!="            { return yy::parser::make_NEQ(); }
"<<="           { return yy::parser::make_SHL_EQ(); }
">>="           { return yy::parser::make_SHR_EQ(); }
"+="            { return yy::parser::make_ADD_EQ(); }
"-="            { return yy::parser::make_SUB_EQ(); }
"*="            { return yy::parser::make_MUL_EQ(); }
"/="            { return yy::parser::make_DIV_EQ(); }
"%="            { return yy::parser::make_MOD_EQ(); }
"&="            { return yy::parser::make_BITAND_EQ(); }
"|="            { return yy::parser::make_BITOR_EQ(); }
"^="            { return yy::parser::make_BITXOR_EQ(); }
"~="            { return yy::parser::make_BITNOT_EQ(); }
"<<"            { return yy::parser::make_SHL(); }
">>"            { return yy::parser::make_SHR(); }

 /* Single-character tokens */
"+"             { return yy::parser::make_PLUS(); }
"-"             { return yy::parser::make_MINUS(); }
"*"             { return yy::parser::make_MUL(); }
"/"             { return yy::parser::make_DIV(); }
"%"             { return yy::parser::make_MOD(); }
"="             { return yy::parser::make_ASSIGN(); }
"&"             { return yy::parser::make_BITAND(); }
"|"             { return yy::parser::make_BITOR(); }
"^"             { return yy::parser::make_BITXOR(); }
"~"             { return yy::parser::make_BITNOT(); }
","             { return yy::parser::make_COMMA(); }
"("             { return yy::parser::make_LPAREN(); }
")"             { return yy::parser::make_RPAREN(); }
"{"             { return yy::parser::make_LBRACE(); }
"}"             { return yy::parser::make_RBRACE(); }
"["             { return yy::parser::make_LBRACKET(); }
"]"             { return yy::parser::make_RBRACKET(); }
";"             { return yy::parser::make_SEMI(); }
":"             { return yy::parser::make_COLON(); }
"."             { return yy::parser::make_DOT(); }
"\n"            { return yy::parser::make_NEWLINE(); }

 /* Numeric literals */
{DIGIT}+"."{DIGIT}*([eE][+-]?{DIGIT}+)?  { return yy::parser::make_FLOAT_LITERAL(std::stod(yytext)); }
{DIGIT}+([eE][+-]?{DIGIT}+)?             { return yy::parser::make_INT_LITERAL(std::stoi(yytext)); }

 /* String literals */
\"(\\.|[^"\\\n])*\"                      { return yy::parser::make_STRING_LITERAL(yytext); } //with ""

 /* Identifiers */
{ID}                                     { return yy::parser::make_IDENT(yytext); } //with ""

 /* Comments */
"/"\*([^*]|\*+[^*/])*\*+"/"              { /* block comment */ }
\/\/[^\n]*                               { /* line comment */ }

 /* Whitespace (except newline)
    Update position but don't emit token */
[ \t\r]+                               { int sl, sc, el, ec; update_position(yytext, yyleng, sl, sc, el, ec); }

 /* All other characters */
.                                       { printf("Syntax error\n"); }

%%

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] <<" <file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cout << "Could not open " << argv[1] << std::endl;
        return 1;
    }

    yyFlexLexer scanner(&file);
    scanner.yylex();
    return 0;
}
