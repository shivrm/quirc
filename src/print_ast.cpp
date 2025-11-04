#include "ast.hpp"
#include <iostream>
#include <string>

PrintVisitor::PrintVisitor(std::ostream &os)
    : out(os), indent(0) {}

void PrintVisitor::print_indent()
{
    out << std::string(indent * 2, ' ');
}

void PrintVisitor::print_type(const Type *t)
{
    if (!t)
    {
        out << "<?>";
        return;
    }
    if (auto a = dynamic_cast<const AtomType *>(t))
    {
        out << a->name;
    }
    else if (auto arr = dynamic_cast<const ArrayType *>(t))
    {
        out << "array<";
        print_type(arr->element_type.get());
        out << ">";
    }
    else
    {
        out << "unknown_type";
    }
}

template <typename T>
void PrintVisitor::visit_block(const std::vector<std::unique_ptr<T>> &block) {
    indent++;
    for (auto &stmt : block) {
        stmt->accept(*this);
    }
    indent--;
}

void PrintVisitor::visit(Program &f)
{
    print_indent();
    out << "Program\n";
    visit_block(f.body);
}

void PrintVisitor::visit(StructDefn &f)
{
    print_indent();
    out << "StructDefn name=" << f.name << "\n";
    indent++;
    for (auto &field : f.fields)
    {
        print_indent();
        out << "Field " << field.first << " : ";
        print_type(field.second.get());
        out << "\n";
    }
    indent--;
}

void PrintVisitor::visit(FunctionDefn &f)
{
    print_indent();
    out << "FunctionDefn name=" << f.name;
    if (f.return_type)
    {
        out << " : ";
        print_type(f.return_type->get());
    }
    out << "\n";
    indent++;
    for (auto &arg : f.args)
    {
        print_indent();
        out << "Arg " << arg.first << " : ";
        print_type(arg.second.get());
        out << "\n";
    }
    print_indent();
    out << "Body\n";
    visit_block(f.body);
    indent--;
}

void PrintVisitor::visit(VariableDefn &f)
{
    print_indent();
    out << "VariableDefn name=" << f.name;
    if (f.type)
    {
        out << " : ";
        print_type(f.type->get());
    }
    out << "\n";
    if (f.value)
    {
        indent++;
        f.value->accept(*this);
        indent--;
    }
}

void PrintVisitor::visit(ReturnStmt &f)
{
    print_indent();
    out << "ReturnStmt\n";
    if (f.value)
    {
        indent++;
        f.value->get()->accept(*this);
        indent--;
    }
}

void PrintVisitor::visit(BreakStmt &)
{
    print_indent();
    out << "BreakStmt\n";
}

void PrintVisitor::visit(ContinueStmt &)
{
    print_indent();
    out << "ContinueStmt\n";
}

void PrintVisitor::visit(LetStmt &f)
{
    print_indent();
    out << "LetStmt name=" << f.name;
    if (f.type)
    {
        out << " : ";
        print_type(f.type->get());
    }
    out << "\n";
    indent++;
    f.value->accept(*this);
    indent--;
}

void PrintVisitor::visit(AsgnStmt &f)
{
    print_indent();
    out << "AsgnStmt name=" << f.name << " op=" << f.op << "\n";
    indent++;
    f.rhs->accept(*this);
    indent--;
}

void PrintVisitor::visit(IfElse &f)
{
    print_indent();
    out << "IfElse\n";
    indent++;
    print_indent();
    out << "Condition:\n";
    indent++;
    f.condition->accept(*this);
    indent--;
    print_indent();
    out << "Then:\n";
    visit_block(f.body);
    if (!f.else_body.empty())
    {
        print_indent();
        out << "Else:\n";
        visit_block(f.else_body);
    }
    indent -= 2;
}

void PrintVisitor::visit(ForLoop &f)
{
    print_indent();
    out << "ForLoop var=" << f.var << "\n";
    indent++;
    print_indent();
    out << "Condition:\n";
    indent++;
    f.condition->accept(*this);
    indent--;
    print_indent();
    out << "Body:\n";
    visit_block(f.body);
    indent--;
}

void PrintVisitor::visit(WhileLoop &f)
{
    print_indent();
    out << "WhileLoop\n";
    indent++;
    print_indent();
    out << "Condition:\n";
    indent++;
    f.condition->accept(*this);
    indent--;
    print_indent();
    out << "Body:\n";
    visit_block(f.body);
    indent--;
}

void PrintVisitor::visit(BinaryExpr &f)
{
    print_indent();
    out << "BinaryExpr op=" << f.op << "\n";
    indent++;
    f.left->accept(*this);
    f.right->accept(*this);
    indent--;
}

void PrintVisitor::visit(UnaryExpr &f)
{
    print_indent();
    out << "UnaryExpr op=" << f.op << "\n";
    indent++;
    f.operand->accept(*this);
    indent--;
}

void PrintVisitor::visit(CallExpr &f)
{
    print_indent();
    out << "CallExpr\n";
    indent++;
    f.function->accept(*this);
    for (auto &a : f.args)
        a->accept(*this);
    indent--;
}

void PrintVisitor::visit(IndexExpr &f)
{
    print_indent();
    out << "IndexExpr\n";
    indent++;
    f.container->accept(*this);
    f.index->accept(*this);
    indent--;
}

void PrintVisitor::visit(MemberExpr &f)
{
    print_indent();
    out << "MemberExpr member=" << f.member << "\n";
    indent++;
    f.container->accept(*this);
    indent--;
}

void PrintVisitor::visit(Ident &f)
{
    print_indent();
    out << "Ident name=" << f.name << "\n";
}

void PrintVisitor::visit(IntLiteral &f)
{
    print_indent();
    out << "IntLiteral value=" << f.value << "\n";
}

void PrintVisitor::visit(FloatLiteral &f)
{
    print_indent();
    out << "FloatLiteral value=" << f.value << "\n";
}

void PrintVisitor::visit(StringLiteral &f)
{
    print_indent();
    out << "StringLiteral value="<< f.value << "\n";
}

void PrintVisitor::visit(ArrayLiteral &f)
{
    print_indent();
    out << "ArrayLiteral\n";
    indent++;
    for (auto &elem : f.elems)
        elem->accept(*this);
    indent--;
}
