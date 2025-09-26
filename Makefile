# Project Makefile

# Compiler and tools
CXX = g++
LEX = flex
YACC = bison

# Flags
CXXFLAGS = -Wall -std=c++11

# Sources
LEX_SRC = src/lexer.l
YACC_SRC = src/yacc.y

# Generated files
LEX_CPP = src/lexer.cpp
YACC_CPP = src/yacc.cpp
YACC_HPP = src/yacc.hpp

# Output binary
BUILD_DIR = build
TARGET = $(BUILD_DIR)/compiler

# Default target
all: $(TARGET)

# Build the final executable
$(TARGET): $(LEX_CPP) $(YACC_CPP)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(LEX_CPP) $(YACC_CPP) -o $(TARGET)

# Generate lexer from Flex
$(LEX_CPP): $(LEX_SRC) $(YACC_HPP)
	$(LEX) -o $(LEX_CPP) $(LEX_SRC)

# Generate parser from Bison
$(YACC_CPP) $(YACC_HPP): $(YACC_SRC)
	$(YACC) -d -o $(YACC_CPP) $(YACC_SRC)

# Run with example file
run: $(TARGET)
	$(TARGET) examples/bell.qc

# Clean generated files
clean:
	rm -f $(LEX_CPP) $(YACC_CPP) $(YACC_HPP) $(TARGET)
	rm -rf $(BUILD_DIR)

.PHONY: all run clean


