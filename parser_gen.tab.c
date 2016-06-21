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
     INT = 258,
     CHAR = 259,
     DIGITS = 260,
     ID = 261,
     CHARS = 262,
     RETURN = 263,
     IF = 264,
     ELSE = 265,
     WHILE = 266,
     BREAK = 267,
     PRINT = 268,
     READ = 269,
     SEMI = 270,
     COMMA = 271,
     ASSIGN = 272,
     LP = 273,
     RP = 274,
     LB = 275,
     RB = 276,
     LS = 277,
     RS = 278,
     OR = 279,
     AND = 280,
     GE = 281,
     LE = 282,
     GT = 283,
     LT = 284,
     NE = 285,
     EQ = 286,
     MINUS = 287,
     PLUS = 288,
     DIVIDE = 289,
     MULT = 290,
     NOT = 291,
     NEG = 292
   };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define DIGITS 260
#define ID 261
#define CHARS 262
#define RETURN 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define BREAK 267
#define PRINT 268
#define READ 269
#define SEMI 270
#define COMMA 271
#define ASSIGN 272
#define LP 273
#define RP 274
#define LB 275
#define RB 276
#define LS 277
#define RS 278
#define OR 279
#define AND 280
#define GE 281
#define LE 282
#define GT 283
#define LT 284
#define NE 285
#define EQ 286
#define MINUS 287
#define PLUS 288
#define DIVIDE 289
#define MULT 290
#define NOT 291
#define NEG 292




