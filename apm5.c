/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 05
DATE: 

**********Data Cleaning Utility: Remove Duplicates**********

AIM: Create a program that takes a list of customer email addresses (stored in an array) and removes any 
     duplicates, ensuring that each email address is only represented once.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a function checkEmail() to verify whether an email address is valid.
Step 3: Read the number of customers n.
Step 4: Declare a two-dimensional character array email[n][100] to store the email addresses.
Step 5: Accept each customer's email address.
Step 6: Count the number of @ symbols and record the position of @.
Step 7: If the email does not contain exactly one @ symbol, consider it invalid.
Step 8: Check whether @ is the first character or whether there is any character after @.
Step 9: Search for a dot after the @ symbol.
Step 10: If the required conditions are not satisfied, display "Invalid Email! Enter again." and read the email again.
Step 11: Compare each email with the emails that appear after it.
Step 12: If two email addresses are identical, shift all following addresses one position to the left.
Step 13: Reduce the number of stored email addresses by one.
Step 14: Continue the comparison until all duplicate addresses are removed.
Step 15: Display the remaining email addresses.
Step 16: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int checkEmail(char email[])
{
    int i, atCount = 0;
    int atPosition = -1;
    int dotFound = 0;

    for(i = 0; email[i] != '\0'; i++)
    {
        if(email[i] == '@')
        {
            atCount++;
            atPosition = i;
        }
    }

    if(atCount != 1)
        return 0;

    if(atPosition <= 0)
        return 0;

    for(i = atPosition + 1; email[i] != '\0'; i++)
    {
        if(email[i] == '.')
        {
            dotFound = 1;
            break;
        }
    }

    if(email[atPosition + 1] == '\0')
        return 0;

    if(dotFound == 0)
        return 0;

    return 1;
}

int main()
{
    int n, i, j, k;
    int duplicate;

    printf("Enter the Number of Customers: ");
    scanf("%d", &n);

    char email[n][100];

    printf("Enter Customers Addresses:\n");

    for(i = 0; i < n; i++)
    {
        while(1)
        {
            printf("Customer %d: ", i + 1);
            scanf("%99s", email[i]);

            if(checkEmail(email[i]))
                break;

            printf("Invalid Email! Enter again.\n");
        }
    }

    /* Remove duplicate email addresses */

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            duplicate = 1;
            k = 0;

            while(email[i][k] != '\0' || email[j][k] != '\0')
            {
                if(email[i][k] != email[j][k])
                {
                    duplicate = 0;
                    break;
                }
                k++;
            }

            if(duplicate)
            {
                for(k = j; k < n - 1; k++)
                {
                    int p = 0;

                    while(email[k + 1][p] != '\0')
                    {
                        email[k][p] = email[k + 1][p];
                        p++;
                    }

                    email[k][p] = '\0';
                }

                n--;
                j--;
            }
        }
    }

    printf("\nEmail Addresses after Removing Duplicates:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s\n", email[i]);
    }

    return 0;
}

/* **********OUTPUT**********

Enter the Number of Customers: 5

Enter Customers Addresses:
Customer 1: nandha@gmail.com
Customer 2: student@gmail.com
Customer 3: example
Invalid Email! Enter again.
Customer 3: example@yahoo.com
Customer 4: nandha@gmail.com
Customer 5: college@university.in

Email Addresses after Removing Duplicates:
nandha@gmail.com
student@gmail.com
example@yahoo.com
college@university.in

*/    