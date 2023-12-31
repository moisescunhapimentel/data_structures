#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>

#include "../doubly_linked_list.h"

void clean_list(TList *list)
{
    clear(list);
    free(list);
}

int insert_element(TList *list, int length)
{
    TData data = {0};

    for (int i = 0; i < length; i++)
    {
        insert_end(list, data);
    }
}

int remove_element(TList *list, int length)
{
    for (int i = 0; i < length; i++)
    {
        remove_end(list);
    }
}

int insert_elements(int length)
{
    TList *list = create_list();

    insert_element(list, length);

    int size_list = size(list);

    clean_list(list);

    return size_list;
}

int remove_elements(int length)
{
    TList *list = create_list();

    insert_element(list, length);

    remove_element(list, length);

    int size_list = size(list);

    clean_list(list);

    return size_list;
}

void testPreviousNext(TList *list)
{
    int size_list = size(list);

    TNode *node = list->first;
    int i = 0;

    while (node != NULL)
    {
        CU_ASSERT_PTR_EQUAL(get(list, i), node);
        node = node->next;
        i++;
    }

    node = list->end;
    i = size_list - 1;

    while (node != NULL)
    {
        CU_ASSERT_PTR_EQUAL(get(list, i), node);
        node = node->previous;
        i--;
    }
}

void testCreateList()
{
    TList *list = create_list();
    CU_ASSERT_PTR_NOT_EQUAL(list, NULL);
    CU_ASSERT_PTR_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_EQUAL(list->end, NULL);
    CU_ASSERT_EQUAL(list->size, 0);

    clean_list(list);
}

void testAddElements()
{
    CU_ASSERT_EQUAL(insert_elements(1), 1);
    CU_ASSERT_EQUAL(insert_elements(10), 10);
    CU_ASSERT_EQUAL(insert_elements(100), 100);
    CU_ASSERT_EQUAL(insert_elements(1000), 1000);
    CU_ASSERT_EQUAL(insert_elements(10000), 10000);
}

void testRemoveElements()
{
    CU_ASSERT_EQUAL(remove_elements(1), 0);
    CU_ASSERT_EQUAL(remove_elements(10), 0);
    CU_ASSERT_EQUAL(remove_elements(100), 0);
    CU_ASSERT_EQUAL(remove_elements(1000), 0);
    CU_ASSERT_EQUAL(remove_elements(10000), 0);
}

void testClear()
{
    TList *list = create_list();

    CU_ASSERT_EQUAL(size(list), 0);

    insert_element(list, 10);

    CU_ASSERT_EQUAL(size(list), 10);

    clear(list);

    CU_ASSERT_EQUAL(size(list), 0);

    insert_element(list, 1000);

    CU_ASSERT_EQUAL(size(list), 1000);

    clear(list);

    CU_ASSERT_EQUAL(size(list), 0);

    clean_list(list);
}

void testEmpty()
{
    TList *list = create_list();

    CU_ASSERT(empty(list));

    insert_element(list, 10);

    CU_ASSERT_FALSE(empty(list));

    remove_element(list, 10);

    CU_ASSERT(empty(list));

    insert_element(list, 1000);

    CU_ASSERT_FALSE(empty(list));

    remove_element(list, 500);

    CU_ASSERT_FALSE(empty(list));

    remove_element(list, 500);

    CU_ASSERT(empty(list));

    clean_list(list);
}

