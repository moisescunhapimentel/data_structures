#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>

#include "../queue.h"

void clean_list(TQueue *queue)
{
    clear(queue);
    free(queue);
}

int insert_element(TQueue *queue, int length)
{
    TData data = {0};

    for (int i = 0; i < length; i++)
    {
        push(queue, data);
    }
}

int remove_element(TQueue *queue, int length)
{
    for (int i = 0; i < length; i++)
    {
        pop(queue);
    }
}

int insert_elements(int length)
{
    TQueue *queue = create_queue();

    insert_element(queue, length);

    int size_list = size(queue);

    clean_list(queue);

    return size_list;
}

int remove_elements(int length)
{
    TQueue *queue = create_queue();

    insert_element(queue, length);

    remove_element(queue, length);

    int size_list = size(queue);

    clean_list(queue);

    return size_list;
}

void testCreateQueue()
{
    TQueue *queue = create_queue();
    CU_ASSERT_PTR_NOT_EQUAL(queue, NULL);
    CU_ASSERT_PTR_EQUAL(queue->first, NULL);
    CU_ASSERT_PTR_EQUAL(queue->end, NULL);
    CU_ASSERT_EQUAL(queue->size, 0);

    clean_list(queue);
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
    TQueue *queue = create_queue();

    CU_ASSERT_EQUAL(size(queue), 0);

    insert_element(queue, 10);

    CU_ASSERT_EQUAL(size(queue), 10);

    clear(queue);

    CU_ASSERT_EQUAL(size(queue), 0);

    insert_element(queue, 1000);

    CU_ASSERT_EQUAL(size(queue), 1000);

    clear(queue);

    CU_ASSERT_EQUAL(size(queue), 0);

    clean_list(queue);
}

void testEmpty()
{
    TQueue *queue = create_queue();

    CU_ASSERT(empty(queue));

    insert_element(queue, 10);

    CU_ASSERT_FALSE(empty(queue));

    remove_element(queue, 10);

    CU_ASSERT(empty(queue));

    insert_element(queue, 1000);

    CU_ASSERT_FALSE(empty(queue));

    remove_element(queue, 500);

    CU_ASSERT_FALSE(empty(queue));

    remove_element(queue, 500);

    CU_ASSERT(empty(queue));

    clean_list(queue);
}

void testPop()
{
    TQueue *queue = create_queue();

    CU_ASSERT_PTR_EQUAL(queue->first, NULL);
    CU_ASSERT_PTR_EQUAL(queue->end, NULL);

    insert_element(queue, 3);

    pop(queue);

    CU_ASSERT_EQUAL(size(queue), 2);

    CU_ASSERT_PTR_NOT_EQUAL(queue->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(queue->end, NULL);

    pop(queue);

    CU_ASSERT_EQUAL(size(queue), 1);

    CU_ASSERT_PTR_NOT_EQUAL(queue->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(queue->end, NULL);

    push(queue, (TData){0});

    pop(queue);
    pop(queue);

    CU_ASSERT_EQUAL(size(queue), 0);

    CU_ASSERT_PTR_EQUAL(queue->first, NULL);
    CU_ASSERT_PTR_EQUAL(queue->end, NULL);

    push(queue, (TData){0});
    pop(queue);

    CU_ASSERT_EQUAL(size(queue), 0);

    clean_list(queue);
}

void testCopy()
{
    TQueue *const_list = create_queue();
    TQueue *queue = create_queue();

    insert_element(const_list, 1000);
    insert_element(queue, 1000);

    TQueue *copy_list = copy(queue);

    clear(copy_list);

    CU_ASSERT_EQUAL(size(copy_list), 0);
    CU_ASSERT_EQUAL(size(queue), 1000);
    CU_ASSERT_EQUAL(size(queue), size(const_list));

    clean_list(const_list);
    clean_list(queue);
    clean_list(copy_list);
}
void testSize()
{
    TQueue *queue = create_queue();

    insert_element(queue, 10);
    CU_ASSERT_EQUAL(size(queue), 10);
    clear(queue);

    insert_element(queue, 100);
    CU_ASSERT_EQUAL(size(queue), 100);
    clear(queue);

    insert_element(queue, 1000);
    CU_ASSERT_EQUAL(size(queue), 1000);
    clear(queue);

    insert_element(queue, 10000);
    CU_ASSERT_EQUAL(size(queue), 10000);

    clean_list(queue);
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite de Teste", NULL, NULL);
    CU_add_test(suite, "Create List Test", testCreateQueue);
    CU_add_test(suite, "Clear Test", testClear);
    CU_add_test(suite, "Size Test", testSize);
    CU_add_test(suite, "Add Elements Test", testAddElements);
    CU_add_test(suite, "Remove Elements Test", testRemoveElements);
    CU_add_test(suite, "Empty Test", testEmpty);
    CU_add_test(suite, "Remove Start Test", testPop);
    CU_add_test(suite, "Copy Test", testCopy);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}