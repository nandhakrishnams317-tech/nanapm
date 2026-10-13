/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 18
DATE: 06-10-2026

**********Priority Queue********** 
AIM: Implementation of Priority Queue.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a structure containing the value and priority of each element. Initialize the priority queue size to zero.
Step 3: Define a swap function to exchange two elements.
Step 4: Define a function to compare two elements. The element with higher priority is preferred. If priorities are equal, the element with the larger value is preferred.
Step 5: Implement the ENQUEUE operation. Read the value and priority, insert the element at the end of the heap, and compare it with its parent. Swap elements until the heap property is satisfied.
Step 6: Implement the DEQUEUE operation. If the queue is empty, display an underflow message. Otherwise, delete the root element, replace it with the last element, and restore the heap property.
Step 7: Implement the DISPLAY operation. If the queue is empty, display a message. Otherwise, display the value and priority of every element.
Step 8: Display the menu and read the user's choice.
Step 9: If the choice is 1, insert an element into the priority queue.
Step 10: If the choice is 2, delete the highest-priority element.
Step 11: If the choice is 3, display the priority queue.
Step 12: If the choice is 4, terminate the program.
Step 13: If the choice is invalid, display an error message.
Step 14: Repeat the menu operations until the user selects Exit.
Step 15: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#define MAX 100

struct Item {
    int value;
    int priority;
};

struct Item queue[MAX];
int count = 0;

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int higherPriority(struct Item a, struct Item b) {
    if (a.priority == b.priority)
        return a.value > b.value;

    return a.priority > b.priority;
}

void enqueue(int value, int priority) {
    if (count == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    int i = count;

    queue[i].value = value;
    queue[i].priority = priority;
    count++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (higherPriority(queue[i], queue[parent])) {
            swap(&queue[i], &queue[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void dequeue() {
    if (count == 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }

    printf("Removed value: %d\n", queue[0].value);

    queue[0] = queue[count - 1];
    count--;

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < count &&
            higherPriority(queue[left], queue[largest])) {
            largest = left;
        }

        if (right < count &&
            higherPriority(queue[right], queue[largest])) {
            largest = right;
        }

        if (largest != i) {
            swap(&queue[i], &queue[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void display() {
    if (count == 0) {
        printf("No elements in the queue!\n");
        return;
    }

    printf("Value\tPriority\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%d\n", queue[i].value, queue[i].priority);
    }
}

int main() {
    int choice, num, pri;

    while (1) {
        printf("\n1. Insert\n2. Delete\n");
        printf("3. Display\n4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");

                if (scanf("%d %d", &num, &pri) != 2)
                    return 0;

                enqueue(num, pri);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}

/* **********OUTPUT**********

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 35 2

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 60 5

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 25 3

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 45 4

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Value   Priority
60      5
45      4
25      3
35      2

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 2
Deleted element: 60

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Value   Priority
45      4
35      2
25      3

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 4

*/    