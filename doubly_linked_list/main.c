#include <stdio.h>
#include "doubly_linked_list.h"

void test_get(TList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("[%d] = %d\n", i, *(type *)get(list, i)->data);
    }
}

int main()
{
    TList *list = create_list();

    int a = 10, b = 20, c = 30, d = 40;

    insert_end(list, &a);
    insert_end(list, &b);
    insert_end(list, &c);
    insert_end(list, &d);

    print(list);
    print_previous_next(list);

    test_get(list);

    TList *reversed_list = reversed(list);

    print(reversed_list);
    print_previous_next(reversed_list);

    test_get(reversed_list);

    insert_at(list, &a, 2);

    print(list);
    print_previous_next(list);

    remove_end(list);

    print(list);
    print_previous_next(list);

    insert_start(list, &d);
    insert_end(list, &b);

    print(list);
    print_previous_next(list);

    clear(list);

    insert_start(list, &d);
    insert_end(list, &b);

    print(list);
    print_previous_next(list);

    printf("%d\n", list->size);

    return 0;
}
