/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 258,
     IDENTIFIER = 259,
     INTLITERAL = 260,
     FLOATLITERAL = 261,
     STRINGLITERAL = 262,
     PROGRAM = 263,
     BEG = 264,
     FUNCTION = 265,
     READ = 266,
     WRITE = 267,
     IF = 268,
     ELSE = 269,
     ENDIF = 270,
     WHILE = 271,
     ENDWHILE = 272,
     RETURN = 273,
     INT = 274,
     VOID = 275,
     STRING = 276,
     FLOAT = 277,
     TRUE = 278,
     FALSE = 279,
     DEF = 280,
     ADD = 281,
     SUB = 282,
     MUL = 283,
     DIV = 284,
     EQ = 285,
     NEQ = 286,
     LESS = 287,
     GRET = 288,
     LPAR = 289,
     RPAR = 290,
     SEMI = 291,
     COM = 292,
     LEQ = 293,
     GEQ = 294
   };
#endif
/* Tokens.  */
#define END 258
#define IDENTIFIER 259
#define INTLITERAL 260
#define FLOATLITERAL 261
#define STRINGLITERAL 262
#define PROGRAM 263
#define BEG 264
#define FUNCTION 265
#define READ 266
#define WRITE 267
#define IF 268
#define ELSE 269
#define ENDIF 270
#define WHILE 271
#define ENDWHILE 272
#define RETURN 273
#define INT 274
#define VOID 275
#define STRING 276
#define FLOAT 277
#define TRUE 278
#define FALSE 279
#define DEF 280
#define ADD 281
#define SUB 282
#define MUL 283
#define DIV 284
#define EQ 285
#define NEQ 286
#define LESS 287
#define GRET 288
#define LPAR 289
#define RPAR 290
#define SEMI 291
#define COM 292
#define LEQ 293
#define GEQ 294




/* Copy the first part of user declarations.  */
#line 1 "microParser.y"

	#include "ASTNode.h"
    #include <iostream>
    #include <sstream>
    #include <stdio.h>
	#include <cstdlib>
	#include <string.h>
	#include <string>
	#include <list>
    #include "stack.h"
    #include "table.h"
    #include "table_entry.h"