/* Copy the first part of user declarations.  */
#line 1 "parser_gen.y"

  #include "headers.h"
  void yyerror(const char *);
  extern int yylex(void);
  extern int yylineno;
  extern FILE *yyin;
  fstream fp;
  vector<string> *code_section;
  vector<string> *save_section;
  string *op_ptr;
  string *temp_ptr;
  string *reg_ptr;
  vector<string> op_stack;
  string tempreg;
  map<string, attribute> *temp_var;
  int stack_top = 0;
  /* vector to print out */
  vector<string> instruction, code_expr;
  vector<string>:: iterator it;
  string kindOfOperator;
  int parameter_count = 0;


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
#line 24 "parser_gen.y"
{
  vector<string> *code;
  string *letters;
}
/* Line 193 of yacc.c.  */
#line 198 "parser_gen.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 211 "parser_gen.tab.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    20,    24,    28,
      35,    40,    43,    45,    47,    48,    52,    54,    57,    62,
      67,    71,    73,    75,    78,    80,    82,    85,    89,    92,
     100,   106,   108,   112,   116,   118,   122,   124,   126,   130,
     137,   142,   149,   154,   156,   158,   162,   166,   169,   172,
     174,   176,   178,   180,   182,   184,   186,   188,   190,   192,
     194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    41,    40,    -1,    -1,    49,
       6,    15,    -1,    49,     6,    22,     5,    23,    15,    -1,
      49,     6,    43,    -1,    49,     6,    15,    -1,    49,     6,
      22,     5,    23,    15,    -1,    18,    45,    19,    48,    -1,
      42,    44,    -1,    42,    -1,    46,    -1,    -1,    47,    16,
      46,    -1,    47,    -1,    49,     6,    -1,    49,     6,    22,
      23,    -1,    20,    44,    50,    21,    -1,    20,    50,    21,
      -1,     3,    -1,     4,    -1,    51,    50,    -1,    51,    -1,
      15,    -1,    54,    15,    -1,     8,    54,    15,    -1,    12,
      15,    -1,     9,    18,    54,    19,    51,    10,    51,    -1,
      11,    18,    54,    19,    51,    -1,    48,    -1,    13,     6,
      15,    -1,    14,     6,    15,    -1,    54,    -1,    52,    16,
      54,    -1,     6,    -1,     5,    -1,     6,    17,    54,    -1,
       6,    22,    54,    23,    56,    54,    -1,     6,    22,    54,
      23,    -1,     6,    22,    54,    23,    17,    54,    -1,     6,
      18,    52,    19,    -1,    55,    -1,    53,    -1,    18,    54,
      19,    -1,    55,    56,    55,    -1,    32,    55,    -1,    36,
      55,    -1,    33,    -1,    32,    -1,    35,    -1,    34,    -1,
      31,    -1,    30,    -1,    29,    -1,    27,    -1,    28,    -1,
      26,    -1,    25,    -1,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    56,    60,    63,    68,    74,    80,    89,
      97,   101,   106,   114,   118,   121,   124,   132,   140,   149,
     153,   159,   162,   167,   172,   181,   182,   192,   201,   205,
     209,   213,   217,   252,   276,   279,   284,   294,   306,   314,
     318,   322,   325,   328,   331,   332,   336,   357,   367,   379,
     387,   395,   403,   411,   419,   427,   435,   443,   451,   459,
     467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHAR", "DIGITS", "ID", "CHARS",
  "RETURN", "IF", "ELSE", "WHILE", "BREAK", "PRINT", "READ", "SEMI",
  "COMMA", "ASSIGN", "LP", "RP", "LB", "RB", "LS", "RS", "OR", "AND", "GE",
  "LE", "GT", "LT", "NE", "EQ", "MINUS", "PLUS", "DIVIDE", "MULT", "NOT",
  "NEG", "$accept", "Program", "DeclList", "_DeclList", "VarDecl",
  "FunDecl", "VarDeclList", "ParamDeclList", "ParamDeclListTail",
  "ParamDecl", "Block", "Type", "StmtList", "Stmt", "ExprList", "Node",
  "Expr", "Operation", "BinaryOp", 0
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     6,     3,     3,     6,
       4,     2,     1,     1,     0,     3,     1,     2,     4,     4,
       3,     1,     1,     2,     1,     1,     2,     3,     2,     7,
       5,     1,     3,     3,     1,     3,     1,     1,     3,     6,
       4,     6,     4,     1,     1,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    21,    22,     0,     2,     4,     0,     1,     3,     0,
       5,    14,     0,     7,     0,    13,    16,     0,     0,     0,
       0,    17,     0,     0,    10,    15,     0,     6,    37,    36,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
      12,     0,    31,     0,     0,    24,    44,     0,    43,    18,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
      36,    47,    48,    11,     0,     0,    20,    23,    26,    60,
      59,    58,    56,    57,    55,    54,    53,    50,    49,    52,
      51,     0,    38,     0,    34,     0,    27,     0,     0,    32,
      33,    45,    19,     8,     0,    46,     0,    42,    40,     0,
       0,     0,    35,     0,     0,     0,    30,     0,    41,    39,
       0,     9,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    40,    13,    41,    14,    15,    16,
      42,     6,    44,    45,    83,    46,    47,    48,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int8 yypact[] =
{
      36,   -92,   -92,    11,   -92,    36,     9,   -92,   -92,   -12,
     -92,    36,    12,   -92,     4,   -92,    14,    41,    19,    29,
      36,    30,    38,    23,   -92,   -92,    31,   -92,   -92,    28,
      59,    39,    40,    45,    50,    55,   -92,    59,    62,    62,
      36,    70,   -92,    56,    42,    70,   -92,    54,    95,   -92,
      59,    59,    59,    57,    59,    59,   -92,    71,    72,    51,
     -92,   -92,   -92,   -92,    68,   -10,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,    62,   -92,    32,   -92,    48,   -92,    73,    74,   -92,
     -92,   -92,   -92,   -92,    91,    95,    59,   -92,    83,    70,
      70,    76,   -92,    59,    59,    87,   -92,    86,   -92,   -92,
      70,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,    98,   -92,   -92,   -92,    64,   -92,    85,   -92,
     112,    -7,   -27,   -91,   -92,   -92,   -30,   -37,    34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      53,    61,    62,    10,    17,    93,    11,    59,   105,   106,
      12,     7,    94,    17,    64,     9,    43,    18,    67,   112,
      82,    84,    85,    19,    87,    88,     1,     2,    28,    29,
      20,    30,    31,    43,    32,    33,    34,    35,    36,     1,
       2,    37,    22,    23,    95,    50,    51,    21,    96,    23,
      52,    97,    26,    27,    49,    38,    57,    54,    55,    39,
      56,    58,    65,    66,    28,    29,   102,    28,    60,    68,
      91,    98,    86,   108,   109,    28,    29,    37,    30,    31,
      37,    32,    33,    34,    35,    36,    89,    90,    37,    92,
      23,    38,    99,   100,    38,    39,   101,   110,    39,   107,
     103,   111,    38,     8,    63,    25,    39,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    24,   104
};

