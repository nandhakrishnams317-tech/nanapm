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
Step 2: Read the input string and calculate the frequency of each unique character.
Step 3: Create a leaf node for each unique character and insert the nodes into a Min-Heap according to their frequencies.
Step 4: Repeat the following operations until only one node remains in the Min-Heap.
Step 5: Remove the two nodes with the lowest frequencies from the Min-Heap.
Step 6: Create a new internal node with a frequency equal to the sum of the two removed nodes.
Step 7: Assign the first removed node as the left child and the second removed node as the right child of the new node.
Step 8: Insert the new internal node back into the Min-Heap.
Step 9: Set the remaining node as the root of the Huffman Tree.
Step 10: Traverse the Huffman Tree recursively, assigning 0 to each left branch and 1 to each right branch to generate the Huffman codes.
Step 11: Store each character, its frequency, and its Huffman code in an array.
Step 12: Sort the array in descending order of frequency.
Step 13: Display the characters, their frequencies, and their Huffman codes.
Step 14: Release the dynamically allocated memory.
Step 15: Stop.

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_STR_LEN 1000
#define ASCII_SIZE 256

struct MinHeapNode {
    char symbol;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned count;
    unsigned limit;
    struct MinHeapNode **nodes;
};

struct CodeEntry {
    char symbol;
    unsigned frequency;
    int code[MAX_TREE_HT];
    int codeLength;
};

struct MinHeapNode *createNode(char symbol, unsigned frequency) {
    struct MinHeapNode *temp =
        (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    temp->left = temp->right = NULL;
    temp->symbol = symbol;
    temp->frequency = frequency;

    return temp;
}

struct MinHeap *makeMinHeap(unsigned limit) {
    struct MinHeap *heap =
        (struct MinHeap *)malloc(sizeof(struct MinHeap));

