#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10
#define INCREMENT_FACTOR 2

typedef int ElemType;

typedef struct {
    ElemType* data;
    int length;
    int capacity;
} LinearList;

bool initList(LinearList* list) {
    list->data = (ElemType*) malloc(INITIAL_CAPACITY * sizeof(ElemType));
    if (list->data == NULL) return false;

    list->length = 0;
    list->capacity = INITIAL_CAPACITY;

    return true;
}

void destroyList(LinearList* list) {
    if (list->data != NULL) {
        free(list->data);
        list->data = NULL;
        list->length = 0;
        list->capacity = 0;
    }
}

void clearList(LinearList* list) {
    list->length = 0;
}

bool isEmpty(LinearList* list) {
    return list->length == 0;
}

int length(LinearList* list) {
    return list->length;
}

bool get(LinearList* list, int index, ElemType* e) {
    if (list->data == NULL || index < 0 || index >= list->length)
        return false;

    *e = list->data[index];

    return true;
}

int locate(LinearList* list, ElemType e) {
    if (list->data == NULL)
        return -1;

    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == e) {
            return i;
        }
    }

    return -1;
}

bool prev(LinearList* list, ElemType current, ElemType* prev) {
    if (list->data == NULL)
        return false;

    int currentIndex = locate(list, current);
    if (currentIndex <= 0)
        return false;

    *prev = list->data[currentIndex - 1];
    return true;
}

bool next(LinearList* list, ElemType current, ElemType* next) {
    if (list->data == NULL)
        return false;

    int currentIndex = locate(list, current);
    if (currentIndex < 0 || currentIndex >= list->length)
        return false;

    *next = list->data[currentIndex + 1];
    return true;
}

bool insert(LinearList* list, int index, ElemType e) {
    if (list->data == NULL || index < 0 || index > list->length)
        return false;

    if (list->length == list->capacity) {
        int newCapacity = list->capacity * INCREMENT_FACTOR;
        ElemType* newData = (ElemType*) realloc(list->data,
                                newCapacity * sizeof(ElemType));
        if (newData == NULL) return false;
        list->data = newData;
        list->capacity = newCapacity;
    }

    for (int i = list->length; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = e;
    list->length++;
    return true;
}

bool delete(LinearList* list, int index, ElemType* e) {
    if (list->data == NULL || index < 0 || index >= list->length)
        return false;

    *e = list->data[index];
    for (int i = index; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
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
            printf("Element prior to 30: %d\n", prior);
        }

        delete(&list, 1, &e);  // Delete element at index 1
        printf("Deleted element: %d\n", e);

        printf("List length: %d\n", length(&list));

        destroyList(&list);
    }
    return 0;
}