static const yytype_uint8 yycheck[] =
{
      30,    38,    39,    15,    11,    15,    18,    37,    99,   100,
      22,     0,    22,    20,    41,     6,    23,     5,    45,   110,
      50,    51,    52,    19,    54,    55,     3,     4,     5,     6,
      16,     8,     9,    40,    11,    12,    13,    14,    15,     3,
       4,    18,    23,    20,    81,    17,    18,     6,    16,    20,
      22,    19,    22,    15,    23,    32,     6,    18,    18,    36,
      15,     6,     6,    21,     5,     6,    96,     5,     6,    15,
      19,    23,    15,   103,   104,     5,     6,    18,     8,     9,
      18,    11,    12,    13,    14,    15,    15,    15,    18,    21,
      20,    32,    19,    19,    32,    36,     5,    10,    36,    23,
      17,    15,    32,     5,    40,    20,    36,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    19,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    39,    40,    41,    49,     0,    40,     6,
      15,    18,    22,    43,    45,    46,    47,    49,     5,    19,
      16,     6,    23,    20,    48,    46,    22,    15,     5,     6,
       8,     9,    11,    12,    13,    14,    15,    18,    32,    36,
      42,    44,    48,    49,    50,    51,    53,    54,    55,    23,
      17,    18,    22,    54,    18,    18,    15,     6,     6,    54,
       6,    55,    55,    44,    50,     6,    21,    50,    15,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    56,    54,    52,    54,    54,    15,    54,    54,    15,
      15,    19,    21,    15,    22,    55,    16,    19,    23,    19,
      19,     5,    54,    17,    56,    51,    51,    23,    54,    54,
      10,    15,    51
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
#line 49 "parser_gen.y"
    {
            printf("Program -> DeclList\n");
            // add to end of stack
            /*instruction.insert(instruction.end(), $1->begin(), $1->end());*/
          ;}
    break;

  case 3:
#line 56 "parser_gen.y"
    {
              printf("DeclList -> _DeclList DeclList\n");
              /*instruction.insert(instruction.end(), $1->begin(), $1->end());*/
           ;}
    break;

  case 4:
#line 60 "parser_gen.y"
    {;}
    break;

  case 5:
#line 63 "parser_gen.y"
    {
              printf("_DeclList -> Type ID Decl\n");
              stack_top += 4;
              addToScope(*(yyvsp[(2) - (3)].letters), stack_top);
            ;}
    break;

  case 6:
#line 68 "parser_gen.y"
    {
              printf("_DeclList -> Type ID [DIGITS];\n");
              // array declaration
              stack_top += ( 4 * atoi((*(yyvsp[(4) - (6)].letters)).c_str()) );
              addToScope(*(yyvsp[(2) - (6)].letters), stack_top);
            ;}
    break;

  case 7:
#line 74 "parser_gen.y"
    {
              printf("_DeclList -> Type ID FunDecl\n");
              // TODO
            ;}
    break;

  case 8:
#line 80 "parser_gen.y"
    {
            printf("VarDecl -> Type ID;\n");
            stack_top += 4;
            addToScope(*(yyvsp[(2) - (3)].letters), stack_top);
            printf("id added: %s\n", (*(yyvsp[(2) - (3)].letters)).c_str());
            // keep track of the attributes of the var
            /* createId(name, type, register, value, isArray); */
            /* createId($2, $1, tempreg, "", false); */
          ;}
    break;

  case 9:
#line 89 "parser_gen.y"
    {
            printf("VarDecl -> Type ID [ DIGITS ] ;");
            stack_top += ( 4 * atoi((*(yyvsp[(4) - (6)].letters)).c_str()) );
            addToScope(*(yyvsp[(2) - (6)].letters), stack_top);
            // createId($2, $1, "", "", true);
          ;}
    break;

  case 10:
#line 97 "parser_gen.y"
    {
          ;}
    break;

  case 11:
#line 101 "parser_gen.y"
    {
                printf("VarDeclList -> VarDecl VarDeclList\n");
                (yyvsp[(2) - (2)].code)->insert((yyvsp[(2) - (2)].code)->end(), (yyvsp[(1) - (2)].code)->begin(), (yyvsp[(1) - (2)].code)->end());
                (yyval.code) = (yyvsp[(2) - (2)].code);
              ;}
    break;

  case 12:
#line 106 "parser_gen.y"
    {
                printf("VarDeclList -> VarDecl\n");
                /* new variable declaration */
                code_section = new Code_frag();
                (yyval.code) = code_section;
              ;}
    break;

  case 13:
#line 114 "parser_gen.y"
    {
                  printf("ParamDeclList -> ParamDeclListTail\n");
                  (yyval.code) = (yyvsp[(1) - (1)].code);
                ;}
    break;

  case 14:
#line 118 "parser_gen.y"
    {;}
    break;

  case 15:
#line 121 "parser_gen.y"
    {
                      printf("ParamDeclListTail -> ParamDecl ParamDeclListTail\n");
                    ;}
    break;

  case 16:
#line 124 "parser_gen.y"
    {
                      printf("ParamDeclListTail -> ParamDecl\n");
                      code_section = new Code_frag();
                      code_section->insert(code_section->end(), (yyvsp[(1) - (1)].code)->begin(), (yyvsp[(1) - (1)].code)->end());
                      (yyval.code) = code_section;
                  ;}
    break;

  case 17:
#line 132 "parser_gen.y"
    {
              printf("ParamDecl -> Type ID\n");
              newScope();
              parameter_count = parameter_count + 1;
              /* 4 bytes for storing and parameter */
              stack_top = stack_top + 4;
              addToScope(*(yyvsp[(2) - (2)].letters), stack_top);
            ;}
    break;

  case 18:
#line 140 "parser_gen.y"
    {
              printf("ParamDecl -> Type ID []");
              newScope();
              parameter_count = parameter_count + 1;
              stack_top = stack_top + 4;
              addToScope(*(yyvsp[(2) - (4)].letters), stack_top);
          ;}
    break;

  case 19:
#line 149 "parser_gen.y"
    {
          printf("Block -> { VarDeclList StmtList }\n");
          // TODO
        ;}
    break;

  case 20:
#line 153 "parser_gen.y"
    {
          printf("Block -> {StmtList}\n");
          // TODO
        ;}
    break;

  case 21:
#line 159 "parser_gen.y"
    {
          printf("Type -> int\t");
       ;}
    break;

  case 22:
#line 162 "parser_gen.y"
    {
          printf("Type -> char\t");
       ;}
    break;

  case 23:
#line 167 "parser_gen.y"
    {
              printf("StmtList -> Stmt StmtList\n");
              (yyvsp[(2) - (2)].code)->insert((yyvsp[(2) - (2)].code)->end(), (yyvsp[(1) - (2)].code)->begin(), (yyvsp[(1) - (2)].code)->end());
              (yyval.code) = (yyvsp[(2) - (2)].code);
           ;}
    break;

  case 24:
#line 172 "parser_gen.y"
    {
              printf("StmtList -> Stmt\n");
              code_section = new Code_frag();
              /* add a new Stmt */
              code_section->insert(code_section->end(), (yyvsp[(1) - (1)].code)->begin(), (yyvsp[(1) - (1)].code)->end());
              (yyval.code) = code_section;
           ;}
    break;

  case 25:
#line 181 "parser_gen.y"
    { /* don't need to do anything for ';' */ ;}
    break;

  case 26:
#line 182 "parser_gen.y"
    {
          printf("Stmt -> Expr ;\n");
          /* Stmt is assigned an Expr */
          code_section = new Code_frag();
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());
          /* clean the vector */
          code_expr.clear();
          (yyval.code) = code_section;
          cleanSingleRegister(*(yyvsp[(1) - (2)].letters));
       ;}
    break;

  case 27:
