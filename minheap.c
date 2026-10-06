#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Insert an element into the Min Heap
void insert(int value) {
    int i = size;
    heap[size++] = value;

    // Move the element upward
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        // Swap
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

// Delete the minimum element (root)
int deleteMin() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int min = heap[0];
    heap[0] = heap[--size];

    // Move the element downward
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        // Swap
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return min;
}

// Display the heap
void display() {
    printf("Min Heap: ");

    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    insert(5);
    insert(15);

    display();

    printf("Deleted minimum: %d\n", deleteMin());

    display();

    return 0;
}