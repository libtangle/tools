#ifndef AST_PROGRAM_H
#define AST_PROGRAM_H

#include <string>
#include <vector>

#include "statement.h"

class Program {
public:
    std::string version;
    std::vector<Statement> program;
};

#endif