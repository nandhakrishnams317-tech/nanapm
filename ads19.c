/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 15
DATE: 18-07-2026

**********Complex Number Calculator for Engineering Simulations**********

AIM: Develop a program that allows the user to input two complex numbers and calculates their sum and 
     difference. This program could be applied in simulations for electrical engineering or physics problems.
*/

/* **********ALGORITHM**********

/* ALGORITHM

Step 1: Start.
Step 2: Define a node containing data, height, and left and right pointers.
Step 3: Create functions to calculate node height, maximum height, and balance factor.
Step 4: Create a new node with the given value and initialize its height to 1.
Step 5: Insert each value into the AVL tree according to the Binary Search Tree property.
Step 6: Update the height and calculate the balance factor of each node after insertion.
Step 7: If the tree becomes unbalanced, perform the appropriate LL, RR, LR, or RL rotation.
Step 8: If the user selects Search, compare the key with the current node and search the appropriate subtree.
Step 9: If the user selects Traversal, display the inorder, preorder, and postorder traversals.
Step 10: If the user selects Exit, terminate the program.
Step 11: If the choice is invalid, display an error message.
Step 12: Repeat the menu operations until the user selects Exit.
Step 13: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value, ht;
    struct Node *left, *right;
};

struct Node *root = NULL;

int getHeight(struct Node *ptr)
{
    if (ptr == NULL)
        return 0;

    return ptr->ht;
}

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *newNode(int value)
{
    struct Node *temp =
        (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->ht = 1;

    return temp;
}

int getBalance(struct Node *ptr)
{
    if (ptr == NULL)
        return 0;

    return getHeight(ptr->left) - getHeight(ptr->right);
}

struct Node *rotateRight(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->ht = maximum(getHeight(y->left),
                    getHeight(y->right)) + 1;

    x->ht = maximum(getHeight(x->left),
                    getHeight(x->right)) + 1;

    return x;
}

struct Node *rotateLeft(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->ht = maximum(getHeight(x->left),
                    getHeight(x->right)) + 1;

    y->ht = maximum(getHeight(y->left),
                    getHeight(y->right)) + 1;

    return y;
}

struct Node *insertNode(struct Node *ptr, int value)
{
    if (ptr == NULL)
        return newNode(value);

    if (value < ptr->value)
        ptr->left = insertNode(ptr->left, value);
    else if (value > ptr->value)
        ptr->right = insertNode(ptr->right, value);
    else
        return ptr;

    ptr->ht = maximum(getHeight(ptr->left),
                      getHeight(ptr->right)) + 1;

    int b = getBalance(ptr);

    if (b > 1 && value < ptr->left->value)
        return rotateRight(ptr);

    if (b < -1 && value > ptr->right->value)
        return rotateLeft(ptr);

    if (b > 1 && value > ptr->left->value)
    {
        ptr->left = rotateLeft(ptr->left);
        return rotateRight(ptr);
    }

    if (b < -1 && value < ptr->right->value)
    {
        ptr->right = rotateRight(ptr->right);
        return rotateLeft(ptr);
    }

    return ptr;
}

void searchNode(struct Node *ptr, int key)
{
    if (ptr == NULL)
    {
        printf("Key not found\n");
        return;
    }

    if (key == ptr->value)
        printf("Key found\n");
    else if (key < ptr->value)
        searchNode(ptr->left, key);
    else
        searchNode(ptr->right, key);
}

void inorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->value);
        inorder(ptr->right);
    }
}

void preorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->value);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->value);
    }
}

int main()
{
    int choice, num, key;

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Traversal\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &num);

                root = insertNode(root, num);
                printf("Inserted successfully\n");
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                searchNode(root, key);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);

                printf("\nPreorder: ");
                preorder(root);

                printf("\nPostorder: ");
                postorder(root);

                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/* **********OUTPUT**********

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 1
Enter value: 40
Inserted successfully

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 1
Enter value: 20
Inserted successfully

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 1
Enter value: 10
Inserted successfully

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 3
Inorder: 10 20 40
Preorder: 20 10 40
Postorder: 10 40 20

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 2
Enter key: 40
Key found

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 2
Enter key: 60
Key not found

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 4

*/    