void testRemoveStart()
{
    TList *list = create_list();

    CU_ASSERT_PTR_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_EQUAL(list->end, NULL);

    insert_element(list, 3);

    remove_start(list);

    CU_ASSERT_EQUAL(size(list), 2);

    CU_ASSERT_PTR_NOT_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(list->end, NULL);

    remove_start(list);

    CU_ASSERT_EQUAL(size(list), 1);

    CU_ASSERT_PTR_EQUAL(list->first->previous, NULL);
    CU_ASSERT_PTR_EQUAL(list->end->previous, NULL);
    CU_ASSERT_PTR_EQUAL(list->first->next, NULL);
    CU_ASSERT_PTR_EQUAL(list->end->next, NULL);

    CU_ASSERT_PTR_NOT_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(list->end, NULL);

    insert_start(list, (TData){0});

    remove_start(list);
    remove_start(list);

    CU_ASSERT_EQUAL(size(list), 0);

    CU_ASSERT_PTR_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_EQUAL(list->end, NULL);

    insert_end(list, (TData){0});
    remove_start(list);

    CU_ASSERT_EQUAL(size(list), 0);

    clean_list(list);
}

void testRemoveEnd()
{
    TList *list = create_list();

    CU_ASSERT_PTR_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_EQUAL(list->end, NULL);

    insert_element(list, 3);

    remove_end(list);

    CU_ASSERT_EQUAL(size(list), 2);

    CU_ASSERT_PTR_NOT_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(list->end, NULL);

    remove_end(list);

    CU_ASSERT_EQUAL(size(list), 1);

    CU_ASSERT_PTR_EQUAL(list->first->previous, NULL);
    CU_ASSERT_PTR_EQUAL(list->end->previous, NULL);
    CU_ASSERT_PTR_EQUAL(list->first->next, NULL);
    CU_ASSERT_PTR_EQUAL(list->end->next, NULL);

    CU_ASSERT_PTR_NOT_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(list->end, NULL);

    insert_start(list, (TData){0});

    remove_end(list);
    remove_end(list);

    CU_ASSERT_EQUAL(size(list), 0);

    CU_ASSERT_PTR_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_EQUAL(list->end, NULL);

    insert_end(list, (TData){0});
    remove_end(list);

    CU_ASSERT_EQUAL(size(list), 0);

    clean_list(list);
}

void testRemoveAt()
{
    TList *list = create_list();

    CU_ASSERT_PTR_EQUAL(list->first, NULL);
    CU_ASSERT_PTR_EQUAL(list->end, NULL);

    for (int i = 1; i <= 4; i++)
    {
        insert_end(list, (TData){i * 10});
    }

    remove_at(list, 1);

    CU_ASSERT_EQUAL(get(list, 0)->data.data, 10);
    CU_ASSERT_EQUAL(get(list, 1)->data.data, 30);
    CU_ASSERT_EQUAL(get(list, 2)->data.data, 40);

    testPreviousNext(list);

    insert_start(list, (TData){0});
    insert_end(list, (TData){0});

    CU_ASSERT_EQUAL(size(list), 5);

    remove_at(list, 2);

    CU_ASSERT_EQUAL(get(list, 0)->data.data, 0);
    CU_ASSERT_EQUAL(get(list, 1)->data.data, 10);
    CU_ASSERT_EQUAL(get(list, 2)->data.data, 40);
    CU_ASSERT_EQUAL(get(list, 3)->data.data, 0);

    testPreviousNext(list);

    CU_ASSERT_PTR_EQUAL(list->first->previous, NULL);
    CU_ASSERT_PTR_EQUAL(list->end->next, NULL);

    remove_at(list, 2);

    CU_ASSERT_EQUAL(get(list, 0)->data.data, 0);
    CU_ASSERT_EQUAL(get(list, 1)->data.data, 10);
    CU_ASSERT_EQUAL(get(list, 2)->data.data, 0);

    clean_list(list);
}

void testCopy()
{
    TList *const_list = create_list();
    TList *list = create_list();

    insert_element(const_list, 1000);
    insert_element(list, 1000);

    TList *copy_list = copy(list);

    clear(copy_list);

    CU_ASSERT_EQUAL(size(copy_list), 0);
    CU_ASSERT_EQUAL(size(list), 1000);
    CU_ASSERT_EQUAL(size(list), size(const_list));

    clean_list(const_list);
    clean_list(list);
    clean_list(copy_list);
}

