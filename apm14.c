/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 14
DATE: 26-09-2026

**********Recursion-Based Sentence Reversal for Voice Transcription**********

AIM: Write a program that reverses the words of a sentence, using recursion. This could be applied in a speech-
     to-text application where the order of words needs to be reversed for analysis.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a character array str[200] to store the sentence.
Step 3: Read the sentence from the user.
Step 4: Remove the newline character from the entered sentence.
Step 5: Find the total length of the sentence.
Step 6: Call the reverseWords() function with the starting and ending positions.
Step 7: Search for the space character to identify the end of the current word.
Step 8: If the end of the sentence is reached, display the current word.
Step 9: Otherwise, recursively call reverseWords() to process the remaining words.
Step 10: Display the current word after the recursive call is completed.
Step 11: Continue the recursive process until all words are displayed in reverse order.
Step 12: Display the reversed sentence.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <string.h>

void reverseWords(char str[], int start, int end)
{
    int i;

    for (i = start; i < end && str[i] != ' '; i++);

    if (i == end)
    {
        printf("%.*s", end - start, str + start);
        return;
    }

    reverseWords(str, i + 1, end);

    printf(" %.*s", i - start, str + start);
}

int main()
{
    char str[200];

    printf("Enter the sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Reversed sentence: ");
    reverseWords(str, 0, strlen(str));

    return 0;
}

/* **********OUTPUT**********

Enter the sentence: Computer science is interesting
Reversed sentence: interesting is science Computer

*/