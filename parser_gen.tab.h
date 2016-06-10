/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     RS = 272,
     LS = 273,
     RB = 274,
     LB = 275,
     RP = 276,
     LP = 277,
     OR = 278,
     AND = 279,
     GE = 280,
     LE = 281,
     GT = 282,
     LT = 283,
     NE = 284,
     EQ = 285,
     DIVIDE = 286,
     MULT = 287,
     ASSIGN = 288,
     NOT = 289,
     MINUS = 290,
     PLUS = 291
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
#define RS 272
#define LS 273
#define RB 274
#define LB 275
#define RP 276
#define LP 277
#define OR 278
#define AND 279
#define GE 280
#define LE 281
#define GT 282
#define LT 283
#define NE 284
#define EQ 285
#define DIVIDE 286
#define MULT 287
#define ASSIGN 288
#define NOT 289
#define MINUS 290
#define PLUS 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "parser_gen.y"
{
  std::vector <std::string> *code;
  std::string *letters;
}
/* Line 1529 of yacc.c.  */
#line 126 "parser_gen.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

