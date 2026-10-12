/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 06
DATE: 03-08-2026

**********Dynamic Data Display(Patterns)**********

AIM: •        Develop an application that displays Pascal's Triangle dynamically based on user input for the number of rows.
     •        Also, create a pattern generator (e.g., number or star pattern) that can be customized with user input.
*/

/* **********ALGORITHM*********
Step 1: Start.
Step 2: Declare integer variables i, j and n.
Step 3: Read the value of n from the user.
Step 4: Use a loop to print n stars in the first row.
Step 5: Move the cursor to the next line.
Step 6: Generate the middle rows using a loop.
Step 7: Print the required spaces before the star in each middle row.
Step 8: Print one star after the spaces.
Step 9: Reduce the number of spaces for every successive row.
Step 10: Print n stars in the final row.
Step 11: Move to the next line.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter the Number:");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("* ");
    }
    printf("\n");

    for(i = 1; i <= n - 2; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            printf("  ");
        }

        printf("*\n");
    }

    for(i = 0; i < n; i++)
    {
        printf("* ");
    }

    printf("\n");

    return 0;
}

/* **********OUTPUT**********

Enter the Number:5
* * * * *
      *
    *
  *
* * * * *

*/
