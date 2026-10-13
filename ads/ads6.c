/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 06
DATE: 14-08-2026

**********Queue Using Linkedlist**********

AIM: Implementation of queue using linkedlist.
*/

/* **********ALGORITHM*********
Step 1: Start.
Step 2: Initialize "front = NULL" and "rear = NULL".
Step 3: Display the menu containing Enqueue, Dequeue, Peek, Display, and Exit.
Step 4: Read the user's choice.
Step 5: If Enqueue is selected, allocate memory for a new node, read the element, and set its "next" pointer to "NULL".
Step 6: If the queue is empty, assign the new node to both "front" and "rear". Otherwise, link the new node after "rear" and update "rear".
Step 7: If Dequeue is selected, check whether "front == NULL". If true, display Underflow. Otherwise, remove the front node, update "front", and free the removed node. If the queue becomes empty, set "rear = NULL".
Step 8: If Peek is selected, check whether the queue is empty. If empty, display Queue is empty. Otherwise, display the element at "front".
Step 9: If Display is selected, traverse the queue from "front" to "NULL" and display each element.
Step 10: If an invalid choice is entered, display Invalid option.
Step 11: Repeat Steps 3 to 10 until the user selects Exit.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted successfully\n");
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue elements: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\nSelect an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid option\n");
        }

    } while (choice != 5);

    while (front != NULL)
    {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;

    return 0;
}

/* **********OUTPUT**********

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value: 20
Element inserted successfully

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value: 30
Element inserted successfully

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value: 40
Element inserted successfully

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 20 30 40

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 3
Front element: 20

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 20

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 30 40

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 30

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 40

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Underflow

Select an operation:
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 5
Exiting program

*/
