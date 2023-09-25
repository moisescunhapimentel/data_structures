#include <stdio.h>
#include "linked_list.h"

void print(TList *list)
{
    for (TNode *no = list->first; no != NULL; no = no->next)
    {
        printf("%d, ", *((int *)no->data));
    }
    putchar('\n');
}

int main()
{
    TList *list = create_list();

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 300;
    int e = -10;

    insert_end(list, &a);
    insert_end(list, &b);
    insert_end(list, &c);

    print(list);

    clear(list);

    insert_start(list, &a);
    insert_start(list, &b);
    insert_start(list, &c);

    print(list);

    insert_at(list, &d, 2);

    print(list);

    return 0;
}
