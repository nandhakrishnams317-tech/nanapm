/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 20
DATE: 03-07-2026

**********Hashing**********

AIM: Implementation of Hashing using Separate Chaining
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a hash table of size SIZE and initialize all its elements to NULL.
Step 3: Define a hash function that calculates the index using key % SIZE.
Step 4: Implement the INSERT operation. Read the value to be inserted and calculate its hash index. Create a new node containing the value. If the index is empty, store the node there; otherwise, insert it at the end of the linked list.
Step 5: Implement the DISPLAY operation. Visit every index in the hash table and display all linked-list elements. Print NULL for empty indexes and after the last node.
Step 6: Display the menu and read the user's choice.
Step 7: If the choice is 1, insert a value into the hash table.
Step 8: If the choice is 2, display the hash table.
Step 9: If the choice is 3, terminate the program.
Step 10: If the choice is invalid, display an error message.
Step 11: Repeat the menu operations until the user selects Exit.
Step 12: Stop.
*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
    int value;
    struct Node *next;
};

struct Node *table[SIZE];

void initializeTable()
{
    int i;

    for (i = 0; i < SIZE; i++)
        table[i] = NULL;
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insertValue(int key)
{
    int index = hashFunction(key);
    struct Node *newNode, *current;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->value = key;
    newNode->next = NULL;

    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        current = table[index];

        while (current->next != NULL)
            current = current->next;

        current->next = newNode;
    }

    printf("Inserted %d at index %d\n", key, index);
}

void displayTable()
{
    int i;
    struct Node *current;

    for (i = 0; i < SIZE; i++)
    {
        printf("Index %d: ", i);
        current = table[i];

        while (current != NULL)
        {
            printf("%d -> ", current->value);
            current = current->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int choice, number;

    initializeTable();

    while (1)
    {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &number);
                insertValue(number);
                break;

            case 2:
                displayTable();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* **********OUTPUT**********

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value: 12
Inserted 12 at index 2

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value: 22
Inserted 22 at index 2

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value: 17
Inserted 17 at index 7

1. Insert
2. Display
3. Exit
Enter choice: 2
Index 0: NULL
Index 1: NULL
Index 2: 12 -> 22 -> NULL
Index 3: NULL
Index 4: NULL
Index 5: NULL
Index 6: NULL
Index 7: 17 -> NULL
Index 8: NULL
Index 9: NULL

1. Insert
2. Display
3. Exit
Enter choice: 3
*/