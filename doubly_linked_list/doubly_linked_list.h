#include <stdio.h>

/**
 * You can change the type below to any other type. If you want to accept any type, replace 'int' with 'void', like this:
typedef void type;
*/
typedef int type;

typedef struct node
{
    struct node *next;
    struct node *previous;
    type *data;
} TNode;

typedef struct
{
    TNode *first;
    TNode *end;
    int size;
} TList;

/**
 * @brief Creates a doubly linked list of type [type].
 *
 * @return Returns a pointer to the created doubly linked list.
 */
TList *create_list();

/**
 * @brief Creates a node for the doubly linked list.
 *
 * @return Returns a pointer to the created node.
 */
TNode *create_node();

/**
 * @brief Adds one doubly linked list to another list.
 *
 * This function adds all elements from a doubly linked list
 * of type [type] to another doubly linked list.
 * @param list A parameter that has a doubly linked list that will receive the new elements.
 * @param list2 A parameter of type pointer that contains the doubly linked list
 * that will be added to the previous list.
 * @return void
 */
void add_all(TList *list, TList *list2);

/**
 * @brief Inserts an element at the beginning of the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @param data A parameter that contains a pointer of type [type] that
 * will be added to the list.
 * @return void
 */
void insert_start(TList *list, void *data);

/**
 * @brief Inserts an element at a position in the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @param data A parameter that contains a pointer of type [type] that
 * will be added to the list.
 * @param position A parameter that contains the position where the element
 * will be added to the list.
 * @return void
 */
void insert_at(TList *list, void *data, int position);

/**
 * @brief Inserts an element at the end of the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @param data A parameter that contains a pointer of type [type] that
 * will be added to the list.
 * @return void
 */
void insert_end(TList *list, void *data);

/**
 * @brief Removes the element from the beginning of the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @return void
 */
void remove_start(TList *list);

/**
 * @brief Removes the element from a position in the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @param position A parameter that contains the position from which the element
 * will be removed from the list.
 * @return void
 */
void remove_at(TList *list, int position);

/**
 * @brief Removes the last element from the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @return void
 */
void remove_end(TList *list);

/**
 * @brief Clears all elements from the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @return void
 */
void clear(TList *list);

/**
 * @brief Prints the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 */
void print(TList *list);

void print_previous_next(TList *list);

/**
 * @brief Prints the list.
 *
 * @param list A parameter of type pointer that receives a doubly linked list.
 * @param position A parameter that receives the position to be accessed in the list.
 * @return Returns a pointer of type [TNode] to the desired position's element.
 */
TNode *get(TList *list, int position);