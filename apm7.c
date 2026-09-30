/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 07
DATE: 

**********Matrix Operations for Financial Modeling**********

AIM: Write a program to perform matrix operations that calculate the row sum, column sum, and diagonal sum 
     of a financial transaction matrix. Additionally, include a function to transpose the matrix for further 
     analysis.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a matrix a[10][10] and variables for rows, columns, row total, column total, and trace.
Step 3: Input the number of rows and columns of the matrix.
Step 4: Read and store all matrix elements.
Step 5: Traverse each row and initialize its sum to zero.
Step 6: Add all elements of the current row and display the row sum.
Step 7: Traverse each column and initialize its sum to zero.
Step 8: Add all elements of the current column and display the column sum.
Step 9: Initialize the trace value to zero.
Step 10: Add the elements whose row and column indexes are equal.
Step 11: Display the calculated trace of the matrix.
Step 12: Call the transpose() function by passing the number of rows and columns.
Step 13: In the transpose() function, interchange rows and columns by accessing a[j][i].
Step 14: Display the resulting transpose matrix.
Step 15: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int a[10][10];

void transpose(int rows, int cols)
{
    int i, j;

    printf("transpose:\n");

    for(i = 0; i < cols; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%d\t", a[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int r, c, i, j;
    int rowSum, colSum;
    int trace = 0;

    printf("Enter no of rows and columns\n");
    scanf("%d %d", &r, &c);

    printf("Enter data\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < r; i++)
    {
        rowSum = 0;

        for(j = 0; j < c; j++)
        {
            rowSum = rowSum + a[i][j];
        }

        printf("sum of row %d is %d\n", i + 1, rowSum);
    }

    for(j = 0; j < c; j++)
    {
        colSum = 0;

        for(i = 0; i < r; i++)
        {
            colSum = colSum + a[i][j];
        }

        printf("sum of col %d is %d\n", j + 1, colSum);
    }

    for(i = 0; i < r && i < c; i++)
    {
        trace = trace + a[i][i];
    }

    printf("trace= %d\n", trace);

    transpose(r, c);

    return 0;
}

/* **********OUTPUT**********

Enter no of rows and columns
3 3
Enter data
2 4 6
1 3 5
7 8 9

sum of row 1 is 12
sum of row 2 is 9
sum of row 3 is 24

sum of col 1 is 10
sum of col 2 is 15
sum of col 3 is 20

trace= 14

transpose:
2       1       7
4       3       8
6       5       9
*/
