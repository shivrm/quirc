# QUIRC: Quantum IR Compiler

## Lexer

The lexer is generated from `src/lexer.l` using Flex (C++ mode).
It takes a single file as an argument and tokenizes it.
The tokens and the corresponding token texts are printed to
standard output.

Th lexer can be built using the following command
```
make
```

This generates the executable `build/lexer`. Example scripts for
testing the lexer are provided in the examples directory.

Example:
```
./build/lexer examples/bell.qc
```

