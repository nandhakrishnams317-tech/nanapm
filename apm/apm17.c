/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 17
DATE: 02-10-2026

**********File Copying Using Command Line Arguments**********

AIM: Write a program that copies the contents of one file into another, using command-line arguments for file names. This utility could be used for backup or migration tasks in system administration. 
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Check whether the correct number of command-line arguments is provided.
Step 3: Open the source file in read mode.
Step 4: Check whether the source file is opened successfully. Display an error message if it fails.
Step 5: Open the destination file in write mode.
Step 6: Check whether the destination file is opened successfully. If it fails, close the source file and display an error message.
Step 7: Read each character from the source file until the end of the file is reached.
Step 8: Write each character into the destination file.
Step 9: Display a message confirming that the file contents have been copied.
Step 10: Close both files.
Step 11: Stop.


/* **********SOURCE CODE********** */



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *srcFile = fopen(argv[1], "r");

    if (srcFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *targetFile = fopen(argv[2], "w");

    if (targetFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile);
        return 1;
    }

    int character;

    while ((character = fgetc(srcFile)) != EOF) {
        fputc(character, targetFile);
    }

    printf("File data successfully copied from '%s' to '%s'.\n",
           argv[1], argv[2]);

    fclose(srcFile);
    fclose(targetFile);

    return 0;
}


/* **********OUTPUT**********


CS2024PG01@csserver:~/pg2026/apm/lablist-apm$ cat file1.txt file2.txt
This is always the starting file.
This is always the second file.

CS2024PG01@csserver:~/pg2026/apm/lablist-apm$ ./a.out file1.txt file2.txt
File data successfully copied from 'file1.txt' to 'file2.txt'.

*/    