/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 02
DATE: 28-09-2026

*********Queues  Using  Arrays**********

AIM: Implementation  of  queues  using  arrays.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize "front = -1" and "rear = -1", and declare integer variables "size", "choice", and "value".
Step 3: Read the size of the queue and create an array "queue" of the given size.
Step 4: Initialize a variable "running" to "1".
Step 5: Display the menu with options Enqueue, Dequeue, Peek, Display, and Exit.
Step 6: Read the user's choice.
Step 7: If the choice is Enqueue, read the value to be inserted and check whether "rear == size - 1".
Step 8: If the queue is full, display Overflow. Otherwise, if the queue is empty, set "front = rear = 0" and insert the value into "queue[rear]". If the queue is not empty, increment "rear" and insert the value.
Step 9: If the choice is Dequeue, check whether "front == -1". If true, display Underflow. Otherwise, display the deleted value. If "front == rear", set "front = rear = -1". Otherwise, increment "front".
Step 10: If the choice is Peek, check whether "front == -1". If true, display Queue is Empty. Otherwise, display "queue[front]" as the front value.
Step 11: If the choice is Display, check whether "front == -1". If true, display Queue is Empty. Otherwise, display all elements from "front" to "rear".
Step 12: If the choice is Exit, set "running" to "0". If an invalid choice is entered, display Invalid Option.
Step 13: Repeat Steps 5 to 12 while "running" is "1".
Step 14: Stop.

*/

/* **********SOURCE CODE********** */


#include <stdio.h>

int front = -1, rear = -1;

void enqueue(int queue[], int size, int value)
{
    if (rear == size - 1)
    {
        printf("Overflow: Queue is full");
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = value;
        printf("Value inserted successfully");
    }
    else
    {
        rear++;
        queue[rear] = value;
        printf("Value inserted successfully");
    }
}

void dequeue(int queue[])
{
    if (front == -1)
    {
        printf("Underflow: Queue is empty");
    }
    else
    {
        printf("Deleted value: %d", queue[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void peek(int queue[])
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Front value: %d", queue[front]);
    }
}

void display(int queue[])
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int size, value, choice;
    int running = 1;

    printf("Enter the size of queue: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid queue size");
        return 0;
    }

    int queue[size];

    while (running)
    {
        printf("\n\nSelect the operation:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, size, value);
                break;

            case 2:
                dequeue(queue);
                break;

            case 3:
                peek(queue);
                break;

            case 4:
                display(queue);
                break;

            case 5:
                running = 0;
                break;

            default:
                printf("Invalid Option");
        }
    }

    return 0;
}


/* **********OUTPUT**********


Enter the size of queue: 3

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 10
Value inserted successfully

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 20
Value inserted successfully

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 30
Value inserted successfully

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 10 20 30

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 3
Front value: 10

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted value: 10

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 20 30

Select the operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 5

*/     