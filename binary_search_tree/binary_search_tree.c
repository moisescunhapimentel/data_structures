#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_search_tree.h"

TNode *create_node()
{
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->left = NULL;
    node->right = NULL;

    return node;
}

TBinarySearchTree *create_binary_search_tree()
{
    TBinarySearchTree *binary_tree = (TBinarySearchTree *)malloc(sizeof(TBinarySearchTree));
    binary_tree->root = NULL;
    return binary_tree;
}

int compare_tdata(TData tdata, TData other)
{
    if (tdata.data > other.data)
    {
        return 1;
    }
    else if (tdata.data == other.data)
    {
        return 0;
    }

    return -1;
}

void em_ordem(TNode *node)
{
    if (node != NULL)
    {
        em_ordem(node->left);
        printf("TDATA %d\n", node->tdata.data);
        em_ordem(node->right);
    }
}

TNode *remove_node(TNode *node)
{
    TNode *n1, *n2;

    if (node->left == NULL)
    {
        n2 = node->right;
        free(node);
        return n2;
    }

    n1 = node;
    n2 = node->left;

    while (n2->right != NULL)
    {
        n1 = n2;
        n2 = n2->right;
    }

    if (n1 != node)
    {
        n1->right = n2->left;
        n2->left = node->left;
    }

    n2->right = node->right;
    free(node);

    return n2;
}

int delete(TBinarySearchTree *binary_search_tree, TData tdata)
{
    if (binary_search_tree->root == NULL)
        return 0;

    TNode *previous;
    TNode *temp = binary_search_tree->root;

    while (temp != NULL)
    {
        if (compare_tdata(tdata, temp->tdata) == 0)
        {
            if (temp == binary_search_tree->root)
            {
                binary_search_tree->root = remove_node(temp);
            }
            else
            {
                if (previous->right == temp)
                {
                    previous->right = remove_node(temp);
                }
                else
                {
                    previous->left = remove_node(temp);
                }
            }   
            return 1;
        }

        previous = temp;
        if (compare_tdata(tdata, temp->tdata) == 1)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return 0;
}

void insert(TBinarySearchTree *binary_search_tree, TData tdata)
{
    TNode *temp = binary_search_tree->root;
    TNode *previous = NULL;

    int compare;

    while (temp != NULL)
    {
        previous = temp;

        compare = compare_tdata(tdata, temp->tdata);

        if (compare == 1)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    TNode *node = create_node();
    node->tdata = tdata;

    if (previous == NULL)
    {
        binary_search_tree->root = node;
    }
    else if (compare_tdata(tdata, previous->tdata) == 1)
    {
        previous->right = node;
    }
    else
    {
        previous->left = node;
    }
}