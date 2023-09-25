#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

TList *create_list()
{
    TList *list = (TList *)malloc(sizeof(TList));
    list->first = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

TNode *create_no()
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->next = NULL;
    return newNode;
}

void insert_start(TList *list, type *data)
{
    TNode *newNode = create_no();
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

int insert_at(TList *list, type *data, int position)
{
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

    TNode *newNode = create_no();

    newNode->data = data;
    newNode->next = previous->next;
    previous->next = newNode;

    list->size++;

    return 1;
}

void insert_end(TList *list, type *data)
{
    if (list->end == NULL)
    {
        insert_start(list, data);
        return;
    }

    TNode *newNode = create_no();
    newNode->data = data;
    newNode->next = NULL;

    list->end->next = newNode;
    list->end = newNode;
    list->size++;
}

int remove_start(TList *list)
{
    if (list->first != NULL)
    {
        TNode *elemento = list->first;
        list->first = list->first->next;
        free(elemento);

        list->size--;

        return 1;
    }

    return 0;
}

int remove_at(TList *list, int position)
{
    if (position < 0 || position >= list->size || list->first == NULL)
    {
        return 0;
    }

    if (position == 0)
    {
        return remove_start(list);
    }

    TNode *previous = get(list, position - 1);
    TNode *element = previous->next;

    if (element == list->end)
    {
        list->end = previous;
    }

    previous->next = element->next;
    free(element);

    list->size--;

    return 1;
}

int remove_end(TList *list)
{
    return remove_at(list, list->size - 1);
}

void clear(TList *list)
{
    TNode *node = list->first, *aux;

    do
    {
        aux = node;
        node = node->next;
        free(aux);

    } while (node != NULL);

    free(list);
    create_list(list);
}

TNode *get(TList *list, int position)
{
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