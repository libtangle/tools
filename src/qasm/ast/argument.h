#ifndef AST_ARGUMENT_H
#define AST_ARGUMENT_H

#include <string>

class Argument {
    // baseclass for an argument.
};

class Identifier : Argument {
public:
    std::string id;
};

class Item : Argument {
public:
    std::string id;
    uint idx;
};

#endif