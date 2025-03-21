// Queue based on linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // For using bool type

// Define the data type stored in the queue.  Change this as needed.
typedef int ElemType;

// Node structure for the linked list
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

// Queue structure
typedef struct Queue {
    Node *front;
    Node *rear;
    int size; // Optional: keep track of the number of elements
} Queue;


// Function prototypes
Queue *createQueue();
void enqueue(Queue *q, ElemType data);
ElemType dequeue(Queue *q);
ElemType peek(Queue *q);
bool isEmpty(Queue *q);
void printQueue(Queue *q);
void freeQueue(Queue *q);  //Important: Free the allocated memory
int queueSize(Queue *q);  // Return the size of the queue

// --- Function implementations ---

// Create an empty queue.
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed for Queue\n");
        exit(EXIT_FAILURE); // Or handle the error appropriately
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Add an element to the rear of the queue.
void enqueue(Queue *q, ElemType data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        exit(EXIT_FAILURE); // Or handle the error appropriately
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Remove and return the element at the front of the queue.
ElemType dequeue(Queue *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Error: Attempted to dequeue from an empty queue.\n");
        exit(EXIT_FAILURE); // Or handle the error (e.g., return a special value)
    }

    Node *temp = q->front;
    ElemType data = temp->data;
    q->front = q->front->next;

    // If the queue becomes empty after dequeueing, update rear as well.
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); // Free the memory of the dequeued node
    q->size--;
    return data;
}

// Return the element at the front of the queue without removing it.
ElemType peek(Queue *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Error: Attempted to peek into an empty queue.\n");
        exit(EXIT_FAILURE); // Or handle the error
    }
    return q->front->data;
}

// Check if the queue is empty.
bool isEmpty(Queue *q) {
    return (q->front == NULL);
}

// Print the elements of the queue (for debugging).
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    Node *current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the memory allocated for the queue.
void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);  // dequeue frees the node memory
    }
    free(q);  // Free the queue structure itself
}

// Return the number of elements in the queue
int queueSize(Queue *q) {
    return q->size;
}


int main() {
    Queue *myQueue = createQueue();

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    printQueue(myQueue); // Output: Queue: 10 20 30
    printf("Size: %d\n", queueSize(myQueue)); // Output: Size: 3

    ElemType firstElement = dequeue(myQueue);
    printf("Dequeued element: %d\n", firstElement); // Output: Dequeued element: 10
    printQueue(myQueue); // Output: Queue: 20 30
    printf("Size: %d\n", queueSize(myQueue));  // Output: Size: 2

    ElemType frontElement = peek(myQueue);
    printf("Front element: %d\n", frontElement); // Output: Front element: 20
    printQueue(myQueue); // Output: Queue: 20 30

    dequeue(myQueue);
    dequeue(myQueue);
    printQueue(myQueue); // Output: Queue is empty.

    // Test error handling (attempt to dequeue from empty queue)
    // dequeue(myQueue); // Uncomment to test error handling

    // Test enqueue after emptying
    enqueue(myQueue, 40);
    printQueue(myQueue); //Output: Queue: 40

    freeQueue(myQueue); // Free the memory
    return 0;
}