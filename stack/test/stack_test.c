#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>

#include "../stack.h"

void clean_list(TStack *stack)
{
    clear(stack);
    free(stack);
}

int insert_element(TStack *stack, int length)
{
    TData data = {0};

    for (int i = 0; i < length; i++)
    {
        push(stack, data);
    }
}

int remove_element(TStack *stack, int length)
{
    for (int i = 0; i < length; i++)
    {
        pop(stack);
    }
}

int insert_elements(int length)
{
    TStack *stack = create_stack();

    insert_element(stack, length);

    int size_list = size(stack);

    clean_list(stack);

    return size_list;
}

int remove_elements(int length)
{
    TStack *stack = create_stack();

    insert_element(stack, length);

    remove_element(stack, length);

    int size_list = size(stack);

    clean_list(stack);

    return size_list;
}

void testCreateList()
{
    TStack *stack = create_stack();
    CU_ASSERT_PTR_NOT_EQUAL(stack, NULL);
    CU_ASSERT_PTR_EQUAL(stack->first, NULL);
    CU_ASSERT_PTR_EQUAL(stack->end, NULL);
    CU_ASSERT_EQUAL(stack->size, 0);

    clean_list(stack);
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
    TStack *stack = create_stack();

    CU_ASSERT_EQUAL(size(stack), 0);

    insert_element(stack, 10);

    CU_ASSERT_EQUAL(size(stack), 10);

    clear(stack);

    CU_ASSERT_EQUAL(size(stack), 0);

    insert_element(stack, 1000);

    CU_ASSERT_EQUAL(size(stack), 1000);

    clear(stack);

    CU_ASSERT_EQUAL(size(stack), 0);

    clean_list(stack);
}

void testEmpty()
{
    TStack *stack = create_stack();

    CU_ASSERT(empty(stack));

    insert_element(stack, 10);

    CU_ASSERT_FALSE(empty(stack));

    remove_element(stack, 10);

    CU_ASSERT(empty(stack));

    insert_element(stack, 1000);

    CU_ASSERT_FALSE(empty(stack));

    remove_element(stack, 500);

    CU_ASSERT_FALSE(empty(stack));

    remove_element(stack, 500);

    CU_ASSERT(empty(stack));

    clean_list(stack);
}

void testPop()
{
    TStack *stack = create_stack();

    CU_ASSERT_PTR_EQUAL(stack->first, NULL);
    CU_ASSERT_PTR_EQUAL(stack->end, NULL);

    insert_element(stack, 3);

    pop(stack);

    CU_ASSERT_EQUAL(size(stack), 2);

    CU_ASSERT_PTR_NOT_EQUAL(stack->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(stack->end, NULL);

    pop(stack);

    CU_ASSERT_EQUAL(size(stack), 1);

    CU_ASSERT_PTR_NOT_EQUAL(stack->first, NULL);
    CU_ASSERT_PTR_NOT_EQUAL(stack->end, NULL);

    push(stack, (TData){0});

    pop(stack);
    pop(stack);

    CU_ASSERT_EQUAL(size(stack), 0);

    CU_ASSERT_PTR_EQUAL(stack->first, NULL);
    CU_ASSERT_PTR_EQUAL(stack->end, NULL);

    push(stack, (TData){0});
    pop(stack);

    CU_ASSERT_EQUAL(size(stack), 0);

    clean_list(stack);
}

void testCopy()
{
    TStack *const_list = create_stack();
    TStack *stack = create_stack();

    insert_element(const_list, 1000);
    insert_element(stack, 1000);

    TStack *copy_list = copy(stack);

    clear(copy_list);

    CU_ASSERT_EQUAL(size(copy_list), 0);
    CU_ASSERT_EQUAL(size(stack), 1000);
    CU_ASSERT_EQUAL(size(stack), size(const_list));

    clean_list(const_list);
    clean_list(stack);
    clean_list(copy_list);
}

void testSize()
{
    TStack *stack = create_stack();

    insert_element(stack, 10);
    CU_ASSERT_EQUAL(size(stack), 10);
    clear(stack);

    insert_element(stack, 100);
    CU_ASSERT_EQUAL(size(stack), 100);
    clear(stack);

    insert_element(stack, 1000);
    CU_ASSERT_EQUAL(size(stack), 1000);
    clear(stack);

    insert_element(stack, 10000);
    CU_ASSERT_EQUAL(size(stack), 10000);

    clean_list(stack);
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
    CU_add_test(suite, "Pop Test", testPop);
    CU_add_test(suite, "Copy Test", testCopy);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}