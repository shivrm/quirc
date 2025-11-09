#include "ast.hpp"

void Program::accept(Visitor &v) { v.visit(*this); }
void StructDefn::accept(Visitor &v) { v.visit(*this); }
void FunctionDefn::accept(Visitor &v) { v.visit(*this); }
void VariableDefn::accept(Visitor &v) { v.visit(*this); }
void ReturnStmt::accept(Visitor &v) { v.visit(*this); }
void BreakStmt::accept(Visitor &v) { v.visit(*this); }
void ContinueStmt::accept(Visitor &v) { v.visit(*this); }
void LetStmt::accept(Visitor &v) { v.visit(*this); }
void AsgnStmt::accept(Visitor &v) { v.visit(*this); }
void IfElse::accept(Visitor &v) { v.visit(*this); }
void ForLoop::accept(Visitor &v) { v.visit(*this); }
void WhileLoop::accept(Visitor &v) { v.visit(*this); }
void ExprStmt::accept(Visitor &v) { v.visit(*this); }
void BinaryExpr::accept(Visitor &v) { v.visit(*this); }
void UnaryExpr::accept(Visitor &v) { v.visit(*this); }
void CallExpr::accept(Visitor &v) { v.visit(*this); }
void IndexExpr::accept(Visitor &v) { v.visit(*this); }
void MemberExpr::accept(Visitor &v) { v.visit(*this); }
void Ident::accept(Visitor &v) { v.visit(*this); }
void IntLiteral::accept(Visitor &v) { v.visit(*this); }
void FloatLiteral::accept(Visitor &v) { v.visit(*this); }
void StringLiteral::accept(Visitor &v) { v.visit(*this); }
void ArrayLiteral::accept(Visitor &v) { v.visit(*this); }