#line 16 "microParser.y"

    extern int yylex();
    extern int yylineno;
    extern char * yytext;
    void yyerror(const char * s) {
        //printf("Error Line %d token %s\n",yylineno,yytext);
    }

    stack* myStack = NULL;
    std::list<ASTNode*>* listAST = NULL;
    std::string varType = "FLOAT";
    int scope = 1;
    int flag = 0;
		int decl = 1;
		int io_flag = 0;
    table currTable;
    table globalTable;
    ASTNode *tmpNode = NULL;
    ASTNode *listID = NULL;
    std::ostringstream os;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 38 "microParser.y"
{
	int intValue;
    float floatValue;
    char * stringValue;
    ASTNode *treeNode;

}
/* Line 193 of yacc.c.  */
#line 217 "microParser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 230 "microParser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    11,    13,    16,    19,    22,    23,
      29,    31,    32,    37,    39,    41,    43,    45,    46,    50,
      51,    56,    57,    60,    61,    64,    68,    69,    72,    73,
      74,    75,    76,    89,    90,    94,    97,    98,   100,   102,
     104,   106,   108,   110,   112,   113,   117,   121,   122,   123,
     124,   133,   134,   135,   136,   145,   149,   152,   156,   157,
     160,   164,   165,   167,   169,   174,   175,   179,   180,   181,
     186,   187,   191,   193,   195,   197,   199,   201,   203,   205,
     206,   216,   217,   222,   223,   227,   229,   231,   233,   235,
     237,   239,   241,   243,   244,   253,   255
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    -1,    42,     8,    43,     9,    44,     3,
      -1,     4,    -1,    45,    59,    -1,    46,    45,    -1,    48,
      45,    -1,    -1,    21,    43,    25,    47,    36,    -1,     7,
      -1,    -1,    50,    49,    52,    36,    -1,    22,    -1,    19,
      -1,    50,    -1,    20,    -1,    -1,    43,    53,    54,    -1,
      -1,    37,    43,    55,    54,    -1,    -1,    57,    58,    -1,
      -1,    50,    43,    -1,    37,    57,    58,    -1,    -1,    60,
      59,    -1,    -1,    -1,    -1,    -1,    10,    61,    51,    43,
      62,    34,    56,    35,    63,     9,    64,     3,    -1,    -1,
      45,    65,    66,    -1,    67,    66,    -1,    -1,    68,    -1,
      94,    -1,   103,    -1,    69,    -1,    72,    -1,    76,    -1,
     102,    -1,    -1,    71,    70,    36,    -1,    43,    25,    81,
      -1,    -1,    -1,    -1,    73,    11,    34,    74,    52,    75,
      35,    36,    -1,    -1,    -1,    -1,    77,    12,    34,    78,
      52,    79,    35,    36,    -1,    18,    81,    36,    -1,    82,
      83,    -1,    82,    83,    92,    -1,    -1,    84,    85,    -1,
      84,    85,    93,    -1,    -1,    91,    -1,    86,    -1,    43,
      34,    87,    35,    -1,    -1,    81,    88,    89,    -1,    -1,
      -1,    37,    81,    90,    89,    -1,    -1,    34,    81,    35,
      -1,    43,    -1,     5,    -1,     6,    -1,    26,    -1,    27,
      -1,    28,    -1,    29,    -1,    -1,    13,    34,    98,    35,
      95,    45,    66,    96,    15,    -1,    -1,    14,    97,    45,
      66,    -1,    -1,    81,    99,    81,    -1,    23,    -1,    24,
      -1,    32,    -1,    33,    -1,    30,    -1,    31,    -1,    38,
      -1,    39,    -1,    -1,    16,    34,    98,    35,   101,    45,
      66,    17,    -1,    80,    -1,   100,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    55,    56,    67,    68,    68,    68,    70,
      71,    73,    73,    74,    74,    75,    75,    76,    76,    82,
      82,    87,    89,    89,    90,    91,    91,    93,    93,    94,
      94,    94,    94,    95,    95,    97,    97,    98,    98,    98,
      99,    99,    99,    99,   101,   101,   102,   113,   113,   113,
     113,   114,   114,   114,   114,   115,   117,   122,   128,   129,
     134,   140,   141,   141,   142,   143,   143,   143,   144,   144,
     144,   145,   145,   145,   145,   146,   146,   147,   147,   149,
     149,   150,   150,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   160,   162,   163
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"end of file\"", "IDENTIFIER",
  "INTLITERAL", "FLOATLITERAL", "STRINGLITERAL", "PROGRAM", "BEG",
  "FUNCTION", "READ", "WRITE", "IF", "ELSE", "ENDIF", "WHILE", "ENDWHILE",
  "RETURN", "INT", "VOID", "STRING", "FLOAT", "TRUE", "FALSE", "\":=\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"=\"", "\"!=\"", "\"<\"", "\">\"",
  "\"(\"", "\")\"", "\";\"", "\",\"", "\"<=\"", "\">=\"", "$accept",
  "program", "@1", "id", "pgm_body", "decl", "string_decl", "str",
  "var_decl", "@2", "var_type", "any_type", "id_list", "@3", "id_tail",
  "@4", "param_decl_list", "param_decl", "param_decl_tail",
  "func_declarations", "func_decl", "@5", "@6", "@7", "func_body", "@8",
  "stmt_list", "stmt", "base_stmt", "assign_stmt", "@9", "assign_expr",
  "read_stmt", "@10", "@11", "@12", "write_stmt", "@13", "@14", "@15",
  "return_stmt", "expr", "expr_prefix", "factor", "factor_prefix",
  "postfix_expr", "call_expr", "expr_list", "@16", "expr_list_tail", "@17",
  "primary", "addop", "mulop", "if_stmt", "@18", "else_part", "@19",
  "cond", "compop", "while_stmt", "@20", "control_stmt", "loop_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    44,    45,    45,    45,    46,
      47,    49,    48,    50,    50,    51,    51,    53,    52,    55,
      54,    54,    56,    56,    57,    58,    58,    59,    59,    61,
      62,    63,    60,    65,    64,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    70,    69,    71,    73,    74,    75,
      72,    77,    78,    79,    76,    80,    81,    82,    82,    83,
      84,    84,    85,    85,    86,    88,    87,    87,    90,    89,
      89,    91,    91,    91,    91,    92,    92,    93,    93,    95,
      94,    97,    96,    96,    98,    98,    98,    99,    99,    99,
      99,    99,    99,   101,   100,   102,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     1,     2,     2,     2,     0,     5,
       1,     0,     4,     1,     1,     1,     1,     0,     3,     0,
       4,     0,     2,     0,     2,     3,     0,     2,     0,     0,
       0,     0,    12,     0,     3,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     3,     0,     0,     0,
       8,     0,     0,     0,     8,     3,     2,     3,     0,     2,
       3,     0,     1,     1,     4,     0,     3,     0,     0,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       9,     0,     4,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     8,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     4,     0,     8,    14,     0,
      13,     0,    28,     8,     8,    11,     0,     3,    29,     5,
      28,     6,     7,     0,     0,     0,    27,    17,     0,    10,
       0,    16,    15,     0,    21,    12,     9,    30,     0,    18,
       0,    19,    23,    21,     0,     0,    26,    20,    24,    31,
       0,    22,     0,    26,     8,    25,    33,     0,    36,    32,
       0,     0,    58,     0,    34,    36,    37,    40,    44,    41,
       0,    42,     0,    95,    38,    96,    43,    39,    58,    58,
       0,    61,    58,    35,     0,     0,     0,    85,    86,     0,
       0,     0,    55,    56,     0,    46,    45,    48,    52,    89,
      90,    87,    88,    91,    92,    58,    79,    93,    75,    76,
      57,    73,    74,    58,    72,    59,    63,    62,     0,     0,
      84,     8,     8,     0,    58,    77,    78,    60,    49,    53,
      36,    36,    71,    65,     0,     0,     0,    83,     0,    70,
      64,     0,     0,    81,     0,    94,    58,    66,    50,    54,
       8,    80,    68,    36,    70,    82,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    63,    11,    12,    13,    30,    14,    23,
      15,    33,    28,    34,    39,    43,    45,    46,    51,    19,
      20,    25,    40,    52,    57,    58,    64,    65,    66,    67,
      84,    68,    69,    70,   118,   135,    71,    72,   119,   136,
      73,    89,    81,    93,    94,   115,   116,   134,   139,   147,
     154,   117,   110,   127,    74,   121,   144,   150,    90,   105,
      75,   122,    76,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -75
