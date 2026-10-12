/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 05
DATE: 23-07-2026

**********Stacks  Using  linkedlist**********

AIM: Implementation  of  stacks  using  linkedlist
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize "top = NULL" and declare a structure containing "data" and a pointer "next".
Step 3: Display the menu with Push, Pop, Peep, and Exit operations.
Step 4: Read the user's choice.
Step 5: If Push is selected, allocate memory for a new node and read the data from the user.
Step 6: Set the "next" pointer of the new node to "top" and update "top" to the new node.
Step 7: If Pop is selected, check whether "top == NULL". If true, display Underflow. Otherwise, display the top node's data, update "top" to the next node, and free the removed node's memory.
Step 8: If Peep is selected, check whether "top == NULL". If true, display Stack is Empty. Otherwise, display the data stored at "top".
Step 9: If Exit is selected, terminate the menu loop.
Step 10: If an invalid choice is entered, display Invalid Option.
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

struct node *top = NULL;

void push()
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = top;
    top = newNode;

    printf("Element pushed successfully\n");
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        temp = top;
        printf("Popped value: %d\n", temp->data);

        top = top->next;
        free(temp);
    }
}

void peep()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top value: %d\n", top->data);
    }
}

int main()
{
    int choice, running = 1;

    while (running)
    {
        printf("\nChoose the operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                running = 0;
                break;

            default:
                printf("Invalid Option\n");
        }
    }

    while (top != NULL)
    {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}


/* **********OUTPUT**********


Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 1
Enter the data: 10
Element pushed successfully

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 1
Enter the data: 20
Element pushed successfully

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 1
Enter the data: 30
Element pushed successfully

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 3
Top value: 30

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 2
Popped value: 30

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 3
Top value: 20

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 2
Popped value: 20

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 2
Popped value: 10

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 2
Underflow

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 3
Stack is empty

Choose the operation:
1. Push
2. Pop
3. Peep
4. Exit
Enter your choice: 4


*/    