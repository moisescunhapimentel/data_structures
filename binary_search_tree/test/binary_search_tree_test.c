#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include "../binary_search_tree.h"

void testTNode()
{
    TNode *node = create_node();

    CU_ASSERT_PTR_NOT_EQUAL(node, NULL);
    CU_ASSERT_PTR_EQUAL(node->left, NULL);
    CU_ASSERT_PTR_EQUAL(node->right, NULL);
}

void testTBinarySearchTree()
{
    TBinarySearchTree *binary_search_tree = create_binary_search_tree();

    CU_ASSERT_PTR_NOT_EQUAL(binary_search_tree, NULL);
}

void testInsert()
{
    TBinarySearchTree *binary_search_tree = create_binary_search_tree();

    insert(binary_search_tree, (TData){10});

    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->tdata, (TData){10}) == 0);

    insert(binary_search_tree, (TData){8});
    insert(binary_search_tree, (TData){12});
    insert(binary_search_tree, (TData){6});

    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->tdata, (TData){10}) == 0);
    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->left->tdata, (TData){8}) == 0);
    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->right->tdata, (TData){12}) == 0);
    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->left->left->tdata, (TData){6}) == 0);
}

void testDelete()
{
    TBinarySearchTree *binary_search_tree = create_binary_search_tree();

    insert(binary_search_tree, (TData){10});
    insert(binary_search_tree, (TData){8});
    insert(binary_search_tree, (TData){12});
    insert(binary_search_tree, (TData){6});

    delete (binary_search_tree, binary_search_tree->root->tdata);

    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->tdata, (TData){8}) == 0);
    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->left->tdata, (TData){6}) == 0);
    CU_ASSERT_TRUE(compare_tdata(binary_search_tree->root->right->tdata, (TData){12}) == 0);
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite Test", NULL, NULL);

    CU_add_test(suite, "TNode Test", testTNode);
    CU_add_test(suite, "TBinarySearchTree Test", testTBinarySearchTree);
    CU_add_test(suite, " Insert Test", testInsert);
    CU_add_test(suite, " Delete Test", testDelete);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
