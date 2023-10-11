#include <stdio.h>
#include "linked_list.h"

void print(TList *list)
{
    for (TNode *no = list->first; no != NULL; no = no->next)
    {
        printf("%d, ", no->data.data);
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

    TData data;

    data.data = a;
    insert_end(list, data);
    data.data = b;
    insert_end(list, data);
    data.data = c;
    insert_end(list, data);

    print(list);

    clear(list);

    data.data = a;
    insert_start(list, data);
    data.data = b;
    insert_start(list, data);
    data.data = c;
    insert_start(list, data);

    print(list);

    data.data = d;
    insert_at(list, data, 2);

    print(list);

    return 0;
}
