/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 20
DATE: 05-10-2026

**********File Merging**********

AIM: Create a program that merges the contents of two or more text files into a single file. This could be applied in scenarios such as aggregating log files or combining reports for analysis.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the number of input files to merge.
Step 3: Check whether at least two input files are specified.
Step 4: Read the name of the output file.
Step 5: Open the output file in write mode.
Step 6: Repeat the following steps for each input file.
Step 7: Read the input filename from the user.
Step 8: Open the input file in read mode. If it cannot be opened, display a warning and continue with the next file.
Step 9: Write a header containing the input filename into the output file.
Step 10: Read each character from the input file and write it into the output file until EOF is reached.
Step 11: Write an ending separator and close the input file.
Step 12: Close the output file after processing all input files.
Step 13: Display a success message.
Step 14: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int fileCount;
    char resultFile[100];

    printf("Enter number of files to merge: ");
    scanf("%d", &fileCount);

    if (fileCount <= 1) {
        printf("Error: Need at least 2 files to merge.\n");
        return 1;
    }

    printf("Enter output aggregated filename: ");
    scanf("%99s", resultFile);

    FILE *output = fopen(resultFile, "w");

    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }

    char inputName[100];

    for (int index = 0; index < fileCount; index++) {
        printf("Enter source file %d name: ", index + 1);
        scanf("%99s", inputName);

        FILE *input = fopen(inputName, "r");

        if (input == NULL) {
            perror("Warning: Could not open source file. Skipping");
            continue;
        }

        fprintf(output, "\n--- Start of File: %s ---\n", inputName);

        int character;

        while ((character = fgetc(input)) != EOF) {
            fputc(character, output);
        }

        fprintf(output, "\n--- End of File: %s ---\n", inputName);

        fclose(input);
    }

    fclose(output);

    printf("Successfully merged %d files into '%s'.\n",
           fileCount, resultFile);

    return 0;
}

/* **********OUTPUT**********


Enter number of files to merge: 2
Enter output aggregated filename: file3.txt
Enter source file 1 name: file1.txt
Enter source file 2 name: file2.txt
Successfully merged 2 files into 'file3.txt'.

Contents of file3.txt:

--- Start of File: file1.txt ---
This is the first file.

--- End of File: file1.txt ---

--- Start of File: file2.txt ---
This is the second file.

--- End of File: file2.txt ---

*/