void testInsertStart()
{
    TList *list = create_list();

    insert_start(list, (TData){0});

    CU_ASSERT_PTR_EQUAL(list->first, list->end);
    CU_ASSERT_PTR_NOT_EQUAL(list->first, NULL);

    insert_start(list, (TData){1});
    insert_start(list, (TData){2});

    CU_ASSERT_EQUAL(list->first->data.data, 2);
    CU_ASSERT_EQUAL(get(list, 0)->data.data, 2);
    CU_ASSERT_EQUAL(get(list, 1)->data.data, 1);
    CU_ASSERT_EQUAL(get(list, 2)->data.data, 0);
    CU_ASSERT_EQUAL(list->end->data.data, 0);

    testPreviousNext(list);

    CU_ASSERT_PTR_EQUAL(list->first->previous, NULL);
    CU_ASSERT_PTR_EQUAL(list->end->next, NULL);

    clear(list);

    insert_start(list, (TData){-1});
    CU_ASSERT_PTR_EQUAL(list->first, list->end);
    CU_ASSERT_EQUAL(list->first->data.data, -1);

    clean_list(list);
}

void testInsertEnd()
{
    TList *list = create_list();

    insert_start(list, (TData){0});

    CU_ASSERT_PTR_EQUAL(list->first, list->end);
    CU_ASSERT_PTR_NOT_EQUAL(list->first, NULL);

    insert_end(list, (TData){1});
    insert_end(list, (TData){2});

    CU_ASSERT_EQUAL(list->first->data.data, 0);
    CU_ASSERT_EQUAL(get(list, 0)->data.data, 0);
    CU_ASSERT_EQUAL(get(list, 1)->data.data, 1);
    CU_ASSERT_EQUAL(get(list, 2)->data.data, 2);
    CU_ASSERT_EQUAL(list->end->data.data, 2);

    testPreviousNext(list);

    clear(list);

    insert_end(list, (TData){-1});
    CU_ASSERT_PTR_EQUAL(list->first, list->end);
    CU_ASSERT_EQUAL(list->first->data.data, -1);

    clean_list(list);
}

void testInsertAt()
{
    TList *list = create_list();

    insert_element(list, 3);

    insert_at(list, (TData){1}, 1);

    CU_ASSERT_EQUAL(get(list, 1)->data.data, 1);

    insert_at(list, (TData){3}, 3);

    CU_ASSERT_EQUAL(get(list, 3)->data.data, 3);
    CU_ASSERT_EQUAL(list->end->data.data, 0);
    CU_ASSERT_PTR_NOT_EQUAL(list->first, list->end);

    clean_list(list);
}

void testSize()
{
    TList *list = create_list();

    insert_element(list, 10);
    CU_ASSERT_EQUAL(size(list), 10);
    clear(list);

    insert_element(list, 100);
    CU_ASSERT_EQUAL(size(list), 100);
    clear(list);

    insert_element(list, 1000);
    CU_ASSERT_EQUAL(size(list), 1000);
    clear(list);

    insert_element(list, 10000);
    CU_ASSERT_EQUAL(size(list), 10000);

    clean_list(list);
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite de Teste", NULL, NULL);
    CU_add_test(suite, "Create List Test", testCreateList);
    CU_add_test(suite, "Clear Test", testClear);
    CU_add_test(suite, "Size Test", testSize);
    CU_add_test(suite, "Add Elements Test", testAddElements);
    CU_add_test(suite, "Remove Elements Test", testRemoveElements);
    CU_add_test(suite, "Empty Test", testEmpty);
    CU_add_test(suite, "Insert At Test", testInsertAt);
    CU_add_test(suite, "Insert End Test", testInsertEnd);
    CU_add_test(suite, "Insert Start Test", testInsertStart);
    CU_add_test(suite, "Remove Start Test", testRemoveStart);
    CU_add_test(suite, "Remove End Test", testRemoveEnd);
    CU_add_test(suite, "Remove At Test", testRemoveAt);
    CU_add_test(suite, "Copy Test", testCopy);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}