#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void check_null_stack(TStack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "*stack is not null\n");
        assert(stack != NULL);
    }
}

void clear(TStack *stack)
{
    check_null_stack(stack);

    if (stack->first == 0)
        return;

    TNode *node = stack->first, *aux;

    do
    {
        aux = node;
        node = node->next;
        free(aux);

    } while (node != NULL);

    initial_values(stack);
}

TStack *copy(TStack *stack)
{
    check_null_stack(stack);

    TStack *copy_list = create_stack();

    if (stack->first == NULL)
        return copy_list;

    TNode *node = stack->first;

    while (node != NULL)
    {
        push(copy_list, node->data);
        node = node->next;
    }

    return copy_list;
}

TStack *create_stack()
{
    TStack *stack = (TStack *)malloc(sizeof(TStack));
    initial_values(stack);
    return stack;
}

TNode *create_node()
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->next = NULL;
    return newNode;
}

int empty(TStack *stack)
{
    check_null_stack(stack);

    return size(stack) == 0;
}

void initial_values(TStack *stack)
{
    stack->first = NULL;
    stack->end = NULL;
    stack->size = 0;
}

void push(TStack *stack, TData data)
{
    check_null_stack(stack);

    TNode *newNode = create_node();
    newNode->data = data;

    if (stack->end == NULL)
    {
        stack->first = newNode;
    }
    else
    {
        stack->end->next = newNode;
    }

    stack->end = newNode;
    stack->size++;
}

int pop(TStack *stack)
{
    check_null_stack(stack);

    if (stack->first == NULL)
    {
        return 0;
    }

    if (stack->first->next == NULL)
    {
        free(stack->first);
        stack->first = NULL;
        stack->end = NULL;
    }
    else
    {
        int c = 0;
        TNode *previous = stack->first;

        while (c < stack->size - 2 && previous->next != NULL)
        {
            c++;
            previous = previous->next;
        }

        free(stack->end);
        previous->next = NULL;
        stack->end = previous;
    }

    stack->size--;

    return 1;
}

int size(TStack *stack)
{
    check_null_stack(stack);

    if (stack->first == NULL)
        return 0;

    int count = 0;

    TNode *node = stack->first;

    do
    {
        count++;
        node = node->next;
    } while (node != NULL);

    return count;
}

TData *top(TStack *stack)
{
    check_null_stack(stack);

    if (stack->end == NULL)
    {
        return NULL;
    }

    return &stack->end->data;
}