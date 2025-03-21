#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10
#define INCREMENT_FACTOR 2

// Define the element type for simplicity
typedef int ElemType;

typedef struct {
    ElemType *data;  // Pointer to the array of elements
    int length;      // Current number of elements in the list
    int capacity;    // Total capacity of the list
} LinearList;

/**
 * Initialize the linear list with a predefined capacity.
 * @param list Pointer to the LinearList to be initialized.
 * @return true if initialization is successful, false otherwise.
 */
bool initList(LinearList *list) {
    list->data = (ElemType *)malloc(INITIAL_CAPACITY * sizeof(ElemType));
    if (list->data == NULL) return false;
    list->length = 0;
    list->capacity = INITIAL_CAPACITY;
    return true;
}

/**
 * Destroy the linear list, freeing allocated memory.
 * @param list Pointer to the LinearList to be destroyed.
 */
void destroyList(LinearList *list) {
    if (list->data != NULL) {
        free(list->data);
        list->data = NULL;
        list->length = 0;
        list->capacity = 0;
    }
}

/**
 * Clear the list by resetting the length to 0, but keep the capacity.
 * @param list Pointer to the LinearList to be cleared.
 */
void clearList(LinearList *list) {
    list->length = 0;
}

/**
 * Check if the list is empty.
 * @param list Pointer to the LinearList to check.
 * @return true if the list is empty, false otherwise.
 */
bool isEmpty(LinearList *list) {
    return list->length == 0;
}

/**
 * Get the current length of the list.
 * @param list Pointer to the LinearList.
 * @return The number of elements in the list.
 */
int length(LinearList *list) {
    return list->length;
}

/**
 * Retrieve an element from the list by its index.
 * @param list Pointer to the LinearList.
 * @param index Index of the element to retrieve (0-based).
 * @param e Pointer where the element value will be stored.
 * @return true if the element was retrieved, false if index out of bounds.
 */
bool get(LinearList *list, int index, ElemType *e) {
    if (index < 0 || index >= list->length) return false;
    *e = list->data[index];
    return true;
}

/**
 * Locate an element in the list by value.
 * @param list Pointer to the LinearList.
 * @param e The element to locate.
 * @return The index of the first occurrence of the element, or -1 if not found.
 */
int locate(LinearList *list, ElemType e) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == e) return i;
    }
    return -1;
}

/**
 * Get the previous element of a given element in the list.
 * @param list Pointer to the LinearList.
 * @param current Element whose predecessor is to be found.
 * @param prev Pointer where the predecessor's value will be stored.
 * @return true if the predecessor was found, false otherwise.
 */
bool prev(LinearList *list, ElemType current, ElemType *prev) {
    int index = locate(list, current);
    if (index > 0) {
        *prev = list->data[index - 1];
        return true;
    }
    return false;
}

/**
 * Get the next element of a given element in the list.
 * @param list Pointer to the LinearList.
 * @param current Element whose successor is to be found.
 * @param next Pointer where the successor's value will be stored.
 * @return true if the successor was found, false otherwise.
 */
bool next(LinearList *list, ElemType current, ElemType *next) {
    int index = locate(list, current);
    if (index != -1 && index < list->length - 1) {
        *next = list->data[index + 1];
        return true;
    }
    return false;
}

/**
 * Insert an element into the list at the given index.
 * @param list Pointer to the LinearList.
 * @param index The index at which to insert the element (0-based).
 * @param e The element to insert.
 * @return true if insertion was successful, false otherwise.
 */
bool insert(LinearList *list, int index, ElemType e) {
    if (index < 0 || index > list->length) return false;

    if (list->length == list->capacity) {
        int newCapacity = list->capacity * INCREMENT_FACTOR;
        ElemType *newData = (ElemType *)realloc(list->data, newCapacity * sizeof(ElemType));
        if (newData == NULL) return false;
        list->data = newData;
        list->capacity = newCapacity;
    }

    for (int i = list->length; i > index; i--) {
        list->data[i] = list->data[i-1];
    }
    list->data[index] = e;
    list->length++;
    return true;
}

/**
 * Delete an element from the list at the given index.
 * @param list Pointer to the LinearList.
 * @param index The index of the element to delete (0-based).
 * @param e Pointer where the deleted element's value will be stored.
 * @return true if deletion was successful, false otherwise.
 */
bool delete(LinearList *list, int index, ElemType *e) {
    if (index < 0 || index >= list->length) return false;
    
    *e = list->data[index];
    for (int i = index; i < list->length - 1; i++) {
        list->data[i] = list->data[i+1];
    }
    list->length--;
    return true;
}

// Example usage
int main() {
    LinearList list;
    if (initList(&list)) {
        insert(&list, 0, 10);  // Insert 10 at index 0
        insert(&list, 1, 20);  // Insert 20 at index 1
        insert(&list, 2, 30);  // Insert 30 at index 2

        ElemType e;
        get(&list, 1, &e);     // Get element at index 1
        printf("Element at index 1: %d\n", e);

        int loc = locate(&list, 20);
        printf("Index of 20: %d\n", loc);

        ElemType prior;
        if (prev(&list, 30, &prior)) {
            printf("Element prev to 30: %d\n", prior);
        }

        delete(&list, 1, &e);  // Delete element at index 1
        printf("Deleted element: %d\n", e);

        printf("List length: %d\n", length(&list));

        destroyList(&list);
    }
    return 0;
}