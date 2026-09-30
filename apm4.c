/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 04
DATE: 

**********Palindrome Checker for Database Records**********

AIM: Write a program to check if a given set of product codes (stored as strings in a database) are palindromes, 
     and generate a report of the results.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Create a function checkPalindrome() to determine whether a product code is a palindrome.
Step 3: Declare a two-dimensional character array code[20][30] to store the product codes.
Step 4: Read the total number of product codes n.
Step 5: Accept n product codes from the user and store them in the array.
Step 6: Pass each product code to the checkPalindrome() function one by one.
Step 7: Find the length of the current product code using strlen().
Step 8: Set starting and ending positions for comparing characters.
Step 9: Compare the characters from both ends until the middle of the string is reached.
Step 10: If any pair of characters is different, return 0.
Step 11: If all corresponding characters are equal, return 1.
Step 12: Display the product code followed by Palindrome if the function returns 1.
Step 13: Otherwise, display the product code followed by Not Palindrome.
Step 14: Repeat the process for all product codes.
Step 15: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <string.h>

int checkPalindrome(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end)
    {
        if(str[start] != str[end])
            return 0;

        start++;
        end--;
    }

    return 1;
}

int main()
{
    int n, i;
    char code[20][30];

    printf("Enter the Number of Product Codes:");
    scanf("%d", &n);

    printf("Enter the product Codes:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%s", code[i]);
    }

    printf("\nProduct Report\n");
    printf("---------------\n");

    for(i = 0; i < n; i++)
    {
        if(checkPalindrome(code[i]) == 1)
            printf("%s:Palindrome\n", code[i]);
        else
            printf("%s:Not Palindrome\n", code[i]);
    }

    return 0;
}

/* **********OUTPUT**********

Enter the Number of Product Codes:2
Enter the product Codes:
level
computer

Product Report
---------------
level:Palindrome
computer:Not Palindrome

*/