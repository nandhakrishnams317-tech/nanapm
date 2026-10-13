/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 16
DATE: 30-09-2026

**********Huffman Algorithm**********

AIM: Implementation of Huffman algorithm.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the number of characters and their frequencies.
Step 3: Create a leaf node for each character with its frequency and initialize its left and right children to -1.
Step 4: Repeat the following steps n - 1 times:
a. Find the two unused nodes having the smallest frequencies.
b. Mark both selected nodes as used.
c. Create a new internal node with the sum of their frequencies.
d. Assign the selected nodes as the left and right children of the new node.
Step 5: Set the last created node as the root of the Huffman tree.
Step 6: Call the printCodes function to generate the Huffman codes.
Step 7: If the current node is a leaf node, display its character and code.
Step 8: If the left child exists, append '0' to the code and recursively traverse the left subtree.
Step 9: If the right child exists, append '1' to the code and recursively traverse the right subtree.
Step 10: Display the Huffman codes for all characters.
Step 11: Stop.

/* **********SOURCE CODE********** */

#include <stdio.h>

struct Node
{
    char ch;
    int freq;
    int left, right;
};

struct Node tree[100];
int total = 0;

int makeNode(char ch, int freq, int left, int right)
{
    tree[total].ch = ch;
    tree[total].freq = freq;
    tree[total].left = left;
    tree[total].right = right;

    return total++;
}

void displayCodes(int node, char code[], int level)
{
    if (tree[node].left == -1 && tree[node].right == -1)
    {
        code[level] = '\0';
        printf("%c : %s\n", tree[node].ch, code);
        return;
    }

    if (tree[node].left != -1)
    {
        code[level] = '0';
        displayCodes(tree[node].left, code, level + 1);
    }

    if (tree[node].right != -1)
    {
        code[level] = '1';
        displayCodes(tree[node].right, code, level + 1);
    }
}

int main()
{
    int n, i, j, first, second, root;
    int freq[50], used[100] = {0};
    char ch[50], code[50];

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter characters and frequencies:\n");

    for (i = 0; i < n; i++)
        scanf(" %c %d", &ch[i], &freq[i]);

    for (i = 0; i < n; i++)
        makeNode(ch[i], freq[i], -1, -1);

    for (i = 0; i < n - 1; i++)
    {
        first = -1;
        second = -1;

        for (j = 0; j < total; j++)
        {
            if (used[j] == 0)
            {
                if (first == -1 || tree[j].freq < tree[first].freq)
                {
                    second = first;
                    first = j;
                }
                else if (second == -1 ||
                         tree[j].freq < tree[second].freq)
                {
                    second = j;
                }
            }
        }

        used[first] = 1;
        used[second] = 1;

        root = makeNode('#',
                        tree[first].freq + tree[second].freq,
                        first, second);
    }

    printf("Huffman Codes:\n");
    displayCodes(root, code, 0);

    return 0;
}

/* OUTPUT
Enter the number of characters: 5
Enter characters and frequencies:
A 4
B 7
C 10
D 15
E 20

Huffman Codes:
D : 11
E : 10
C : 01
A : 000
B : 001

*/    