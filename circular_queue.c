#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;

int isEmpty() {
    return count == 0;
}

int isFull() {
    return count == MAX;
}

int size() {
    return count;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;

    printf("%d inserted\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("%d deleted\n", queue[front]);
    front = (front + 1) % MAX;
    count--;
}

void display() {
    int i, index;

    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    for (i = 0; i < count; i++) {
        index = (front + i) % MAX;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Is Empty");
        printf("\n4. Is Full");
        printf("\n5. Size");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf(isEmpty() ? "Queue is Empty\n" : "Queue is Not Empty\n");
                break;

            case 4:
                printf(isFull() ? "Queue is Full\n" : "Queue is Not Full\n");
                break;

            case 5:
                printf("Size = %d\n", size());
                break;

            case 6:
                display();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}