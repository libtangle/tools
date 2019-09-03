#ifndef TANGLE_QASM_AST
#define TANGLE_QASM_AST

#include <iostream>
#include <string>

//----------------------------------------------
// BASE STATMENT CLASS
//----------------------------------------------

class Statement {
public:
    virtual ~Statement() {}
    virtual Statement* clone() = 0;
};

//----------------------------------------------
// UTILITY DECLARATIONS
//----------------------------------------------

using IdentifierList = std::vector<std::string>;

//----------------------------------------------
// REGISTER DECLARATION
//----------------------------------------------

class Decl : public Statement {
    std::string* label;
    int size;

public:
    Decl(std::string* label, int size)
        : label(label)
        , size(size)
    {
        std::cout << "Decl: " << *label << "[" << size << "]" << std::endl;
    }
    Decl(const Decl& other)
    {
        label = other.label;
        size = other.size;
    }
    virtual Statement* clone() { return new Decl(*this); }
};

class CRegDecl : public Decl {
public:
    using Decl::Decl;
};

class QRegDecl : public Decl {
public:
    using Decl::Decl;
};

//----------------------------------------------
// GATE DEFINITION
//----------------------------------------------

class GateDef : public Statement {
    std::string* label;
    IdentifierList *params;
    IdentifierList *arguments;

public:
    GateDef(std::string* label, IdentifierList *args)
        : label(label)
        , arguments(args)
    {
        std::cout << "Gate: (" << *label << std::endl;
        for (std::string a : *arguments) {
            std::cout << a;
        }
        std::cout << ")" std::endl;
    }

    GateDef(std::string* label, IdentifierList *params, IdentifierList *args)
        : label(label)
        , params(params)
        , arguments(args)
    {
        std::cout << "Gate: " << *label << ", with params" << std::endl;
    }

    GateDef(const GateDef& other)
    {
        label = other.label;
        params = other.params;
    }
    virtual Statement* clone() { return new GateDef(*this); }
};

#endif
