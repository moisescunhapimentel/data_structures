#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include "../array_list.h"

void clean_list(TArrayList *array_list)
{
    // clear(array_list);
    // free(array_list);
}

void print(TArrayList *array_list)
{
    check_null_array_list(array_list);

    if (array_list->size == 0)
    {
        puts("[]");
        return;
    }

    putchar('[');
    printf("%d", array_list->array[0]->data);

    for (int i = 1; i < array_list->size; i++)
    {
        printf(", %d", array_list->array[i]->data);
    }

    putchar(']');
}

void testCreateArrayList()
{
    TArrayList *array_list = create_array_list(0);

    CU_ASSERT_PTR_NOT_EQUAL(array_list, NULL);
    CU_ASSERT_EQUAL(array_list->size, 0);
    CU_ASSERT_EQUAL(array_list->MAX, 1);

    clean_list(array_list);
}

void testAdd()
{
    TArrayList *array_list = create_array_list(0);

    TData data;

    for (int i = 0; i < 10; i++)
    {
        TData *data = create_tdata();
        data->data = (i + 1) * 10;
        add(array_list, data);
    }

    for (int i = 0; i < 10; i++)
    {
        CU_ASSERT_EQUAL(array_list->array[i]->data, (i + 1) * 10);
    }

    clean_list(array_list);
}

void testInsertAt()
{
    TArrayList *array_list = create_array_list(0);

    TData *data = create_tdata();

    data->data = 20;

    add(array_list, data);

    data->data = 30;

    add(array_list, data);

    data->data = 0;

    insert_at(array_list, data, 0);

    clean_list(array_list);
}

void testRemoveAt()
{
    TArrayList *array_list = create_array_list(0);

    for (int i = 0; i < 5; i++)
    {
        TData *tData = create_tdata();
        tData->data = (i + 1) * 10;
        add(array_list, tData);
    }

    remove_at(array_list, 3);

    CU_ASSERT_EQUAL(array_list->array[0]->data, 10);
    CU_ASSERT_EQUAL(array_list->array[1]->data, 20);
    CU_ASSERT_EQUAL(array_list->array[2]->data, 30);
    CU_ASSERT_EQUAL(array_list->array[3]->data, 50);

    remove_at(array_list, 0);

    CU_ASSERT_EQUAL(array_list->array[0]->data, 20);
    CU_ASSERT_EQUAL(array_list->array[1]->data, 30);
    CU_ASSERT_EQUAL(array_list->array[2]->data, 50);

    remove_at(array_list, 1);
    remove_at(array_list, 1);

    CU_ASSERT_EQUAL(array_list->array[0]->data, 20);
    CU_ASSERT_EQUAL(array_list->size, 1);
}

void testRemoveAll()
{
    TArrayList *array_list = create_array_list(0);

    TData *tData = create_tdata();
    tData->data = 10;
    add(array_list, tData);

    tData = create_tdata();
    tData->data = 20;
    add(array_list, tData);

    tData = create_tdata();
    tData->data = 20;
    add(array_list, tData);

    tData = create_tdata();
    tData->data = 30;
    add(array_list, tData);

    tData = create_tdata();
    tData->data = 20;
    add(array_list, tData);

    remove_all(array_list, (TData){20});

    CU_ASSERT_EQUAL(array_list->array[0]->data, 10);
    CU_ASSERT_EQUAL(array_list->array[1]->data, 30);

    CU_ASSERT_PTR_EQUAL(array_list->array[2], NULL);
    CU_ASSERT_PTR_EQUAL(array_list->array[3], NULL);

    CU_ASSERT_EQUAL(array_list->size, 2);
}

void testClear()
{
    TArrayList *array_list = create_array_list(0);

    for (int i = 0; i < 10000; i++)
    {
        TData *tData = create_tdata();
        tData->data = 10;
        add(array_list, tData);
    }

    CU_ASSERT_EQUAL(array_list->size, 10000);

    int MAX = array_list->MAX;

    clear(array_list);

    CU_ASSERT_EQUAL(array_list->size, 0);
    CU_ASSERT_EQUAL(array_list->MAX, MAX);
}
int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite de Teste", NULL, NULL);
    CU_add_test(suite, "Create Array List Test", testCreateArrayList);
    CU_add_test(suite, "Add Test", testAdd);
    CU_add_test(suite, "Insert At Test", testInsertAt);
    CU_add_test(suite, "Remove At Test", testRemoveAt);
    CU_add_test(suite, "Remove All Test", testRemoveAll);

    CU_add_test(suite, "Clear Test", testClear);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}