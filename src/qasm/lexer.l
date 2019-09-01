%{
#include <iostream>
#include <string>

#include "parser.hpp"
%}

%option noyywrap

OPENQASM "OPENQASM"

%%

[ \t\n]             { /* DO NOTHING */ }
"//".*              { /* DO NOTHING */ }

OPENQASM            { return VERSION; }

[0-9]+\.[0-9]+      { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+              { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z0-9]+        { yylval.sval = strdup(yytext); return STRING; }

";"                 { return SEMI; }

%%

// int main(int, char**) {
//     FILE *f = std::fopen("../sample.qasm", "r");
//     if (!f) {
//         std::cout << "Could not open `sample.qasm`." << std::endl;
//         return -1;
//     }

//     yyin = f;
//     int token;
//     while ((token = yylex()) != 0)
//         printf("Token: %d (%s)\n", token, yytext);
//     return 0;
// }
