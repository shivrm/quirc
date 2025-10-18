/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_YACC_H_INCLUDED
# define YY_YY_SRC_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRUCT = 258,                  /* STRUCT  */
    FN = 259,                      /* FN  */
    LET = 260,                     /* LET  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    FOR = 264,                     /* FOR  */
    IN = 265,                      /* IN  */
    BREAK = 266,                   /* BREAK  */
    CONTINUE = 267,                /* CONTINUE  */
    RETURN = 268,                  /* RETURN  */
    NEWLINE = 269,                 /* NEWLINE  */
    ASSIGN = 270,                  /* ASSIGN  */
    ADD_EQ = 271,                  /* ADD_EQ  */
    SUB_EQ = 272,                  /* SUB_EQ  */
    MUL_EQ = 273,                  /* MUL_EQ  */
    DIV_EQ = 274,                  /* DIV_EQ  */
    MOD_EQ = 275,                  /* MOD_EQ  */
    BITAND_EQ = 276,               /* BITAND_EQ  */
    BITOR_EQ = 277,                /* BITOR_EQ  */
    BITXOR_EQ = 278,               /* BITXOR_EQ  */
    BITNOT_EQ = 279,               /* BITNOT_EQ  */
    SHR_EQ = 280,                  /* SHR_EQ  */
    SHL_EQ = 281,                  /* SHL_EQ  */
    BITAND = 282,                  /* BITAND  */
    BITOR = 283,                   /* BITOR  */
    BITXOR = 284,                  /* BITXOR  */
    BITNOT = 285,                  /* BITNOT  */
    EQ = 286,                      /* EQ  */
    NEQ = 287,                     /* NEQ  */
    LT = 288,                      /* LT  */
    LE = 289,                      /* LE  */
    GT = 290,                      /* GT  */
    GE = 291,                      /* GE  */
    COMMA = 292,                   /* COMMA  */
    COLON = 293,                   /* COLON  */
    SEMI = 294,                    /* SEMI  */
    ARROW = 295,                   /* ARROW  */
    LPAREN = 296,                  /* LPAREN  */
    RPAREN = 297,                  /* RPAREN  */
    LBRACKET = 298,                /* LBRACKET  */
    RBRACKET = 299,                /* RBRACKET  */
    LBRACE = 300,                  /* LBRACE  */
    RBRACE = 301,                  /* RBRACE  */
    DOT = 302,                     /* DOT  */
    AND = 303,                     /* AND  */
    OR = 304,                      /* OR  */
    NOT = 305,                     /* NOT  */
    PLUS = 306,                    /* PLUS  */
    MINUS = 307,                   /* MINUS  */
    MUL = 308,                     /* MUL  */
    DIV = 309,                     /* DIV  */
    MOD = 310,                     /* MOD  */
    SHL = 311,                     /* SHL  */
    SHR = 312,                     /* SHR  */
    INT_LITERAL = 313,             /* INT_LITERAL  */
    FLOAT_LITERAL = 314,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 315,          /* STRING_LITERAL  */
    IDENT = 316,                   /* IDENT  */
    UPLUS = 317,                   /* UPLUS  */
    UMINUS = 318,                  /* UMINUS  */
    POSTFIX = 319                  /* POSTFIX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "src/yacc.y"

    int int_val;
    double float_val;
    char* string_val;
    struct parse_tree_node* node;

#line 135 "src/yacc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_YACC_H_INCLUDED  */