#line 192 "parser_gen.y"
    {
          printf("Stmt -> return Expr ;\n");
          code_section = new Code_frag();
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());
          /* always save Expr in saved register */
          /* clean the vector */
          code_expr.clear();
          (yyval.code) = code_section;
       ;}
    break;

  case 28:
#line 201 "parser_gen.y"
    {
          // TODO
          printf("Stmt -> break ;\n");
       ;}
    break;

  case 29:
#line 205 "parser_gen.y"
    {
          // TODO
          printf("Stmt -> if (Expr) Stmt else Stmt\n");
       ;}
    break;

  case 30:
#line 209 "parser_gen.y"
    {
          // TODO
          printf("Stmt -> while (Expr) Stmt\n");
       ;}
    break;

  case 31:
#line 213 "parser_gen.y"
    {
          // TODO
          printf("Stmt -> Block\n");
       ;}
    break;

  case 32:
#line 217 "parser_gen.y"
    {
          /* // print out ID using temp register --> need to load the value
          // code_section = new Code_frag();
          // load register from variables:
          // tempreg = getVarRegister($2);
          // move before printing
          // string temp = "\tmove $a0, ";
          // temp = temp + tempreg;
          // code_section->push_back(temp); */
          printf("Stmt -> print ID;\n");
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string temp1 = "\tlw $";
          temp1 = temp1 + *reg_ptr;
          temp1 = temp1 + ", -";
          temp1 = temp1 + to_string(getOffset(*(yyvsp[(2) - (3)].letters))) + "($fp)";
          // code_section->push_back(temp1);
          instruction.push_back(temp1);

          temp1 = "\tmove $a0, $" + *reg_ptr;
          // move to $a0 to print
          // code_section->push_back(temp1);
          instruction.push_back(temp1);

          // print id as string
          // code_section->push_back("\tli $v0, 1");
          // code_section->push_back("\tsyscall");
          instruction.push_back("\tli $v0, 1");
          instruction.push_back("\tsyscall");

          (yyval.code) = code_section;
          // make register unused again
          cleanSingleRegister(tempreg);
          cleanSingleRegister(*(yyvsp[(2) - (3)].letters));
       ;}
    break;

  case 33:
