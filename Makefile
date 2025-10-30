# Project Makefile

# Compiler and tools
CXX = gcc
LEX = flex
YACC = bison

# Flags
CXXFLAGS = -Wall

# Sources
LEX_SRC = src/lexer.l
YACC_SRC = src/yacc.y

# Generated files
LEX_CPP = src/lexer.c
YACC_CPP = src/yacc.c
YACC_HPP = src/yacc.h

# Output binary
BUILD_DIR = build
TARGET = $(BUILD_DIR)/compiler

# Default target
all: $(TARGET)

# Build the final executable
$(TARGET): $(LEX_CPP) $(YACC_CPP)
	mkdir -p $(BUILD_DIR)
	$(CXX) src/parse_tree.c -c -o build/parse_tree.o
# g++ build/parse_tree.o build/lexer.o build/yacc.o src/build_ast.cpp -o $(TARGET)
	g++ build/parse_tree.o build/lexer.o build/yacc.o src/parse_show.cpp -o $(TARGET)

# Generate lexer from Flex
$(LEX_CPP): $(LEX_SRC) $(YACC_HPP)
	$(LEX) -o $(LEX_CPP) $(LEX_SRC)
	$(CXX) $(LEX_CPP) -c -o build/lexer.o

# Generate parser from Bison
$(YACC_CPP) $(YACC_HPP): $(YACC_SRC)
	$(YACC) -d -o $(YACC_CPP) $(YACC_SRC)
	$(CXX) $(YACC_CPP) -c -o build/yacc.o

# Run with example file
run: $(TARGET)
	$(TARGET) examples/bell.qc

# Clean generated files
clean:
	rm -f $(LEX_CPP) $(YACC_CPP) $(YACC_HPP) $(TARGET)
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)

.PHONY: all run clean


