#include "lib/PrintVisitor.hpp"
//---------------------------------------------------------------------------
namespace ast {

 
void PrintVisitor::visit(const UnaryMinus& node) const {
    std::cout << "(-";
    node.getInput().accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(const Add& node) const {
    std::cout << "(";
    node.getLeft().accept(*this);
    std::cout << " + ";
    node.getRight().accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(const Subtract& node) const {
    std::cout << "(";
    node.getLeft().accept(*this);
    std::cout << " - ";
    node.getRight().accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(const Multiply& node) const {
    std::cout << "(";
    node.getLeft().accept(*this);
    std::cout << " * ";
    node.getRight().accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(const Divide& node) const {
    std::cout << "(";
    node.getLeft().accept(*this);
    std::cout << " / ";
    node.getRight().accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(const Power& node) const {
    std::cout << "(";
    node.getLeft().accept(*this);
    std::cout << " ^ ";
    node.getRight().accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(const Constant& node) const {
    std::cout << node.getValue();
}

 

void PrintVisitor::visit(const Parameter& node) const {
    std::cout << "P" << node.getIndex();
}

void PrintVisitor::visit(const ASTNode& node) const {
    // Generic handling for ASTNode
     static_cast<void>(node);
    std::cout << "Generic ASTNode";
}

void PrintVisitor::visit(const UnaryASTNode& node) const {
    // Generic handling for UnaryASTNode
    std::cout << "UnaryASTNode";
    node.getInput().accept(*this);  // Recursively visit the child node
}

} // namespace ast
//---------------------------------------------------------------------------
