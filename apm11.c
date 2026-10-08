/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 11
DATE: 13-09-2026

**********String Manipulation Utility**********

AIM: Create an application that implements a suite of string functions like concatenation, comparison, and 
     conversion (uppercase to lowercase), which can be applied to a list of user-provided strings.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare three character arrays str1, str2, and result.
Step 3: Read the first string from the user.
Step 4: Read the second string from the user.
Step 5: Remove the newline character from both strings.
Step 6: Copy the first string into result.
Step 7: Concatenate the second string to result.
Step 8: Compare the two strings using strcmp().
Step 9: Display whether the two strings are equal or not.
Step 10: Convert all characters of the first string to lowercase using tolower().
Step 11: Convert all characters of the second string to uppercase using toupper().
Step 12: Display the concatenated string, comparison result, lowercase first string, and uppercase second string.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str1[100], str2[100], result[200];
    int i;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    strcpy(result, str1);
    strcat(result, str2);

    printf("\n--- String Operations ---\n");
    printf("Concatenation: %s\n", result);

    if (strcmp(str1, str2) == 0)
        printf("Comparison: Strings are equal\n");
    else
        printf("Comparison: Strings are not equal\n");

    for (i = 0; str1[i] != '\0'; i++)
        str1[i] = tolower(str1[i]);

    printf("First string in lowercase: %s\n", str1);

    for (i = 0; str2[i] != '\0'; i++)
        str2[i] = toupper(str2[i]);

    printf("Second string in uppercase: %s\n", str2);

    return 0;
}
/* **********OUTPUT**********

Enter first string: HELLO
Enter second string: world

--- String Operations ---
Concatenation: HELLOworld
Comparison: Strings are not equal
First string in lowercase: hello
Second string in uppercase: WORLD

*/
