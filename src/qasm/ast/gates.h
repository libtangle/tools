#ifndef AST_GATES_H
#define AST_GATES_H

#include <string>
#include <vector>

#include "statement.h"

class GateOperation {
    // baseclass for generic gate operation
};

class GateDecl : Statement {
public:
    std::string name;
    std::vector<std::string> params;
    std::vector<std::string> arguments;
    std::vector<GateOperation> operations;
};

#endif