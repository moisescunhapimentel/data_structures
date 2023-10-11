#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

void check_null_list(TList *list)
{
    if (list == NULL)
    {
        fprintf(stderr, "*list is not null\n");
        assert(list != NULL);
    }
}

void clear(TList *list)
{
    check_null_list(list);

    if (list->first == 0)
        return;

    TNode *node = list->first, *aux;

    do
    {
        aux = node;
        node = node->next;
        free(aux);

    } while (node != NULL);

    initial_values(list);
}

TList *copy(TList *list)
{
    check_null_list(list);

    TList *copy_list = create_list();

    if (list->first == NULL)
        return copy_list;

    TNode *node = list->first;

    while (node != NULL)
    {
        insert_end(copy_list, node->data);
        node = node->next;
    }

    return copy_list;
}

TList *create_list()
{
    TList *list = (TList *)malloc(sizeof(TList));
    initial_values(list);
    return list;
}

TNode *create_node()
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->next = NULL;
    return newNode;
}

int empty(TList *list)
{
    check_null_list(list);

    return size(list) == 0;
}

TNode *get(TList *list, int position)
{
    check_null_list(list);

    if (position < 0 || position >= list->size || list->first == NULL)
    {
        return NULL;
    }

    int c = 0;
    TNode *aux = list->first;

    while (c < position && aux->next != NULL)
    {
        c++;
        aux = aux->next;
    }

    return aux;
}

void initial_values(TList *list)
{
    list->first = NULL;
    list->end = NULL;
    list->size = 0;
}

int insert_at(TList *list, TData data, int position)
{
    check_null_list(list);

    if (position == 0)
    {
        insert_start(list, data);
        return 1;
    }

    if (position == list->size)
    {
        insert_end(list, data);
        return 1;
    }

    if (position < 0 || position > list->size)
    {
        return 0;
    }

    TNode *previous = get(list, position - 1);

    TNode *newNode = create_node();

    newNode->data = data;
    newNode->next = previous->next;
    previous->next = newNode;

    list->size++;

    return 1;
}

void insert_end(TList *list, TData data)
{
    check_null_list(list);

    if (list->end == NULL)
    {
        insert_start(list, data);
        return;
    }

    TNode *newNode = create_node();
    newNode->data = data;

    list->end->next = newNode;
    list->end = newNode;
    list->size++;
}

void insert_start(TList *list, TData data)
{
    check_null_list(list);

    TNode *newNode = create_node();
    newNode->data = data;

    if (list->first == NULL)
    {
        list->first = newNode;
        list->end = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = list->first;
        list->first = newNode;
    }
    list->size++;
}

int remove_at(TList *list, int position)
{
    check_null_list(list);

    if (position < 0 || position >= list->size || list->first == NULL)
    {
        return 0;
    }

    if (position == 0)
    {
        return remove_start(list);
    }

    if (position == list->size - 1)
    {
        return remove_end(list);
    }

    TNode *previous = get(list, position - 1);
    TNode *element = previous->next;

    previous->next = element->next;
    free(element);

    list->size--;

    return 1;
}

int remove_end(TList *list)
{
    check_null_list(list);

    if (list->first == NULL)
    {
        return 0;
    }

    if (list->first->next == NULL)
    {
        return remove_start(list);
    }

    TNode *previous = get(list, list->size - 2);
    free(list->end);
    previous->next = NULL;
    list->end = previous;

    list->size--;

    return 1;
    // return remove_at(list, list->size - 1);
}

int remove_start(TList *list)
{
    check_null_list(list);

    if (list->first == NULL)
    {
        return 0;
    }

    if (list->first->next == NULL)
    {
        free(list->first);
        list->first = NULL;
        list->end = NULL;
    }
    else
    {
        TNode *elemento = list->first;
        list->first = list->first->next;
        free(elemento);
    }

    list->size--;

    return 1;
}

int size(TList *list)
{
    check_null_list(list);

    if (list->first == NULL)
        return 0;

    int count = 0;

    TNode *node = list->first;

    do
    {
        count++;
        node = node->next;
    } while (node != NULL);

    return count;
}
