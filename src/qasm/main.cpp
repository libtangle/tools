#include <iostream>
#include <string>
#include <vector>

#include "ast.h"
#include "tokens.h"

int main()
{
    Program prog;
    prog.version = "OpenQASM 2.0";

    Token a = Token(Kind::Cos);

    return 0;
}