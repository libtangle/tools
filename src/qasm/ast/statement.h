#ifndef AST_STATEMENT_H
#define AST_STATEMENT_H

#include <string>
#include <vector>

#include "argument.h"

class Statement {
    // baseclass for a generic statement
};

class QRegDecl : Statement {
public:
    std::string name;
    uint size;
};

class CRegDecl : Statement {
public:
    std::string name;
    uint size;
};

class Measure : Statement {
public:
    Argument qarg;
    Argument carg;
};

class Reset : Statement {
public:
    Argument qarg;
};

#endif