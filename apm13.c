/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 13
DATE: 

**********Text Editor: Substring Insertion**********

AIM: Create a text editor program that allows a user to insert a given substring at a specified position within an 
     existing string of text. This tool can help in editing and updating documents or code.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare character arrays text and insert to store the original string and substring.
Step 3: Declare integer variables position, i, and length.
Step 4: Read the original string from the user.
Step 5: Read the substring that needs to be inserted.
Step 6: Read the position where the substring should be inserted.
Step 7: Find the length of the original string using strlen().
Step 8: Remove the newline character from the original string and substring.
Step 9: Shift the characters of the original string towards the right to create space for the substring.
Step 10: Start from the specified position and make sufficient space for the substring.
Step 11: Copy the characters of the substring into the newly created space.
Step 12: Display the updated string after inserting the substring.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], insert[50];
    int position, i, length;
    printf("Enter the original string: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the substring to insert: ");
    fgets(insert, sizeof(insert), stdin);
    printf("Enter the position to insert: ");
    scanf("%d", &position);
    length = strlen(text);
    if (text[length - 1] == '\n')
        text[length - 1] = '\0';
    length = strlen(insert);
    if (insert[length - 1] == '\n')
        insert[length - 1] = '\0';
    for (i = strlen(text); i >= position; i--)
        text[i + strlen(insert)] = text[i];
    for (i = 0; insert[i] != '\0'; i++)
        text[position + i] = insert[i];
    printf("Updated text: %s\n", text);
    return 0;
}

/* **********OUTPUT**********

Enter the original string: Good Morning
Enter the substring to insert: Everyone 
Enter the position to insert: 5

Updated text: Good Everyone Morning
*/ 
