#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpImplementation.h"

#include "Dialect/Dialect.h.inc"
#include "Dialect/Ops.h.inc"
#include "Dialect/Types.h.inc"

using namespace mlir;
using namespace quirc;

void QuircDialect::initialize() {
  addTypes<
      Quirc_AtomType,
      Quirc_ArrayType,
      Quirc_InferType
  >();

  addOperations<
      Quirc_ProgramOp,
      Quirc_StructDefOp,
      Quirc_FunctionOp,
      Quirc_VarDefOp,
      Quirc_ReturnOp,
      Quirc_BreakOp,
      Quirc_ContinueOp,
      Quirc_LetOp,
      Quirc_AssignOp,
      Quirc_IfOp,
      Quirc_ForOp,
      Quirc_WhileOp,
      Quirc_ExprStmtOp,
      Quirc_CallOp,
      Quirc_IndexOp,
      Quirc_MemberOp,
      Quirc_IdentOp,
      Quirc_IntOp,
      Quirc_FloatOp,
      Quirc_StringOp,
      Quirc_ArrayOp,
      Quirc_UnaryOp,
      Quirc_BinaryOp
  >();
}

