/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 10
DATE: 29-08-2026

**********Permutation Generator for Password Cracking Simulation**********

AIM: Write a program that generates all possible permutations of a given string, which could simulate a 
     password-cracking tool for security testing.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a character array str to hold the input string.
Step 3: Read the string from the user.
Step 4: Determine the length of the given string.
Step 5: Call the generate() function with the first and last positions of the string.
Step 6: In generate(), check whether the current position has reached the last position.
Step 7: If the positions are equal, display the current arrangement.
Step 8: Otherwise, select each character from the current position to the end.
Step 9: Exchange the selected character with the character at the current position.
Step 10: Call generate() recursively for the next position.
Step 11: Restore the exchanged characters after returning from the recursive call.
Step 12: Continue the process until every possible arrangement is produced.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <string.h>

void exchange(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void generate(char str[], int pos, int last)
{
    int k;

    if (pos >= last)
    {
        printf("%s\n", str);
        return;
    }

    for (k = pos; k <= last; k++)
    {
        exchange(&str[pos], &str[k]);
        generate(str, pos + 1, last);
        exchange(&str[pos], &str[k]);
    }
}

int main()
{
    char str[100];
    int length;
    printf("Enter a string: ");
    scanf("%99s", str);
    length = strlen(str);
    printf("All permutations:\n");
    generate(str, 0, length - 1);
    return 0;
}

/* **********OUTPUT**********

Enter a string: ABC
All permutations:
ABC
ACB
BAC
BCA
CBA
CAB

*/
