/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/yacc.y"

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

#line 91 "src/yacc.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRUCT = 3,                     /* STRUCT  */
  YYSYMBOL_FN = 4,                         /* FN  */
  YYSYMBOL_LET = 5,                        /* LET  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IN = 10,                        /* IN  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_NEWLINE = 14,                   /* NEWLINE  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_ADD_EQ = 16,                    /* ADD_EQ  */
  YYSYMBOL_SUB_EQ = 17,                    /* SUB_EQ  */
  YYSYMBOL_MUL_EQ = 18,                    /* MUL_EQ  */
  YYSYMBOL_DIV_EQ = 19,                    /* DIV_EQ  */
  YYSYMBOL_MOD_EQ = 20,                    /* MOD_EQ  */
  YYSYMBOL_BITAND_EQ = 21,                 /* BITAND_EQ  */
  YYSYMBOL_BITOR_EQ = 22,                  /* BITOR_EQ  */
  YYSYMBOL_BITXOR_EQ = 23,                 /* BITXOR_EQ  */
  YYSYMBOL_BITNOT_EQ = 24,                 /* BITNOT_EQ  */
  YYSYMBOL_SHR_EQ = 25,                    /* SHR_EQ  */
  YYSYMBOL_SHL_EQ = 26,                    /* SHL_EQ  */
  YYSYMBOL_BITAND = 27,                    /* BITAND  */
  YYSYMBOL_BITOR = 28,                     /* BITOR  */
  YYSYMBOL_BITXOR = 29,                    /* BITXOR  */
  YYSYMBOL_BITNOT = 30,                    /* BITNOT  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NEQ = 32,                       /* NEQ  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_GE = 36,                        /* GE  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_SEMI = 39,                      /* SEMI  */
  YYSYMBOL_ARROW = 40,                     /* ARROW  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 43,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 44,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 45,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 46,                    /* RBRACE  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_AND = 48,                       /* AND  */
  YYSYMBOL_OR = 49,                        /* OR  */
  YYSYMBOL_NOT = 50,                       /* NOT  */
  YYSYMBOL_PLUS = 51,                      /* PLUS  */
  YYSYMBOL_MINUS = 52,                     /* MINUS  */
  YYSYMBOL_MUL = 53,                       /* MUL  */
  YYSYMBOL_DIV = 54,                       /* DIV  */
  YYSYMBOL_MOD = 55,                       /* MOD  */
  YYSYMBOL_SHL = 56,                       /* SHL  */
  YYSYMBOL_SHR = 57,                       /* SHR  */
  YYSYMBOL_INT_LITERAL = 58,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 59,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 60,            /* STRING_LITERAL  */
  YYSYMBOL_IDENT = 61,                     /* IDENT  */
  YYSYMBOL_UPLUS = 62,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 63,                    /* UMINUS  */
  YYSYMBOL_POSTFIX = 64,                   /* POSTFIX  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_declaration_list = 67,          /* declaration_list  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_struct_definition = 69,         /* struct_definition  */
  YYSYMBOL_struct_field_list = 70,         /* struct_field_list  */
  YYSYMBOL_struct_field = 71,              /* struct_field  */
  YYSYMBOL_function_definition = 72,       /* function_definition  */
  YYSYMBOL_parameter_list_optional = 73,   /* parameter_list_optional  */
  YYSYMBOL_parameter_list = 74,            /* parameter_list  */
  YYSYMBOL_parameter = 75,                 /* parameter  */
  YYSYMBOL_return_type_optional = 76,      /* return_type_optional  */
  YYSYMBOL_variable_definition = 77,       /* variable_definition  */
  YYSYMBOL_block = 78,                     /* block  */
  YYSYMBOL_statement_list = 79,            /* statement_list  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_variable_decl_stmt = 81,        /* variable_decl_stmt  */
  YYSYMBOL_assignment_stmt = 82,           /* assignment_stmt  */
  YYSYMBOL_assignment_op = 83,             /* assignment_op  */
  YYSYMBOL_conditional_stmt = 84,          /* conditional_stmt  */
  YYSYMBOL_else_clause_optional = 85,      /* else_clause_optional  */
  YYSYMBOL_while_loop_stmt = 86,           /* while_loop_stmt  */
  YYSYMBOL_for_loop_stmt = 87,             /* for_loop_stmt  */
  YYSYMBOL_break_stmt = 88,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 89,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 90,               /* return_stmt  */
  YYSYMBOL_expression_optional = 91,       /* expression_optional  */
  YYSYMBOL_expression = 92,                /* expression  */
  YYSYMBOL_unary_expression = 93,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 94,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 95,        /* primary_expression  */
  YYSYMBOL_literal = 96,                   /* literal  */
  YYSYMBOL_argument_list_optional = 97,    /* argument_list_optional  */
  YYSYMBOL_argument_list = 98,             /* argument_list  */
  YYSYMBOL_type_optional = 99,             /* type_optional  */
  YYSYMBOL_type = 100,                     /* type  */
  YYSYMBOL_array_size_optional = 101,      /* array_size_optional  */
  YYSYMBOL_numeric = 102                   /* numeric  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   115,   118,   125,   129,   133,   141,   153,
     157,   164,   175,   189,   192,   199,   203,   210,   220,   223,
     232,   245,   255,   258,   265,   269,   273,   277,   281,   285,
     289,   293,   297,   301,   308,   320,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   343,   353,   354,   359,
     367,   376,   388,   392,   396,   403,   404,   411,   417,   423,
     429,   435,   441,   447,   453,   459,   465,   471,   477,   483,
     489,   495,   501,   507,   513,   519,   523,   527,   531,   535,
     539,   543,   550,   557,   567,   571,   576,   585,   590,   595,
     602,   603,   610,   614,   622,   623,   630,   635,   645,   646,
     654,   659
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRUCT", "FN", "LET",
  "IF", "ELSE", "WHILE", "FOR", "IN", "BREAK", "CONTINUE", "RETURN",
  "NEWLINE", "ASSIGN", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ",
  "BITAND_EQ", "BITOR_EQ", "BITXOR_EQ", "BITNOT_EQ", "SHR_EQ", "SHL_EQ",
  "BITAND", "BITOR", "BITXOR", "BITNOT", "EQ", "NEQ", "LT", "LE", "GT",
  "GE", "COMMA", "COLON", "SEMI", "ARROW", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "DOT", "AND", "OR", "NOT", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "SHL", "SHR", "INT_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "IDENT", "UPLUS", "UMINUS", "POSTFIX",
  "$accept", "program", "declaration_list", "declaration",
  "struct_definition", "struct_field_list", "struct_field",
  "function_definition", "parameter_list_optional", "parameter_list",
  "parameter", "return_type_optional", "variable_definition", "block",
  "statement_list", "statement", "variable_decl_stmt", "assignment_stmt",
  "assignment_op", "conditional_stmt", "else_clause_optional",
  "while_loop_stmt", "for_loop_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "expression_optional", "expression", "unary_expression",
  "postfix_expression", "primary_expression", "literal",
  "argument_list_optional", "argument_list", "type_optional", "type",
  "array_size_optional", "numeric", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -91,    36,    21,   -91,   -50,   -40,    -6,   -91,   -91,   -91,
     -91,    15,    28,   -39,    14,    18,   -39,   -91,    55,   -91,
      34,   -32,   -91,    42,    51,    60,   -91,    62,   319,   -39,
      14,   -91,   -39,    59,    18,    -7,    58,   319,   319,   319,
     319,   -91,   -91,   -91,   -91,    56,   -91,    53,   -91,   -91,
     -91,   -91,   -91,   -39,    61,   -91,   -91,   -91,   -91,   -91,
      97,   -91,   -91,   -91,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   -91,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,    54,   -91,   -91,   -91,   -91,
     279,   241,   272,   286,   286,   311,   311,   311,   311,   231,
     200,     9,     9,   -91,   -91,   -91,   -45,   -45,   190,    72,
      66,   128,   -91,     7,   -91,   319,   -91,    57,   319,   319,
      73,   -91,   -91,   319,   -91,   333,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   190,   190,   -39,   159,
     159,   106,   -91,   190,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   319,   104,   113,   -91,   319,   190,
     319,    11,   -91,   159,   190,   -91,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     4,     5,     6,
       7,     0,     0,    94,     0,    13,     0,    96,     0,    95,
       0,     0,     9,     0,     0,    14,    15,    98,     0,     0,
       0,     8,     0,    18,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    85,     0,    75,    79,    80,    84,
      11,    10,    17,     0,     0,    16,   100,   101,    99,    97,
       0,    78,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,     0,    19,    22,    12,    86,
      61,    59,    60,    62,    63,    64,    65,    66,    67,    58,
      57,    70,    71,    72,    73,    74,    68,    69,    92,     0,
      91,     0,    83,     0,    81,     0,    82,     0,     0,     0,
       0,    52,    53,    55,    21,    85,    32,    23,    24,    25,
      26,    27,    28,    30,    31,    29,    33,    93,    94,     0,
       0,     0,    54,    56,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,     0,    47,    50,     0,    35,
       0,     0,    46,     0,    34,    48,    49,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -91,   -91,    92,   -91,   -91,   -91,
      93,   -91,   -91,   -90,   -91,   -91,   -91,   -91,   -91,   -26,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -37,   -91,   -91,
     -91,   -91,   -91,   -91,    -2,    45,   -91,   -91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    21,    22,     9,    24,    25,
      26,    54,    10,    88,   113,   127,   128,   129,   154,   130,
     162,   131,   132,   133,   134,   135,   142,    45,    46,    47,
      48,    49,   109,   110,    18,    19,    36,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    61,    62,    63,    16,    30,    76,    77,    78,    79,
      80,    11,   117,   118,    31,   119,   120,   118,   121,   122,
     123,    12,    17,   126,     4,     5,     6,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     3,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   111,    37,   156,
     157,    56,    87,   124,    57,    13,    87,    38,    39,    40,
      14,    27,    78,    79,    80,    41,    42,    43,   125,    15,
      28,   165,    29,   167,    50,    20,   136,    52,   137,    23,
      32,   139,   140,    64,    65,    66,   143,    67,    68,    69,
      70,    71,    72,    33,    83,    73,    84,    34,    86,    53,
      85,    35,    59,   115,    74,    75,    87,    76,    77,    78,
      79,    80,    81,    82,   114,   112,   158,   159,   138,   160,
     161,   163,    51,   164,    64,    65,    66,    55,    67,    68,
      69,    70,    71,    72,   141,   166,   155,     0,     0,    89,
       0,     0,     0,     0,     0,    74,    75,     0,    76,    77,
      78,    79,    80,    81,    82,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,    74,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,     0,    74,    75,
       0,    76,    77,    78,    79,    80,    81,    82,    74,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    64,     0,
      66,     0,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    64,
       0,     0,     0,    67,    68,    69,    70,    71,    72,     0,
      67,    68,    69,    70,    71,    72,     0,    -1,    -1,    69,
      70,    71,    72,    76,    77,    78,    79,    80,    81,    82,
      76,    77,    78,    79,    80,    81,    82,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
      37,     0,    76,    77,    78,    79,    80,    81,    82,    38,
      39,    40,     0,     0,     0,     0,     0,    41,    42,    43,
      44
};

static const yytype_int16 yycheck[] =
{
      37,    38,    39,    40,    43,    37,    51,    52,    53,    54,
      55,    61,     5,     6,    46,     8,     9,     6,    11,    12,
      13,    61,    61,   113,     3,     4,     5,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    41,   139,
     140,    58,    45,    46,    61,    61,    45,    50,    51,    52,
      45,    16,    53,    54,    55,    58,    59,    60,    61,    41,
      15,   161,    38,   163,    29,    61,   113,    32,   115,    61,
      38,   118,   119,    27,    28,    29,   123,    31,    32,    33,
      34,    35,    36,    42,    41,    39,    43,    37,    53,    40,
      47,    39,    44,    37,    48,    49,    45,    51,    52,    53,
      54,    55,    56,    57,    42,    61,    10,   154,    61,    15,
       7,   158,    30,   160,    27,    28,    29,    34,    31,    32,
      33,    34,    35,    36,    61,   161,   138,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    -1,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    48,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    27,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      31,    32,    33,    34,    35,    36,    -1,    31,    32,    33,
      34,    35,    36,    51,    52,    53,    54,    55,    56,    57,
      51,    52,    53,    54,    55,    56,    57,    51,    52,    53,
      54,    55,    56,    57,    33,    34,    35,    36,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      41,    -1,    51,    52,    53,    54,    55,    56,    57,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,    67,     0,     3,     4,     5,    68,    69,    72,
      77,    61,    61,    61,    45,    41,    43,    61,    99,   100,
      61,    70,    71,    61,    73,    74,    75,   100,    15,    38,
      37,    46,    38,    42,    37,    39,   101,    41,    50,    51,
      52,    58,    59,    60,    61,    92,    93,    94,    95,    96,
     100,    71,   100,    40,    76,    75,    58,    61,   102,    44,
      92,    92,    92,    92,    27,    28,    29,    31,    32,    33,
      34,    35,    36,    39,    48,    49,    51,    52,    53,    54,
      55,    56,    57,    41,    43,    47,   100,    45,    78,    42,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    97,
      98,    92,    61,    79,    42,    37,    44,     5,     6,     8,
       9,    11,    12,    13,    46,    61,    78,    80,    81,    82,
      84,    86,    87,    88,    89,    90,    92,    92,    61,    92,
      92,    61,    91,    92,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    83,    99,    78,    78,    10,    92,
      15,     7,    85,    92,    92,    78,    84,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    69,    70,
      70,    71,    72,    73,    73,    74,    74,    75,    76,    76,
      77,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    85,    85,
      86,    87,    88,    89,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     5,     1,
       3,     3,     7,     0,     1,     1,     3,     3,     0,     2,
       6,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     2,     2,
       3,     5,     1,     1,     2,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     2,     1,
       1,     4,     4,     3,     1,     1,     3,     1,     1,     1,
       0,     1,     1,     3,     0,     1,     1,     4,     0,     2,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 107 "src/yacc.y"
                       {
        (yyval.node) = create_node("program");
        add_child((yyval.node), (yyvsp[0].node));
        root = (yyval.node);
    }
#line 1354 "src/yacc.c"
    break;

  case 3: /* declaration_list: %empty  */