static const yytype_int8 yypact[] =
{
     -75,    23,    27,   -75,    46,   -75,    42,    18,   -75,    46,
     -75,    49,    43,    18,    18,   -75,    29,   -75,   -75,   -75,
      43,   -75,   -75,    46,    50,    -3,   -75,   -75,    22,   -75,
      24,   -75,   -75,    46,    19,   -75,   -75,   -75,    46,   -75,
      25,   -75,    10,    19,    46,    26,    28,   -75,   -75,   -75,
      10,   -75,    53,    28,    18,   -75,   -75,    60,     2,   -75,
      30,    33,   -75,    45,   -75,     2,   -75,   -75,   -75,   -75,
      61,   -75,    59,   -75,   -75,   -75,   -75,   -75,   -12,   -12,
      37,   -75,   -75,   -75,    38,    41,    44,   -75,   -75,    -5,
      47,    48,   -75,    17,     4,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,    51,    20,   -75,   -75,    46,    46,
     -75,    18,    18,    52,    54,   -75,   -75,   -75,   -75,   -75,
       2,     2,   -75,   -75,    55,    58,    62,    63,    64,    39,
     -75,    65,    66,   -75,    69,   -75,   -75,   -75,   -75,   -75,
      18,   -75,   -75,     2,    39,   -75,   -75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,    -2,   -75,   -13,   -75,   -75,   -75,   -75,
     -20,   -75,   -73,   -75,    36,   -75,   -75,    56,    57,    74,
     -75,   -75,   -75,   -75,   -75,   -75,   -62,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -58,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -74,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     7,   -75,
     -75,   -75,   -75,   -75
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -68
static const yytype_int16 yytable[] =
{
      21,    22,     6,    83,    80,    32,     5,    16,     5,   111,
     112,    87,    88,   -47,   -51,    60,     8,    31,    61,    10,
      62,    27,    44,     3,    95,    99,   100,   101,   102,     8,
      44,    37,    10,   103,   104,     4,    41,     8,   113,     9,
      10,    56,    48,   108,   109,   128,   129,   120,   125,   126,
       5,     7,    17,    18,    24,   123,    38,    29,    35,    42,
      36,    49,    54,    59,    78,    50,   133,    79,   137,   138,
      82,    86,    85,    92,    96,    97,   146,   143,    98,    47,
     156,   145,   106,   107,   151,   124,    91,   132,   152,   -67,
     140,   155,   114,   141,    26,     0,     0,   142,     0,     0,
       0,   148,   149,     0,     0,     0,    53,     0,   130,   131,
      55,     0,     0,     0,     0,     0,    27,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153
};

static const yytype_int16 yycheck[] =
{
      13,    14,     4,    65,    62,    25,     4,     9,     4,     5,
       6,    23,    24,    11,    12,    13,    19,    20,    16,    22,
      18,    23,    42,     0,    82,    30,    31,    32,    33,    19,
      50,    33,    22,    38,    39,     8,    38,    19,    34,    21,
      22,    54,    44,    26,    27,   118,   119,   105,    28,    29,
       4,     9,     3,    10,    25,   113,    37,     7,    36,    34,
      36,    35,     9,     3,    34,    37,   124,    34,   130,   131,
      25,    12,    11,    36,    36,    34,    37,    14,    34,    43,
     154,    17,    35,    35,    15,    34,    79,    35,   146,    35,
      35,   153,    94,    35,    20,    -1,    -1,    35,    -1,    -1,
      -1,    36,    36,    -1,    -1,    -1,    50,    -1,   121,   122,
      53,    -1,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     8,     4,    43,     9,    19,    21,
      22,    44,    45,    46,    48,    50,    43,     3,    10,    59,
      60,    45,    45,    49,    25,    61,    59,    43,    52,     7,
      47,    20,    50,    51,    53,    36,    36,    43,    37,    54,
      62,    43,    34,    55,    50,    56,    57,    54,    43,    35,
      37,    58,    63,    57,     9,    58,    45,    64,    65,     3,
      13,    16,    18,    43,    66,    67,    68,    69,    71,    72,
      73,    76,    77,    80,    94,   100,   102,   103,    34,    34,
      81,    82,    25,    66,    70,    11,    12,    23,    24,    81,
      98,    98,    36,    83,    84,    81,    36,    34,    34,    30,
      31,    32,    33,    38,    39,    99,    35,    35,    26,    27,
      92,     5,     6,    34,    43,    85,    86,    91,    74,    78,
      81,    95,   101,    81,    34,    28,    29,    93,    52,    52,
      45,    45,    35,    81,    87,    75,    79,    66,    66,    88,
      35,    35,    35,    14,    96,    17,    37,    89,    36,    36,
      97,    15,    81,    45,    90,    66,    89
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "microParser.y"
    {myStack = new stack; currTable = table("Symbol table GLOBAL"); listAST = new std::list<ASTNode*>;;}
    break;

  case 3:
#line 55 "microParser.y"
    {myStack->push(currTable);;}
    break;

  case 4:
#line 56 "microParser.y"
    {
			if(io_flag)
				{(yyval.stringValue) = (yyvsp[(1) - (1)].stringValue);}
			else
				{if(!decl)
					{std::string s = currTable.index((yyvsp[(1) - (1)].stringValue));
					if(s == "")
						{(yyval.stringValue) = (yyvsp[(1) - (1)].stringValue);}
					else
						{(yyval.stringValue) = (strdup(s.c_str()));}}
				else {(yyval.stringValue) = (yyvsp[(1) - (1)].stringValue);}};}
    break;

  case 9:
#line 70 "microParser.y"
    {currTable.add(table_entry("STRING", ((yyvsp[(2) - (5)].stringValue)), ((yyvsp[(4) - (5)].stringValue))));;}
    break;

  case 10:
#line 71 "microParser.y"
    {(yyval.stringValue) = (yyvsp[(1) - (1)].stringValue);;}
    break;

  case 11:
#line 73 "microParser.y"
    {flag = 1;;}
    break;

  case 13:
#line 74 "microParser.y"
    {varType = "FLOAT";;}
    break;

  case 14:
#line 74 "microParser.y"
    {varType = "INT";;}
    break;

  case 17:
#line 76 "microParser.y"
    {if(flag) {currTable.add(table_entry(varType, ((yyvsp[(1) - (1)].stringValue)), ""));}
				else {varType = currTable.search((yyvsp[(1) - (1)].stringValue));
				if(varType == "") {varType = myStack->tables[0].search((yyvsp[(1) - (1)].stringValue));}
				std::string s = currTable.index((yyvsp[(1) - (1)].stringValue)); if(s == "") {s = (yyvsp[(1) - (1)].stringValue);}
				tmpNode->right = new ASTNode(s,varType); tmpNode = tmpNode->right;};}
    break;

  case 19:
#line 82 "microParser.y"
    {if(flag) {currTable.add(table_entry(varType, ((yyvsp[(2) - (2)].stringValue)), ""));}
					else {varType = currTable.search((yyvsp[(2) - (2)].stringValue));
					if(varType == "") {varType = myStack->tables[0].search((yyvsp[(2) - (2)].stringValue));}
					std::string s = currTable.index((yyvsp[(2) - (2)].stringValue)); if(s == "") {s = (yyvsp[(2) - (2)].stringValue);}
					tmpNode->right = new ASTNode(s,varType); tmpNode = tmpNode->right;};}
    break;

  case 24:
#line 90 "microParser.y"
    {currTable.add(table_entry(((yyvsp[(1) - (2)].stringValue)), ((yyvsp[(2) - (2)].stringValue)), ""));;}
    break;

  case 29:
#line 94 "microParser.y"
    {decl = 1;;}
    break;

  case 30:
#line 94 "microParser.y"
    {listAST->push_back(new ASTNode((yyvsp[(4) - (4)].stringValue), "FUNC")); myStack->push(currTable); currTable = table("Symbol table " + std::string((yyvsp[(4) - (4)].stringValue)));;}
    break;

  case 31:
#line 94 "microParser.y"
    {currTable.pos = currTable.entries.size();;}
    break;

  case 32:
#line 94 "microParser.y"
    {listAST->push_back(new ASTNode("END", "END"));;}
    break;

  case 33:
#line 95 "microParser.y"
    {decl = 0; std::stringstream os; os << (currTable.entries.size() - currTable.pos); listAST->push_back(new ASTNode(os.str(), "LINK"));;}
    break;

  case 44:
#line 101 "microParser.y"
    {listAST->push_back((yyvsp[(1) - (1)].treeNode));;}
    break;

  case 46:
#line 103 "microParser.y"
    {
					varType = currTable.search_Stack((yyvsp[(1) - (3)].stringValue));
					if(varType == "") {varType = myStack->tables[0].search((yyvsp[(1) - (3)].stringValue));}
					//std::cout << "***IMP STATMENT: " << $<stringValue>1 << " " << varType << " END***\n";
					tmpNode = new ASTNode((yyvsp[(1) - (3)].stringValue),varType);
					if((yyvsp[(3) - (3)].treeNode)->type == "POP"){
					(yyval.treeNode) = new ASTNode(tmpNode, (yyvsp[(3) - (3)].treeNode), "POP", varType, NULL);
					} else {
					(yyval.treeNode) = new ASTNode(tmpNode, (yyvsp[(3) - (3)].treeNode), ":=", varType, NULL);}
					;}
    break;

  case 47:
#line 113 "microParser.y"
    {flag = 0; listID = new ASTNode("READ","READ"); tmpNode = listID;;}
    break;

  case 48:
#line 113 "microParser.y"
    {io_flag = 1;;}
    break;

  case 49:
#line 113 "microParser.y"
    {io_flag = 0;;}
    break;

  case 50:
#line 113 "microParser.y"
    {listAST->push_back(listID);;}
    break;

  case 51:
#line 114 "microParser.y"
    {flag = 0; listID = new ASTNode("WRITE","WRITE"); tmpNode = listID;;}
    break;

  case 52:
#line 114 "microParser.y"
    {io_flag = 1;;}
    break;

  case 53:
#line 114 "microParser.y"
    {io_flag = 0;;}
    break;

  case 54:
#line 114 "microParser.y"
    {listAST->push_back(listID);;}
    break;

  case 55:
#line 115 "microParser.y"
    {std::stringstream ss; ss << currTable.pos + 6; tmpNode = new ASTNode(ss.str(), "RETURN"); tmpNode->right = (yyvsp[(2) - (3)].treeNode); listAST->push_back(tmpNode);;}
    break;

  case 56:
#line 118 "microParser.y"
    {if((yyvsp[(1) - (2)].treeNode) == NULL)
					{(yyval.treeNode) = (yyvsp[(2) - (2)].treeNode);}
					else
					{(yyvsp[(1) - (2)].treeNode)->right = (yyvsp[(2) - (2)].treeNode); (yyval.treeNode) = (yyvsp[(1) - (2)].treeNode);};}
    break;

  case 57:
#line 123 "microParser.y"
    {if((yyvsp[(1) - (3)].treeNode) == NULL)
					{(yyvsp[(3) - (3)].treeNode)->left = (yyvsp[(2) - (3)].treeNode);}
					else
					{(yyvsp[(1) - (3)].treeNode)->right = (yyvsp[(2) - (3)].treeNode); (yyvsp[(3) - (3)].treeNode)->left = (yyvsp[(1) - (3)].treeNode);}
					(yyval.treeNode) = (yyvsp[(3) - (3)].treeNode);;}
    break;

  case 58:
#line 128 "microParser.y"
    {(yyval.treeNode) = NULL;;}
    break;

  case 59:
#line 130 "microParser.y"
    {if((yyvsp[(1) - (2)].treeNode) == NULL)
					{(yyval.treeNode) = (yyvsp[(2) - (2)].treeNode);}
					else
					{(yyvsp[(1) - (2)].treeNode)->right = (yyvsp[(2) - (2)].treeNode); (yyval.treeNode) = (yyvsp[(1) - (2)].treeNode);};}
    break;

  case 60:
#line 135 "microParser.y"
    {if((yyvsp[(1) - (3)].treeNode) == NULL)
					{(yyvsp[(3) - (3)].treeNode)->left = (yyvsp[(2) - (3)].treeNode);}
					else
					{(yyvsp[(1) - (3)].treeNode)->right = (yyvsp[(2) - (3)].treeNode); (yyvsp[(3) - (3)].treeNode)->left = (yyvsp[(1) - (3)].treeNode);}
					(yyval.treeNode) = (yyvsp[(3) - (3)].treeNode);;}
    break;

  case 61:
#line 140 "microParser.y"
    {(yyval.treeNode) = NULL;;}
    break;

  case 62:
#line 141 "microParser.y"
    {(yyval.treeNode) = (yyvsp[(1) - (1)].treeNode);;}
    break;

  case 63:
#line 141 "microParser.y"
    {(yyval.treeNode) = (yyvsp[(1) - (1)].treeNode);;}
    break;

  case 64:
#line 142 "microParser.y"
    {listAST->push_back(new ASTNode("PUSHREGS", "PUSHREGS")); (yyval.treeNode) = new ASTNode((yyvsp[(1) - (4)].stringValue), "POP");;}
    break;

  case 65:
#line 143 "microParser.y"
    {tmpNode = new ASTNode("ARG", "ARG"); tmpNode->right = (yyvsp[(1) - (1)].treeNode); listAST->push_back(tmpNode);;}
    break;

  case 67:
#line 143 "microParser.y"
    {(yyval.treeNode) = NULL;;}
    break;

  case 68:
#line 144 "microParser.y"
    {tmpNode = new ASTNode("ARG", "ARG"); tmpNode->right = (yyvsp[(2) - (2)].treeNode); listAST->push_back(tmpNode);;}
    break;

  case 70:
#line 144 "microParser.y"
    {(yyval.treeNode) = NULL;;}
    break;

  case 71:
#line 145 "microParser.y"
    {(yyval.treeNode) = (yyvsp[(2) - (3)].treeNode);;}
    break;

  case 72:
#line 145 "microParser.y"
    {varType = currTable.search_Stack((yyvsp[(1) - (1)].stringValue)); if(varType == "") {varType = myStack->tables[0].search((yyvsp[(1) - (1)].stringValue));} (yyval.treeNode) = new ASTNode((yyvsp[(1) - (1)].stringValue),varType);;}
    break;

  case 73:
#line 145 "microParser.y"
    {(yyval.treeNode) = new ASTNode((yyvsp[(1) - (1)].stringValue),"INT");;}
    break;

  case 74:
#line 145 "microParser.y"
    {(yyval.treeNode) = new ASTNode((yyvsp[(1) - (1)].stringValue),"FLOAT");;}
    break;

  case 75:
#line 146 "microParser.y"
    {(yyval.treeNode) = new ASTNode("+");;}
    break;

  case 76:
#line 146 "microParser.y"
    {(yyval.treeNode) = new ASTNode("-");;}
    break;

  case 77:
#line 147 "microParser.y"
    {(yyval.treeNode) = new ASTNode("*");;}
    break;

  case 78:
#line 147 "microParser.y"
    {(yyval.treeNode) = new ASTNode("/");;}
    break;

  case 79:
#line 149 "microParser.y"
    {(yyvsp[(3) - (4)].treeNode)->type = "IF"; listAST->push_back((yyvsp[(3) - (4)].treeNode));;}
    break;

  case 80:
#line 149 "microParser.y"
    {listAST->push_back(new ASTNode("end", "ENDIF"));;}
    break;

  case 81:
#line 150 "microParser.y"
    {listAST->push_back(new ASTNode("else", "ELSE"));;}
    break;

  case 84:
#line 151 "microParser.y"
    {(yyvsp[(2) - (3)].treeNode)->right = (yyvsp[(3) - (3)].treeNode); (yyvsp[(2) - (3)].treeNode)->left = (yyvsp[(1) - (3)].treeNode); (yyval.treeNode) = (yyvsp[(2) - (3)].treeNode);;}
    break;

  case 85:
#line 152 "microParser.y"
    {(yyval.treeNode) = NULL;;}
    break;

  case 86:
#line 153 "microParser.y"
    {(yyval.treeNode) = NULL;;}
    break;

  case 87:
#line 154 "microParser.y"
    {(yyval.treeNode) = new ASTNode("<");;}
    break;

  case 88:
#line 155 "microParser.y"
    {(yyval.treeNode) = new ASTNode(">");;}
    break;

  case 89:
#line 156 "microParser.y"
    {(yyval.treeNode) = new ASTNode("=");;}
    break;

  case 90:
#line 157 "microParser.y"
    {(yyval.treeNode) = new ASTNode("!=");;}
    break;

  case 91:
#line 158 "microParser.y"
    {(yyval.treeNode) = new ASTNode("<=");;}
    break;

  case 92:
#line 159 "microParser.y"
    {(yyval.treeNode) = new ASTNode(">=");;}
    break;

  case 93:
#line 160 "microParser.y"
    {(yyvsp[(3) - (4)].treeNode)->type = "WHILE"; listAST->push_back((yyvsp[(3) - (4)].treeNode));;}
    break;

  case 94:
#line 160 "microParser.y"
    {listAST->push_back(new ASTNode("end", "ENDWHILE"));;}
    break;


/* Line 1267 of yacc.c.  */
#line 1925 "microParser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



