#include <stdio.h>
#include "doubly_circular_linked_list.h"

void print(TList *list)
{
    if (list->size == 0 || list->HEAD == NULL)
    {
        return;
    }

    TNode *no = list->HEAD;
    printf("(HEAD) ");
    do
    {
        printf("%d <==> ", *((int *)no->data));
        no = no->next;
    } while (no != list->HEAD);
    puts("(HEAD)");
}

void print_previous_next(TList *list)
{
    if (list->size == 0 || list->HEAD == NULL)
    {
        return;
    }

    TNode *no = list->HEAD;

    do
    {
        printf("%d <= %d => %d\n", *((int *)no->previous->data), *((int *)no->data), *((int *)no->next->data));
        no = no->next;
    } while (no != list->HEAD);

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

    print_previous_next(list);

    remove_at(list, 0);
    remove_at(list, 0);
    remove_at(list, 0);

    print(list);

    print_previous_next(list);


    return 0;
}
