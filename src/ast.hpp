#include <vector>
#include <memory>
#include <string>
#include <variant>
#include <optional>
#pragma once

struct Visitor;

struct Type {
    virtual ~Type() = default;
};

struct AtomType: Type {
    std::string name;
};

struct ArrayType: Type {
    std::unique_ptr<Type> element_type;
};

struct InferType: Type {};

enum BinaryOp {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    OR,
    AND,
    BITOR,
    BITXOR,
    BITAND,
    EQ,
    NEQ,
    LT,
    LE,
    GT,
    GE,
    SHL,
    SHR,
};

enum UnaryOp {
    PLUS,
    MINUS,
    NOT,
    BITNOT,
};

enum AssignmentOp {
    ASSIGN,
    ADD_EQ,
    SUB_EQ,
    MUL_EQ, 
    DIV_EQ,
    MOD_EQ,
    BITAND_EQ,
    BITOR_EQ,
    BITXOR_EQ,
    BITNOT_EQ,
};

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void accept(Visitor &v) = 0;
};

struct Definition : ASTNode { };
struct Statement : ASTNode { };
struct Expr : ASTNode { };

struct Program : ASTNode {
    std::vector<std::unique_ptr<Definition>> body;
    void accept(Visitor &v) override;
};

struct StructDefn : Definition {
    std::string name;
    std::vector<std::pair<std::string, std::unique_ptr<Type>>> fields;
    void accept(Visitor &v) override;
};

struct FunctionDefn : Definition {
    std::string name;
    std::vector<std::pair<std::string, std::unique_ptr<Type>>> args;
    std::optional<std::unique_ptr<Type>> return_type;
    std::vector<std::unique_ptr<Statement>> body;
    void accept(Visitor &v) override;
};

struct VariableDefn : Definition {
    std::string name;
    std::optional<std::unique_ptr<Type>> type;
    std::unique_ptr<Expr> value;
    void accept(Visitor &v) override;
};

struct ReturnStmt : Statement {
    std::optional<std::unique_ptr<Expr>> value;
    void accept(Visitor &v) override;
};
struct BreakStmt : Statement {
    void accept(Visitor &v) override;
};
struct ContinueStmt : Statement {
    void accept(Visitor &v) override;
};

struct LetStmt : Statement {
    std::string name;
    std::optional<std::unique_ptr<Type>> type;
    std::unique_ptr<Expr> value;
    void accept(Visitor &v) override;
};

struct AsgnStmt : Statement {
    std::string name;
    AssignmentOp op;
    std::unique_ptr<Expr> rhs;
    void accept(Visitor &v) override;
};

struct IfElse : Statement {
    std::unique_ptr<Expr> condition;
    std::vector<std::unique_ptr<Statement>> body;
    std::vector<std::unique_ptr<Statement>> else_body;
    void accept(Visitor &v) override;
};

struct ForLoop : Statement {
    std::string var;
    std::unique_ptr<Expr> condition;
    std::vector<std::unique_ptr<Statement>> body;
    void accept(Visitor &v) override;
};

struct WhileLoop : Statement {
    std::unique_ptr<Expr> condition;
    std::vector<std::unique_ptr<Statement>> body;
    void accept(Visitor &v) override;
};

struct BinaryExpr : Expr {
    std::unique_ptr<Expr> left, right;
    BinaryOp op;
    void accept(Visitor &v) override;
};

struct UnaryExpr : Expr {
    std::unique_ptr<Expr> operand;
    UnaryOp op;
    void accept(Visitor &v) override;
};

struct CallExpr : Expr {
    std::unique_ptr<Expr> function;
    std::vector<std::unique_ptr<Expr>> args;
    void accept(Visitor &v) override;
};

struct IndexExpr : Expr {
    std::unique_ptr<Expr> container, index;
    void accept(Visitor &v) override;
};

struct MemberExpr : Expr {
    std::unique_ptr<Expr> container;
    std::string member;
    void accept(Visitor &v) override;
};

struct Ident : Expr {
    std::string name;
    void accept(Visitor &v) override;
};

struct IntLiteral : Expr {
    int value;
    void accept(Visitor &v) override;
};
struct FloatLiteral : Expr {
    double value;
    void accept(Visitor &v) override;
};
struct StringLiteral : Expr {
    std::string value;
    void accept(Visitor &v) override;
};
struct ArrayLiteral : Expr {
    std::vector<std::unique_ptr<Expr>> elems;
    void accept(Visitor &v) override;
};

struct Visitor {
    virtual void visit(Program &f) = 0;
    virtual void visit(StructDefn &f) = 0;
    virtual void visit(FunctionDefn &f) = 0;
    virtual void visit(VariableDefn &f) = 0;
    virtual void visit(ReturnStmt &f) = 0;
    virtual void visit(BreakStmt &f) = 0;
    virtual void visit(ContinueStmt &f) = 0;
    virtual void visit(LetStmt &f) = 0;
    virtual void visit(AsgnStmt &f) = 0;
    virtual void visit(IfElse &f) = 0;
    virtual void visit(ForLoop &f) = 0;
    virtual void visit(WhileLoop &f) = 0;
    virtual void visit(BinaryExpr &f) = 0;
    virtual void visit(UnaryExpr &f) = 0;
    virtual void visit(CallExpr &f) = 0;
    virtual void visit(IndexExpr &f) = 0;
    virtual void visit(MemberExpr &f) = 0;
    virtual void visit(Ident &f) = 0;
    virtual void visit(IntLiteral &f) = 0;
    virtual void visit(FloatLiteral &f) = 0;
    virtual void visit(StringLiteral &f) = 0;
    virtual void visit(ArrayLiteral &f) = 0;
};

struct PrintVisitor : Visitor {
    explicit PrintVisitor(std::ostream &os);
    void visit(Program &f) override;
    void visit(StructDefn &f) override;
    void visit(FunctionDefn &f) override;
    void visit(VariableDefn &f) override;
    void visit(ReturnStmt &f) override;
    void visit(BreakStmt &f) override;
    void visit(ContinueStmt &f) override;
    void visit(LetStmt &f) override;
    void visit(AsgnStmt &f) override;
    void visit(IfElse &f) override;
    void visit(ForLoop &f) override;
    void visit(WhileLoop &f) override;
    void visit(BinaryExpr &f) override;
    void visit(UnaryExpr &f) override;
    void visit(CallExpr &f) override;
    void visit(IndexExpr &f) override;
    void visit(MemberExpr &f) override;
    void visit(Ident &f) override;
    void visit(IntLiteral &f) override;
    void visit(FloatLiteral &f) override;
    void visit(StringLiteral &f) override;
    void visit(ArrayLiteral &f) override;

private:
    std::ostream &out;
    int indent;
    void print_indent();
    void print_type(const Type *t);
    template<typename T> void visit_block(const std::vector<std::unique_ptr<T>> &block);
};
