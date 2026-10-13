/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 9
DATE: 03-07-2026

**********Binary Tree And Traversals.**********

AIM: Implementation  of  binary  tree  and  traversals.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a structure "node" containing data, left pointer, and right pointer.
Step 3: Create a function "newNode(value)" to allocate memory for a node, assign the value, and initialize the left and right pointers to "NULL".
Step 4: Read the number of nodes, "n", from the user.
Step 5: If "n <= 0", display "Tree is empty" and terminate the program.
Step 6: Read the data values and insert the nodes into the binary tree using level-order traversal with a queue.
Step 7: Perform inorder traversal by visiting the left subtree, displaying the root data, and visiting the right subtree.
Step 8: Perform preorder traversal by displaying the root data, visiting the left subtree, and visiting the right subtree.
Step 9: Perform postorder traversal by visiting the left subtree, visiting the right subtree, and displaying the root data.
Step 10: Display the results of inorder, preorder, and postorder traversals.
Step 11: Stop.

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

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

void insertNode(Node *root, int value) {
    Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node *current = queue[front++];

        if (current->left == NULL) {
            current->left = newNode(value);
            return;
        }

        queue[rear++] = current->left;

        if (current->right == NULL) {
            current->right = newNode(value);
            return;
        }

        queue[rear++] = current->right;
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node *root = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tree is empty\n");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        if (root == NULL) {
            root = newNode(value);
        } else {
            insertNode(root, value);
        }
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}

/* **********OUTPUT**********

Enter number of nodes: 5
Enter data: 10
Enter data: 20
Enter data: 30
Enter data: 40
Enter data: 50

Inorder Traversal: 40 20 50 10 30
Preorder Traversal: 10 20 40 50 30
Postorder Traversal: 40 50 20 30 10

*/