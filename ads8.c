/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 08
DATE: 18-09-2026

**********Matrix Multiplication for Image Processing**********

AIM: Implement matrix multiplication to apply a transformation matrix to an image. The program should accept
     a 2D image matrix and a transformation matrix, then output the transformed image.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare three matrices a, b and result along with row, column and loop variables.
Step 3: Input the number of rows and columns of the first matrix.
Step 4: Enter and store all elements of the first matrix.
Step 5: Input the number of rows and columns of the second matrix.
Step 6: Enter and store all elements of the second matrix.
Step 7: Verify whether the columns of the first matrix are equal to the rows of the second matrix.
Step 8: If the condition is false, display "Not possible because c1=r2" and terminate the program.
Step 9: Set every element of the result matrix to zero.
Step 10: Select each row of the first matrix and each column of the second matrix.
Step 11: Multiply the corresponding elements and add their products.
Step 12: Store the obtained sum in the corresponding position of the result matrix.
Step 13: Repeat the multiplication process until all result elements are calculated.
Step 14: Display the resulting matrix.
Step 15: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter the noof rows and cols of 1st matrix\n");
    scanf("%d %d", &r1, &c1);

    printf("Enter the data\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the noof rows and cols of 2nd matrix\n");
    scanf("%d %d", &r2, &c2);

    printf("Enter the data\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    if(c1 != r2)
    {
        printf("Not possible because c1=r2\n");
        return 0;
    }

    printf("Matrix multiplication\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < r2; k++)
            {
                result[i][j] = result[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* **********OUTPUT**********

Enter the noof rows and cols of 1st matrix
2 2
Enter the data
2 3
4 5

Enter the noof rows and cols of 2nd matrix
2 2
Enter the data
1 2
3 4

Matrix multiplication
11      16
19      28

*/