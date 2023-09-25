#include <stdio.h>
#include <stdlib.h>

#include "circular_linked_list.h"

TList *create_list()
{
    TList *list = (TList *)malloc(sizeof(TList));
    list->HEAD = NULL;
    list->size = 0;

    return list;
}

TNode *create_node()
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->next = NULL;
    return newNode;
}

void add_all(TList *list, TList *lista2)
{
    TNode *node = lista2->HEAD;
    do
    {
        insert_end(list, node->data);
        node = node->next;
    } while (node != lista2->HEAD);
}

void insert_start(TList *list, type *data)
{
    TNode *newNode = create_node();
    newNode->data = data;

    if (list->HEAD == NULL)
    {
        list->HEAD = newNode;
        newNode->next = newNode;
    }
    else
    {
        TNode *ultimo = last(list);

        ultimo->next = newNode;
        newNode->next = list->HEAD;
        list->HEAD = newNode;
    }

    list->size++;
}

int insert_at(TList *list, type *data, int position)
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

void insert_end(TList *list, type *data)
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

int remove_start(TList *list)
{

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

int remove_at(TList *list, int position)
{
    if (list->HEAD == NULL || position < 0 || position >= list->size)
    {
        return 0;
    }

    if (list->HEAD->next == list->HEAD || position == 0)
    {
        return remove_start(list);
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
    return remove_at(list, list->size - 1);
}

void clear(TList *list)
{
    TNode *node = list->HEAD;
    TNode *aux;

    do
    {
        aux = node;
        node = node->next;
        free(aux);
        aux = NULL;
    } while (node != list->HEAD);

    free(list);
    create_list(list);
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