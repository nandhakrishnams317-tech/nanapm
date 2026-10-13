/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 15
DATE: 18-07-2026

**********Heap Tree********** 
AIM: Implementation of heap tree and operations.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize the heap array and set the heap size to 0.
Step 3: Display the menu containing Insert, Delete Root, Display, and Exit options.
Step 4: Read the user's choice.
Step 5: If the choice is 1, check whether the heap is full. If space is available, read a value, insert it into the heap, and swap it with its parent while it is greater than the parent.
Step 6: If the choice is 2, check whether the heap is empty. If it is not empty, delete the root element, replace it with the last element, decrease the heap size, and rearrange the elements to maintain the max heap property.
Step 7: If the choice is 3, display all heap elements. If the heap is empty, display "Heap is empty".
Step 8: If the choice is 4, display "Exiting..." and terminate the program.
Step 9: If the choice is invalid, display "Invalid choice".
Step 10: Repeat Steps 3 to 9 until the user selects 4.
Step 11: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int heap[100], size = 0;

void insertValue(int value)
{
    int pos, temp;

    heap[size] = value;
    pos = size;
    size++;

    while (pos > 0 && heap[(pos - 1) / 2] < heap[pos])
    {
        temp = heap[pos];
        heap[pos] = heap[(pos - 1) / 2];
        heap[(pos - 1) / 2] = temp;

        pos = (pos - 1) / 2;
    }
}

void removeRoot()
{
    int pos = 0, left, right, max, temp;

    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    while (1)
    {
        left = 2 * pos + 1;
        right = 2 * pos + 2;
        max = pos;

        if (left < size && heap[left] > heap[max])
            max = left;

        if (right < size && heap[right] > heap[max])
            max = right;

        if (max == pos)
            break;

        temp = heap[pos];
        heap[pos] = heap[max];
        heap[max] = temp;

        pos = max;
    }
}

void displayHeap()
{
    int i;

    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap elements: ");

    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int choice, num;

    do
    {
        printf("\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (size >= 100)
                    printf("Heap is full\n");
                else
                {
                    printf("Enter the value: ");
                    scanf("%d", &num);
                    insertValue(num);
                }
                break;

            case 2:
                removeRoot();
                break;

            case 3:
                displayHeap();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}


/* **********OUTPUT**********

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 50

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 30

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 70

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 20

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 3
Heap elements: 70 30 50 20

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 2
Deleted element: 70

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 3
Heap elements: 50 30 20

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 4
Exiting...

*/    