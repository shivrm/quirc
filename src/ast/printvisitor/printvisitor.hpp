#include "../ast.hpp"

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
    void visit(ExprStmt &f) override;
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