# Project Makefile

# Compiler and tools
CXX = g++
FLEX = flex
YACC = bison

CC = gcc
CFLAGS = 

# Flags
CXXFLAGS = -Wall -g

# Sources
FLEX_SRC = src/parser/flex.l
YACC_SRC = src/parser/yacc.y

# Generated files
FLEX_CPP = src/parser/flex.c
YACC_CPP = src/parser/yacc.c
YACC_HPP = src/parser/yacc.h

# Output binary
BUILD_DIR = build
TARGET = $(BUILD_DIR)/compiler

FLEX_OUT = build/flex.o
YACC_OUT = build/yacc.o
PARSE_TREE_OUT = build/parse_tree.o

PARSER_OUT = $(FLEX_OUT) $(YACC_OUT) $(PARSE_TREE_OUT)

# Default target
all: $(TARGET)

# Generate lexer from Flex
$(FLEX_CPP): $(FLEX_SRC) $(YACC_HPP)
	$(FLEX) -o $(FLEX_CPP) $(FLEX_SRC)
	
# Generate parser from Bison
$(YACC_CPP) $(YACC_HPP): $(YACC_SRC)
	$(YACC) -d -o $(YACC_CPP) $(YACC_SRC)


$(FLEX_OUT): $(FLEX_CPP)
	$(CC) $(FLEX_CPP) -c -o $(FLEX_OUT)

$(YACC_OUT): $(YACC_CPP) $(YACC_HPP)
	$(CC) $(YACC_CPP) -c -o $(YACC_OUT)

$(PARSE_TREE_OUT):
	$(CC) src/parser/parse_tree.c -c -o $(PARSE_TREE_OUT)


parser: $(FLEX_OUT) $(YACC_OUT) $(PARSE_TREE_OUT)
	$(CC) src/parser/parse_tree.c -c -o build/parse_tree.o


$(TARGET): parser
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(PARSER_OUT) src/ast/ast.cpp src/ast/printvisitor/printvisitor.cpp src/main.cpp -o $(TARGET)
	

# Run with example file
run: $(TARGET)
	$(TARGET) examples/bell.qc

# Clean generated files
clean:
	rm -f $(FLEX_CPP) $(YACC_CPP) $(YACC_HPP) $(TARGET)
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)

.PHONY: all run clean


