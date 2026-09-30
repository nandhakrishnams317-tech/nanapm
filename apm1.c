/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 01
DATE: 

**********Character Analysis Tool**********

AIM: Write a program to develop a simple text analysis tool that takes an input string and categorizes each 
     character as a vowel, consonant, or other (special character, number, etc.) using a switch statement.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a character array str[100] and initialize counters for vowels, consonants, digits, and other characters to zero.
Step 3: Read a string from the user using fgets().
Step 4: Find the length of the string using strlen().
Step 5: Traverse each character of the string using a for loop.
Step 6: Convert the current character to lowercase using tolower().
Step 7: Check whether the character is an alphabet using isalpha().
Step 8: If it is an alphabet, check whether it is a vowel (a, e, i, o, u).
Step 9: If it is a vowel, display Vowel and increment the vowel counter.
Step 10: Otherwise, display Consonant and increment the consonant counter.
Step 11: If the character is not an alphabet, check whether it is a digit using isdigit().
Step 12: If it is a digit, display Digit and increment the digit counter.
Step 13: Otherwise, check whether the character is a punctuation character using ispunct().
Step 14: If it is a punctuation character, display Others and increment the punctuation counter.
Step 15: Repeat Steps 6 to 14 until all characters in the string are processed.
Step 16: Display the total number of vowels, consonants, digits, and other characters.
Step 17: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int vowel = 0, consonant = 0, digit = 0, punct = 0;
    int i, len;

    printf("Enter the String: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    printf("\nCharacter Breakdown:\n");

    for(i = 0; i < len; i++)
    {
        char c = tolower((unsigned char)str[i]);

        if(isalpha((unsigned char)str[i]))
        {
            if(c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u')
            {
                printf("%c - Vowel\n", str[i]);
                vowel++;
            }
            else
            {
                printf("%c - Consonant\n", str[i]);
                consonant++;
            }
        }
        else if(isdigit((unsigned char)str[i]))
        {
            printf("%c - Digit\n", str[i]);
            digit++;
        }
        else if(ispunct((unsigned char)str[i]))
        {
            printf("%c - Others\n", str[i]);
            punct++;
        }
    }

    printf("\nSummary: %d Vowels, %d Consonants, %d Digits, %d Others\n",
           vowel, consonant, digit, punct);

    return 0;
}

/* **********OUTPUT**********

Enter the String: nan@3

Character Breakdown:
n - Consonant
a - Vowel
n - Consonant
@ - Others
3 - Digit

Summary: 1 Vowels, 2 Consonants, 1 Digits, 1 Others

*/