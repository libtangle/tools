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
     IDENTIFIER = 258,
     REAL = 259,
     NNINTEGER = 260,
     SIN = 261,
     COS = 262,
     TAN = 263,
     EXP = 264,
     LN = 265,
     SQRT = 266,
     PI = 267,
     PLUS = 268,
     MINUS = 269,
     MUL = 270,
     DIV = 271,
     POWER = 272,
     ASSIGN = 273,
     MATCHES = 274,
     LPAREN = 275,
     RPAREN = 276,
     LBRACE = 277,
     RBRACE = 278,
     LSQUARE = 279,
     RSQUARE = 280,
     SEMI = 281,
     COMMA = 282,
     BARRIER = 283,
     CREG = 284,
     QREG = 285,
     IF = 286,
     MEASURE = 287,
     OPAQUE = 288,
     RESET = 289,
     GATE = 290,
     CX = 291,
     U = 292,
     VERSION = 293
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define REAL 259
#define NNINTEGER 260
#define SIN 261
#define COS 262
#define TAN 263
#define EXP 264
#define LN 265
#define SQRT 266
#define PI 267
#define PLUS 268
#define MINUS 269
#define MUL 270
#define DIV 271
#define POWER 272
#define ASSIGN 273
#define MATCHES 274
#define LPAREN 275
#define RPAREN 276
#define LBRACE 277
#define RBRACE 278
#define LSQUARE 279
#define RSQUARE 280
#define SEMI 281
#define COMMA 282
#define BARRIER 283
#define CREG 284
#define QREG 285
#define IF 286
#define MEASURE 287
#define OPAQUE 288
#define RESET 289
#define GATE 290
#define CX 291
#define U 292
#define VERSION 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.y"
{
    int token;
    std::string *string;
    int ival;
    // int nnint;

    /* AST Types */
    Statement *stmt;
    IdentifierList *idlist;
}
/* Line 1529 of yacc.c.  */
#line 136 "parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

