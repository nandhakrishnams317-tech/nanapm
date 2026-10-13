/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 17
DATE: 05-10-2026

**********Deque**********

AIM: Implementation of Deque(double ended  queue). 
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize the front and rear pointers to NULL.
Step 3: Display the menu containing Insert Front, Insert Rear, Delete Front, Delete Rear, Display, and Exit options.
Step 4: Read the user's choice.
Step 5: If the choice is 1, create a new node and insert it at the front of the deque.
Step 6: If the choice is 2, create a new node and insert it at the rear of the deque.
Step 7: If the choice is 3, check whether the deque is empty. If it is not empty, delete the front node and update the front pointer.
Step 8: If the choice is 4, check whether the deque is empty. If it is not empty, delete the rear node and update the rear pointer.
Step 9: If the choice is 5, display all elements from front to rear.
Step 10: If the choice is 6, display "Exiting..." and terminate the program.
Step 11: If the choice is invalid, display "Invalid choice".
Step 12: Repeat Steps 3 to 11 until the user selects 6.
Step 13: Stop.

/* **********SOURCE CODE********** */


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *prev, *next;
};

struct Node *start = NULL, *end = NULL;

void addFront(int value)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = start;

    if (start == NULL)
        start = end = newNode;
    else
    {
        start->prev = newNode;
        start = newNode;
    }

    printf("Inserted %d at the front.\n", value);
}

void addRear(int value)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = end;

    if (end == NULL)
        start = end = newNode;
    else
    {
        end->next = newNode;
        end = newNode;
    }

    printf("Inserted %d at the rear.\n", value);
}

void removeFront()
{
    struct Node *temp;

    if (start == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }

    temp = start;
    printf("Deleted front element: %d\n", temp->value);

    start = start->next;

    if (start == NULL)
        end = NULL;
    else
        start->prev = NULL;

    free(temp);
}

void removeRear()
{
    struct Node *temp;

    if (end == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }

    temp = end;
    printf("Deleted rear element: %d\n", temp->value);

    end = end->prev;

    if (end == NULL)
        start = NULL;
    else
        end->next = NULL;

    free(temp);
}

void showDeque()
{
    struct Node *temp = start;

    if (start == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");

    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, num;

    do
    {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &num);
                addFront(num);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &num);
                addRear(num);
                break;

            case 3:
                removeFront();
                break;

            case 4:
                removeRear();
                break;

            case 5:
                showDeque();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

/* **********OUTPUT**********

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 1
Enter value: 25
Inserted 25 at the front.

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 2
Enter value: 40
Inserted 40 at the rear.

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 2
Enter value: 60
Inserted 60 at the rear.

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 1
Enter value: 10
Inserted 10 at the front.

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 5
Deque elements: 10 25 40 60

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 3
Deleted front element: 10

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 4
Deleted rear element: 60

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 5
Deque elements: 25 40

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 6
Exiting...

*/    