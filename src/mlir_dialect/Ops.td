//===- Ops.td ------------------------------------------------------*- tablegen -*-===//
//
//     This file defines ops that correspond directly to AST nodes in ast.hpp
//
//==============================================================================//

include "Dialect.td"
include "Types.td"
include "mlir/IR/OpBase.td"

class Quirc_Op<string mnemonic, list<Trait> traits = []> :
    Op<mnemonic, traits> {
  let dialect = Quirc_Dialect;
}

//------------------------------------------------------------------------------
// ProgramOp
//------------------------------------------------------------------------------

def Quirc_ProgramOp : Quirc_Op<"program"> {
  let summary = "Program root containing definitions";
  let regions = (region AnyRegion:$body);
}

//------------------------------------------------------------------------------
// Definitions
//------------------------------------------------------------------------------

def Quirc_StructDefOp : Quirc_Op<"struct"> {
  let summary = "Structure definition";
  let arguments = (ins StrAttr:$name);
  let regions = (region AnyRegion:$fields);
}

def Quirc_FunctionOp : Quirc_Op<"func"> {
  let summary = "Function definition";
  let arguments = (ins StrAttr:$name);
  let regions = (region AnyRegion:$body);
}

def Quirc_VarDefOp : Quirc_Op<"vdef"> {
  let summary = "Variable definition";
  let arguments = (ins StrAttr:$name, Type:$type);
  let results = (outs Type:$value);
}

//------------------------------------------------------------------------------
// Statements
//------------------------------------------------------------------------------

def Quirc_ReturnOp : Quirc_Op<"return"> {
  let summary = "Return statement";
  let arguments = (ins Optional<AnyType>:$value);
}

def Quirc_BreakOp : Quirc_Op<"break">;
def Quirc_ContinueOp : Quirc_Op<"continue">;

def Quirc_LetOp : Quirc_Op<"let"> {
  let summary = "Let binding";
  let arguments = (ins StrAttr:$name, Optional<Type>:$type);
  let results = (outs AnyType:$value);
}

def Quirc_AssignOp : Quirc_Op<"assign"> {
  let summary = "Assignment";
  let arguments = (ins StrAttr:$name, I32Attr:$op);
  let results = (outs AnyType:$result);
}

def Quirc_IfOp : Quirc_Op<"if"> {
  let arguments = (ins AnyType:$cond);
  let regions = (region AnyRegion:$thenRegion,
                 region AnyRegion:$elseRegion);
}

def Quirc_ForOp : Quirc_Op<"for"> {
  let arguments = (ins StrAttr:$var);
  let regions = (region AnyRegion:$body);
}

def Quirc_WhileOp : Quirc_Op<"while"> {
  let arguments = (ins AnyType:$cond);
  let regions = (region AnyRegion:$body);
}

//------------------------------------------------------------------------------
// Expressions
//------------------------------------------------------------------------------

def Quirc_ExprStmtOp : Quirc_Op<"exprstmt"> {
  let arguments = (ins AnyType:$expr);
}

def Quirc_CallOp : Quirc_Op<"call"> {
  let arguments = (ins StrAttr:$callee, Variadic<AnyType>:$args);
  let results = (outs Optional<AnyType>:$result);
}

def Quirc_IndexOp : Quirc_Op<"index"> {
  let arguments = (ins AnyType:$container, AnyType:$index);
  let results = (outs AnyType:$value);
}

def Quirc_MemberOp : Quirc_Op<"member"> {
  let arguments = (ins AnyType:$container, StrAttr:$field);
  let results = (outs AnyType:$value);
}

def Quirc_IdentOp : Quirc_Op<"ident"> {
  let arguments = (ins StrAttr:$name);
  let results = (outs AnyType:$value);
}

//------------------------------------------------------------------------------
// Literals
//------------------------------------------------------------------------------

def Quirc_IntOp : Quirc_Op<"int"> {
  let arguments = (ins I64Attr:$value);
  let results = (outs AnyType:$out);
}

def Quirc_FloatOp : Quirc_Op<"float"> {
  let arguments = (ins F64Attr:$value);
  let results = (outs AnyType:$out);
}

def Quirc_StringOp : Quirc_Op<"string"> {
  let arguments = (ins StrAttr:$value);
  let results = (outs AnyType:$out);
}

def Quirc_ArrayOp : Quirc_Op<"array"> {
  let arguments = (ins Variadic<AnyType>:$elems);
  let results = (outs AnyType:$out);
}

//------------------------------------------------------------------------------
// Unary & Binary operators
//------------------------------------------------------------------------------

def Quirc_UnaryOp : Quirc_Op<"unary"> {
  let arguments = (ins I32Attr:$op, AnyType:$operand);
  let results = (outs AnyType:$out);
}

def Quirc_BinaryOp : Quirc_Op<"binary"> {
  let arguments = (ins AnyType:$lhs, AnyType:$rhs, I32Attr:$op);
  let results = (outs AnyType:$out);
}

