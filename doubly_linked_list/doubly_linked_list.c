#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

TList *create_list()
{
    TList *list = (TList *)malloc(sizeof(TList));
    list->first = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

TNode *create_node()
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void add_all(TList *list, TList *list2)
{
    TNode *node = list2->first;

    while (node != NULL)
    {
        insert_end(list, node->data);
        node = node->next;
    }
}

TList *reversed(TList *list)
{
    TList *reversed_list = create_list();

    TNode *node = list->end;

    while (node != NULL)
    {
        insert_end(reversed_list, node->data);
        node = node->previous;
    }

    return reversed_list;
}

int insert_start(TList *list, type *data)
{
    TNode *newNode = create_node();
    newNode->data = data;

    if (list->first == NULL)
    {
        list->end = newNode;
    }
    else
    {
        newNode->next = list->first;
        list->first->previous = newNode;
    }

    list->first = newNode;
    list->size++;

    return 1;
}

int insert_at(TList *list, type *data, int position)
{
    if (position < 0 || position > list->size)
    {
        return 0;
    }

    if (position == 0)
    {
        return insert_start(list, data);
    }
    if (position == list->size)
    {
        return insert_end(list, data);
    }

    TNode *oldNode = get(list, position);
    TNode *newNode = create_node();
    newNode->data = data;

    newNode->previous = oldNode->previous;
    oldNode->previous->next = newNode;
    oldNode->previous = newNode;
    newNode->next = oldNode;

    list->size++;
    return 1;
}

int insert_end(TList *list, type *data)
{
    if (list->end == NULL)
    {
        return insert_start(list, data);
    }

    TNode *newNode = create_node();
    newNode->data = data;

    list->end->next = newNode;
    newNode->previous = list->end;
    list->end = newNode;

    list->size++;

    return 1;
}

int remove_start(TList *list)
{
    if (list->first != NULL)
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
        list->first = list->first->next;
        free(list->first->previous);
        list->first->previous = NULL;
    }

    list->size--;

    return 1;
}

int remove_end(TList *list)
{
    if (list->end == NULL)
    {
        return 0;
    }

    if (list->end == list->first)
    {
        return remove_start(list);
    }

    list->end = list->end->previous;
    free(list->end->next);
    list->end->next = NULL;
    list->size--;

    return 1;
}

int remove_at(TList *list, int position)
{
    if (position < 0 || position >= list->size)
    {
        return 0;
    }

    if (position == 0)
        return remove_start(list);
    if (position == list->size - 1)
        return remove_end(list);

    TNode *element = get(list, position);
    TNode *previous = element->previous;

    previous->next = element->next;
    previous->next->previous = previous;

    free(element);
    list->size--;

    return 1;
}

void clear(TList *list)
{
    if (list->first == NULL)
        return;

    TNode *node = list->first;
    TNode *aux;

    do
    {
        aux = node;
        node = node->next;
        free(aux);
        aux = NULL;

    } while (node != NULL);

    free(list);
    create_list(list);
}

void print(TList *list)
{
    if (list->size == 0)
    {
        return;
    }

    if (list->first != NULL && list->first->previous == NULL)
        printf("NULL");

    TNode *node = list->first;

    while (node != NULL)
    {
        if (list->first == node)
        {
            printf(" <= ");
        }
        else
        {
            printf("=> ");
        }

        printf("%d", *(type *)(node->data));

        if (list->end == node)
        {
            printf(" => ");
        }
        else
        {
            printf(" <=");
        }
        node = node->next;
    }

    if (list->end->next == NULL)
        printf("NULL");

    putchar('\n');
}

void print_previous_next(TList *list)
{
    for (TNode *node = list->first; node != NULL; node = node->next)
    {
        if (node->previous == NULL)
        {
            printf("NULL <= ");
        }
        else
        {
            printf("%d <= ", *(type *)(node->previous->data));
        }

        printf("%d", *(type *)(node->data));

        if (node->next == NULL)
        {
            printf(" => NULL");
        }
        else
        {
            printf(" => %d", *(type *)(node->next->data));
        }

        putchar('\n');
    }
}

TNode *get(TList *list, int position)
{
    if (list->first == NULL || position < 0 || position >= list->size)
    {
        return NULL;
    }

    TNode *node;
    int c;

    if (position >= list->size / 2)
    {
        node = list->end;
        c = list->size - 1;

        while (c > 0 && c != position && node != NULL)
        {
            c--;
            node = node->previous;
        }
    }
    else
    {
        node = list->first;
        c = 0;

        while (c < list->size - 1 && c != position && node != NULL)
        {
            c++;
            node = node->next;
        }
    }

    return node;
}
