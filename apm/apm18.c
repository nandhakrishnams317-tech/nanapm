/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 18
DATE: 03-10-2026

**********String Reversal and Insertion********** 
AIM: Develop a program that takes a text file, reverses the content of the first 'n' characters, and writes the result to another file. This could be useful for data manipulation or encryption tasks.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the source file name, destination file name, and number of characters n from the user.
Step 3: Check whether n is greater than zero. Display an error message if it is not.
Step 4: Open the source file in read mode.
Step 5: Check whether the source file is opened successfully.
Step 6: Open the destination file in write mode and check whether it is opened successfully.
Step 7: Allocate memory dynamically to store the first n characters.
Step 8: Read up to n characters from the source file and record the actual number of characters read.
Step 9: Reverse the characters in the buffer using a two-pointer approach.
Step 10: Write the reversed characters into the destination file.
Step 11: Copy the remaining characters from the source file to the destination file without changing their order.
Step 12: Display a success message.
Step 13: Free the allocated memory and close both files.
Step 14: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputFile[100], outputFile[100];
    int limit;

    printf("Enter source file name: ");
    scanf("%99s", inputFile);

    printf("Enter destination file name: ");
    scanf("%99s", outputFile);

    printf("Enter number of characters to reverse (n): ");
    scanf("%d", &limit);

    if (limit <= 0) {
        printf("Error: 'n' must be greater than 0.\n");
        return 1;
    }

    FILE *inFile = fopen(inputFile, "r");

    if (inFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *outFile = fopen(outputFile, "w");

    if (outFile == NULL) {
        perror("Error opening destination file");
        fclose(inFile);
        return 1;
    }

    char *textBuffer = (char *)malloc((limit + 1) * sizeof(char));

    if (textBuffer == NULL) {
        perror("Memory allocation failed");
        fclose(inFile);
        fclose(outFile);
        return 1;
    }

    int count = 0;

    while (count < limit) {
        int value = fgetc(inFile);

        if (value == EOF)
            break;

        textBuffer[count] = (char)value;
        count++;
    }

    textBuffer[count] = '\0';

    int left = 0;
    int right = count - 1;

    while (left < right) {
        char temp = textBuffer[left];
        textBuffer[left] = textBuffer[right];
        textBuffer[right] = temp;

        left++;
        right--;
    }

    fputs(textBuffer, outFile);

    int value;

    while ((value = fgetc(inFile)) != EOF) {
        fputc(value, outFile);
    }

    printf("Successfully reversed first %d characters and written to '%s'.\n",
           count, outputFile);

    free(textBuffer);
    fclose(inFile);
    fclose(outFile);

    return 0;
}


/* **********OUTPUT**********

Contents of file1.txt:
This is always the starting file.

Enter source file name: file1.txt
Enter destination file name: file2.txt
Enter number of characters to reverse (n): 10
Successfully reversed first 10 characters and written to 'file2.txt'.

Contents of file2.txt:
la syaw si sihT the starting file.


*/    