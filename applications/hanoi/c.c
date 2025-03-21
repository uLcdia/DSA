#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>  // For uint32_t

// Structure to represent a tower (stack)
typedef struct {
    uint32_t *disks;
    int top;
    int capacity;
} Tower;

// Function to create a new tower
Tower *create_tower(int capacity) {
    Tower *tower = (Tower *)malloc(sizeof(Tower));
    tower->capacity = capacity;
    tower->top = -1;  // Initialize top to -1 (empty stack)
    tower->disks = (uint32_t *)malloc(capacity * sizeof(uint32_t));
    return tower;
}

// Function to push a disk onto a tower
void push(Tower *tower, uint32_t disk) {
    if (tower->top == tower->capacity - 1) {
        fprintf(stderr, "Error: Stack overflow!\n");
        exit(EXIT_FAILURE); // Or handle the error appropriately
    }
    tower->disks[++tower->top] = disk;
}

// Function to pop a disk from a tower
uint32_t pop(Tower *tower) {
    if (tower->top == -1) {
        fprintf(stderr, "Error: Stack underflow!\n");
        exit(EXIT_FAILURE); // Or handle the error appropriately
    }
    return tower->disks[tower->top--];
}

// Function to move a disk from one tower to another
void move_disk(Tower *source, Tower *destination) {
    uint32_t disk = pop(source);
    push(destination, disk);
}


// Recursive function to solve the Towers of Hanoi puzzle
void hanoi(int num_disks, Tower *source, Tower *auxiliary, Tower *destination) {
    if (num_disks == 1) {
        move_disk(source, destination);
    } else {
        hanoi(num_disks - 1, source, destination, auxiliary);
        move_disk(source, destination);
        hanoi(num_disks - 1, auxiliary, source, destination);
    }
}

// Function to initialize the source tower
void initialize_tower(Tower *tower, int num_disks) {
    for (int i = num_disks; i >= 1; i--) {
        push(tower, i);
    }
}

// Function to free the memory allocated for a tower
void free_tower(Tower *tower) {
    free(tower->disks);
    free(tower);
}

int main() {
    int num_disks = 32;

    // Create the towers
    Tower *source = create_tower(num_disks);
    Tower *auxiliary = create_tower(num_disks);
    Tower *destination = create_tower(num_disks);

    // Initialize the source tower
    initialize_tower(source, num_disks);

    // Solve the Towers of Hanoi puzzle
    hanoi(num_disks, source, auxiliary, destination);

    // Verification (optional, but highly recommended for debugging)
    assert(source->top == -1);       // Source tower should be empty
    assert(auxiliary->top == -1);    // Auxiliary tower should be empty
    assert(destination->top == num_disks - 1); // Destination should have all disks

    for (int i = 0; i < num_disks; ++i) {
        assert(destination->disks[i] == (uint32_t)(num_disks - i));
    }

    // Free the allocated memory
    free_tower(source);
    free_tower(auxiliary);
    free_tower(destination);

    return 0;
}