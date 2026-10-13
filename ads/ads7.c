/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 07
DATE: 20-08-2026

**********Doubly Linkedlist**********

AIM: Implementation of doubly linkedlist.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize "head = NULL" and define a doubly linked list node containing "data", "prev", and "next".
Step 3: Display the menu with Insert at Beginning, Insert at End, Insert After a Value, Delete, Display, and Exit options.
Step 4: Read the user's choice.
Step 5: If Insert at Beginning is selected, create a new node, connect it before the current head, and update "head".
Step 6: If Insert at End is selected, create a new node. If the list is empty, make it the head. Otherwise, traverse to the last node and attach the new node.
Step 7: If Insert After a Value is selected, read the new value and the existing value after which it should be inserted. Search for that value and update the links to insert the new node.
Step 8: If Delete is selected, read the value to delete and search for the node. If found, update the surrounding links and free its memory. Otherwise, display an appropriate message.
Step 9: If Display is selected, traverse the list from "head" to "NULL" and print all elements.
Step 10: If an invalid choice is entered, display Invalid choice.
Step 11: Repeat Steps 3 to 10 until the user selects Exit.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertBeginning(int value)
{
    Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("Inserted %d at the beginning\n", value);
}

void insertEnd(int value)
{
    Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Inserted %d at the end\n", value);
}

void insertAfter(int value, int key)
{
    Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value %d not found\n", key);
        return;
    }

    Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Inserted %d after %d\n", value, key);
}

void deleteNode(int value)
{
    Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Element %d not found\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Deleted %d successfully\n", value);
}

void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, value, key;

    do
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Value\n");
        printf("4. Delete a Node\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1)
                    insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1)
                    insertEnd(value);
                break;

            case 3:
                printf("Enter new value: ");
                if (scanf("%d", &value) != 1)
                    break;

                printf("Insert after which value? ");
                if (scanf("%d", &key) == 1)
                    insertAfter(value, key);
                break;

            case 4:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) == 1)
                    deleteNode(value);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/* **********OUTPUT**********

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 1
Enter value: 20
Inserted 20 at the beginning

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 2
Enter value: 30
Inserted 30 at the end

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 2
Enter value: 40
Inserted 40 at the end

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 3
Enter new value: 25
Insert after which value? 20
Inserted 25 after 20

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 5
Linked List: 20 -> 25 -> 30 -> 40 -> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 4
Enter value to delete: 30
Deleted 30 successfully

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 5
Linked List: 20 -> 25 -> 40 -> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 6
Exiting program

*/