#line 252 "parser_gen.y"
    {
          printf("Stmt -> read ID;\n");
          /* read ID --> need to write value only id for integers */
          code_section = new Code_frag();
          /* read out from reg */
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string prefix = "\tsw $v0, $";
          string action = prefix + to_string(getOffset(*(yyvsp[(2) - (3)].letters))) + "($fp)";
          /*code_section->push_back("\tli $v0, 5");
          code_section->push_back("\tsyscall");
          code_section->push_back(action);
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());*/

          instruction.push_back("\tli $v0, 5");
          instruction.push_back("\tsyscall");
          instruction.push_back(action);

          (yyval.code) = code_section;
          cleanSingleRegister(tempreg);
          cleanSingleRegister(*(yyvsp[(2) - (3)].letters));
       ;}
    break;

  case 34:
#line 276 "parser_gen.y"
    {
              printf("ExprList -> Expr\n");
           ;}
    break;

  case 35:
#line 279 "parser_gen.y"
    {
              /* ExprList, Expr .....  */
           ;}
    break;

  case 36:
#line 284 "parser_gen.y"
    {
          printf("ID\t");
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string prefix = "\tlw $";
          string action = prefix + *reg_ptr + ", -" + to_string(getOffset(*(yyvsp[(1) - (1)].letters))) + "($fp)";
          /*code_expr.push_back(action);*/
          instruction.push_back(action);
          (yyval.letters) = reg_ptr;
       ;}
    break;

  case 37:
#line 294 "parser_gen.y"
    {
          printf("num\t");
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string prefix = "\tli $";
          string action = prefix + *reg_ptr + ", $" + *(yyvsp[(1) - (1)].letters);
          /*code_expr.push_back(action);*/
          instruction.push_back(action);
          (yyval.letters) = (yyvsp[(1) - (1)].letters);
       ;}
    break;

  case 38:
#line 306 "parser_gen.y"
    {
          printf("Expr -> ID = Expr\n");
          string prefix = "\tsw $";
          /* get id offset in the stack and store the word in it */
          string action = prefix + *(yyvsp[(3) - (3)].letters) + ", -" + to_string(getOffset(*(yyvsp[(1) - (3)].letters))) + "($fp)";
          /*code_expr.push_back(action);*/
          instruction.push_back(action);
       ;}
    break;

  case 39:
#line 314 "parser_gen.y"
    {
          /* TODO: deal with Arrays */
          printf("Expr -> ID [Expr] BinaryOp Expr\n");
       ;}
    break;

  case 40:
#line 318 "parser_gen.y"
    {
          /* TODO: deal with Arrays */
          printf("Expr -> ID [Expr]\n");
       ;}
    break;

  case 41:
#line 322 "parser_gen.y"
    {
          /* TODO: array... */
       ;}
    break;

  case 42:
#line 325 "parser_gen.y"
    {

       ;}
    break;

  case 44:
#line 331 "parser_gen.y"
    { (yyval.letters) = (yyvsp[(1) - (1)].letters); ;}
    break;

  case 45:
#line 332 "parser_gen.y"
    {
                printf("Operation -> (Operation)\n");
                (yyval.letters) = (yyvsp[(2) - (3)].letters);
            ;}
    break;

  case 46:
