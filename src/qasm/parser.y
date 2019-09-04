%{

#include "ast/ast.h"
#include "parser.hpp"
#include <iostream>
#include <string>
#include <vector>
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
    int ival;
    // int nnint;

    /* AST Types */
    Statement *stmt;
    StatementList *stmtlist;
    IdentifierList *idlist;
}

/* Define the terminal symbols (tokens). This matches the `tokens.l`
   file. We also define the node type they represent.
*/
%token <string> IDENTIFIER REAL
%token <ival> NNINTEGER
%token <token> SIN COS TAN EXP LN SQRT PI
%token <token> PLUS MINUS MUL DIV POWER
%token <token> ASSIGN MATCHES LPAREN RPAREN 
%token <token> LBRACE RBRACE LSQUARE RSQUARE SEMI COMMA
%token <token> BARRIER CREG QREG IF MEASURE OPAQUE RESET GATE CX U VERSION

/* Define the types for nonterminal symbols */

%type <stmtlist> mainprogram program
%type <stmt> statement decl gatedecl
%type <idlist> idlist

/* Operator precendence for mathematical operators */
%left PLUS MINUS
%left MUL DIV
%right POWER

%start mainprogram

%%

mainprogram : VERSION REAL SEMI program
            { $$ = $4; }
            ;

program : statement
        { $$ = new StatementList(); $$->push_back($1); }
        | program statement
        { $$ = $1; $$->push_back($2); }
        ;

statement : decl
          | gatedecl goplist RBRACE { $$ = $1; }
          | gatedecl RBRACE { $$ = $1; }
          ;
          /*
          | OPAQUE IDENTIFIER idlist SEMI
          | OPAQUE IDENTIFIER LPAREN RPAREN idlist SEMI
          | OPAQUE IDENTIFIER LPAREN idlist RPAREN idlist SEMI 
          | qop
          | IF LPAREN IDENTIFIER MATCHES NNINTEGER RPAREN qop
          | BARRIER mixedlist SEMI
          ;*/

decl : QREG IDENTIFIER LSQUARE NNINTEGER RSQUARE SEMI
     { $$ = new CRegDecl($2, $4); }
     | CREG IDENTIFIER LSQUARE NNINTEGER RSQUARE SEMI
     { $$ = new CRegDecl($2, $4); }
     ;

gatedecl : GATE IDENTIFIER idlist LBRACE
         { $$ = new GateDef($2, $3); }
         | GATE IDENTIFIER LPAREN RPAREN idlist LBRACE
         { $$ = new GateDef($2, $5); }
         | GATE IDENTIFIER LPAREN idlist RPAREN idlist LBRACE
         { $$ = new GateDef($2, $4, $6); }
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

idlist : IDENTIFIER 
       { $$ = new IdentifierList(); $$->push_back(*$1); }
       | idlist COMMA IDENTIFIER
       { $$ = $1; $$->push_back(*$3); }
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