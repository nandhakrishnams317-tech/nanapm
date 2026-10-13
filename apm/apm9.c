/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 9
DATE: 03-07-2026

**********Symmetry Checker for Geometric Designs**********

AIM: Develop a program to check if a given design (represented as a matrix) is symmetric. This program can be 
     useful for analyzing symmetry in architectural or geometric design patterns.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a square matrix mat[10][10] and variables size, i, j, and flag.
Step 3: Initialize flag to 1, assuming that the matrix is symmetric.
Step 4: Accept the order of the square matrix from the user.
Step 5: Read all the values into the matrix.
Step 6: Print the entered matrix in matrix form.
Step 7: Compare every element mat[i][j] with mat[j][i].
Step 8: If any two corresponding elements are unequal, change flag to 0.
Step 9: Continue checking the remaining elements of the matrix.
Step 10: If flag remains 1, display "The Matrix is symmetric."
Step 11: Otherwise, display "The Matrix is not symmetric."
Step 12: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>

int main()
{
    int mat[10][10], size, i, j, flag = 1;

    printf("Enter the size of matrix:");
    scanf("%d", &size);

    printf("Enter the matrix:\n");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(mat[i][j] != mat[j][i])
            {
                flag = 0;
            }
        }
    }

    if(flag == 1)
        printf("\nThe Matrix is symmetric.\n");
    else
        printf("\nThe Matrix is not symmetric,\n");

    return 0;
}

/* **********OUTPUT**********

Enter the size of matrix:3
Enter the matrix:
4 7 2
7 5 9
2 9 6

Matrix:
4 7 2
7 5 9
2 9 6

The Matrix is symmetric.
*/

