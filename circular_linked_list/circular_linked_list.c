#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "circular_linked_list.h"

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

    TNode *previous = get(list, position - 1);

    TNode *novo = create_node();
    novo->data = data;

    novo->next = previous->next;
    previous->next = novo;

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
    last_element->next = novoNo;

    list->size++;
}

void insert_start(TList *list, TData data)
{
    TNode *newNode = create_node();
    newNode->data = data;

    if (list->HEAD == NULL)
    {
        newNode->next = newNode;
    }
    else
    {
        TNode *ultimo = last(list);
        newNode->next = list->HEAD;
        ultimo->next = newNode;
    }

    list->HEAD = newNode;
    list->size++;
}

TNode *last(TList *list)
{
    if (list->HEAD == NULL)
        return NULL;

    TNode *last_element = list->HEAD;

    while (last_element->next != list->HEAD)
    {
        last_element = last_element->next;
    }

    return last_element;
}

int remove_at(TList *list, int position)
{
    check_null_list(list);

    if (list->HEAD == NULL || position < 0 || position >= list->size)
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

    if (list->HEAD == NULL)
    {
        return 0;
    }

    if (list->HEAD->next == list->HEAD)
    {
        return remove_start(list);
    }

    TNode *previous = get(list, list->size - 2);
    free(previous->next);
    previous->next = list->HEAD;

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
