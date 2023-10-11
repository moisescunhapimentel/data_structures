#include <stdio.h>

typedef struct
{
    int data;
} TData;

typedef struct node
{
    struct node *next;
    TData data;
} TNode;

typedef struct
{
    TNode *first;
    TNode *end;
    int size;
} TList;

/**
 * @brief Check if a pointer to a TList is null. If it is null, it will raise an assert
 *
 * @param list A parameter of type pointer that receives a linked list.
 */
void check_null_list(TList *list);

/**
 * @brief Clears all elements from the list.
 *
 * @param list A parameter of type pointer that receives a linked list.
 * @return void
 */
void clear(TList *list);

/**
 *@brief Makes a safe copy of a [TList]
 *
 *@param list A parameter of pointer type that receives a linked list
 *@return Returns a copy of the list
 */
TList *copy(TList *list);

/**
 * @brief Creates a linked list of type [TData].
 *
 * @return Returns a pointer to the created linked list.
 */
TList *create_list();

/**
 * @brief Creates a [TNode] node
 *
 * @return Returns a reference to the created node
 */
TNode *create_node();

/**
 * @brief Checks if a [TList] is empty
 *
 * @param list A parameter of pointer type that receives a linked list
 * @return Returns 1 if the list is empty, or 0 otherwise
 */
int empty(TList *list);

/**
 * @brief Gets the element from the list given its position.
 *
 * @param list Parameter of pointer type that receives a circular
 * list.
 * @param position Parameter representing the position of the element.
 * @return Returns a pointer [TNode] to the specified position.
 */
TNode *get(TList *list, int position);

/**
 * @brief Initializes the list with default values
*/
void initial_values(TList *list);

/**
 * @brief Inserts an element at the beginning of the list.
 *
 * @param list A parameter of type pointer that receives a linked list.
 * @param data A parameter that contains a [TData] that
 * will be added to the list.
 * @return void
 */
void insert_start(TList *list, TData data);

/**
 * @brief Inserts an element at a position in the list.
 *
 * @param list A parameter of type pointer that receives a linked list.
 * @param data A parameter that contains a [TData] that
 * will be added to the list.
 * @param position A parameter that contains the position where the element
 * will be added to the list.
 * @return void
 */
int insert_at(TList *list, TData data, int position);

/**
 * @brief Inserts an element at the end of the list.
 *
 * @param list A parameter of type pointer that receives a linked list.
 * @param data A parameter that contains a [TData] that
 * will be added to the list.
 * @return void
 */
void insert_end(TList *list, TData data);

/**
 * @brief Removes the element from the beginning of the list.
 *
 * @param list A parameter of type pointer that receives a linked list.
 * @return void
 */
int remove_start(TList *list);

/**
 * @brief Removes the element from a position in the list.
 *
 * @param list A parameter of type pointer that receives a linked list.
 * @param position A parameter that contains the position from which the element
 * will be removed from the list.
 * @return void
 */
int remove_at(TList *list, int position);

/**
 * @brief Removes the last element from the list.
 *
 * @param list A parameter of type pointer that receives a linked list.
 * @return void
 */
int remove_end(TList *list);

/**
 * @brief Checks the total number of elements in a [TList].
 * 
 * This function will iterate through the [TList] and count 
 * the total number of elements
 * 
 * @param list A parameter of type pointer that receives a linked list.
 * @return Returns the total number of elements in the list
*/
int size(TList *list);
