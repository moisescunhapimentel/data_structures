#include <stdio.h>

typedef struct
{
    int data;
} TData;

typedef struct
{
    TData **array;
    int size;
    int MAX;
} TArrayList;

/**
 * @brief Add a [TData] at the end of the [TArrayList]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @param data Parameter containing the pointer to [TData] to be added
 *
 * @return Returns an integer indicating whether the operation was successful
 */
int add(TArrayList *array_list, TData data);

/**
 * @brief Deletes all elements from a [TArrayList].
 *
 * Please note that this action does not reallocate [TArrayList],
 * so it will have [TArrayList->size] = 0, but [TArrayList->MAX]
 * will remain unchanged. Therefore, the allocated memory
 * before calling [clear] will be the same after the [clear] call.
 *
 * If you wish, after calling [clear], you can call [realloc_array_list]
 * to reduce the number of unused elements and free up memory.
 */
void clear(TArrayList *array_list);

/**
 * @brief Creates a safe copy of [TArrayList]
 *
 * @param array_list Parameter that receives the pointer to [TArrayList] to be copied
 * @return Returns a new pointer, a copy of [TArrayList*]
 */
TArrayList *copy_array_list(TArrayList *array_list);

/**
 * @brief Creates a safe copy of [TData]
 *
 * @param tData Parameter that receives the pointer to [TData] to be copied
 * @return Returns a new pointer, a copy of [TData*]
 */
TData *copy_tdata(TData *tData);

/**
 * @brief Checks if [TArrayList] contains [TData]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @return Returns 1 if [TArrayList] contains [TData], and 0 otherwise
 */
int contains(TArrayList *array_list, TData data);

/**
 * @brief Check if the index is valid
 *
 * @param array_list Parameter containing the [TArrayList]
 */
void check_index_range(TArrayList *array_list, int index);

/**
 * @brief Check if [length] is non-negative.
 *
 * If it's negative, an [assert] will be triggered.
 */
void check_length(int length);

/**
 * @brief Check if [TArrayList] is valid and if [array] is valid.
 *
 * If [TArrayList] is [NULL] or [array] is [NULL], it will trigger an [assert].
 * @param array_list Parameter containing the [TArrayList]
 */
void check_null_array_list(TArrayList *array_list);

/**
 * @brief Allocate a new [TArrayList]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @return Returns a pointer to the allocated [TArrayList]
 */
TArrayList *create_array_list(int length);

/**
 * @brief Allocate a new valid [TData]
 *
 * @return Returns a pointer to the allocated [TData]
 */
TData *create_tdata();

/**
 * @brief Delete and deallocate the [TArrayList]
 *
 * @param array_list Parameter containing the [TArrayList]
 */
void delete_list(TArrayList *array_list);

/**
 * @brief Compare two [TData]
 *
 * @param data Parameter [TData]
 * @param other Parameter [TData] that will be compared with [data]
 * @return Returns 1 if [data] and [other] are equal
 */
int equals_tdata(TData data, TData other);

/**
 * @brief Check if [TArrayList] is empty
 *
 * @param array_list Parameter containing the [TArrayList]
 * @return Returns 1 if [array_list] is empty
 */
int empty(TArrayList *array_list);

/**
 * @brief Gets the element of [TArrayList] starting at position.
 */
TData get(TArrayList *array_list, int position);

/**
 * @brief Index of [TData] in [TArrayList]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @return Returns the index if [TArrayList] contains [TData], and -1 otherwise
 */
int index_of(TArrayList *array_list, TData data);

/**
 * @brief Add a [TData] at a specified position in the [TArrayList]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @param data Parameter containing the pointer to [TData] to be added
 * @param position Parameter containing the position at which the element will be added
 *
 * @return Returns an integer indicating whether the operation was successful
 */
int insert_at(TArrayList *array_list, TData data, int position);

/**
 * @brief Initialize the [TArrayList] with default values
 *
 * @param array_list Parameter containing the [TArrayList]
 */
void initial_values(TArrayList *array_list);

/**
 * @brief Allocate memory for the [array] of the [TArrayList] to a specified [size]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @param length Parameter containing the size of the [array]
 */
void malloc_array_list(TArrayList *array_list, int length);

/**
 * @brief Reallocate memory for the [array] of the [TArrayList] to a new [size]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @param length Parameter containing the new size of the [array]
 */
void realloc_array_list(TArrayList *array_list, int length);

/**
 * @brief Remove an element from [TArrayList] at a specified position.
 *
 * Please note that when removing an element, the [TArrayList] will not be
 * reallocated and will continue to have the same number of
 * elements in [TArrayList->MAX].
 *
 * @param array_list Parameter containing the [TArrayList]
 * @param position Parameter containing the position of the element to be removed
 */
void remove_at(TArrayList *array_list, int position);

/**
 * @brief Remove all elements equal to [TData]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @param data Parameter containing the [TData] to be removed
 */
void remove_all(TArrayList *array_list, TData data);

/**
 * @brief Reverses all elements in the [TArrayList]
 *
 * @param array_list Parameter containing the [TArrayList]
 * @return Returns a new [TArrayList] pointer with the elements reversed
 */
TArrayList *reversed(TArrayList *array_list);

/**
 * @brief Change the value of [TData] at a specific position
 *
 * @param array_list Parameter containing the [TArrayList]
 */
void set(TArrayList *array_list, TData data, int position);