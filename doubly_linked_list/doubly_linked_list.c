#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "doubly_linked_list.h"

void check_null_list(TList *list)
{
    if (list == NULL)
    {
        fprintf(stderr, "*list is not null\n");
        assert(list != NULL);
    }
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
    newNode->previous = NULL;
    return newNode;
}

int empty(TList *list)
{
    check_null_list(list);

    return size(list) == 0;
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

int insert_start(TList *list, TData data)
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

int insert_at(TList *list, TData data, int position)
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
    newNode->next = oldNode;
    oldNode->previous->next = newNode;
    oldNode->previous = newNode;

    list->size++;
    return 1;
}

int insert_end(TList *list, TData data)
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
        list->first = list->first->next;
        free(list->first->previous);
        list->first->previous = NULL;
    }

    list->size--;

    return 1;
}

int remove_end(TList *list)
{
    if (list->first == NULL)
    {
        return 0;
    }

    if (list->first->next == NULL)
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

    TNode *previous = get(list, position - 1);
    TNode *element = previous->next;

    previous->next = element->next;
    previous->next->previous = previous;

    free(element);
    list->size--;

    return 1;
}

void clear(TList *list)
{
    check_null_list(list);

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

    initial_values(list);
}

void initial_values(TList *list)
{
    list->first = NULL;
    list->end = NULL;
    list->size = 0;
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

        printf("%d", node->data.data);

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
            printf("%d <= ", node->previous->data.data);
        }

        printf("%d", node->data.data);

        if (node->next == NULL)
        {
            printf(" => NULL");
        }
        else
        {
            printf(" => %d", node->next->data.data);
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
