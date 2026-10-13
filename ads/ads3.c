/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 03
DATE: 30-07-2026

**********Circular  Queue  Using  Arrays.**********

AIM: Implementation of circular queue using arrays.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize "front = -1" and "rear = -1", and declare an array "queue" of size "SIZE".
Step 3: Display the menu with Enqueue, Dequeue, Display, and Exit options.
Step 4: Read the user's choice.
Step 5: If Enqueue is selected, read the value to be inserted and check whether "(rear + 1) % SIZE == front".
Step 6: If the circular queue is full, display Queue is Full. Otherwise, if the queue is empty, set "front = 0". Increment "rear" circularly using "(rear + 1) % SIZE" and insert the value into "queue[rear]".
Step 7: If Dequeue is selected, check whether "front == -1". If true, display Queue is Empty. Otherwise, display the front element. If "front == rear", set "front = rear = -1". Otherwise, increment "front" circularly using "(front + 1) % SIZE".
Step 8: If Display is selected, check whether the queue is empty. If true, display Queue is Empty. Otherwise, display all elements from "front" to "rear", moving circularly through the array.
Step 9: If Exit is selected, terminate the program.
Step 10: If an invalid choice is entered, display Invalid Choice.
Step 11: Repeat Steps 3 to 10 until the user selects Exit.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */
#
#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int item)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Circular queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = item;

        printf("Element inserted successfully\n");
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Circular queue is empty\n");
    }
    else
    {
        printf("Removed element: %d\n", queue[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    int index;

    if (front == -1)
    {
        printf("Circular queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        index = front;

        while (index != rear)
        {
            printf("%d ", queue[index]);
            index = (index + 1) % SIZE;
        }

        printf("%d\n", queue[rear]);
    }
}

int main()
{
    int choice, item;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}

/* **********OUTPUT**********


1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 20
Element inserted successfully

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 40
Element inserted successfully

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 50
Element inserted successfully

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 20 40 50

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Removed element: 20

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 40 50

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Program terminated


*/     