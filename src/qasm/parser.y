%{
#include <iostream>
#include <string>

void yyerror (char const *s);

extern int yylex();
extern int yyparse();
extern FILE *yyin;
%}

%union {
    int ival;
    float fval;
    char *sval;
}

%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING 

%token VERSION

%token SEMI

%%

program: version statement
        { std::cout << "Finished Parsing File" << std::endl; }

version: VERSION FLOAT SEMI
        { std::cout << "Running Version " << $2 << std::endl; }

statement:  statement INT
            { std::cout << "Found an int " << $2 << std::endl; }
|           statement FLOAT
            { std::cout << "Found a float " << $2 << std::endl; }
|           statement STRING
            { std::cout << "Found a string " << $2 << std::endl; free($2); }
|           %empty
;

%%

void yyerror (char const *s) {
    fprintf (stderr, "%s\n", s);
}

int main(int, char**) {
    FILE *f = std::fopen("../sample.qasm", "r");
    if (!f) {
        std::cout << "Could not open `sample.qasm`." << std::endl;
        return -1;
    }

    yyin = f;
    yyparse();
}

