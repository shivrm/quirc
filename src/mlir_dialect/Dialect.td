//===- Dialect.td -------------------------------------------------*- tablegen -*-===//
//
// Full MLIR dialect corresponding to AST nodes in ast.hpp
//
//==============================================================================//

include "mlir/IR/Dialect.h"
include "mlir/IR/OpBase.td"

def Quirc_Dialect : Dialect {
  let name = "quirc";
  let cppNamespace = "::quirc";
  let summary = "High-level QuirC language dialect";
}

