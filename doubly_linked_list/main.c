#include <stdio.h>
#include "doubly_linked_list.h"

void test_get(TList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("L[%d] = %d\n", i, *(type *)get(list, i)->data);
    }
}

int main()
{
    TList *list = create_list();

    int element1 = 10, element2, element3;

    insert_start(list, &element1);

    element2 = -10;

    insert_start(list, &element2);

    element3 = 500;

    insert_end(list, &element3);

    print(list);

    test_get(list);

    int element4 = -1;

    insert_at(list, &element4, 1);

    print(list);

    return 0;
}
