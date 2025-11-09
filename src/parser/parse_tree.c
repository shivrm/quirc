#include "parse_tree.h"

/**
 * Creates a new parse tree node with the given value
 */
parse_tree_node* create_node(const char* value) {
    if (value == NULL) {
        return NULL;
    }
    
    parse_tree_node* node = (parse_tree_node*)malloc(sizeof(parse_tree_node));
    if (node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for parse tree node\n");
        exit(1);
    }
    
    /* Copy the value string */
    node->value = strdup(value);
    if (node->value == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for node value\n");
        free(node);
        exit(1);
    }
    
    /* Initialize children array */
    node->capacity = 10;  /* Initial capacity */
    node->children = (parse_tree_node**)malloc(node->capacity * sizeof(parse_tree_node*));
    if (node->children == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for children array\n");
        free(node->value);
        free(node);
        exit(1);
    }
    
    node->num_children = 0;
    
    return node;
}

/**
 * Adds a child node to a parent node
 */
void add_child(parse_tree_node* parent, parse_tree_node* child) {
    if (parent == NULL) {
        fprintf(stderr, "Error: Cannot add child to NULL parent\n");
        return;
    }
    
    if (child == NULL) {
        /* Allow NULL children to be added but skip them */
        return;
    }
    
    /* Check if we need to resize the children array */
    if (parent->num_children >= parent->capacity) {
        parent->capacity *= 2;
        parse_tree_node** new_children = (parse_tree_node**)realloc(
            parent->children, 
            parent->capacity * sizeof(parse_tree_node*)
        );
        
        if (new_children == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed for children array\n");
            exit(1);
        }
        
        parent->children = new_children;
    }
    
    parent->children[parent->num_children] = child;
    parent->num_children++;
}

/**
 * Helper function to print tree with indentation
 */
void print_tree_helper(parse_tree_node* node, int depth) {
    if (node == NULL) {
        return;
    }
    
    /* Print indentation */
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    /* Print node value */
    printf("%s\n", node->value);
    
    /* Recursively print children */
    for (int i = 0; i < node->num_children; i++) {
        print_tree_helper(node->children[i], depth + 1);
    }
}

/**
 * Prints the parse tree in a hierarchical format
 */
void print_tree(parse_tree_node* node) {
    printf("\n=== Parse Tree ===\n");
    print_tree_helper(node, 0);
    printf("==================\n\n");
}

/**
 * Frees all memory associated with the parse tree
 */
void free_tree(parse_tree_node* node) {
    if (node == NULL) {
        return;
    }
    
    /* Recursively free all children */
    for (int i = 0; i < node->num_children; i++) {
        free_tree(node->children[i]);
    }
    
    /* Free the children array */
    free(node->children);
    
    /* Free the value string */
    free(node->value);
    
    /* Free the node itself */
    free(node);
}

/**
 * Gets the number of children for a node
 */
int get_num_children(parse_tree_node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->num_children;
}

/**
 * Gets a specific child node
 */
parse_tree_node* get_child(parse_tree_node* node, int index) {
    if (node == NULL || index < 0 || index >= node->num_children) {
        return NULL;
    }
    return node->children[index];
}