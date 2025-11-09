#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum number of children a node can have */
#define MAX_CHILDREN 100

/* Parse tree node structure */
typedef struct parse_tree_node {
    char* value;                           /* Node value/label */
    struct parse_tree_node** children;     /* Array of child nodes */
    int num_children;                      /* Number of children */
    int capacity;                          /* Allocated capacity for children */
} parse_tree_node;

/* Function declarations */

/**
 * Creates a new parse tree node with the given value
 * @param value The string value for the node
 * @return Pointer to the newly created node
 */
parse_tree_node* create_node(const char* value);

/**
 * Adds a child node to a parent node
 * @param parent The parent node
 * @param child The child node to add
 */
void add_child(parse_tree_node* parent, parse_tree_node* child);

/**
 * Prints the parse tree in a hierarchical format
 * @param node The root node of the tree
 */
void print_tree(parse_tree_node* node);

/**
 * Helper function to print tree with indentation
 * @param node The current node
 * @param depth The depth level for indentation
 */
void print_tree_helper(parse_tree_node* node, int depth);

/**
 * Frees all memory associated with the parse tree
 * @param node The root node of the tree to free
 */
void free_tree(parse_tree_node* node);

/**
 * Gets the number of children for a node
 * @param node The node to query
 * @return Number of children
 */
int get_num_children(parse_tree_node* node);

/**
 * Gets a specific child node
 * @param node The parent node
 * @param index The index of the child to retrieve
 * @return Pointer to the child node, or NULL if index is invalid
 */
parse_tree_node* get_child(parse_tree_node* node, int index);

#endif /* PARSE_TREE_H */

