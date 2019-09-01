#ifndef AST_TOKENS_H
#define AST_TOKENS_H

#include <optional>
#include <string>

enum class Kind {
    Illegal,
    EndOfFile,

    // Literals
    Real,
    NNInteger,
    Id,

    // Other Tokens

    OpenQASM,
    Semicolon,
    Comma,
    LParen, //`(`
    LSParen, // `[`
    LCParen, // `{`
    RParen, // `)`
    RSParen, // `]`
    RCParen, // `}`
    Arrow, // `->`
    Equals, // `==`

    // Mathematical Expressions

    Pi,
    Plus,
    Minus,
    Times,
    Divide,
    Power,

    // Unary Functions
    Sin,
    Cos,
    Tan,
    Exp,
    Ln,
    Sqrt,

    // Operators
    QReg,
    CReg,
    Barrier,
    Gate,
    Measure,
    Reset,
    Include,
    Opaque,
    If,
};

class Token {
public:
    Kind kind = Kind::Illegal;
    std::optional<float> real = std::nullopt;
    std::optional<int> integer = std::nullopt;
    std::optional<std::string> str = std::nullopt;

    Token(Kind k) { kind = k; }
    Token Id(std::string id) { str = id; }

    Token lookup_ident(std::string ident)
    {
        if (ident == "qreg") {
            return Token(Kind::QReg);
        } else if (ident == "creg") {
            return Token(Kind::CReg);
        } else if (ident == "barrier") {
            return Token(Kind::Barrier);
        } else if (ident == "gate") {
            return Token(Kind::Gate);
        } else if (ident == "measure") {
            return Token(Kind::Measure);
        } else if (ident == "reset") {
            return Token(Kind::Reset);
        } else if (ident == "include") {
            return Token(Kind::Include);
        } else if (ident == "opaque") {
            return Token(Kind::Opaque);
        } else if (ident == "if") {
            return Token(Kind::If);
        } else if (ident == "sin") {
            return Token(Kind::Sin);
        } else if (ident == "cos") {
            return Token(Kind::Cos);
        } else if (ident == "tan") {
            return Token(Kind::Tan);
        } else if (ident == "exp") {
            return Token(Kind::Exp);
        } else if (ident == "ln") {
            return Token(Kind::Ln);
        } else if (ident == "sqrt") {
            return Token(Kind::Sqrt);
        } else if (ident == "pi") {
            return Token(Kind::Pi);
        } else if (ident == "OPENQASM") {
            return Token(Kind::OpenQASM);
        } else {
            return Token::Id(ident);
        }
    }
};

#endif