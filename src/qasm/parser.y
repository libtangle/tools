%{

#include "ast.h"

extern int yylex();

void yyerror(const char *s) {
    printf("ERROR: %sn", s);
}

RootNode *root_node;

%}

/* Represents the many different ways we can access our data */
%union {
    RootNode *root;
    Statement *stmt;
    int token;
    std::string *string;
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
%type <root> program mainprogram
%type <stmt> statement

/* Operator precendence for mathematical operators */
%left PLUS MINUS
%left MUL DIV
%right POWER

%start mainprogram

%%

mainprogram : VERSION REAL SEMI program { root_node = $4; }
        ;

program : statement { $$ = new RootNode(); $$->statements.push_back($<statement>1); }
      | program statement { $1->statements.push_back($<stmt>2); }
      ;

statement : decl
          | gatedecl goplist RBRACE
          | gatedecl RBRACE
          | OPAQUE IDENTIFIER idlist SEMI
          | OPAQUE IDENTIFIER LPAREN RPAREN idlist SEMI
          | OPAQUE IDENTIFIER LPAREN idlist RPAREN idlist SEMI 
          | qop
          | IF LPAREN IDENTIFIER MATCHES NNINTEGER RPAREN qop
          | BARRIER anylist SEMI
          ;

decl : QREG IDENTIFIER LSQUARE NNINTEGER RSQUARE SEMI
     | CREG IDENTIFIER LSQUARE NNINTEGER RSQUARE SEMI
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
    | IDENTIFIER anylist SEMI
    | IDENTIFIER LPAREN RPAREN anylist SEMI
    | IDENTIFIER LPAREN explist RPAREN anylist SEMI

idlist : IDENTIFIER | idlist COMMA IDENTIFIER
       ;

mixedlist : idlist COMMA IDENTIFIER LSQUARE NNINTEGER RSQUARE
          | IDENTIFIER LSQUARE NNINTEGER RSQUARE
          | IDENTIFIER LSQUARE NNINTEGER RSQUARE COMMA IDENTIFIER
          | mixedlist COMMA IDENTIFIER
          | mixedlist COMMA IDENTIFIER LSQUARE NNINTEGER RSQUARE
          ;

anylist : idlist | mixedlist
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
