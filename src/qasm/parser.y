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
%token <token> ASSIGN MATCHES LPAREN RPAREN LBRACE RBRACE LSQUARE RSQUARE SEMI
%token <token> BARRIER CREG QREG IF MEASURE OPAQUE RESET CX U VERSION

/* Define the types for nonterminal symbols */
%type <root> program stmts
%type <stmt> stmt decl

/* Operator precendence for mathematical operators */
%left PLUS MINUS
%left MUL DIV
%right POWER

%start program

%%

program : version stmts { root_node = $2; }
        ;

version : VERSION REAL SEMI
        ;

stmts : stmt { $$ = new RootNode(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

stmt : decl
     ;

decl : QREG SEMI { $$ = new QRegDecl(0); }
     | CREG SEMI { $$ = new CRegDecl(0); }
     ;

