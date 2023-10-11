#include <stdio.h>
#include "circular_linked_list.h"

void print(TList *list)
{
    if (list->size == 0)
    {
        puts("[]");
        return;
    }

    if (list->HEAD != NULL)
        printf("[ (HEAD) ");

    TNode *no = list->HEAD;

    printf("%d", no->data.data);

    while (no->next != list->HEAD)
    {
        printf(" => ");
        no = no->next;
        printf("%d", no->data.data);
    }

    if (no->next == list->HEAD)
        printf(" => (HEAD) ]");

    putchar('\n');
}

int main()
{
    TList *list = create_list();

    int a = 10;
    TData data = {a};
    insert_end(list, data);

    int b = 20;
    data.data = b;
    insert_end(list, data);

    int c = 30;
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

    remove_at(list, 1);

    print(list);

    data.data = b;

    insert_at(list, data, 1);

    print(list);

    return 0;
}
