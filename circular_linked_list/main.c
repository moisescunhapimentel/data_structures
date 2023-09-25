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

    printf("%d", *((int *)no->data));

    while (no->next != list->HEAD)
    {
        printf(" => ");
        no = no->next;
        printf("%d", *((int *)no->data));
    }

    if (no->next == list->HEAD)
        printf(" => (HEAD) ]");

    putchar('\n');
}

int main()
{
    TList *list = create_list();

    int a = 10;

    insert_end(list, &a);

    int b = 20;

    insert_end(list, &b);

    int c = 30;

    insert_end(list, &c);

    print(list);

    clear(list);

    insert_start(list, &a);
    insert_start(list, &b);
    insert_start(list, &c);

    print(list);

    remove_at(list, 1);

    print(list);

    insert_at(list, &b, 1);

    print(list);

    return 0;
}
