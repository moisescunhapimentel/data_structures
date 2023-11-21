#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include "../avl_tree.h"

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite Test", NULL, NULL);

    // CU_add_test(suite, "Your Test", testYourFunction);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
