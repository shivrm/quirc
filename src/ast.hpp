#include <vector>
#include <memory>
#include <string>
#include <variant>
#include <optional>

struct Visitor;

struct AtomType {
    std::string name;
};

struct ArrayType {
    std::unique_ptr<Type> elementType;
};

using Type = std::variant<AtomType, ArrayType>;

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

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void accept(Visitor& v) = 0;
};

struct Definition: ASTNode {};
struct Statement: ASTNode {};
struct Expr: ASTNode {};

struct Program: ASTNode {
    std::vector<std::unique_ptr<Definition>> body;
};

struct StructDefn: Definition {
    std::string name;
    std::vector<std::pair<std::string, Type>> fields;
};

struct FunctionDefn: Definition {
    std::string name;
    std::vector<std::pair<std::string, Type>> args;
    std::optional<Type> return_type;
    std::vector<std::unique_ptr<Statement>> body;
};

struct VariableDefn: Definition {
    std::string name;
    std::optional<Type> type;
    std::unique_ptr<Expr> value;
};

struct ReturnStmt: Statement {
    std::optional<std::unique_ptr<Expr>> value;
};
struct BreakStmt: Statement {};
struct ContinueStmt: Statement {};

struct LetStmt: Statement {
    std::string name;
    std::optional<Type> type;
    std::unique_ptr<Expr> value;
};

struct IfElse: Statement {
    std::unique_ptr<Expr> condition;
    std::vector<std::unique_ptr<Statement>> body;
    std::vector<std::unique_ptr<Statement>> else_body;
};

struct ForLoop: Statement {
    std::string var;
    std::vector<std::unique_ptr<Statement>> body;
};

struct WhileLoop: Statement {
    std::unique_ptr<Expr> condition;
    std::vector<std::unique_ptr<Statement>> body;
};

struct BinaryExpr: Expr {
    std::unique_ptr<Expr> left, right;
    BinaryOp op;
};

struct UnaryExpr: Expr {
    std::unique_ptr<Expr> operand;
    UnaryOp op;   
};

struct CallExpr: Expr {
    std::unique_ptr<Expr> function;
    std::vector<std::unique_ptr<Expr>> args;
};

struct IndexExpr: Expr {
    std::unique_ptr<Expr> container, index;
};

struct MemberExpr: Expr {
    std::unique_ptr<Expr> container;
    std::string member;
};

struct Ident: Expr {
    std::string name;
};

struct IntLiteral: Expr { int value; };
struct FloatLiteral: Expr { double value; };
struct StringLiteral: Expr { std::string value; };
struct ArrayLiteral: Expr {
    std::vector<Expr> elems;
};