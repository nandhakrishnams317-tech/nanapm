/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 03
DATE: 

**********Efficient Prime Number Generation**********

AIM: Implement the Sieve of Eratosthenes algorithm to generate a list of prime numbers up to a specified upper 
     limit (e.g., 10,000). This list will be used for efficient lookups in a mathematical application.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Get the upper limit n from the user.
Step 3: Declare an integer array prime of size n + 1.
Step 4: Initialize every element of the prime array with 1, indicating that the numbers are initially considered prime.
Step 5: Assign 0 to prime[0] and prime[1] since 0 and 1 are not prime numbers.
Step 6: Begin checking numbers from 2.
Step 7: Continue the checking process while i × i is less than or equal to n.
Step 8: If prime[i] is 1, consider i as a prime number.
Step 9: Starting from i × i, mark every multiple of i as 0.
Step 10: Increase the multiple by i and continue marking until the value exceeds n.
Step 11: Repeat Steps 7 to 10 for all required values of i.
Step 12: Traverse the prime array from 2 to n.
Step 13: If prime[i] is 1, print i as a prime number.
Step 14: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter the Upper limit:");
    scanf("%d", &n);

    int prime[n + 1];

    for(i = 0; i <= n; i++)
    {
        prime[i] = 1;
    }

    prime[0] = 0;
    prime[1] = 0;

    for(i = 2; i * i <= n; i++)
    {
        if(prime[i] == 1)
        {
            for(j = i * i; j <= n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }

    printf("\nPrime number upto %d are:\n", n);

    for(i = 2; i <= n; i++)
    {
        if(prime[i] == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}

/* **********OUTPUT**********

Enter the Upper limit:20

Prime number upto 20 are:
2 3 5 7 11 13 17 19

*/     
