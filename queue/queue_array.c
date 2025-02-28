// Queue based on static array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Define the element type.  You can change this to whatever you need.
typedef int ElemType;


typedef struct {
    ElemType *data;    // Pointer to the dynamically allocated array
    size_t front;        // Index of the front element
    size_t rear;         // Index of the rear element (where the next element will be added)
    size_t size;         // Current number of elements in the queue
    size_t capacity;     // Maximum capacity of the queue (size of the array)
} Queue;

// Function prototypes
Queue* createQueue(size_t capacity);
void destroyQueue(Queue* queue);
bool isEmpty(const Queue* queue);
bool isFull(const Queue* queue);
bool enqueue(Queue* queue, ElemType e);
bool dequeue(Queue* queue, ElemType *e);
bool peek(const Queue* queue, ElemType *e);
size_t size(const Queue* queue);
void printQueue(const Queue* queue);
bool resize(Queue* q, size_t new_capacity);

Queue* createQueue(size_t capacity) {
    if (capacity <= 0) {
        fprintf(stderr, "Error: Capacity must be positive.\n");
        return NULL;
    }
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if (queue == NULL) {
        perror("Error: Memory allocation failed (queue struct).");
        return NULL;
    }

    queue->data = (ElemType*) malloc(sizeof(ElemType) * capacity);
    if (queue->data == NULL) {
        perror("Error: Memory allocation failed (data array).");
        free(queue);
        return NULL;
    }

    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void destroyQueue(Queue* queue) {
    if (queue != NULL) {
        free(queue->data);
        free(queue);
    }
}

bool isEmpty(const Queue* queue) {
    if (queue == NULL) {
        return true;
    }
    return queue->size == 0;
}

bool isFull(const Queue* queue) {
    if (queue == NULL) {
        return false;
    }
    return queue->size >= queue->capacity;
}

bool enqueue(Queue* queue, ElemType e) {
    if (queue == NULL) {
        return false;
    }

    if (isFull(queue)) {
        if (!resize(queue, queue->capacity * 2)) {
            return false;
        }
    }

    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % queue->capacity; // Circular buffer
    queue->size++;
    return true;
}

bool dequeue(Queue* queue, ElemType* e) {
    if (queue == NULL || e == NULL) {
        return false;
    }
    if (isEmpty(queue)) {
        return false;
    }

    *e = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity; // Circular buffer
    queue->size--;
    return true;
}

bool peek(const Queue* queue, ElemType* e) {
    if (queue == NULL || e == NULL) {
        return false;
    }
    if (isEmpty(queue)) {
        return false;
    }

    *e = queue->data[queue->front];
    return true;
}

size_t size(const Queue* queue) {
    if (queue == NULL) {
        return 0;
    }
    return queue->size;
}

void printQueue(const Queue* queue) {
    if (queue == NULL) {
        printf("Queue: (NULL)\n");
        return;
    }
    printf("Queue: [");
    if (!isEmpty(queue)) {
        size_t i = queue->front;
        size_t count = 0;
        while (count < queue->size) {
            printf("%d", queue->data[i]);
            count++;
            if (count < queue->size) {
                printf(", ");
            }
            i = (i + 1) % queue->capacity;
        }
    }
    printf("]  (front=%zu, rear=%zu, size=%zu, capacity=%zu)\n", 
                queue->front, queue->rear, queue->size, queue->capacity);
}

bool resize(Queue* queue, size_t newCapacity) {
    if (queue == NULL || newCapacity <= queue->size) {
        return false;
    }

    // Don't use realloc, it preserves the physical structure
    ElemType* newData = (ElemType*) malloc(sizeof(ElemType) * newCapacity);
    if (newData == NULL) {
        perror("Error: Memory allocation failed (resize)");
        return false;
    }

    // Copy elements to new array, handling wrap-around
    size_t j = 0;
    size_t i = queue->front;
    for (size_t count = 0; count < queue->size; count++) {
        newData[j] = queue->data[i];
        i = (i + 1) % queue->capacity;
        j++;
    }

    free(queue->data);
    queue->data = newData;
    queue->front = 0;
    queue->rear = queue->size;
    queue->capacity = newCapacity;
    return true;
}

int main() {
    // Test queue creation
    Queue* q = createQueue(5);
    assert(q != NULL);
    assert(isEmpty(q));
    assert(!isFull(q));
    assert(size(q) == 0);

    // Test enqueue
    assert(enqueue(q, 10));
    assert(enqueue(q, 20));
    assert(enqueue(q, 30));
    assert(!isEmpty(q));
    assert(size(q) == 3);

    // Test peek
    ElemType value;
    assert(peek(q, &value));
    assert(value == 10);
    assert(size(q) == 3);  // Peek shouldn't change size

    // Test dequeue
    assert(dequeue(q, &value));
    assert(value == 10);
    assert(size(q) == 2);

    assert(dequeue(q, &value));
    assert(value == 20);
    assert(size(q) == 1);

    // Test circular buffer behavior
    assert(enqueue(q, 40));
    assert(enqueue(q, 50));
    assert(enqueue(q, 60));  // Should NOT trigger resize
    assert(q->capacity == 5);  // Capacity should remain the same

    // Test dequeue until empty
    assert(dequeue(q, &value));
    assert(value == 30);
    assert(dequeue(q, &value));
    assert(value == 40);
    assert(dequeue(q, &value));
    assert(value == 50);
    assert(dequeue(q, &value));
    assert(value == 60);
    assert(isEmpty(q));

    // Test dequeue from empty queue
    assert(!dequeue(q, &value));

    // Clean up
    destroyQueue(q);
    printf("All tests passed!\n");
    return 0;
}
