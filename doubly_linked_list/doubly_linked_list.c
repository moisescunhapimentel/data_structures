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

TNode *create_no()
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void add_all(TList *list, TList *list2){
    TNode *node = list2->first;

    while(node != NULL){
        insert_end(list, node);
        node = node->next;
    }
}

void insert_start(TList *list, void *data)
{
    TNode *newNode = create_no();

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
}

void insert_at(TList *list, void *data, int position)
{
    if (position < 0 || position > list->size)
    {
        printf("Invalid Position! (%d)\n", position);
        return;
    }

    if (position == 0)
    {
        insert_start(list, data);
    }
    else if (position == list->size)
    {
        insert_end(list, data);
    }
    else
    {
        TNode *oldNode = get(list, position);
        TNode *newNode = create_no();
        newNode->data = data;

        newNode->previous = oldNode->previous;
        oldNode->previous->next = newNode;
        oldNode->previous = newNode;
        newNode->next = oldNode;
    }
}

void insert_end(TList *list, void *data)
{
    if (list->end == NULL)
    {
        insert_start(list, data);
        return;
    }
    TNode *newNode = create_no();
    newNode->data = data;

    list->end->next = newNode;
    newNode->previous = list->end;
    list->end = newNode;
    list->size++;
}

void remove_start(TList *list)
{
    if (list->first != NULL)
    {
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
    }
}

void remove_end(TList *list)
{
    if (list->end != NULL)
    {
        if (list->end == list->first)
        {
            free(list->end);
            list->first = NULL;
            list->end = NULL;
        }
        else
        {
            list->end = list->end->previous;
            free(list->end->next);
            list->first->next = NULL;
        }
        list->size--;
    }
}

void remover_at(TList *list, int position)
{
    if (position < 0 || position >= list->size)
    {
        printf("Invalid Position!");
        return;
    }

    if (list->end != NULL)
    {
        if (position == 0)
        {
            remove_start(list);
            return;
        }

        int c = 0;

        for (TNode *no = list->first; no != NULL; no = no->next)
        {

            if (c + 1 == position)
            {
                TNode *next = no->next->next;
                no->next = next;
                break;
            }

            c++;
        }

        list->size--;
    }
}

void clear(TList *list)
{
    puts("Clear");
    while (list->size > 0)
    {
        remove_start(list);
    }
}

void print(TList *list)
{
    if (list->size == 0)
    {
        return;
    }

    if (list->first != NULL && list->first->previous == NULL)
        printf("NULL");

    TNode *no = list->first;

    while (no != NULL)
    {
        if (list->first == no)
        {
            printf(" <= ");
        }
        else
        {
            printf("=> ");
        }

        printf("%d", *(type *)(no->data));

        if (list->end == no)
        {
            printf(" => ");
        }
        else
        {
            printf(" <=");
        }
        no = no->next;
    }

    if (list->end->next == NULL)
        printf("NULL");

    putchar('\n');
}

void print_previous_next(TList *list)
{
    for (TNode *no = list->first; no != NULL; no = no->next)
    {
        if (no->previous == NULL)
        {
            printf("NULL <= ");
        }
        else
        {
            printf("%d <= ", *(type *)(no->previous->data));
        }

        printf("%d", *(type *)(no->data));

        if (no->next == NULL)
        {
            printf(" => NULL");
        }
        else
        {
            printf(" => %d", *(type *)(no->next->data));
        }

        putchar('\n');
    }
}

TNode *get(TList *list, int position)
{
    if (list->size == 0 || position < 0 || position >= list->size)
    {
        return NULL;
    }

    TNode *no;
    int c;

    if (position >= list->size / 2)
    {
        no = list->end;
        c = list->size - 1;

        while (c >= 0)
        {
            if (c == position)
            {
                return no;
            }

            c--;
            no = no->previous;
        }
    }
    else
    {
        no = list->first;
        c = 0;

        while (c < list->size)
        {
            if (c == position)
            {
                return no;
            }

            c++;
            no = no->next;
        }
    }

    printf("Erro!");
    return NULL;
}
