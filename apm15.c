/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 15
DATE: 

**********Complex Number Calculator for Engineering Simulations**********

AIM: Develop a program that allows the user to input two complex numbers and calculates their sum and 
     difference. This program could be applied in simulations for electrical engineering or physics problems.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a structure Complex containing real and imaginary parts.
Step 3: Declare Complex variables num1, num2, sum, and difference.
Step 4: Display a message to enter the real and imaginary parts of the first complex number.
Step 5: Read and store the values in num1.
Step 6: Display a message to enter the real and imaginary parts of the second complex number.
Step 7: Read and store the values in num2.
Step 8: Add the real parts of num1 and num2 and store the result in sum.
Step 9: Add the imaginary parts of num1 and num2 and store the result in sum.
Step 10: Subtract the real part of num2 from num1 and store the result in difference.
Step 11: Subtract the imaginary part of num2 from num1 and store the result in difference.
Step 12: Display the sum and difference of the two complex numbers.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

int main()
{
    struct Complex num1, num2, sum, difference;

    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;

    difference.real = num1.real - num2.real;
    difference.imag = num1.imag - num2.imag;

    printf("\nSum = %.2f + %.2fi", sum.real, sum.imag);
    printf("\nDifference = %.2f + %.2fi", difference.real, difference.imag);

    return 0;
}

/* **********OUTPUT**********

Enter real and imaginary parts of first complex number: 6 4
Enter real and imaginary parts of second complex number: 3 2

Sum = 9.00 + 6.00i
Difference = 3.00 + 2.00i

*/    