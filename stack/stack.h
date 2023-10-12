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
} TStack;

/**
 * @brief Check if a pointer to a TStack is null. If it is null, it will raise an assert
 *
 * @param stack A parameter of type pointer that receives a linked stack.
 */
void check_null_stack(TStack *stack);

/**
 * @brief Clears all elements from the stack.
 *
 * @param stack A parameter of type pointer that receives a linked stack.
 * @return void
 */
void clear(TStack *stack);

/**
 *@brief Makes a safe copy of a [TStack]
 *
 *@param stack A parameter of pointer type that receives a linked stack
 *@return Returns a copy of the stack
 */
TStack *copy(TStack *stack);

/**
 * @brief Creates a linked stack of type [TData].
 *
 * @return Returns a pointer to the created linked stack.
 */
TStack *create_stack();

/**
 * @brief Creates a [TNode] node
 *
 * @return Returns a reference to the created node
 */
TNode *create_node();

/**
 * @brief Checks if a [TStack] is empty
 *
 * @param stack A parameter of pointer type that receives a linked stack
 * @return Returns 1 if the stack is empty, or 0 otherwise
 */
int empty(TStack *stack);

/**
 * @brief Initializes the stack with default values
 */
void initial_values(TStack *stack);

/**
 * @brief Inserts an element at the end of the stack.
 *
 * @param stack A parameter of type pointer that receives a linked stack.
 * @param data A parameter that contains a [TData] that
 * will be added to the stack.
 * @return void
 */
void push(TStack *stack, TData data);

/**
 * @brief Removes the last element from the stack.
 *
 * @param stack A parameter of type pointer that receives a linked stack.
 * @return void
 */
int pop(TStack *stack);

/**
 * @brief Checks the total number of elements in a [TStack].
 *
 * This function will iterate through the [TStack] and count
 * the total number of elements
 *
 * @param stack A parameter of type pointer that receives a linked stack.
 * @return Returns the total number of elements in the stack
 */
int size(TStack *stack);

/**
 * @brief Element at the top of the stack
 * 
 * @param stack A pointer parameter that receives a linked stack
 * @return Returns a reference to the element at the top of the stack
*/
TData *top(TStack *stack);