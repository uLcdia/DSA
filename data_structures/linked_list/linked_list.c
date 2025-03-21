#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int length;
} LinkedList;

void initList(LinkedList* linkedList) {
    linkedList->head = NULL;
    linkedList->length = 0;
}

void destroyList(LinkedList* linkedList) {
    Node* current = linkedList->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    linkedList->head = NULL;
    linkedList->length = 0;
}

void clearList(LinkedList* linkedList) {
    destroyList(linkedList);
    initList(linkedList);
}

bool isEmpty(LinkedList* linkedList) {
    return linkedList->length == 0;
}

int length(LinkedList* linkedList) {
    return linkedList->length;
}

bool get(LinkedList* linkedList, int index, Node** node) {
    if (index < 0 || index >= linkedList->length) {
        return false;
    }

    Node* current = linkedList->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current != NULL) {
        *node = current;
        return true;
    } else {
        return false;
    }
}

int locate(LinkedList* linkedList, ElemType e) {
    Node* current = linkedList->head;
    for (int i = 0; i < linkedList->length; i++) {
        if (current->data == e) {
            return i;
        }
        current = current->next;
    }
    return -1;
}

bool prev(LinkedList* linkedList, Node* current, Node* prev) {
    if (linkedList->head == NULL || linkedList->head == current) {
        return false;
    }

    Node* prevNode = linkedList->head;
    Node* currNode = prevNode->next;

    while (currNode != NULL && currNode != current) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode != NULL) {
        *prev = *prevNode;
        return true;
    } else {
        return false;
    }
}

bool next(LinkedList* linkedList, Node* current, Node* next) {
    Node* currNode = linkedList->head;

    while (currNode != NULL && currNode != current) {
        currNode = currNode->next;
    }

    Node* nextNode = currNode->next;
    if (currNode != NULL && nextNode != NULL) {
        *next = *nextNode;
        return true;
    } else {
        return false;
    }
}

bool insert(LinkedList* linkedList, int index, ElemType e) {
    if (index < 0 || index > linkedList->length) {
        return false;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }
    newNode->data = e;

    if (index == 0) {
        newNode->next = linkedList->head;
        linkedList->head = newNode;
    } else {
        Node* prev = NULL;
        bool condition = get(linkedList, index - 1, &prev);
        if (condition) {
            newNode->next = prev->next;
            prev->next = newNode;
        } else {
            return false;
        }
    }
    
    linkedList->length++;
    return true;
}

bool delete(LinkedList* linkedList, int index, ElemType* e) {
    if (index < 0 || index >= linkedList->length) {
        return false;
    }
    
    Node* deletedNode;
    if (index == 0) {
        deletedNode = linkedList->head;
        linkedList->head = deletedNode->next;
    } else {
        Node* prevNode = NULL;
        if (get(linkedList, index - 1, &prevNode)) {
            deletedNode = prevNode->next;
            prevNode->next = deletedNode->next;
        } else {
            return false;
        }
    }

    *e = deletedNode->data;
    free(deletedNode);
    linkedList->length--;
    return true;
}

int main() {
    LinkedList list;
    initList(&list);

    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 2, 30);    // List now has the values [10, 20, 30]

    Node* e;

    if(get(&list, 1, &e)) {
      printf("Element at index 1: %d\n", e->data);
    }

    int loc = locate(&list, 20);
    printf("Index of 20: %d\n", loc);

    Node prevNode;
    Node* currNode = NULL;
    get(&list, 2, &currNode);
    if (prev(&list, currNode, &prevNode)) {
      printf("prev to 30 is: %d.\n", prevNode.data);
    }

    ElemType data;
    if(delete(&list, 1, &data )) {
      printf("Deleted item with data: %d", data);  // Should be 20
    }
    printf("\nNew length: %d\n", length(&list));

    destroyList(&list);

    return 0;
}