.PHONY: create_project

create_project:
	@echo "Criando projeto $(PROJECT)"
	mkdir -p $(PROJECT)/test
	echo "#include <stdio.h>\n#include <stdlib.h>\n#include <assert.h>\n#include \"$(PROJECT).h\"\n\nint main(){\n    return 0;\n}" > $(PROJECT)/$(PROJECT).c
	echo "#include <stdio.h>\n\ntypedef struct\n{\n    int data;\n} TData;" > $(PROJECT)/$(PROJECT).h
	echo "#include <CUnit/Basic.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include \"../$(PROJECT).h\"\n\nint main()\n{\n    CU_initialize_registry();\n    CU_pSuite suite = CU_add_suite(\"Suite Test\", NULL, NULL);\n\n    // CU_add_test(suite, \"Your Test\", testYourFunction);\n\n    CU_basic_set_mode(CU_BRM_VERBOSE);\n    CU_basic_run_tests();\n    CU_cleanup_registry();\n    return CU_get_error();\n}" > $(PROJECT)/test/$(PROJECT)_test.c
