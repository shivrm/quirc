//===- Types.td ---------------------------------------------------*- tablegen -*-===//
//
// Types corresponding to AST::Type hierarchy
//
//==============================================================================//

include "mlir/IR/OpBase.td"
include "Dialect.td"

// Base type
class Quirc_Type<string name> : TypeDef<Quirc_Dialect, name>;

// AtomType(name)
def Quirc_AtomType : Quirc_Type<"Atom"> {
  let summary = "Atomic type (identifier-based)";
  let arguments = (ins StrAttr:$name);
}

// ArrayType(element_type)
def Quirc_ArrayType : Quirc_Type<"Array"> {
  let summary = "Array type";
  let arguments = (ins Type:$element);
}

// Infer (_) type
def Quirc_InferType : Quirc_Type<"Infer"> {
  let summary = "Type inferred by compiler";
}

