/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 10
DATE: 04-09-2026

**********Binary Search Trees**********

AIM: Implementation of binary search trees  and  perform the operations on BST. 
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a structure "Node" containing data, a left pointer, and a right pointer.
Step 3: Initialize the root pointer to "NULL".
Step 4: Create a function "newNode(value)" to allocate memory for a node and initialize its data and child pointers.
Step 5: Display a menu containing insertion, search, inorder traversal, preorder traversal, postorder traversal, and exit options.
Step 6: Read the user's choice.
Step 7: If insertion is selected, read a value and insert it into the Binary Search Tree according to BST properties.
Step 8: If search is selected, read the key and search for it by comparing it with the current node's data. Display whether the key is found or not found.
Step 9: If inorder traversal is selected, display the nodes in left-root-right order.
Step 10: If preorder traversal is selected, display the nodes in root-left-right order.
Step 11: If postorder traversal is selected, display the nodes in left-right-root order.
Step 12: Repeat steps 5 to 11 until the user selects Exit.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *root = NULL;

Node* newNode(int value) {
    Node *temp = malloc(sizeof(Node));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* insertNode(Node *tree, int value) {
    if (tree == NULL) {
        return newNode(value);
    }

    if (value < tree->data) {
        tree->left = insertNode(tree->left, value);
    }
    else if (value > tree->data) {
        tree->right = insertNode(tree->right, value);
    }

    return tree;
}

int searchNode(Node *tree, int key) {
    if (tree == NULL) {
        return 0;
    }

    if (tree->data == key) {
        return 1;
    }

    if (key < tree->data) {
        return searchNode(tree->left, key);
    }

    return searchNode(tree->right, key);
}

void inorder(Node *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void preorder(Node *tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(Node *tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

int main() {
    int choice, value, key;

    do {
        printf("\n\n--- BST MENU ---\n");
        printf("1. Insert Node\n");
        printf("2. Search Key\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);

                if (searchNode(root, key)) {
                    printf("Key is found\n");
                } else {
                    printf("Key is not found\n");
                }
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}


/* **********OUTPUT**********

--- BST MENU ---
1. Insert Node
2. Search Key
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 1
Enter value: 60

--- BST MENU ---
Enter choice: 1
Enter value: 20

--- BST MENU ---
Enter choice: 1
Enter value: 30

--- BST MENU ---
Enter choice: 1
Enter value: 40

--- BST MENU ---
Enter choice: 1
Enter value: 70

--- BST MENU ---
Enter choice: 2
Enter key to search: 40
Key is found

--- BST MENU ---
Enter choice: 3
Inorder Traversal: 20 30 40 60 70

--- BST MENU ---
Enter choice: 4
Preorder Traversal: 60 20 30 40 70

--- BST MENU ---
Enter choice: 5
Postorder Traversal: 40 30 20 70 60

--- BST MENU ---
Enter choice: 6
Exiting program

*/