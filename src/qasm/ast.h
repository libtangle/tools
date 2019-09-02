#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>

class Node {
public:
    virtual ~Node() {}
};

class Statement : public Node {
};

class QRegDecl : public Statement {
public:
    uint value;
    QRegDecl(uint value)
        : value(value)
    {
    }
};

class CRegDecl : public Statement {
public:
    uint value;
    CRegDecl(uint value)
        : value(value)
    {
    }
};

class RootNode : Node {
public:
    std::vector<Statement*> statements;
    RootNode() {}
};

#endif