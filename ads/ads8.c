/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 08
DATE: 26-08-2026

**********Circular Linkedlist**********

AIM: Implementation of circular linkedlist.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a doubly linked list node containing "data", "next", and "prev" fields.
Step 3: Initialize "head = NULL".
Step 4: Display the menu containing insertion at beginning, insertion at end, insertion after a value, deletion, display, and exit options.
Step 5: Read the user's choice.
Step 6: If insertion at beginning is selected, read the value and create a new node using "malloc()".
Step 7: If memory allocation fails, display an error message and return to the menu.
Step 8: If the list is empty, assign the new node to "head" and make its "next" and "prev" pointers point to itself.
Step 9: Otherwise, connect the new node between the last node and the current head, and update "head".
Step 10: If insertion at end is selected, read the value and create a new node.
Step 11: If the list is empty, assign the new node to "head". Otherwise, connect the new node between the last node and the head.
Step 12: If insertion after a value is selected, read the new value and the existing value after which it must be inserted.
Step 13: Traverse the circular linked list to search for the specified existing value.
Step 14: If the value is found, create a new node and update the "next" and "prev" pointers to insert it after that node. Otherwise, display a message indicating that the value was not found.
Step 15: If deletion is selected, read the value to be deleted and search for the corresponding node.
Step 16: If the list is empty or the value is not found, display an appropriate message.
Step 17: If the node is found, update its neighboring nodes' links and update "head" if the first node is deleted.
Step 18: If the deleted node is the only node, set "head = NULL". Free the memory occupied by the deleted node.
Step 19: If display is selected, traverse from "head" and display each element until the traversal reaches "head" again.
Step 20: Repeat the menu and perform the selected operation until the user chooses Exit. Release the memory occupied by the remaining nodes.
Step 21: Stop.

*/

/* **********SOURCE CODE********** */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
    newNode->next = newNode;
    newNode->prev = newNode;

    return newNode;
}

void insertBeginning(int value)
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
        Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

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
        Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }

    printf("Inserted %d at the end\n", value);
}

void insertAfter(int value, int key)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->data == key)
        {
            Node *newNode = createNode(value);

            if (newNode == NULL)
                return;

            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;

            printf("Inserted %d after %d\n", value, key);
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Value %d not found\n", key);
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->data == value)
        {
            if (temp->next == temp)
            {
                head = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;
            }

            free(temp);
            printf("Deleted %d successfully\n", value);
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Element %d not found\n", value);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;

    printf("Circular List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

int main()
{
    int choice, value, key;

    do
    {
        printf("\n--- Circular Linked List Menu ---\n");
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

        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }

        free(temp);
    }

    return 0;
}

/* **********OUTPUT**********

--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 1
Enter value: 20
Inserted 20 at the beginning

--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 2
Enter value: 30
Inserted 30 at the end

--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 2
Enter value: 40
Inserted 40 at the end

--- Circular Linked List Menu ---
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

--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 5
Circular List: 20 -> 25 -> 30 -> 40 -> (head)

--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 4
Enter value to delete: 30
Deleted 30 successfully

--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 5
Circular List: 20 -> 25 -> 40 -> (head)

--- Circular Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert After a Value
4. Delete a Node
5. Display
6. Exit
Enter your choice: 6
Exiting program

*/