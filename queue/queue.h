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
} TQueue;

/**
 * @brief Last element of the queue
 * 
 * @param queue A parameter of type pointer that receives a queue
 * @return Returns the last element [TData] of the queue
*/
TData *back(TQueue *queue);

/**
 * @brief Check if a pointer to a TQueue is null. If it is null, it will raise an assert
 *
 * @param queue A parameter of type pointer that receives a queue.
 */
void check_null_queue(TQueue *queue);

/**
 * @brief Clears all elements from the queue.
 *
 * @param queue A parameter of type pointer that receives a queue.
 * @return void
 */
void clear(TQueue *queue);

/**
 *@brief Makes a safe copy of a [TQueue]
 *
 *@param queue A parameter of pointer type that receives a queue
 *@return Returns a copy of the queue
 */
TQueue *copy(TQueue *queue);

/**
 * @brief Creates a queue of type [TData].
 *
 * @return Returns a pointer to the created queue.
 */
TQueue *create_queue();

/**
 * @brief Creates a [TNode] node
 *
 * @return Returns a reference to the created node
 */
TNode *create_node();

/**
 * @brief Checks if a [TQueue] is empty
 *
 * @param queue A parameter of pointer type that receives a queue
 * @return Returns 1 if the queue is empty, or 0 otherwise
 */
int empty(TQueue *queue);

/**
 * @brief First element of the queue
 * 
 * @param queue A parameter of pointer type that receives a queue
 * @return Returns the first element [TData] of the queue
*/
TData *front(TQueue *queue);

/**
 * @brief Initializes the queue with default values
 */
void initial_values(TQueue *queue);

 /**
 * @brief Inserts an element at the end of the queue.
 *
 * @param queue A parameter of type pointer that receives a queue.
 * @param data A parameter that contains a [TData] that
 * will be added to the queue.
 * @return void
 */
void push(TQueue *queue, TData data);

/**
 * @brief Removes the element from the beginning of the queue.
 *
 * @param queue A parameter of type pointer that receives a queue.
 * @return Returns the removed element
 */
TData pop(TQueue *queue);

/**
 * @brief Checks the total number of elements in a [TQueue].
 *
 * This function will iterate through the [TQueue] and count
 * the total number of elements
 *
 * @param queue A parameter of type pointer that receives a queue.
 * @return Returns the total number of elements in the queue
 */
int size(TQueue *queue);
