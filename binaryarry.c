#include <stdio.h>

#define MAX 100

int tree[MAX];
int n = 0;

// Insert element
void insert(int value) {
    if (n >= MAX) {
        printf("Tree is full\n");
        return;
    }

    tree[n] = value;
    n++;
}

// Inorder Traversal
void inorder(int index) {
    if (index >= n)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

// Preorder Traversal
void preorder(int index) {
    if (index >= n)
        return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

// Postorder Traversal
void postorder(int index) {
    if (index >= n)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}

int main() {

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);

    printf("Inorder Traversal: ");
    inorder(0);

    printf("\nPreorder Traversal: ");
    preorder(0);

    printf("\nPostorder Traversal: ");
    postorder(0);

    return 0;
}