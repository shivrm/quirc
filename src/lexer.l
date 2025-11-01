%option yylineno
%option noyywrap

%{
#define YY_NO_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_tree.h"
#include "yacc.h"

#define TAB_WIDTH 4

// int yylineno = 1;
int yycolumn = 1;

/* Updates the position of the lexer in the input */
static void update_position(const char* text, int length,
                           int* start_line, int* start_col,
                           int* end_line, int* end_col) {
    *start_line = yylineno;
    *start_col = yycolumn;
    
    for (int i = 0; i < length; i++) {
        if (text[i] == '\n') {
            yycolumn = 1;
        } else if (text[i] == '\t') {
            yycolumn += TAB_WIDTH;
        } else {
            yycolumn++;
        }
    }
    
    *end_line = yylineno;
    *end_col = yycolumn - 1;
}

// Macro for emitting a token
#define TOKEN(name) { \
    int sl, sc, el, ec; \
    update_position(yytext, yyleng, &sl, &sc, &el, &ec); \
    if (strcmp(#name, "NEWLINE") == 0) { \
        yytext = "\\n"; \
    } \
    /*printf("%-10s %-10s (%d:%d-%d:%d)\n", #name, yytext, sl, sc, el, ec);*/ \
    return name; \
}

%}

DIGIT [0-9]
ID [A-Za-z_][A-Za-z0-9_]*

%%

"let"       { TOKEN(LET); }
"if"        { TOKEN(IF); }
"else"      { TOKEN(ELSE); }
"for"       { TOKEN(FOR); }
"in"        { TOKEN(IN); }
"break"     { TOKEN(BREAK); }
"continue"  { TOKEN(CONTINUE); }
"return"    { TOKEN(RETURN); }
"fn"        { TOKEN(FN); }
"struct"    { TOKEN(STRUCT); }
"while"     { TOKEN(WHILE); }
"and"       { TOKEN(AND); }
"or"        { TOKEN(OR); }
"not"       { TOKEN(NOT); }

"->"    { TOKEN(ARROW); }
"=="    { TOKEN(EQ); }
"!="    { TOKEN(NEQ); }
"<<="   { TOKEN(SHL_EQ); }
">>="   { TOKEN(SHR_EQ); }
"+="    { TOKEN(ADD_EQ); }
"-="    { TOKEN(SUB_EQ); }
"*="    { TOKEN(MUL_EQ); }
"/="    { TOKEN(DIV_EQ); }
"%="    { TOKEN(MOD_EQ); }
"&="    { TOKEN(BITAND_EQ); }
"|="    { TOKEN(BITOR_EQ); }
"^="    { TOKEN(BITXOR_EQ); }
"~="    { TOKEN(BITNOT_EQ); }
"<<"    { TOKEN(SHL); }
">>"    { TOKEN(SHR); }
"<="    { TOKEN(LE); }
">="    { TOKEN(GE); }

"+"     { TOKEN(PLUS); }
"-"     { TOKEN(MINUS); }
"*"     { TOKEN(MUL); }
"/"     { TOKEN(DIV); }
"%"     { TOKEN(MOD); }
"="     { TOKEN(ASSIGN); }
"&"     { TOKEN(BITAND); }
"|"     { TOKEN(BITOR); }
"^"     { TOKEN(BITXOR); }
"~"     { TOKEN(BITNOT); }
","     { TOKEN(COMMA); }
"("     { TOKEN(LPAREN); }
")"     { TOKEN(RPAREN); }
"{"     { TOKEN(LBRACE); }
"}"     { TOKEN(RBRACE); }
"["     { TOKEN(LBRACKET); }
"]"     { TOKEN(RBRACKET); }
";"     { TOKEN(SEMI); }
":"     { TOKEN(COLON); }
"."     { TOKEN(DOT); }
"<"     { TOKEN(LT); }
">"     { TOKEN(GT); }
 /* "\n"    { TOKEN(NEWLINE); } */

{DIGIT}+"."{DIGIT}*([eE][+-]?{DIGIT}+)? { 
    yylval.float_val = atof(yytext); 
    TOKEN(FLOAT_LITERAL); 
}

{DIGIT}+([eE][+-]?{DIGIT}+)? { 
    yylval.int_val = atoi(yytext); 
    TOKEN(INT_LITERAL); 
}

\"(\\.|[^"\\\n])*\" { 
    yylval.string_val = strdup(yytext); 
    TOKEN(STRING_LITERAL); 
}

{ID} { 
    yylval.string_val = strdup(yytext); 
    TOKEN(IDENT); 
}

"/*"([^*]|\*+[^*/])*\*+"/" { /* block comment */ }
"//"[^\n]*                   { /* line comment */ }

[ \t\r\n]+ { 
    int sl, sc, el, ec; 
    update_position(yytext, yyleng, &sl, &sc, &el, &ec); 
}

. { printf("Syntax error\n"); }

%%
