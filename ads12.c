/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 12
DATE: 28-09-2026

**********Heap Sort**********

AIM: Implementation  of  heap  sort.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the number of elements, "n".
Step 3: Read "n" elements into the array "arr".
Step 4: Call the function "heapSort(arr, n)" to sort the elements.
Step 5: In the "heapSort()" function, construct a max heap by calling "heapify()" for each non-leaf node, starting from "n/2 - 1" and moving backward to "0".
Step 6: Exchange the first element of the heap with the last element.
Step 7: Reduce the heap size by one.
Step 8: Call "heapify()" to restore the max heap property.
Step 9: Repeat steps 6 to 8 until only one element remains in the heap.
Step 10: Display the sorted array.
Step 11: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != root)
    {
        swap(&arr[root], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of elements\n");
        return 0;
    }

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

/* **********OUTPUT**********

Enter number of elements: 5
Enter the elements:
45 12 78 23 56
Sorted array:
12 23 45 56 78

*/