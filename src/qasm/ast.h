#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>

typedef std::vector<Statement*> StatementList;

class Node {
public:
    virtual ~Node() {}
};

class RootNode : Node {
public:
    StatementList statements;
    RootNode() {}
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

#endif