#line 336 "parser_gen.y"
    {
              printf("Operation -> Operation BinaryOp Operation\n");
              string arithmetic_prefix = correspondOp(*(yyvsp[(2) - (3)].letters));
              // result stored in operation ($3)
              string action = "";
              if(kindOfOperator.compare("==") == 0 || kindOfOperator.compare("!=") == 0 | kindOfOperator.compare("<") == 0 | kindOfOperator.compare("<=") == 0 | kindOfOperator.compare(">") == 0 | kindOfOperator.compare(">=") == 0 | kindOfOperator.compare("&&") == 0 | kindOfOperator.compare("||") == 0) {
                  // have to store value into new register if using ==, !=, <, <=, >, >=, &&, ||
                  tempreg = getTempReg();
                  reg_ptr = new string(tempreg);
                  action = arithmetic_prefix + *reg_ptr + ", $" + *(yyvsp[(1) - (3)].letters) + ", $" + *(yyvsp[(3) - (3)].letters);
                  /*code_expr.push_back(action);*/
                  instruction.push_back(action);
                  (yyval.letters) = reg_ptr;
               } else {
                  action = arithmetic_prefix + *(yyvsp[(1) - (3)].letters) + ", $" + *(yyvsp[(1) - (3)].letters) + ", $" + *(yyvsp[(3) - (3)].letters);
                  /*code_expr.push_back(action);*/
                  instruction.push_back(action);
                  (yyval.letters) = (yyvsp[(1) - (3)].letters);
               }
               cleanSingleRegister(*(yyvsp[(3) - (3)].letters));
            ;}
    break;

  case 47:
#line 357 "parser_gen.y"
    {
               printf("-Operation");
               /* this should be NEG token */
               string a = "\tneg ";
               string action = a + *(yyvsp[(2) - (2)].letters) + ", $" + *(yyvsp[(2) - (2)].letters);
               /*code_expr.push_back(action);*/
               instruction.push_back(action);
               (yyval.letters) = (yyvsp[(2) - (2)].letters);
               // return $2 back
            ;}
    break;

  case 48:
#line 367 "parser_gen.y"
    {
               printf("!Operation\n");
               /* printf(" ! "); */
               string a = "\tnot $";
               /* not command */
               string action = a + *(yyvsp[(2) - (2)].letters) + ", $" + *(yyvsp[(2) - (2)].letters);
               /*code_expr.push_back(action);*/
               instruction.push_back(action);
               (yyval.letters) = (yyvsp[(2) - (2)].letters);
            ;}
    break;

  case 49:
#line 379 "parser_gen.y"
    {
              /* printf(" + "); */
              /* fp << "\tadd " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              // op_stack.push_back(*$1);
              kindOfOperator = "+";
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 50:
#line 387 "parser_gen.y"
    {
              printf(" - ");
              /* fp << "\tsub " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "-";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 51:
#line 395 "parser_gen.y"
    {
              /* printf(" * "); */
              /* fp << "\tmul " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "*";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 52:
#line 403 "parser_gen.y"
    {
              /* printf(" / "); */
              /* fp << "\tdiv " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "/";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 53:
#line 411 "parser_gen.y"
    {
              /* printf(" == "); */
              /* fp << "\tseq " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "==";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 54:
#line 419 "parser_gen.y"
    {
              /* printf(" != "); */
              /* fp << "\tsne " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "!=";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 55:
#line 427 "parser_gen.y"
    {
              /* printf(" < "); */
              /* fp << "\tslt " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "<";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 56:
#line 435 "parser_gen.y"
    {
              /* printf(" <= "); */
              /* fp << "\tlte " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "<=";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 57:
#line 443 "parser_gen.y"
    {
              /* printf(" > "); */
              /* fp << "\tlgt " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = ">";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 58:
#line 451 "parser_gen.y"
    {
              /* printf(" >= "); */
              /* fp << "\tlge " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = ">=";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 59:
#line 459 "parser_gen.y"
    {
              /* printf(" && "); */
              /* fp << "\tand " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "&&";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;

  case 60:
#line 467 "parser_gen.y"
    {
              /* printf(" || "); */
              /* fp << "\tor " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "||";
              // op_stack.push_back(*$1);
              (yyval.letters) = (yyvsp[(1) - (1)].letters);
           ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2130 "parser_gen.tab.c"
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


#line 477 "parser_gen.y"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctype.h>

void yyerror(const char *err) {
  cout << "line " << yylineno << ": " << err << "token: " << &yylex << endl;
}

int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  //FILE *fp = fopen("code_gen.s", "w");
  ofstream fp("code_gen.s", ios::out);
  initialize();
  if(yyparse()) {
    fprintf(stderr, "parsing error!\n");
  } else {
    // can parse and print into .s
    fp << "main:" << endl;
    for(int i = 0; i< instruction.size(); i++) {
      fp << instruction[i] << endl;
    }
  }
  fclose(yyin);
  fp.close();
  return 0;
}

