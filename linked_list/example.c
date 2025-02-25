#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the element type for simplicity
typedef int ElemType;

// Define the structure for a node in the linked list
typedef struct Node {
    ElemType data;          // Data stored in the node
    struct Node *next;      // Pointer to the next node in the list
} Node;

/**
 * Structure to represent the linked list.  It tracks the head node and length
 */
typedef struct {
    Node *head; // Pointer to the fist node
    int length; // Number of elements in the list
} LinkedList;

/**
 * Initializes an empty linked list.
 * @param list Pointer to the LinkedList to be initialized.
 */
void initList(LinkedList *list) {
    list->head = NULL;
    list->length = 0;
}

/**
 * Destroys the linked list and frees all allocated memory.
 * @param list Pointer to the LinkedList to be destroyed.
 */
void destroyList(LinkedList *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->length = 0;
}

/**
 * Clears the linked list, removing all elements but keeping the list alive.
 * @param list Pointer to the LinkedList to be cleared.
 */
void clearList(LinkedList *list) {
    destroyList(list);  // Reuse destroyList to remove all elements.
    initList(list);     // Reinitialize to create a new empty list.
}

/**
 * Checks if the linked list is empty.
 * @param list Pointer to the LinkedList to check.
 * @return true if the list is empty, false otherwise.
 */
bool isEmpty(LinkedList *list) {
    return list->head == NULL;
}

/**
 * Gets the number of nodes in the linkded list.
 * @param list A pointer to the LinkedList to get.
 * @return The length of the linked list.
 */
int length(LinkedList *list) {
    return list->length;
}

/**
 * Gets the data for a node at the given index.
 * @param list The linked list to get from.
 * @param index the index of the node.
 * @param e A pointer to write data for the node, if found.
 * @return true, if found; othewise false.
 */
bool get(LinkedList *list, int index, ElemType *e) {
  if (index < 0 || index >= list->length) {
    return false; // Invalid index
  }

  Node *current = list->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }

  if (current != NULL) {
    *e = current->data;
    return true;
  } else {
    return false; // Should not happen if length is maintained correctly
  }
}

/**
 * Locate an element in the list by value.
 * @param list Pointer to the LinkedList.
 * @param e The element to locate.
 * @return The index of the first occurrence of the element, or -1 if not found.
 */
int locate(LinkedList *list, ElemType e) {
  int index = 0;
  Node *current = list->head;
  while (current != NULL) {
    if (current->data == e) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1; // Not found
}

/**
 * Get the previous element of a given element in the list.
 * @param list Pointer to the LinkedList.
 * @param current Element whose predecessor is to be found.
 * @param prev Pointer where the predecessor's value will be stored.
 * @return true if the predecessor was found, false otherwise.
 */
bool prev(LinkedList *list, ElemType current, ElemType *prev) {
  if (list->head == NULL || list->head->data == current) {
    return false; // No prev element (empty list or first element)
  }

  Node *prior = NULL;
  Node *curr = list->head;

  while (curr != NULL && curr->data != current) {
    prior = curr;
    curr = curr->next;
  }

  if (curr == NULL) {
    return false; // Element not found
  }

  *prev = prior->data;
  return true;
}

/**
  * Get the next element of a given element in the list.
  * @param list Pointer to the LinkedList.
  * @param current Element whose successor is to be found.
  * @param next Pointer where the successor's value will be stored.
  * @return true if the successor was found, false otherwise.
  */
bool next(LinkedList *list, ElemType current, ElemType *next) {
  Node *curr = list->head;

  while (curr != NULL && curr->data != current) {
    curr = curr->next;
  }

  if (curr == NULL || curr->next == NULL) {
    return false; // Element not found or no next element
  }

  *next = curr->next->data;
  return true;
}


/**
 * Inserts a new node with the given element at the specified index.
 * @param list Pointer to the LinkedList.
 * @param index The index at which to insert the element (0-based).
 * @param e   The data element to insert.
 * @return true if insertion was successful, false otherwise.
 */
bool insert(LinkedList *list, int index, ElemType e) {
    if (index < 0 || index > list->length) {
        return false; // Invalid index
    }

    Node *newNode = (Node *)malloc(sizeof(Node));  // Allocate memory for the new node.
    if (newNode == NULL) {
        return false; // Memory allocation failed.
    }
    newNode->data = e;  // Set the element to the new node's data;

    if (index == 0) {  // Insert at the beginning of the list
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;  // Set the new node to point to the node current would other wise point to next
        current->next = newNode;        // Set current to point to the new node
    }

    list->length++;
    return true;
}

/**
 * Deletes a node based on the index
 * @param list Pointer to the LinkedList.
 * @param index The index  of the node to delete.
 * @param e A pointer to the data value for the deleted node.
 * @return true, if deleted.  False, if the index is out of bound or not found.
*/
bool delete(LinkedList *list, int index, ElemType *e) {
    if (index < 0 || index >= list->length) {
        return false; // Invalid index
    }

    Node *deletedNode;

    if (index == 0) {
        // Deleting the head node
        deletedNode = list->head;
        list->head = list->head->next;
    } else {
        // Deleting a node in the middle or at the end
        Node *current = list->head;

        // Traverse to the Node before index
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        deletedNode = current->next;         // Delete the node `current` would otherwise be pointing to.
        current->next = deletedNode->next;    // Set `current` to point to the original `next` value for the delete node, skipping the delete node.
    }

    *e = deletedNode->data;  // Retrieve the data

    free(deletedNode);
    list->length--;

    return true;
}

// Example usage
int main() {
    LinkedList list;
    initList(&list);

    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 2, 30);    // List now has the values [10, 20, 30]

    ElemType e;

    if(get(&list, 1, &e)) {
      printf("Element at index 1: %d\n", e);
    }

    int loc = locate(&list, 20);
    printf("Index of 20: %d\n", loc);

    ElemType prev_val;
    if (prev(&list, 30, &prev_val)) {
      printf("prev to 30 is: %d.\n", prev_val);
    }

    if(delete(&list, 1, &e )) {
      printf("Deleted item with value: %d", e);  // Should be 20
    }
    printf("\nNew length: %d\n", length(&list));

    destroyList(&list);

    return 0;
}