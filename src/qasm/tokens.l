%{

#include <string>
#include "ast.h"
#include "parser.hpp"

// SAVE_TOKEN keeps the text of identifiers and numbers.
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)

%}

%option noyywrap

%%

[ \t\n]                                             ;

"sin"                return TOKEN(SIN);
"cos"                return TOKEN(COS);
"tan"                return TOKEN(TAN);
"exp"                return TOKEN(EXP);
"ln"                 return TOKEN(LN);
"sqrt"               return TOKEN(SQRT);
"pi"                 return TOKEN(PI);


"+"                  return TOKEN(PLUS);
"-"                  return TOKEN(MINUS);
"*"                  return TOKEN(MUL);
"/"                  return TOKEN(DIV);
"^"                  return TOKEN(POWER);

"->"                 return TOKEN(ASSIGN);
"=="                 return TOKEN(MATCHES);
"("                  return TOKEN(LPAREN);
")"                  return TOKEN(RPAREN);
"{"                  return TOKEN(LBRACE);
"}"                  return TOKEN(RBRACE);
"["                  return TOKEN(LSQUARE);
"]"                  return TOKEN(RSQUARE);
";"                  return TOKEN(SEMI);

"barrier"            return TOKEN(BARRIER);
"creg"               return TOKEN(CREG);
"qreg"               return TOKEN(QREG);
"if"                 return TOKEN(IF);
"measure"            return TOKEN(MEASURE);
"opaque"             return TOKEN(OPAQUE);
"reset"              return TOKEN(RESET);
"OPENQASM"           return TOKEN(VERSION);

"CX"                 return TOKEN(CX);
"U"                  return TOKEN(U);

[a-z][A-Za-z0-9_]*                                  SAVE_TOKEN; return IDENTIFIER;
([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?   SAVE_TOKEN; return REAL;
[1-9]+[0-9]*|0                                      SAVE_TOKEN; return NNINTEGER;


%%