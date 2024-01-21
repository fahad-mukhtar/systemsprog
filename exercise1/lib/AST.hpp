#ifndef H_lib_AST
#define H_lib_AST
//---------------------------------------------------------------------------
#include <memory>
#include <cmath>
#include "lib/ASTVisitor.hpp" 
#include "lib/EvaluationContext.hpp"
//---------------------------------------------------------------------------
namespace ast {
//---------------------------------------------------------------------------
/// Base class for AST nodes

class EvaluationContext;

class PrintVisitor;
class ASTVisitor;
class UnaryMinus;
class UnaryASTNode;
class Add;
class Subtract;
class Multiply;
class Divide;
class Power;
 
class ASTNode {
    public:
    /// All possible types of ASTNodes
    enum class Type {
        UnaryPlus,
        UnaryMinus,
        Add,
        Subtract,
        Multiply,
        Divide,
        Power,
        Constant,
        Parameter
    };

    virtual Type getType() const = 0;
   // virtual void accept(const ASTVisitor& visitor) const = 0;
    //virtual void accept(ASTVisitor& visitor) const = 0;
    virtual void accept(const ASTVisitor& visitor) const = 0;
      
    virtual double evaluate(const EvaluationContext& context) const = 0;
    virtual void optimize(std::unique_ptr<ASTNode>& thisRef) = 0;
    virtual ~ASTNode() = default;
   
};


class UnaryASTNode : public ASTNode {
public:
    UnaryASTNode(std::unique_ptr<ASTNode> child);
virtual void accept(ASTVisitor& visitor) const = 0;
 //virtual void accept(ASTVisitor& visitor) const;
    const ASTNode& getInput() const;
    std::unique_ptr<ASTNode> releaseInput();

protected:
    std::unique_ptr<ASTNode> child;
};

class BinaryASTNode : public ASTNode {
public:
    BinaryASTNode(std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right);
    virtual void accept(ASTVisitor& visitor) const = 0;
    //const ASTNode& getLeft() const;
    //const ASTNode& getRight() const;
    virtual const ASTNode& getLeft() const = 0;
    virtual const ASTNode& getRight() const = 0;
    std::unique_ptr<ASTNode> releaseLeft();
    std::unique_ptr<ASTNode> releaseRight();

protected:
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
};

class UnaryPlus : public UnaryASTNode {
public:
    using UnaryASTNode::UnaryASTNode;
    
    Type getType() const override;
    void accept(ASTVisitor& visitor) const override;
       
    //double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
     
    UnaryPlus(std::unique_ptr<ASTNode> child);
      
    double evaluate(const EvaluationContext& context) const override;

    void accept(const ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }
 
};

 

class UnaryMinus : public UnaryASTNode {
public:
    explicit UnaryMinus(std::unique_ptr<ASTNode> child);
    using UnaryASTNode::UnaryASTNode;
    
    Type getType() const override;
    void accept(ASTVisitor& visitor) const override;
     
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;

    void accept(const ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }
};

class Add : public BinaryASTNode {
public:
    using BinaryASTNode::BinaryASTNode;
    Type getType() const override;
    void accept(ASTVisitor& visitor) const override;
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;


     const ASTNode& getLeft() const override {
        return *leftOperand; // Assuming leftOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    const ASTNode& getRight() const override {
        return *rightOperand; // Assuming rightOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    void accept(const ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }

    private:
    std::unique_ptr<ASTNode> leftOperand;
    std::unique_ptr<ASTNode> rightOperand;
};

class Subtract : public BinaryASTNode {
public:
    using BinaryASTNode::BinaryASTNode;
    Type getType() const override;
    void accept(ASTVisitor& visitor) const override;
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;

    void accept(const ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }

     const ASTNode& getLeft() const override {
        return *leftOperand; // Assuming leftOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    const ASTNode& getRight() const override {
        return *rightOperand; // Assuming rightOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    private:
        std::unique_ptr<ASTNode> leftOperand;
        std::unique_ptr<ASTNode> rightOperand;
};

class Multiply : public BinaryASTNode {
public:
    using BinaryASTNode::BinaryASTNode;
    Type getType() const override;
    void accept(ASTVisitor& visitor) const override;
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;

    void accept(const ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }

       const ASTNode& getLeft() const override {
        return *leftOperand; // Assuming leftOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    const ASTNode& getRight() const override {
        return *rightOperand; // Assuming rightOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    private:
    std::unique_ptr<ASTNode> leftOperand;
    std::unique_ptr<ASTNode> rightOperand;
};


class Divide : public BinaryASTNode {
public:
    using BinaryASTNode::BinaryASTNode;
    Type getType() const override;
    void accept(ASTVisitor& visitor) const override;
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;

    void accept(const ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }

     const ASTNode& getLeft() const override {
        return *leftOperand; // Assuming leftOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    const ASTNode& getRight() const override {
        return *rightOperand; // Assuming rightOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    private:
    std::unique_ptr<ASTNode> leftOperand;
    std::unique_ptr<ASTNode> rightOperand;
};

class Power : public BinaryASTNode {
public:
    using BinaryASTNode::BinaryASTNode;
    Type getType() const override;
    void accept(ASTVisitor& visitor) const override;
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;

    void accept(const ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }

    const ASTNode& getLeft() const override {
        return *leftOperand; // Assuming leftOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    const ASTNode& getRight() const override {
        return *rightOperand; // Assuming rightOperand is a member variable of type std::unique_ptr<ASTNode>
    }

    private:
    std::unique_ptr<ASTNode> leftOperand;
    std::unique_ptr<ASTNode> rightOperand;
};

class Constant : public ASTNode {
public:
    Constant(double value);
    Type getType() const override;
   // void accept(ASTVisitor& visitor) const override;
    void accept(const ASTVisitor& visitor) const override;
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    double getValue() const;

private:
    double value;
};

class Parameter : public ASTNode {
public:
    Parameter(size_t index);
    Type getType() const override;
   // void accept(ASTVisitor& visitor) const override;
    void accept(const ASTVisitor& visitor) const override;
    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    size_t getIndex() const;

private:
    size_t index;
};


class ConcreteUnaryPlus : public ast::UnaryPlus {
public:
    using ast::UnaryPlus::UnaryPlus;

    double evaluate(const ast::EvaluationContext& context) const override {
        return getInput().evaluate(context);  
    }
};

class ConcreteUnaryMinus : public UnaryMinus {
public:
    using UnaryMinus::UnaryMinus;

    void accept(ASTVisitor& visitor) const override {
        visitor.visit(*this);
    }
};

//---------------------------------------------------------------------------
} // namespace ast
//---------------------------------------------------------------------------
#endif
