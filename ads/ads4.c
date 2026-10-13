/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 04
DATE: 05-08-2026

**********Linkedlists Operations**********

AIM: Implementation of linkedlists and operations on linkedlists.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize "head = NULL" and declare the required pointer and integer variables.
Step 3: Create a linked list by allocating memory for each node and reading data from the user.
Step 4: Set the "next" pointer of each new node to "NULL" and link it to the previous node.
Step 5: Repeat Step 3 and Step 4 until the user chooses to stop creating nodes.
Step 6: Display the linked list and the total number of nodes.
Step 7: Display the menu with options for insertion, deletion, and Quit.
Step 8: Read the user's choice.
Step 9: If insertion at beginning is selected, create a new node, link it to the current head, and update "head".
Step 10: If insertion in between is selected, read the position, locate the required node, and insert the new node at that position.
Step 11: If insertion at end is selected, create a new node and link it to the last node.
Step 12: If deletion at beginning is selected, remove the first node, update "head", and free the deleted node's memory.
Step 13: If deletion in between is selected, read the position, locate the node, unlink it, and free its memory.
Step 14: If deletion at end is selected, locate the last node, unlink it, and free its memory.
Step 15: Update the node count after a successful insertion or deletion.
Step 16: Display the updated linked list and the total number of nodes after each operation.
Step 17: If an invalid choice is entered, display Invalid Option.
Step 18: Repeat Steps 7 to 17 until the user selects Quit.
Step 19: Stop.

*/

/* **********SOURCE CODE********** */


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode()
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter the number: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    return newNode;
}

void printList()
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int createList()
{
    struct node *newNode, *current;
    int choice, count = 0;

    do
    {
        newNode = createNode();

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            current = head;

            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
        }

        count++;

        printf("Enter data again (1/0): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return count;
}

void insertBeginning()
{
    struct node *newNode = createNode();

    newNode->next = head;
    head = newNode;
}

int insertBetween(int count)
{
    struct node *newNode, *current;
    int pos, i;

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > count)
    {
        printf("Invalid position\n");
        return 0;
    }

    if (pos == 0)
    {
        insertBeginning();
        return 1;
    }

    newNode = createNode();
    current = head;

    for (i = 1; i < pos; i++)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return 1;
}

void insertEnd()
{
    struct node *newNode = createNode();
    struct node *current;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

int deleteBeginning()
{
    struct node *current;

    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    current = head;
    head = head->next;
    free(current);

    return 1;
}

int deleteBetween(int count)
{
    struct node *current, *deleted;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= count)
    {
        printf("Invalid position\n");
        return 0;
    }

    if (pos == 0)
    {
        return deleteBeginning();
    }

    current = head;

    for (i = 1; i < pos; i++)
    {
        current = current->next;
    }

    deleted = current->next;
    current->next = deleted->next;
    free(deleted);

    return 1;
}

int deleteEnd()
{
    struct node *current, *previous = NULL;

    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    current = head;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
    {
        head = NULL;
    }
    else
    {
        previous->next = NULL;
    }

    free(current);

    return 1;
}

int main()
{
    int choice, count, running = 1, changed;

    count = createList();

    printf("\nLinked list: ");
    printList();
    printf("Number of nodes: %d\n", count);

    while (running)
    {
        printf("\nChoose an operation:\n");
        printf("1. Insertion at beginning\n");
        printf("2. Insertion in between\n");
        printf("3. Insertion at end\n");
        printf("4. Deletion at beginning\n");
        printf("5. Deletion in between\n");
        printf("6. Deletion at end\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        changed = 0;

        switch (choice)
        {
            case 1:
                insertBeginning();
                count++;
                changed = 1;
                break;

            case 2:
                changed = insertBetween(count);
                if (changed)
                    count++;
                break;

            case 3:
                insertEnd();
                count++;
                changed = 1;
                break;

            case 4:
                changed = deleteBeginning();
                if (changed)
                    count--;
                break;

            case 5:
                changed = deleteBetween(count);
                if (changed)
                    count--;
                break;

            case 6:
                changed = deleteEnd();
                if (changed)
                    count--;
                break;

            case 7:
                running = 0;
                break;

            default:
                printf("Invalid option\n");
        }

        if (changed)
        {
            printf("Updated linked list: ");
            printList();
            printf("Number of nodes: %d\n", count);
        }
    }

    while (head != NULL)
    {
        struct node *current = head;
        head = head->next;
        free(current);
    }

    return 0;
}

/* **********OUTPUT**********


Enter the number: 10
Enter data again: (1/0): 1
Enter the number: 20
Enter data again: (1/0): 1
Enter the number: 30
Enter data again? (1/0): 0

Linked list: 10 -> 20 -> 30 -> NULL
Number of nodes: 3

Choose an operation:
1. Insertion at beginning
2. Insertion in between
3. Insertion at end
4. Deletion at beginning
5. Deletion in between
6. Deletion at end
7. Quit
Enter your choice: 1
Enter the number: 50
Updated linked list: 50 -> 10 -> 20 -> 30 -> NULL
Number of nodes: 4

Choose an operation:
1. Insertion at beginning
2. Insertion in between
3. Insertion at end
4. Deletion at beginning
5. Deletion in between
6. Deletion at end
7. Quit
Enter your choice: 2
Enter position to insert: 2
Enter the number: 15
Updated linked list: 50 -> 10 -> 15 -> 20 -> 30 -> NULL
Number of nodes: 5

Choose an operation:
1. Insertion at beginning
2. Insertion in between
3. Insertion at end
4. Deletion at beginning
5. Deletion in between
6. Deletion at end
7. Quit
Enter your choice: 3
Enter the number: 40
Updated linked list: 50 -> 10 -> 15 -> 20 -> 30 -> 40 -> NULL
Number of nodes: 6

Choose an operation:
1. Insertion at beginning
2. Insertion in between
3. Insertion at end
4. Deletion at beginning
5. Deletion in between
6. Deletion at end
7. Quit
Enter your choice: 4
Updated linked list: 10 -> 15 -> 20 -> 30 -> 40 -> NULL
Number of nodes: 5

Choose an operation:
1. Insertion at beginning
2. Insertion in between
3. Insertion at end
4. Deletion at beginning
5. Deletion in between
6. Deletion at end
7. Quit
Enter your choice: 5
Enter position to delete: 2
Updated linked list: 10 -> 15 -> 30 -> 40 -> NULL
Number of nodes: 4

Choose an operation:
1. Insertion at beginning
2. Insertion in between
3. Insertion at end
4. Deletion at beginning
5. Deletion in between
6. Deletion at end
7. Quit
Enter your choice: 6
Updated linked list: 10 -> 15 -> 30 -> NULL
Number of nodes: 3

Choose an operation:
1. Insertion at beginning
2. Insertion in between
3. Insertion at end
4. Deletion at beginning
5. Deletion in between
6. Deletion at end
7. Quit
Enter your choice: 7


*/