    if (heap == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    heap->count = 0;
    heap->limit = limit;
    heap->nodes = (struct MinHeapNode **)malloc(
        limit * sizeof(struct MinHeapNode *));

    if (heap->nodes == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    return heap;
}

void swapNodes(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *heap, int pos) {
    int smallest = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;

    if (left < heap->count &&
        heap->nodes[left]->frequency <
        heap->nodes[smallest]->frequency)
        smallest = left;

    if (right < heap->count &&
        heap->nodes[right]->frequency <
        heap->nodes[smallest]->frequency)
        smallest = right;

    if (smallest != pos) {
        swapNodes(&heap->nodes[smallest], &heap->nodes[pos]);
        heapify(heap, smallest);
    }
}

int hasOneNode(struct MinHeap *heap) {
    return heap->count == 1;
}

struct MinHeapNode *removeMin(struct MinHeap *heap) {
    struct MinHeapNode *temp = heap->nodes[0];

    heap->nodes[0] = heap->nodes[heap->count - 1];
    heap->count--;

    if (heap->count > 0)
        heapify(heap, 0);

    return temp;
}

void addMinHeap(struct MinHeap *heap,
                struct MinHeapNode *newNode) {
    int i = heap->count;
    heap->count++;

    while (i > 0 &&
           newNode->frequency <
           heap->nodes[(i - 1) / 2]->frequency) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->nodes[i] = newNode;
}

void buildHeap(struct MinHeap *heap) {
    int i;

    for (i = (int)heap->count / 2 - 1; i >= 0; i--)
        heapify(heap, i);
}

int isLeafNode(struct MinHeapNode *root) {
    return root->left == NULL && root->right == NULL;
}

struct MinHeap *createAndBuildHeap(
    char characters[], int frequencies[], int total) {

    struct MinHeap *heap = makeMinHeap(total);

    for (int i = 0; i < total; i++)
        heap->nodes[i] =
            createNode(characters[i], frequencies[i]);

    heap->count = total;
    buildHeap(heap);

    return heap;
}

struct MinHeapNode *buildHuffmanTree(
    char characters[], int frequencies[], int total) {

    struct MinHeapNode *left, *right, *parent;

    struct MinHeap *heap =
        createAndBuildHeap(characters, frequencies, total);

    while (!hasOneNode(heap)) {
        left = removeMin(heap);
        right = removeMin(heap);

        parent = createNode('$',
            left->frequency + right->frequency);

        parent->left = left;
        parent->right = right;

        addMinHeap(heap, parent);
    }

    return removeMin(heap);
}

void storeCodes(struct MinHeapNode *root, int path[],
                int depth, struct CodeEntry entries[],
                int *totalCodes) {

    if (root->left != NULL) {
        path[depth] = 0;
        storeCodes(root->left, path, depth + 1,
                   entries, totalCodes);
    }

    if (root->right != NULL) {
        path[depth] = 1;
        storeCodes(root->right, path, depth + 1,
                   entries, totalCodes);
    }

    if (isLeafNode(root)) {
        entries[*totalCodes].symbol = root->symbol;
        entries[*totalCodes].frequency = root->frequency;
        entries[*totalCodes].codeLength = depth;

        for (int i = 0; i < depth; i++)
            entries[*totalCodes].code[i] = path[i];

        (*totalCodes)++;
    }
}

void generateCodes(char characters[],
                   int frequencies[], int total) {

    struct MinHeapNode *root =
        buildHuffmanTree(characters, frequencies, total);

    int path[MAX_TREE_HT];
    struct CodeEntry entries[ASCII_SIZE];
    int totalCodes = 0;

    storeCodes(root, path, 0, entries, &totalCodes);

    for (int i = 0; i < totalCodes - 1; i++) {
        for (int j = 0; j < totalCodes - i - 1; j++) {
            if (entries[j].frequency <
                entries[j + 1].frequency) {

                struct CodeEntry temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }

    printf("\nChar  |  Freq  |  Huffman Code\n");
    printf("-----------------------------\n");

    for (int i = 0; i < totalCodes; i++) {
        if (entries[i].symbol == ' ')
            printf(" SPACE |   %2u   |   ", entries[i].frequency);
        else
            printf("   %c   |   %2u   |   ",
                   entries[i].symbol, entries[i].frequency);

        if (entries[i].codeLength == 0)
            printf("0");

        for (int j = 0; j < entries[i].codeLength; j++)
            printf("%d", entries[i].code[j]);

        printf("\n");
    }
}

int main() {
    char input[MAX_STR_LEN];
    int frequencyMap[ASCII_SIZE] = {0};

    printf("Enter the input string: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    size_t length = strlen(input);

    if (length > 0 && input[length - 1] == '\n')
        input[--length] = '\0';

    if (length == 0) {
        printf("Empty string entered.\n");
        return 1;
    }

    for (size_t i = 0; i < length; i++)
        frequencyMap[(unsigned char)input[i]]++;

    int uniqueChars = 0;

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequencyMap[i] > 0)
            uniqueChars++;
    }

    char *characters =
        (char *)malloc(uniqueChars * sizeof(char));

    int *frequencies =
        (int *)malloc(uniqueChars * sizeof(int));

    if (characters == NULL || frequencies == NULL) {
        printf("Memory allocation failed!\n");
        free(characters);
        free(frequencies);
        return 1;
    }

    int pos = 0;

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequencyMap[i] > 0) {
            characters[pos] = (char)i;
            frequencies[pos] = frequencyMap[i];
            pos++;
        }
    }

    generateCodes(characters, frequencies, uniqueChars);

    free(characters);
    free(frequencies);

    return 0;
}

/* OUTPUT

Enter the input string: I Love Computer Science

Char  |  Freq  |  Huffman Code
-----------------------------
   e   |    4   |   110
 SPACE |    3   |   100
   c   |    2   |   010
   o   |    2   |   1010
   u   |    1   |   0000
   i   |    1   |   0001
   p   |    1   |   0010
   t   |    1   |   0011
   C   |    1   |   0110
   L   |    1   |   0111
   r   |    1   |   10110
   S   |    1   |   10111
   v   |    1   |   11100
   m   |    1   |   11101
   n   |    1   |   11110
   I   |    1   |   11111
*/    