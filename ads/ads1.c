/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 01
DATE: 21-07-2026

**********Stacks Using Arrays**********

AIM: Implementation of stacks using arrays
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

int top = -1;

void push(int stack[], int size)
{
    int item;

    printf("Enter the value you want to push: ");
    scanf("%d", &item);

    if (top == size - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = item;
        printf("Value pushed successfully");
    }
}

void pop(int stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Popped value: %d", stack[top]);
        top--;
    }
}

void peek(int stack[])
{
    if (top == -1)
    {
        printf("\nNo values entered");
    }
    else
    {
        printf("Top value: %d", stack[top]);
    }
}

int main()
{
    int size, choice;

    printf("Enter the size of stack: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid stack size");
        return 0;
    }

    int stack[size];
    int running = 1;

    while (running)
    {
        printf("\n\nEnter the operation you want to perform:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push(stack, size);
                break;

            case 2:
                pop(stack);
                break;

            case 3:
                peek(stack);
                break;

            case 4:
                running = 0;
                break;

            default:
                printf("Invalid Option");
        }
    }

    return 0;
}


/* **********OUTPUT**********


Enter the size of stack: 3

Enter the operation you want to perform:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter the value you want to push: 10
Value pushed successfully

Enter the operation you want to perform:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter the value you want to push: 20
Value pushed successfully

Enter the operation you want to perform:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 3
Top value: 20

Enter the operation you want to perform:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 2
Popped value: 20

Enter the operation you want to perform:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 3
Top value: 10

Enter the operation you want to perform:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 4


*/