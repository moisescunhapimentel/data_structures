#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

TData *back(TQueue *queue)
{
    check_null_queue(queue);

    if (queue->end == NULL)
        return NULL;

    return &queue->end->data;
}

void check_null_queue(TQueue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "*queue is not null\n");
        assert(queue != NULL);
    }
}

void clear(TQueue *queue)
{
    check_null_queue(queue);

    if (queue->first == 0)
        return;

    TNode *node = queue->first, *aux;

    do
    {
        aux = node;
        node = node->next;
        free(aux);

    } while (node != NULL);

    initial_values(queue);
}

TQueue *copy(TQueue *queue)
{
    check_null_queue(queue);

    TQueue *copy_list = create_queue();

    if (queue->first == NULL)
        return copy_list;

    TNode *node = queue->first;

    while (node != NULL)
    {
        push(copy_list, node->data);
        node = node->next;
    }

    return copy_list;
}

TQueue *create_queue()
{
    TQueue *queue = (TQueue *)malloc(sizeof(TQueue));
    initial_values(queue);
    return queue;
}

TNode *create_node()
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->next = NULL;
    return newNode;
}

int empty(TQueue *queue)
{
    check_null_queue(queue);

    return size(queue) == 0;
}

TData *front(TQueue *queue)
{
    check_null_queue(queue);

    if (queue->first == NULL)
        return NULL;

    return &queue->first->data;
}

void initial_values(TQueue *queue)
{
    queue->first = NULL;
    queue->end = NULL;
    queue->size = 0;
}

void push(TQueue *queue, TData data)
{
    check_null_queue(queue);

    TNode *newNode = create_node();
    newNode->data = data;

    if (queue->end == NULL)
    {
        queue->first = newNode;
    }
    else
    {
        queue->end->next = newNode;
    }

    queue->end = newNode;
    queue->size++;
}

TData pop(TQueue *queue)
{
    check_null_queue(queue);

    TData data;

    if (queue->first == NULL)
    {
        return data;
    }

    if (queue->first->next == NULL)
    {
        data = queue->first->data;
        free(queue->first);
        queue->first = NULL;
        queue->end = NULL;
    }
    else
    {
        TNode *elemento = queue->first;
        queue->first = queue->first->next;
        data = elemento->data;
        free(elemento);
    }

    queue->size--;

    return data;
}

int size(TQueue *queue)
{
    check_null_queue(queue);

    if (queue->first == NULL)
        return 0;

    int count = 0;

    TNode *node = queue->first;

    do
    {
        count++;
        node = node->next;
    } while (node != NULL);

    return count;
}
