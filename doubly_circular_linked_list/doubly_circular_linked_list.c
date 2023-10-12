#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "doubly_circular_linked_list.h"

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

    if (list->HEAD == NULL)
        return;

    TNode *node = list->HEAD;
    TNode *aux;

    do
    {
        aux = node;
        node = node->next;
        free(aux);
        aux = NULL;
    } while (node != list->HEAD);

    initial_values(list);
}

TList *copy(TList *list)
{
    check_null_list(list);

    TList *copy_list = create_list();

    if (list->HEAD == NULL)
        return copy_list;

    TNode *node = list->HEAD;

    do
    {
        insert_end(copy_list, node->data);
        node = node->next;
    } while (node != list->HEAD);

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
    newNode->previous = NULL;
    return newNode;
}

int empty(TList *list)
{
    check_null_list(list);

    return size(list) == 0;
}

TNode *get(TList *list, int position)
{
    if (position < 0 || position >= list->size || list->HEAD == NULL)
    {
        return NULL;
    }

    int c = 0;
    TNode *aux = list->HEAD;

    while (c < position && aux->next != list->HEAD)
    {
        c++;
        aux = aux->next;
    }

    return aux;
}

void initial_values(TList *list)
{
    list->HEAD = NULL;
    list->size = 0;
}

int insert_at(TList *list, TData data, int position)
{
    if (position < 0 || position > list->size)
    {
        return 0;
    }

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

    TNode *element = get(list, position);

    TNode *novo = create_node();
    novo->data = data;

    novo->next = element;
    novo->previous = element->previous;

    element->previous->next = novo;
    element->previous = novo;

    list->size++;
}

void insert_end(TList *list, TData data)
{
    if (list->HEAD == NULL)
    {
        insert_start(list, data);
        return;
    }

    TNode *novoNo = create_node();
    novoNo->data = data;

    TNode *last_element = last(list);

    novoNo->next = list->HEAD;
    list->HEAD->previous = novoNo;

    last_element->next = novoNo;
    novoNo->previous = last_element;

    list->size++;
}

void insert_start(TList *list, TData data)
{
    TNode *newNode = create_node();
    newNode->data = data;

    if (list->HEAD == NULL)
    {
        newNode->next = newNode;
        newNode->previous = newNode;
    }
    else
    {
        TNode *last_element = list->HEAD->previous;

        last_element->next = newNode;
        newNode->previous = last_element;
        newNode->next = list->HEAD;
        list->HEAD->previous = newNode;
    }
    list->HEAD = newNode;

    list->size++;
}

TNode *last(TList *list)
{
    if (list->HEAD == NULL)
        return NULL;

    return list->HEAD->previous;
}

int remove_at(TList *list, int position)
{
    if (list->HEAD == NULL || position < 0 || position >= list->size)
    {
        return 0;
    }

    if (list->HEAD->next == list->HEAD)
    {
        free(list->HEAD);
        list->HEAD = NULL;
        return 1;
    }

    if (position == list->size - 1)
    {
        remove_end(list);
    }

    TNode *element = get(list, position);

    element->previous->next = element->next;
    element->next->previous = element->previous;

    free(element);

    list->size--;
    return 1;
}

int remove_end(TList *list)
{
    check_null_list(list);

    if (list->HEAD == NULL)
    {
        return 0;
    }

    if (list->HEAD->next == list->HEAD)
    {
        return remove_start(list);
    }

    TNode *last_element = last(list);

    list->HEAD->previous = last_element->previous;
    last_element->previous->next = list->HEAD;

    free(last_element);

    list->size--;

    return 1;
}

int remove_start(TList *list)
{
    check_null_list(list);

    if (list->HEAD == NULL)
    {
        return 0;
    }

    if (list->HEAD->next == list->HEAD)
    {
        free(list->HEAD);
        list->HEAD = NULL;
    }
    else
    {
        TNode *last_element = last(list);

        last_element->next = list->HEAD->next;
        list->HEAD->next->previous = last_element;

        free(list->HEAD);
        list->HEAD = last_element->next;
    }

    list->size--;
    return 1;
}

int size(TList *list)
{
    check_null_list(list);

    int count = 0;

    if (list->HEAD == NULL)
        return count;

    TNode *node = list->HEAD;

    do
    {
        count++;
        node = node->next;
    } while (node != list->HEAD);

    return count;
}