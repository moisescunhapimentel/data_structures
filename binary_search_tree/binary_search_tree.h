#include <stdio.h>

typedef struct
{
    int data;
} TData;

typedef struct Node
{
    TData tdata;
    struct Node *left;
    struct Node *right;
} TNode;

typedef struct
{
    TNode *root;
} TBinarySearchTree;

TNode *create_node();

void em_ordem(TNode *node);

int compare_tdata(TData tdata, TData other);

void insert(TBinarySearchTree *binary_search_tree, TData tdata);

TBinarySearchTree *create_binary_search_tree();

int delete(TBinarySearchTree *binary_search_tree, TData tdata);

TNode *remove_node(TNode *node);