#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include "../array_list.h"

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

    delete_list(array_list);
}

void testAdd()
{
    TArrayList *array_list = create_array_list(0);

    TData data;

    for (int i = 0; i < 10; i++)
    {
        add(array_list, (TData){(i + 1) * 10});
    }

    for (int i = 0; i < 10; i++)
    {
        CU_ASSERT_EQUAL(array_list->array[i]->data, (i + 1) * 10);
    }

    clear(array_list);

    for (size_t i = 0; i < 10000; i++)
    {
        add(array_list, (TData){0});
    }

    CU_ASSERT_EQUAL(array_list->size, 10000);

    delete_list(array_list);
}

void testInsertAt()
{
    TArrayList *array_list = create_array_list(0);

    add(array_list, (TData){20});
    add(array_list, (TData){30});
    insert_at(array_list, (TData){0}, 0);

    CU_ASSERT_EQUAL(array_list->array[0]->data, 0);
    CU_ASSERT_EQUAL(array_list->array[1]->data, 20);
    CU_ASSERT_EQUAL(array_list->array[2]->data, 30);

    delete_list(array_list);
}

void testRemoveAt()
{
    TArrayList *array_list = create_array_list(0);

    for (int i = 0; i < 5; i++)
    {
        TData *tData = create_tdata();
        tData->data = (i + 1) * 10;
        add(array_list, (TData){(i + 1) * 10});
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

    delete_list(array_list);
}

void testRemoveAll()
{
    TArrayList *array_list = create_array_list(0);

    add(array_list, (TData){10});
    add(array_list, (TData){20});
    add(array_list, (TData){20});
    add(array_list, (TData){30});
    add(array_list, (TData){20});

    remove_all(array_list, (TData){20});

    CU_ASSERT_EQUAL(array_list->array[0]->data, 10);
    CU_ASSERT_EQUAL(array_list->array[1]->data, 30);

    CU_ASSERT_PTR_EQUAL(array_list->array[2], NULL);
    CU_ASSERT_PTR_EQUAL(array_list->array[3], NULL);

    CU_ASSERT_EQUAL(array_list->size, 2);

    delete_list(array_list);
}

void testClear()
{
    TArrayList *array_list = create_array_list(0);

    for (int i = 0; i < 10000; i++)
    {
        add(array_list, (TData){0});
    }

    CU_ASSERT_EQUAL(array_list->size, 10000);

    int MAX = array_list->MAX;

    clear(array_list);

    CU_ASSERT_EQUAL(array_list->size, 0);
    CU_ASSERT_EQUAL(array_list->MAX, MAX);

    delete_list(array_list);
}

void testSet()
{
    TArrayList *array_list = create_array_list(3);

    for (int i = 0; i < array_list->MAX; i++)
    {
        add(array_list, (TData){(i + 1) * 10});
    }

    set(array_list, (TData){-1}, 1);

    CU_ASSERT_EQUAL(array_list->array[0]->data, 10);
    CU_ASSERT_EQUAL(array_list->array[1]->data, -1);
    CU_ASSERT_EQUAL(array_list->array[2]->data, 30);

    delete_list(array_list);
}

void testGet()
{
    TArrayList *array_list = create_array_list(0);

    for (int i = 0; i < 10; i++)
    {
        add(array_list, (TData){(i + 1) * 10});
    }

    for (int i = 0; i < 10; i++)
    {
        equals_tdata(*array_list->array[i], get(array_list, i));
    }

    delete_list(array_list);
}

void testEmpty()
{
    TArrayList *array_list = create_array_list(0);

    CU_ASSERT(empty(array_list));

    for (int i = 0; i < 10000; i++)
    {
        add(array_list, (TData){0});
    }

    CU_ASSERT_FALSE(empty(array_list));

    clear(array_list);

    CU_ASSERT(empty(array_list));

    delete_list(array_list);
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
    CU_add_test(suite, "Set Test", testSet);
    CU_add_test(suite, "Get Test", testGet);
    CU_add_test(suite, "Empty Test", testEmpty);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}