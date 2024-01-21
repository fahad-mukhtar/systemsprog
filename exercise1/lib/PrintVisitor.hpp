#ifndef H_lib_PrintVisitor
#define H_lib_PrintVisitor
#include "lib/AST.hpp"
#include "lib/ASTVisitor.hpp"
#include <iostream>
#include "lib/AST.hpp"
 
//---------------------------------------------------------------------------
namespace ast {

class PrintVisitor : public ASTVisitor {
public:
    void visit(const UnaryMinus& node) const override;
     
    void visit(const UnaryPlus& node) const override;
    void visit(const Add& node) const override;
    void visit(const Subtract& node) const override;
    void visit(const Multiply& node) const override;
    void visit(const Divide& node) const override;
    void visit(const Power& node) const override;
    void visit(const Constant& node) const override;
    void visit(const Parameter& node) const override;
    void visit(const ASTNode& node) const override;
    void visit(const UnaryASTNode& node) const override;
     
     
    
};
} // namespace ast
//---------------------------------------------------------------------------
#endif
