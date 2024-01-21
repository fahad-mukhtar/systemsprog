#ifndef H_lib_ASTVisitor
#define H_lib_ASTVisitor

#include "lib/AST.hpp"
//---------------------------------------------------------------------------
namespace ast {
class PrintVisitor;
class ASTVisitor;

class ASTNode;
class UnaryASTNode;
class Add;
class Subtract;
class Multiply;
class Divide;
class Power;
class Constant;
class Parameter;
class UnaryMinus;
class UnaryPlus;

class ASTVisitor {
public:
    virtual void visit(const ASTNode& node) const = 0;
    virtual ~ASTVisitor() = default;
    virtual void visit(const UnaryASTNode& node) const = 0;
    virtual void visit(const Add& node) const = 0;
    virtual void visit(const Subtract& node) const = 0;
    virtual void visit(const Multiply& node) const = 0;
    virtual void visit(const Divide& node) const = 0;
    virtual void visit(const Power& node) const = 0;
    virtual void visit(const Constant& node) const = 0;
    virtual void visit(const Parameter& node) const = 0;
    virtual void visit(const UnaryMinus& node) const = 0;
    virtual void visit(const UnaryPlus& node) const = 0;
    // Add more visit methods for other ASTNode types as needed
};

 

} // namespace ast
//---------------------------------------------------------------------------
#endif
