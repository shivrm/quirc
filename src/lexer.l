%option c++
%option yylineno
%option noyywrap

%{
#include <iostream>
#include <fstream>
#include <string>

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
// TODO: When a parser is added, return token instead of printing it
#define TOKEN(name) do { \
    int sl, sc, el, ec; \
    update_position(yytext, yyleng, sl, sc, el, ec); \
    if (strcmp(#name, "NEWLINE") == 0) { \
        yytext = (char*)"\\n"; \
    } \
    printf("%-10s %-10s (%d:%d-%d:%d)\n", #name, yytext, sl, sc, el, ec); \
} while(0)
%}

DIGIT      [0-9]
ID         [A-Za-z_][A-Za-z0-9_]*

%%
 /* Keywords */
"let"           { TOKEN(LET); }
"if"            { TOKEN(IF); }
"else"          { TOKEN(ELSE); }
"for"           { TOKEN(FOR); }
"in"            { TOKEN(IN); }
"break"         { TOKEN(BREAK); }
"continue"      { TOKEN(CONTINUE); }
"fn"            { TOKEN(FN); }
"struct"        { TOKEN(STRUCT); }
"and"           { TOKEN(AND); }
"or"            { TOKEN(OR); }
"not"           { TOKEN(NOT); }

 /* Multi-character tokens */
"->"            { TOKEN(ARROW); }
"<<="           { TOKEN(SHL_EQ); }
">>="           { TOKEN(SHR_EQ); }
"+="            { TOKEN(ADD_EQ); }
"-="            { TOKEN(SUB_EQ); }
"*="            { TOKEN(MUL_EQ); }
"/="            { TOKEN(DIV_EQ); }
"%="            { TOKEN(MOD_EQ); }
"&="            { TOKEN(AND_EQ); }
"|="            { TOKEN(OR_EQ); }
"^="            { TOKEN(XOR_EQ); }
"~="            { TOKEN(TILDE_EQ); }
"<<"            { TOKEN(SHL); }
">>"            { TOKEN(SHR); }

 /* Single-character tokens */
"="             { TOKEN(EQ); }
"&"             { TOKEN(AMP); }
"|"             { TOKEN(BAR); }
"^"             { TOKEN(CARET); }
"~"             { TOKEN(TILDE); }
","             { TOKEN(COMMA); }
"("             { TOKEN(LPAREN); }
")"             { TOKEN(RPAREN); }
"{"             { TOKEN(LBRACE); }
"}"             { TOKEN(RBRACE); }
"["             { TOKEN(LBRACKET); }
"]"             { TOKEN(RBRACKET); }
";"             { TOKEN(SEMI); }
":"             { TOKEN(COLON); }
"."             { TOKEN(DOT); }
"\n"            { TOKEN(NEWLINE); }

 /* Numeric literals */
{DIGIT}+"."{DIGIT}*([eE][+-]?{DIGIT}+)?  { TOKEN(FLOAT); }
{DIGIT}+([eE][+-]?{DIGIT}+)?             { TOKEN(INT); }

 /* String literals */
\"(\\.|[^"\\\n])*\"                      { TOKEN(STRING); }

 /* Identifiers */
{ID}                                     { TOKEN(IDENT); }

 /* Comments */
"/"\*([^*]|\*+[^*/])*\*+"/"              { /* block comment */ }
\/\/[^\n]*                               { /* line comment */ }

 /* Whitespace (except newline)
    Update position but don't emit token */
[ \t\r]+                               { int sl, sc, el, ec; update_position(yytext, yyleng, sl, sc, el, ec); }

 /* All other characters */
.                                       { TOKEN(UNKNOWN); }

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