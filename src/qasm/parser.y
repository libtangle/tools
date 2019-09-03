%{

#include "ast/ast.h"
#include "parser.hpp"
#include <iostream>
#include <string>
#include <memory>

extern int yylex();

void yyerror(const char *s) {
    printf("ERROR: %sn", s);
}

%}

/* Represents the many different ways we can access our data */
%union {
    int token;
    std::string *string;

    /* AST Types */
    Statement *stmt;
}

/* Define the terminal symbols (tokens). This matches the `tokens.l`
   file. We also define the node type they represent.
*/
%token <string> IDENTIFIER REAL NNINTEGER
%token <token> SIN COS TAN EXP LN SQRT PI
%token <token> PLUS MINUS MUL DIV POWER
%token <token> ASSIGN MATCHES LPAREN RPAREN 
%token <token> LBRACE RBRACE LSQUARE RSQUARE SEMI COMMA
%token <token> BARRIER CREG QREG IF MEASURE OPAQUE RESET GATE CX U VERSION

/* Define the types for nonterminal symbols */

%type <stmt> decl 
%type <string> identifier
/*
%type <root> program mainprogram
%type <stmt> statement decl
%type <NNINTEGER> NNINTEGER*/


/* Operator precendence for mathematical operators */
%left PLUS MINUS
%left MUL DIV
%right POWER

%start mainprogram

%%

mainprogram : VERSION REAL SEMI program 
        ;

program : statement
      | program statement
      ;

statement : decl
          | gatedecl goplist RBRACE
          | gatedecl RBRACE
          | OPAQUE IDENTIFIER idlist SEMI
          | OPAQUE IDENTIFIER LPAREN RPAREN idlist SEMI
          | OPAQUE IDENTIFIER LPAREN idlist RPAREN idlist SEMI 
          | qop
          | IF LPAREN IDENTIFIER MATCHES NNINTEGER RPAREN qop
          | BARRIER mixedlist SEMI
          ;

decl : QREG identifier LSQUARE NNINTEGER RSQUARE SEMI
     { $$ = new QRegDecl($2, $4); }
     | CREG identifier LSQUARE NNINTEGER RSQUARE SEMI
     { $$ = new CRegDecl($2, $4); }
     ;

gatedecl : GATE IDENTIFIER idlist LBRACE
         | GATE IDENTIFIER LPAREN RPAREN idlist LBRACE
         | GATE IDENTIFIER LPAREN idlist RPAREN idlist LBRACE
         ;

goplist : uop
        | BARRIER idlist SEMI
        | goplist uop
        | goplist BARRIER idlist SEMI
        ;

qop : uop
    | MEASURE argument ASSIGN argument SEMI
    | RESET argument SEMI

uop : U LPAREN explist RPAREN argument SEMI
    | CX argument COMMA argument SEMI
    | IDENTIFIER mixedlist SEMI
    | IDENTIFIER LPAREN RPAREN mixedlist SEMI
    | IDENTIFIER LPAREN explist RPAREN mixedlist SEMI

idlist : IDENTIFIER | idlist COMMA IDENTIFIER
       ;

mixedlist : idlist
          | idlist LSQUARE NNINTEGER RSQUARE 
          ;

argument : IDENTIFIER | IDENTIFIER LSQUARE NNINTEGER RSQUARE
         ;

explist : exp | explist COMMA exp
        ;

exp : REAL | NNINTEGER | PI | IDENTIFIER
    | exp PLUS exp | exp MINUS exp | exp MUL exp
    | exp DIV exp | MINUS exp | exp POWER exp
    | LPAREN exp RPAREN
    | unaryop LPAREN exp RPAREN
    ;

unaryop : SIN | COS | TAN | EXP | LN | SQRT

identifier : IDENTIFIER
           { $$ = *yylval.string; }
           ;
