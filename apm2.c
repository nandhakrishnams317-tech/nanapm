/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 02
DATE: 28-09-2026

**********Prime Number Finder for Data Processing**********

AIM: Write a program that scans a list of numbers and identifies which ones are prime. It should store the prime 
     numbers separately for further processing.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a function checkPrime() to identify whether a given number is prime or not.
Step 3: Pass the number to the checkPrime() function.
Step 4: If the number is less than 2, return 0 because it is not prime.
Step 5: Initialize a loop variable i with value 2.
Step 6: Check the divisibility of the number by each value from 2 to n/2.
Step 7: If the number is exactly divisible by any value of i, return 0.
Step 8: If no divisor is found, return 1 indicating that the number is prime.
Step 9: In the main() function, input the total number of elements n.
Step 10: Declare an array arr to store the given numbers.
Step 11: Declare another array prime to store only the prime numbers.
Step 12: Read n numbers from the user and store them in the arr array.
Step 13: Pass each element of arr to the checkPrime() function.
Step 14: If the function returns 1, store that element in the prime array.
Step 15: Increase the prime number counter after storing each prime number.
Step 16: Repeat the checking process until all n elements are examined.
Step 17: Display all the elements stored in the prime array.
Step 18: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int checkPrime(int num)
{
    int i;

    if(num < 2)
        return 0;

    for(i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n, i, count = 0;

    printf("Enter the Number of Elements:");
    scanf("%d", &n);

    int arr[n], prime[n];

    printf("Enter %d Numbers:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if(checkPrime(arr[i]) == 1)
        {
            prime[count] = arr[i];
            count++;
        }
    }

    printf("\nPrime Numbers are:");

    for(i = 0; i < count; i++)
    {
        printf("%d ", prime[i]);
    }

    return 0;
}

/* **********OUTPUT**********

Enter the Number of Elements:5
Enter 5 Numbers:
7
10
13
15
20

Prime Numbers are:7 13
*/     