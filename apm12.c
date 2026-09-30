
/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 12
DATE: 

**********Text Reversal Tool for Document Review**********

AIM: Write a program that checks if a document (string) is a palindrome by reversing it manually without using 
     built-in functions. This tool could be used for reviewing documents that need to maintain symmetry.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare character arrays text and reverse, and integer variables pos, length, and flag.
Step 3: Read the document string from the user.
Step 4: Calculate the length of the string manually using a while loop.
Step 5: Copy the characters of the string in reverse order into the reverse array.
Step 6: Add '\0' at the end of the reversed string.
Step 7: Compare the original and reversed strings character by character.
Step 8: If any two characters are different, set flag to 0.
Step 9: Display the reversed document.
Step 10: Check the value of flag.
Step 11: If flag is 1, display that the document is a palindrome.
Step 12: Otherwise, display that the document is not a palindrome.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int main()
{
    char text[100], reverse[100];
    int pos, length = 0;
    int flag = 1;

    printf("Enter a document: ");
    scanf("%s", text);

    while (text[length] != '\0')
        length++;

    for (pos = 0; pos < length; pos++)
        reverse[pos] = text[length - pos - 1];

    reverse[length] = '\0';

    for (pos = 0; pos < length; pos++)
    {
        if (text[pos] != reverse[pos])
        {
            flag = 0;
            break;
        }
    }

    printf("Reversed document: %s\n", reverse);

    if (flag == 1)
        printf("The document is a palindrome.\n");
    else
        printf("The document is not a palindrome.\n");

    return 0;
}

********** OUTPUT **********

Enter a document: level
Reversed document: level
The document is a palindrome.

*/
