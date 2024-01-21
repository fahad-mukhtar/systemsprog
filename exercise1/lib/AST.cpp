#include "lib/AST.hpp"
#include "lib/ASTVisitor.hpp"
#include "lib/EvaluationContext.hpp"
//---------------------------------------------------------------------------
namespace ast {


UnaryMinus::UnaryMinus(std::unique_ptr<ASTNode> child) : UnaryASTNode(std::move(child)) {}
UnaryASTNode::UnaryASTNode(std::unique_ptr<ASTNode> child) : child(std::move(child)) {}
UnaryPlus::UnaryPlus(std::unique_ptr<ASTNode> child) : UnaryASTNode(std::move(child)) {}
 


ASTNode::Type UnaryMinus::getType() const {
    return Type::UnaryMinus;
}

void UnaryMinus::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

double UnaryMinus::evaluate(const EvaluationContext& context) const {
    return -child->evaluate(context);
}

void UnaryMinus::optimize(std::unique_ptr<ASTNode>& thisRef) {
    // Check if the child is a Constant
    if (const auto* constantChild = dynamic_cast<const Constant*>(child.get())) {
        // If yes, optimize by evaluating the negation
        double newValue = -constantChild->getValue();
        thisRef = std::make_unique<Constant>(newValue);
    }
    // You can add more optimizations specific to UnaryMinus as needed.
}


Constant::Constant(double value) : value(value) {}

ASTNode::Type Constant::getType() const {
    return Type::Constant;
}

void Constant::accept(const ASTVisitor& visitor) const {
    visitor.visit(*this);
}

double Constant::evaluate(const EvaluationContext& /* context */) const {
    return value;
}

void Constant::optimize(std::unique_ptr<ASTNode>& thisRef) {
   (void)thisRef;
}

double Constant::getValue() const {
    return value;
}

Parameter::Parameter(size_t index) : index(index) {}

ASTNode::Type Parameter::getType() const {
    return Type::Parameter;
}

void Parameter::accept(const ASTVisitor& visitor) const {
    visitor.visit(*this);
}

double Parameter::evaluate(const EvaluationContext& context) const {
    return context.getParameter(index);
}

void Parameter::optimize(std::unique_ptr<ASTNode>& thisRef) {
    (void)thisRef;
}

size_t Parameter::getIndex() const {
    return index;
}

ASTNode::Type UnaryPlus::getType() const {
    return Type::UnaryPlus;
}

void UnaryPlus::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

double UnaryPlus::evaluate(const EvaluationContext& context) const {
    // UnaryPlus simply returns the value of its child.
    return child->evaluate(context);
}

void UnaryPlus::optimize(std::unique_ptr<ASTNode>& thisRef) {
    // Your optimization logic here, if needed.
    // For simplicity, I'm not making any changes in this example.

     child->optimize(child);

    // Apply specific optimizations
    if (dynamic_cast<Constant*>(child.get())) {
        // Optimization: +CONST => CONST
        thisRef = std::move(child);
    }
    else {
        // If the child is not a constant, keep the UnaryPlus node
        // or apply other optimizations specific to UnaryPlus

        // Other UnaryPlus specific optimizations can be added here.
        // For now, let's check for the case +E => E
        if (auto* unaryChild = dynamic_cast<UnaryASTNode*>(child.get())) {
            // Optimization: +E => E
            thisRef = unaryChild->releaseInput();
        }
    }
}

 
} // namespace ast
//---------------------------------------------------------------------------
