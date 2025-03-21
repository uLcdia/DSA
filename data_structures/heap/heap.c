#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Define the element type. Must be comparable.
typedef int ElemType;

// Define heap types
typedef enum {
    MIN_HEAP,
    MAX_HEAP
} HeapType;

// Structure to represent the heap
typedef struct {
    ElemType* data;     // Array to store the heap elements
    int size;           // Current number of elements in the heap
    int capacity;       // Maximum capacity of the heap
    HeapType type;      // Type of heap (MIN or MAX)
} Heap;

// Function prototypes
Heap* createHeap(int capacity, HeapType type);
void destroyHeap(Heap* heap);
bool isEmpty(const Heap* heap);
bool isFull(const Heap* heap);
int size(const Heap* heap);
bool insert(Heap* heap, ElemType value);
bool extractTop(Heap* heap, ElemType* value);
bool extract(Heap* heap, ElemType* value, int index);
bool peekTop(const Heap* heap, ElemType* value);
void printHeap(const Heap* heap);

// Helper function prototypes
static void heapifyUp(Heap* heap, int index);
static void heapifyDown(Heap* heap, int index);
static void swap(ElemType* a, ElemType* b);
static int parent(int index);
static int leftChild(int index);
static int rightChild(int index);
static bool compareElements(HeapType type, ElemType a, ElemType b);

// Create a new heap
Heap* createHeap(int capacity, HeapType type) {
    if (capacity <= 0) {
        fprintf(stderr, "Error: Capacity must be positive.\n");
        return NULL;
    }

    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL) {
        perror("Error: Memory allocation failed (heap struct)");
        return NULL;
    }

    heap->data = (ElemType*)malloc(capacity * sizeof(ElemType));
    if (heap->data == NULL) {
        perror("Error: Memory allocation failed (data array)");
        free(heap);
        return NULL;
    }

    heap->capacity = capacity;
    heap->size = 0;
    heap->type = type;
    return heap;
}

// Destroy the heap and free memory
void destroyHeap(Heap* heap) {
    if (heap != NULL) {
        free(heap->data);
        free(heap);
    }
}

// Check if the heap is empty
bool isEmpty(const Heap* heap) {
    return heap == NULL || heap->size == 0;
}

// Check if the heap is full
bool isFull(const Heap* heap) {
    return heap != NULL && heap->size >= heap->capacity;
}

// Get the current size of the heap
int size(const Heap* heap) {
    return heap != NULL ? heap->size : 0;
}

// Helper function to compare elements based on heap type
static bool compareElements(HeapType type, ElemType a, ElemType b) {
    return (type == MIN_HEAP) ? (a < b) : (a > b);
}

// Helper functions to get parent and child indices
static int parent(int index) { return (index - 1) / 2; }
static int leftChild(int index) { return 2 * index + 1; }
static int rightChild(int index) { return 2 * index + 2; }

// Helper function to swap two elements
static void swap(ElemType* a, ElemType* b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to maintain heap property upward
static void heapifyUp(Heap* heap, int index) {
    while (index > 0) {
        int p = parent(index);
        if (compareElements(heap->type, heap->data[index], heap->data[p])) {
            swap(&heap->data[index], &heap->data[p]);
            index = p;
        } else {
            break;
        }
    }
}

// Helper function to maintain heap property downward
static void heapifyDown(Heap* heap, int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && 
        compareElements(heap->type, heap->data[left], heap->data[smallest])) {
        smallest = left;
    }

    if (right < heap->size && 
        compareElements(heap->type, heap->data[right], heap->data[smallest])) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert a new element into the heap
bool insert(Heap* heap, ElemType value) {
    if (heap == NULL || isFull(heap)) {
        return false;
    }

    heap->data[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
    return true;
}

// Extract the top element from the heap
bool extractTop(Heap* heap, ElemType* value) {
    if (isEmpty(heap)) {
        return false;
    }

    *value = heap->data[0];
    heap->size--;
    if (heap->size > 0) {
        heap->data[0] = heap->data[heap->size];
        heapifyDown(heap, 0);
    }
    return true;
}

bool extract(Heap* heap, ElemType* value, int index) {
    if (heap == NULL || index < 0 || index >= heap->size) {
        return false;
    }

    *value = heap->data[index];
    heap->data[index] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, index);
    return true;
}

// Peek at the top element without removing it
bool peekTop(const Heap* heap, ElemType* value) {
    if (isEmpty(heap)) {
        return false;
    }
    *value = heap->data[0];
    return true;
}

// Print the heap elements
void printHeap(const Heap* heap) {
    if (heap == NULL) {
        printf("Heap: (NULL)\n");
        return;
    }

    printf("Heap (%s): [", heap->type == MIN_HEAP ? "MIN" : "MAX");
    for (int i = 0; i < heap->size; i++) {
        printf("%d", heap->data[i]);
        if (i < heap->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Size: %d, Capacity: %d\n", heap->size, heap->capacity);
}

// Example usage
int main() {
    // Create a min heap
    Heap* minHeap = createHeap(10, MIN_HEAP);
    assert(minHeap != NULL);
    assert(isEmpty(minHeap));

    // Insert some elements
    insert(minHeap, 5);
    insert(minHeap, 3);
    insert(minHeap, 7);
    insert(minHeap, 1);
    insert(minHeap, 4);

    printf("After inserting elements:\n");
    printHeap(minHeap);

    // Extract minimum elements
    ElemType value;
    while (extractTop(minHeap, &value)) {
        printf("Extracted: %d\n", value);
    }

    // Create a max heap
    Heap* maxHeap = createHeap(10, MAX_HEAP);
    assert(maxHeap != NULL);

    // Insert same elements
    insert(maxHeap, 5);
    insert(maxHeap, 3);
    insert(maxHeap, 7);
    insert(maxHeap, 1);
    insert(maxHeap, 4);

    printf("\nMax Heap after inserting elements:\n");
    printHeap(maxHeap);

    // Extract maximum elements
    while (extractTop(maxHeap, &value)) {
        printf("Extracted: %d\n", value);
    }

    // Clean up
    destroyHeap(minHeap);
    destroyHeap(maxHeap);
    printf("Heaps destroyed\n");

    return 0;
}