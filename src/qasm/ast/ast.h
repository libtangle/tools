#ifndef TANGLE_QASM_AST
#define TANGLE_QASM_AST

// #include <iostream>
// #include <memory>
// #include <string>

// class Statement {
// public:
//     virtual ~Statement() = 0;
// };
// inline Statement::~Statement() = default;
// using StatementPtr = std::unique_ptr<Statement>;

// class Decl : public Statement {
//     std::string* label;
//     uint size;

// public:
//     Decl(std::string* label, uint size)
//         : label(label)
//         , size(size)
//     {
//         std::cout << "Declared " << label << " of size " << size << std::endl;
//     }
// };

// class CRegDecl : public Decl {
// public:
//     using Decl::Decl;
// };

// class QRegDecl : public Decl {
// public:
//     using Decl::Decl;
// };

#include <string>

class Statement {
public:
    virtual ~Statement () {}
    virtual Statement *clone() = 0;
};

// For Declarations
class CRegDecl : public Statement {
    std::string *label;
    int size;

public:
    CRegDecl(std::string *label, int size) : label(label), size(size) {}
    CRegDecl(const CRegDecl &other) {
        label = other.label;
        size = other.size;
    }
    virtual Statement *clone () { return new CRegDecl (*this); }
};

#endif