#line 115 "src/yacc.y"
                  {
        (yyval.node) = create_node("declaration_list");
    }
#line 1362 "src/yacc.c"
    break;

  case 4: /* declaration_list: declaration_list declaration  */
#line 118 "src/yacc.y"
                                   {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1371 "src/yacc.c"
    break;

  case 5: /* declaration: struct_definition  */
#line 125 "src/yacc.y"
                        {
        (yyval.node) = create_node("declaration");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1380 "src/yacc.c"
    break;

  case 6: /* declaration: function_definition  */
#line 129 "src/yacc.y"
                          {
        (yyval.node) = create_node("declaration");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1389 "src/yacc.c"
    break;

  case 7: /* declaration: variable_definition  */
#line 133 "src/yacc.y"
                          {
        (yyval.node) = create_node("declaration");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1398 "src/yacc.c"
    break;

  case 8: /* struct_definition: STRUCT IDENT LBRACE struct_field_list RBRACE  */
#line 141 "src/yacc.y"
                                                   {
        (yyval.node) = create_node("struct_definition");
        add_child((yyval.node), create_node("STRUCT"));
        add_child((yyval.node), create_node((yyvsp[-3].string_val)));
        add_child((yyval.node), create_node("{"));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("}"));
        free((yyvsp[-3].string_val));
    }
#line 1412 "src/yacc.c"
    break;

  case 9: /* struct_field_list: struct_field  */
#line 153 "src/yacc.y"
                               {
        (yyval.node) = create_node("struct_field_list");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1421 "src/yacc.c"
    break;

  case 10: /* struct_field_list: struct_field_list COMMA struct_field  */
#line 157 "src/yacc.y"
                                           {
        (yyval.node) = (yyvsp[-2].node);
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1430 "src/yacc.c"
    break;

  case 11: /* struct_field: IDENT COLON type  */
#line 164 "src/yacc.y"
                       {
        (yyval.node) = create_node("struct_field");
        add_child((yyval.node), create_node((yyvsp[-2].string_val)));
        add_child((yyval.node), create_node(":"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        free((yyvsp[-2].string_val));
    }
#line 1442 "src/yacc.c"
    break;

  case 12: /* function_definition: FN IDENT LPAREN parameter_list_optional RPAREN return_type_optional block  */
#line 175 "src/yacc.y"
                                                                                {
        (yyval.node) = create_node("function_definition");
        add_child((yyval.node), create_node("FN"));
        add_child((yyval.node), create_node((yyvsp[-5].string_val)));
        add_child((yyval.node), create_node("("));
        if ((yyvsp[-3].node)) add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node(")"));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        free((yyvsp[-5].string_val));
    }
#line 1458 "src/yacc.c"
    break;

  case 13: /* parameter_list_optional: %empty  */
#line 189 "src/yacc.y"
                  {
        (yyval.node) = create_node("parameter_list_optional");
    }
#line 1466 "src/yacc.c"
    break;

  case 14: /* parameter_list_optional: parameter_list  */
#line 192 "src/yacc.y"
                     {
        (yyval.node) = create_node("parameter_list_optional");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1475 "src/yacc.c"
    break;

  case 15: /* parameter_list: parameter  */
#line 199 "src/yacc.y"
                {
        (yyval.node) = create_node("parameter_list");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1484 "src/yacc.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA parameter  */
#line 203 "src/yacc.y"
                                     {
        (yyval.node) = (yyvsp[-2].node);
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1493 "src/yacc.c"
    break;

  case 17: /* parameter: IDENT COLON type  */
#line 210 "src/yacc.y"
                       {
        (yyval.node) = create_node("parameter");
        add_child((yyval.node), create_node((yyvsp[-2].string_val)));
        add_child((yyval.node), create_node(":"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        free((yyvsp[-2].string_val));
    }
#line 1505 "src/yacc.c"
    break;

  case 18: /* return_type_optional: %empty  */
#line 220 "src/yacc.y"
                  {
        (yyval.node) = create_node("return_type_optional");
    }
#line 1513 "src/yacc.c"
    break;

  case 19: /* return_type_optional: ARROW type  */
#line 223 "src/yacc.y"
                 {
        (yyval.node) = create_node("return_type_optional");
        add_child((yyval.node), create_node("ARROW"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1523 "src/yacc.c"
    break;

  case 20: /* variable_definition: LET IDENT type_optional ASSIGN expression SEMI  */
#line 232 "src/yacc.y"
                                                     {
        (yyval.node) = create_node("variable_definition");
        add_child((yyval.node), create_node("LET"));
        add_child((yyval.node), create_node((yyvsp[-4].string_val)));
        if ((yyvsp[-3].node)) add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("="));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node(";"));
        free((yyvsp[-4].string_val));
    }
#line 1538 "src/yacc.c"
    break;

  case 21: /* block: LBRACE statement_list RBRACE  */
#line 245 "src/yacc.y"
                                   {
        (yyval.node) = create_node("block");
        add_child((yyval.node), create_node("{"));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("}"));
    }
#line 1549 "src/yacc.c"
    break;

  case 22: /* statement_list: %empty  */
#line 255 "src/yacc.y"
                  {
        (yyval.node) = create_node("statement_list");
    }
#line 1557 "src/yacc.c"
    break;

  case 23: /* statement_list: statement_list statement  */
#line 258 "src/yacc.y"
                               {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1566 "src/yacc.c"
    break;

  case 24: /* statement: variable_decl_stmt  */
#line 265 "src/yacc.y"
                         {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1575 "src/yacc.c"
    break;

  case 25: /* statement: assignment_stmt  */
#line 269 "src/yacc.y"
                      {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1584 "src/yacc.c"
    break;

  case 26: /* statement: conditional_stmt  */
#line 273 "src/yacc.y"
                       {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1593 "src/yacc.c"
    break;

  case 27: /* statement: while_loop_stmt  */
#line 277 "src/yacc.y"
                      {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1602 "src/yacc.c"
    break;

  case 28: /* statement: for_loop_stmt  */
#line 281 "src/yacc.y"
                    {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1611 "src/yacc.c"
    break;

  case 29: /* statement: return_stmt  */
#line 285 "src/yacc.y"
                  {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1620 "src/yacc.c"
    break;

  case 30: /* statement: break_stmt  */
#line 289 "src/yacc.y"
                 {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1629 "src/yacc.c"
    break;

  case 31: /* statement: continue_stmt  */
#line 293 "src/yacc.y"
                    {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1638 "src/yacc.c"
    break;

  case 32: /* statement: block  */
#line 297 "src/yacc.y"
            {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1647 "src/yacc.c"
    break;

  case 33: /* statement: expression  */
#line 301 "src/yacc.y"
                 {
        (yyval.node) = create_node("statement");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1656 "src/yacc.c"
    break;

  case 34: /* variable_decl_stmt: LET IDENT type_optional ASSIGN expression  */
#line 308 "src/yacc.y"
                                                {
        (yyval.node) = create_node("variable_decl_stmt");
        add_child((yyval.node), create_node("LET"));
        add_child((yyval.node), create_node((yyvsp[-3].string_val)));
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("="));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        free((yyvsp[-3].string_val));
    }
#line 1670 "src/yacc.c"
    break;

  case 35: /* assignment_stmt: IDENT assignment_op expression  */
#line 320 "src/yacc.y"
                                     {
        (yyval.node) = create_node("assignment_stmt");
        add_child((yyval.node), create_node((yyvsp[-2].string_val)));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        free((yyvsp[-2].string_val));
    }
#line 1682 "src/yacc.c"
    break;

  case 36: /* assignment_op: ASSIGN  */
#line 330 "src/yacc.y"
                    { (yyval.node) = create_node("="); }
#line 1688 "src/yacc.c"
    break;

  case 37: /* assignment_op: ADD_EQ  */
#line 331 "src/yacc.y"
                    { (yyval.node) = create_node("+="); }
#line 1694 "src/yacc.c"
    break;

  case 38: /* assignment_op: SUB_EQ  */
#line 332 "src/yacc.y"
                    { (yyval.node) = create_node("-="); }
#line 1700 "src/yacc.c"
    break;

  case 39: /* assignment_op: MUL_EQ  */
#line 333 "src/yacc.y"
                    { (yyval.node) = create_node("*="); }
#line 1706 "src/yacc.c"
    break;

  case 40: /* assignment_op: DIV_EQ  */
#line 334 "src/yacc.y"
                    { (yyval.node) = create_node("/="); }
#line 1712 "src/yacc.c"
    break;

  case 41: /* assignment_op: MOD_EQ  */
#line 335 "src/yacc.y"
                    { (yyval.node) = create_node("%="); }
#line 1718 "src/yacc.c"
    break;

  case 42: /* assignment_op: BITAND_EQ  */
#line 336 "src/yacc.y"
                    { (yyval.node) = create_node("&="); }
#line 1724 "src/yacc.c"
    break;

  case 43: /* assignment_op: BITOR_EQ  */
#line 337 "src/yacc.y"
                    { (yyval.node) = create_node("|="); }
#line 1730 "src/yacc.c"
    break;

  case 44: /* assignment_op: BITXOR_EQ  */
#line 338 "src/yacc.y"
                    { (yyval.node) = create_node("^="); }
#line 1736 "src/yacc.c"
    break;

  case 45: /* assignment_op: BITNOT_EQ  */
#line 339 "src/yacc.y"
                    { (yyval.node) = create_node("~="); }
#line 1742 "src/yacc.c"
    break;

  case 46: /* conditional_stmt: IF expression block else_clause_optional  */
#line 343 "src/yacc.y"
                                               {
        (yyval.node) = create_node("conditional_stmt");
        add_child((yyval.node), create_node("IF"));
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1754 "src/yacc.c"
    break;

  case 47: /* else_clause_optional: %empty  */
#line 353 "src/yacc.y"
                  { (yyval.node) = NULL; }
#line 1760 "src/yacc.c"
    break;

  case 48: /* else_clause_optional: ELSE block  */
#line 354 "src/yacc.y"
                 {
        (yyval.node) = create_node("else_clause_optional");
        add_child((yyval.node), create_node("ELSE"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1770 "src/yacc.c"
    break;

  case 49: /* else_clause_optional: ELSE conditional_stmt  */
#line 359 "src/yacc.y"
                            {
        (yyval.node) = create_node("else_clause_optional");
        add_child((yyval.node), create_node("ELSE"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1780 "src/yacc.c"
    break;

  case 50: /* while_loop_stmt: WHILE expression block  */
#line 367 "src/yacc.y"
                             {
        (yyval.node) = create_node("while_loop_stmt");
        add_child((yyval.node), create_node("WHILE"));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1791 "src/yacc.c"
    break;

  case 51: /* for_loop_stmt: FOR IDENT IN expression block  */
#line 376 "src/yacc.y"
                                    {
        (yyval.node) = create_node("for_loop_stmt");
        add_child((yyval.node), create_node("FOR"));
        add_child((yyval.node), create_node((yyvsp[-3].string_val)));
        add_child((yyval.node), create_node("IN"));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        free((yyvsp[-3].string_val));
    }
#line 1805 "src/yacc.c"
    break;

  case 52: /* break_stmt: BREAK  */
#line 388 "src/yacc.y"
            { (yyval.node) = create_node("BREAK"); }
#line 1811 "src/yacc.c"
    break;

  case 53: /* continue_stmt: CONTINUE  */
#line 392 "src/yacc.y"
               { (yyval.node) = create_node("CONTINUE"); }
#line 1817 "src/yacc.c"
    break;

  case 54: /* return_stmt: RETURN expression_optional  */
#line 396 "src/yacc.y"
                                 {
        (yyval.node) = create_node("RETURN");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1826 "src/yacc.c"
    break;

  case 55: /* expression_optional: %empty  */
#line 403 "src/yacc.y"
                  { (yyval.node) = NULL; }
#line 1832 "src/yacc.c"
    break;

  case 56: /* expression_optional: expression  */
#line 404 "src/yacc.y"
                 {
        (yyval.node) = create_node("expression_optional");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1841 "src/yacc.c"
    break;

  case 57: /* expression: expression OR expression  */
#line 411 "src/yacc.y"
                               {
        (yyval.node) = create_node("or");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("OR"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1852 "src/yacc.c"
    break;

  case 58: /* expression: expression AND expression  */
#line 417 "src/yacc.y"
                                {
        (yyval.node) = create_node("and");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("AND"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1863 "src/yacc.c"
    break;

  case 59: /* expression: expression BITOR expression  */
#line 423 "src/yacc.y"
                                  {
        (yyval.node) = create_node("bitor");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("|"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1874 "src/yacc.c"
    break;

  case 60: /* expression: expression BITXOR expression  */
#line 429 "src/yacc.y"
                                   {
        (yyval.node) = create_node("bitxor");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("^"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1885 "src/yacc.c"
    break;

  case 61: /* expression: expression BITAND expression  */
#line 435 "src/yacc.y"
                                   {
        (yyval.node) = create_node("bitand");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("&"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1896 "src/yacc.c"
    break;

  case 62: /* expression: expression EQ expression  */
#line 441 "src/yacc.y"
                               {
        (yyval.node) = create_node("eq");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("=="));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1907 "src/yacc.c"
    break;

  case 63: /* expression: expression NEQ expression  */
#line 447 "src/yacc.y"
                                {
        (yyval.node) = create_node("neq");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("!="));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1918 "src/yacc.c"
    break;

  case 64: /* expression: expression LT expression  */
#line 453 "src/yacc.y"
                               {
        (yyval.node) = create_node("lt");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("<"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1929 "src/yacc.c"
    break;

  case 65: /* expression: expression LE expression  */
#line 459 "src/yacc.y"
                               {
        (yyval.node) = create_node("le");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("<="));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1940 "src/yacc.c"
    break;

  case 66: /* expression: expression GT expression  */
#line 465 "src/yacc.y"
                               {
        (yyval.node) = create_node("gt");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node(">"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1951 "src/yacc.c"
    break;

  case 67: /* expression: expression GE expression  */
#line 471 "src/yacc.y"
                               {
        (yyval.node) = create_node("ge");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node(">="));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1962 "src/yacc.c"
    break;

  case 68: /* expression: expression SHL expression  */
#line 477 "src/yacc.y"
                                {
        (yyval.node) = create_node("shl");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("<<"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1973 "src/yacc.c"
    break;

  case 69: /* expression: expression SHR expression  */
#line 483 "src/yacc.y"
                                {
        (yyval.node) = create_node("shr");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node(">>"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1984 "src/yacc.c"
    break;

  case 70: /* expression: expression PLUS expression  */
#line 489 "src/yacc.y"
                                 {
        (yyval.node) = create_node("add");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("+"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1995 "src/yacc.c"
    break;

  case 71: /* expression: expression MINUS expression  */
#line 495 "src/yacc.y"
                                  {
        (yyval.node) = create_node("sub");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("-"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2006 "src/yacc.c"
    break;

  case 72: /* expression: expression MUL expression  */
#line 501 "src/yacc.y"
                                {
        (yyval.node) = create_node("mul");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("*"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2017 "src/yacc.c"
    break;

  case 73: /* expression: expression DIV expression  */
#line 507 "src/yacc.y"
                                {
        (yyval.node) = create_node("div");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("/"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2028 "src/yacc.c"
    break;

  case 74: /* expression: expression MOD expression  */
#line 513 "src/yacc.y"
                                {
        (yyval.node) = create_node("mod");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("%"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2039 "src/yacc.c"
    break;

  case 75: /* expression: unary_expression  */
#line 519 "src/yacc.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2045 "src/yacc.c"
    break;

  case 76: /* unary_expression: PLUS expression  */
#line 523 "src/yacc.y"
                                  {
        (yyval.node) = create_node("unary_plus");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2054 "src/yacc.c"
    break;

  case 77: /* unary_expression: MINUS expression  */
#line 527 "src/yacc.y"
                                    {
        (yyval.node) = create_node("unary_minus");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2063 "src/yacc.c"
    break;

  case 78: /* unary_expression: NOT expression  */
#line 531 "src/yacc.y"
                     {
        (yyval.node) = create_node("unary_not");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2072 "src/yacc.c"
    break;

  case 79: /* unary_expression: postfix_expression  */
#line 535 "src/yacc.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2078 "src/yacc.c"
    break;

  case 80: /* postfix_expression: primary_expression  */
#line 539 "src/yacc.y"
                         {
        (yyval.node) = create_node("postfix_expression");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2087 "src/yacc.c"
    break;

  case 81: /* postfix_expression: postfix_expression LPAREN argument_list_optional RPAREN  */
#line 543 "src/yacc.y"
                                                                            {
        (yyval.node) = create_node("postfix_expression");
        if ((yyvsp[-3].node)) add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("("));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node(")"));
    }
#line 2099 "src/yacc.c"
    break;

  case 82: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 550 "src/yacc.y"
                                                                    {
        (yyval.node) = create_node("postfix_expression");
        if ((yyvsp[-3].node)) add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), create_node("["));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("]"));
    }
#line 2111 "src/yacc.c"
    break;

  case 83: /* postfix_expression: postfix_expression DOT IDENT  */
#line 557 "src/yacc.y"
                                                 {
        (yyval.node) = create_node("postfix_expression");
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), create_node("."));
        add_child((yyval.node), create_node((yyvsp[0].string_val)));
        free((yyvsp[0].string_val));
    }
#line 2123 "src/yacc.c"
    break;

  case 84: /* primary_expression: literal  */
#line 567 "src/yacc.y"
              {
        (yyval.node) = create_node("primary_expression");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2132 "src/yacc.c"
    break;

  case 85: /* primary_expression: IDENT  */
#line 571 "src/yacc.y"
            {
        (yyval.node) = create_node("primary_expression");
        add_child((yyval.node), create_node((yyvsp[0].string_val)));
        free((yyvsp[0].string_val));
    }
#line 2142 "src/yacc.c"
    break;

  case 86: /* primary_expression: LPAREN expression RPAREN  */
#line 576 "src/yacc.y"
                               {
        (yyval.node) = create_node("primary_expression");
        add_child((yyval.node), create_node("("));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node(")"));
    }
#line 2153 "src/yacc.c"
    break;

  case 87: /* literal: INT_LITERAL  */
#line 585 "src/yacc.y"
                  { 
        char buffer[32];
        sprintf(buffer, "%d", (yyvsp[0].int_val));
        (yyval.node) = create_node(buffer); 
    }
#line 2163 "src/yacc.c"
    break;

  case 88: /* literal: FLOAT_LITERAL  */
#line 590 "src/yacc.y"
                    { 
        char buffer[32];
        sprintf(buffer, "%f", (yyvsp[0].float_val));
        (yyval.node) = create_node(buffer); 
    }
#line 2173 "src/yacc.c"
    break;

  case 89: /* literal: STRING_LITERAL  */
#line 595 "src/yacc.y"
                     { 
        (yyval.node) = create_node((yyvsp[0].string_val)); 
        free((yyvsp[0].string_val));
    }
#line 2182 "src/yacc.c"
    break;

  case 90: /* argument_list_optional: %empty  */
#line 602 "src/yacc.y"
                  { (yyval.node) = NULL; }
#line 2188 "src/yacc.c"
    break;

  case 91: /* argument_list_optional: argument_list  */
#line 603 "src/yacc.y"
                    {
        (yyval.node) = create_node("argument_list_optional");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2197 "src/yacc.c"
    break;

  case 92: /* argument_list: expression  */
#line 610 "src/yacc.y"
                 {
        (yyval.node) = create_node("argument_list");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2206 "src/yacc.c"
    break;

  case 93: /* argument_list: argument_list COMMA expression  */
#line 614 "src/yacc.y"
                                     {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), create_node(","));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2216 "src/yacc.c"
    break;

  case 94: /* type_optional: %empty  */
#line 622 "src/yacc.y"
                  { (yyval.node) = NULL; }
#line 2222 "src/yacc.c"
    break;

  case 95: /* type_optional: type  */
#line 623 "src/yacc.y"
           {
        (yyval.node) = create_node("type_optional");
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2231 "src/yacc.c"
    break;

  case 96: /* type: IDENT  */
#line 630 "src/yacc.y"
            {
        (yyval.node) = create_node("type");
        add_child((yyval.node), create_node((yyvsp[0].string_val)));
        free((yyvsp[0].string_val));
    }
#line 2241 "src/yacc.c"
    break;

  case 97: /* type: LBRACKET type array_size_optional RBRACKET  */
#line 635 "src/yacc.y"
                                                 {
        (yyval.node) = create_node("type");
        add_child((yyval.node), create_node("["));
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), create_node("]"));
    }
#line 2253 "src/yacc.c"
    break;

  case 98: /* array_size_optional: %empty  */
#line 645 "src/yacc.y"
                  { (yyval.node) = NULL; }
#line 2259 "src/yacc.c"
    break;

  case 99: /* array_size_optional: SEMI numeric  */
#line 646 "src/yacc.y"
                   {
        (yyval.node) = create_node("array_size_optional");
        add_child((yyval.node), create_node(";"));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 2269 "src/yacc.c"
    break;

  case 100: /* numeric: INT_LITERAL  */
#line 654 "src/yacc.y"
                  { 
        char buffer[32];
        sprintf(buffer, "%d", (yyvsp[0].int_val));
        (yyval.node) = create_node(buffer); 
    }
#line 2279 "src/yacc.c"
    break;

  case 101: /* numeric: IDENT  */
#line 659 "src/yacc.y"
            { 
        (yyval.node) = create_node((yyvsp[0].string_val));
        free((yyvsp[0].string_val));
    }
#line 2288 "src/yacc.c"
    break;


#line 2292 "src/yacc.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 665 "src/yacc.y"


void yyerror(const char *msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
}

int main(void) {
    int result = yyparse();
    if (root) {
        print_tree(root);
        free_tree(root);
    }
    return result;
}
