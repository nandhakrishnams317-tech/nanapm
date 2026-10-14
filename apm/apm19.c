/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 19
DATE: 04-10-2026

**********File Utility Program**********

AIM: Write a utility that performs various file operations such as opening, reading, writing, appending, and closing files. This tool could be used to automate file handling in administrative tasks.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Display a menu containing the options Write, Read, Append, and Exit.
Step 3: Read the user's choice.
Step 4: If the choice is Write, accept the filename and open the file in write mode.
Step 5: Read text from the user and write it into the file until the user enters STOP.
Step 6: If the choice is Read, accept the filename and open the file in read mode.
Step 7: Display the contents of the file character by character until EOF is reached.
Step 8: If the choice is Append, accept the filename and open the file in append mode.
Step 9: Read additional text and append it to the file until the user enters STOP.
Step 10: Close the opened file after completing the selected operation.
Step 11: If the choice is invalid, display an error message.
Step 12: Repeat the menu until the user selects Exit.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInput() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void writeData() {
    char fileName[100], text[256];

    printf("Enter filename to write: ");
    scanf("%99s", fileName);
    clearInput();

    FILE *filePtr = fopen(fileName, "w");

    if (filePtr == NULL) {
        perror("Error opening file for writing");
        return;
    }

    printf("Enter text to write (type 'STOP' on a new line to finish):\n");

    while (fgets(text, sizeof(text), stdin) != NULL) {
        if (strcmp(text, "STOP\n") == 0 ||
            strcmp(text, "STOP") == 0)
            break;

        fputs(text, filePtr);
    }

    fclose(filePtr);
    printf("File written successfully.\n");
}

void readData() {
    char fileName[100];

    printf("Enter filename to read: ");
    scanf("%99s", fileName);
    clearInput();

    FILE *filePtr = fopen(fileName, "r");

    if (filePtr == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("\n--- Contents of '%s' ---\n", fileName);

    int ch;
    while ((ch = fgetc(filePtr)) != EOF) {
        putchar(ch);
    }

    printf("\n---------------------------\n");
    fclose(filePtr);
}

void appendData() {
    char fileName[100], text[256];

    printf("Enter filename to append: ");
    scanf("%99s", fileName);
    clearInput();

    FILE *filePtr = fopen(fileName, "a");

    if (filePtr == NULL) {
        perror("Error opening file for appending");
        return;
    }

    printf("Enter text to append (type 'STOP' on a new line to finish):\n");

    while (fgets(text, sizeof(text), stdin) != NULL) {
        if (strcmp(text, "STOP\n") == 0 ||
            strcmp(text, "STOP") == 0)
            break;

        fputs(text, filePtr);
    }

    fclose(filePtr);
    printf("Data appended successfully.\n");
}

int main() {
    int option;

    while (1) {
        printf("\n=== File Operations Utility ===\n");
        printf("1. Write to File (New/Overwrite)\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &option) != 1) {
            clearInput();
            printf("Invalid input.\n");
            continue;
        }

        clearInput();

        switch (option) {
            case 1:
                writeData();
                break;

            case 2:
                readData();
                break;

            case 3:
                appendData();
                break;

            case 4:
                printf("Exiting File Operations Utility.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


/* **********OUTPUT**********

=== File Operations Utility ===
1. Write to File (New/Overwrite)
2. Read File
3. Append to File
4. Exit
Enter your choice: 1
Enter filename to write: file1.txt
Enter text to write (type 'STOP' on a new line to finish):
Welcome to file handling
This is a sample program
STOP
File written successfully.

=== File Operations Utility ===
1. Write to File (New/Overwrite)
2. Read File
3. Append to File
4. Exit
Enter your choice: 2
Enter filename to read: file1.txt

--- Contents of 'file1.txt' ---
Welcome to file handling
This is a sample program

---------------------------

=== File Operations Utility ===
1. Write to File (New/Overwrite)
2. Read File
3. Append to File
4. Exit
Enter your choice: 3
Enter filename to append: file1.txt
Enter text to append (type 'STOP' on a new line to finish):
Additional text added
STOP
Data appended successfully.

=== File Operations Utility ===
1. Write to File (New/Overwrite)
2. Read File
3. Append to File
4. Exit
Enter your choice: 4
Exiting File Operations Utility.


*/    