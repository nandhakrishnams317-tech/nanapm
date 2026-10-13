/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 11
DATE: 10-09-2026

**********Quick Sort**********

AIM: Implementation of quick sort.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the number of elements, "n".
Step 3: Read "n" elements into array "arr".
Step 4: Call "quickSort(arr, 0, n-1)" to sort the array.
Step 5: In the "quickSort()" function, if "low < high", select the first element as the pivot.
Step 6: Initialize "i = low + 1" and "j = high".
Step 7: Move "i" forward while "i <= high" and "arr[i] <= pivot".
Step 8: Move "j" backward while "arr[j] > pivot".
Step 9: If "i < j", exchange "arr[i]" and "arr[j]".
Step 10: Repeat steps 7 to 9 until "i >= j".
Step 11: Exchange the pivot element with "arr[j]".
Step 12: Recursively sort the left subarray and the right subarray.
Step 13: Display the sorted array.
Step 14: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quickSort(int arr[], int low, int high)
{
    int i, j, pivot;

    if (low < high)
    {
        pivot = arr[low];
        i = low + 1;
        j = high;

        while (i <= j)
        {
            while (i <= high && arr[i] <= pivot)
                i++;

            while (j > low && arr[j] > pivot)
                j--;

            if (i < j)
                swap(&arr[i], &arr[j]);
        }

        swap(&arr[low], &arr[j]);

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
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

    quickSort(arr, 0, n - 1);

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