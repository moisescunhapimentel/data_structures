#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "array_list.h"

int add(TArrayList *array_list, TData data)
{
    check_null_array_list(array_list);

    if (array_list->MAX == array_list->size)
    {
        realloc_array_list(array_list, (int)ceil(array_list->size * 1.5));
    }

    TData *p_tdata = create_tdata();
    *p_tdata = data;

    array_list->array[array_list->size] = p_tdata;
    array_list->size++;

    return 1;
}

TData *copy_tdata(TData *tData)
{
    TData *p_copy_tdata = create_tdata();
    *p_copy_tdata = *tData;

    return p_copy_tdata;
}

void clear(TArrayList *array_list)
{
    check_null_array_list(array_list);

    for (int i = 0; i < array_list->size; i++)
    {
        free(array_list->array[i]);
        array_list->array[i] = NULL;
    }

    initial_values(array_list);
}

TData *create_tdata()
{
    TData *tData = (TData *)malloc(sizeof(TData));
    return tData;
}
void check_length(int length)
{
    if (length < 0)
    {
        fprintf(stderr, "[length] cannot be negative\n");
        assert(length >= 0);
    }
}

void check_null_array_list(TArrayList *array_list)
{
    if (array_list == NULL)
    {
        fprintf(stderr, "[array_list] is not null\n");
        assert(array_list != NULL);
    }

    if (array_list->array == NULL)
    {
        fprintf(stderr, "[array_list->array] is not null\n");
        assert(array_list->array != NULL);
    }
}

void check_index_range(TArrayList *array_list, int index)
{
    if (index < 0 || index >= array_list->size)
    {
        fprintf(stderr, "index out of range [%d-%d)\n", 0, array_list->size);
        assert(index >= 0 && index < array_list->size);
    }
}

TArrayList *create_array_list(int length)
{
    TArrayList *array_list = (TArrayList *)malloc(sizeof(TArrayList));

    malloc_array_list(array_list, length);

    initial_values(array_list);

    return array_list;
}

void delete_list(TArrayList *array_list)
{
    check_null_array_list(array_list);

    for (int i = 0; i < array_list->size; i++)
    {
        free(array_list->array[i]);
    }

    free(array_list->array);
    free(array_list);
}

int equals_tdata(TData data, TData other)
{
    return data.data == other.data;
}

int empty(TArrayList *array_list)
{
    return array_list->size == 0;
}

TData get(TArrayList *array_list, int position)
{
    check_null_array_list(array_list);
    check_index_range(array_list, position);

    return *array_list->array[position];
}

void initial_values(TArrayList *array_list)
{
    array_list->size = 0;
}

int insert_at(TArrayList *array_list, TData data, int position)
{
    check_null_array_list(array_list);

    if (position < 0 || position > array_list->size)
    {
        fprintf(stderr, "index out of range [%d-%d]\n", 0, array_list->size);
        assert(position < 0 || position > array_list->size);
    }

    if (position == array_list->size)
    {
        return add(array_list, data);
    }

    if (array_list->MAX == array_list->size)
    {
        realloc_array_list(array_list, (int)ceil(array_list->size * 1.5));
    }

    int i = array_list->size;

    while (i > position)
    {
        array_list->array[i] = array_list->array[i - 1];
        i--;
    }

    TData *p_tdata = create_tdata();
    *p_tdata = data;

    array_list->array[position] = p_tdata;

    array_list->size++;

    return 1;
}

void malloc_array_list(TArrayList *array_list, int length)
{
    check_length(length);

    if (length == 0)
    {
        length = 1;
    }

    array_list->array = (TData **)malloc(length * sizeof(TData *));
    array_list->MAX = length;

    check_null_array_list(array_list);
}

void realloc_array_list(TArrayList *array_list, int length)
{
    check_null_array_list(array_list);
    check_length(length);

    if (length == 0)
    {
        length = 1;
    }

    array_list->array = (TData **)realloc(array_list->array, length * sizeof(TData *));
    array_list->MAX = length;

    check_null_array_list(array_list);
}

void remove_at(TArrayList *array_list, int position)
{
    check_null_array_list(array_list);

    check_index_range(array_list, position);

    if (array_list->size == 1)
    {
        free(array_list->array[0]);
        array_list->array[0] = NULL;
    }
    else
    {

        for (int i = position; i < array_list->size - 1; i++)
        {
            *array_list->array[i] = *array_list->array[i + 1];
        }

        free(array_list->array[array_list->size - 1]);
        array_list->array[array_list->size - 1] = NULL;
    }

    array_list->size--;
}

void remove_all(TArrayList *array_list, TData data)
{
    check_null_array_list(array_list);

    int jump = 0;

    for (int i = 0; i < array_list->size; i++)
    {
        if (array_list->array[i]->data == data.data)
        {
            jump++;
            continue;
        }

        if (jump != 0)
        {
            *(array_list->array[i - jump]) = *(array_list->array[i]);
        }
    }

    for (int i = array_list->size - 1; i >= array_list->size - jump; i--)
    {
        free(array_list->array[i]);
        array_list->array[i] = NULL;
    }

    array_list->size -= jump;
}

void set(TArrayList *array_list, TData data, int position)
{
    check_null_array_list(array_list);
    check_index_range(array_list, position);

    *array_list->array[position] = data;
}