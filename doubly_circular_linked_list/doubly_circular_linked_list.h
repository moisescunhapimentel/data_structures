#include <stdio.h>

/**
 *  You can change the type below to any other type. If you want to accept any type, replace 'int' with 'void', like this:
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
    TNode *HEAD;
    int size;
} TList;

/**
 * @brief Creates a circular list of type [TList].
 *
 * @return Returns a pointer to the created circular list.
 */
TList *create_list();

/**
 * @brief Creates a node for the circular list.
 *
 * @return Returns a pointer to the created node.
 */
TNode *create_node();

/**
 * @brief Adds a circular list to another list.
 *
 * This function adds all elements of a circular list
 * of type [TList] into another circular list.
 * @param list Parameter of pointer type that receives a circular
 * list that will receive the new elements.
 * @param list2 Parameter of pointer type that contains the circular list
 * that will be added to the previous list.
 * @return void
 */
void add_all(TList *list, TList *list2);

/**
 * @brief Inserts an element at the beginning of the list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @param data Parameter containing a [type] that
 * will be added to the list.
 * @return void
 */
void insert_start(TList *list, type *data);

/**
 * @brief Inserts an element at a position in the list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @param data Parameter containing a [type] that
 * will be added to the list.
 * @param position Parameter containing the position at which the student
 * element will be added to the list.
 * @return void
 */
int insert_at(TList *list, type *data, int position);

/**
 * @brief Inserts an element at the end of the circular list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @param data Parameter containing a [type] that
 * will be added to the list.
 * @return void
 */
void insert_end(TList *list, type *data);

/**
 * @brief Removes the element from the beginning of the list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @return void
 */
int remove_start(TList *list);

/**
 * @brief Removes the element from a position in the list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @param position Parameter containing the position at which the student
 * element will be removed from the list.
 * @return Returns 1 if the operation is successful, and 0 otherwise.
 */
int remove_at(TList *list, int position);

/**
 * @brief Removes the last element from the circular list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @return Returns 1 if the operation is successful, and 0 otherwise.
 */
int remove_end(TList *list);

/**
 * @brief Quickly clears all elements from the list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @return void
 */
void clear(TList *list);

/**
 * @brief Gets the element from the list given its position.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @param position Parameter representing the position of the circular element.
 * @return Returns a pointer [TNo] to the specified position.
 */
TNode *get(TList *list, int position);

/**
 * @brief Gets the last element of the circular list.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @return Returns a pointer [TNo] to the last element of the list.
 */
TNode *last(TList *list);