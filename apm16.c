/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 16
DATE: 

**********Employee Management System**********

AIM: Create an application to manage employee data using structures. The program should allow input, display, 
     and update employee details such as name, ID, salary, and department.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a structure Employee with members id, name, salary, and department.
Step 3: Declare a structure variable employee and an integer variable option.
Step 4: Display a message to enter the employee ID and read the ID.
Step 5: Read and store the employee name.
Step 6: Read and store the employee salary.
Step 7: Read and store the employee department.
Step 8: Display all the entered employee information.
Step 9: Ask the user whether the employee details need to be updated.
Step 10: Read the user's choice.
Step 11: If the choice is 1, read the new name, salary, and department.
Step 12: Store the new values in the corresponding structure members.
Step 13: Display the updated employee information.
Step 14: If the choice is 0, retain the existing employee information.
Step 15: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
    char department[30];
};

int main()
{
    struct Employee employee;
    int option;

    printf("Enter Employee ID: ");
    scanf("%d", &employee.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employee.name);

    printf("Enter Salary: ");
    scanf("%f", &employee.salary);

    printf("Enter Department: ");
    scanf(" %[^\n]", employee.department);

    printf("\n--- Employee Details ---\n");
    printf("ID: %d\n", employee.id);
    printf("Name: %s\n", employee.name);
    printf("Salary: %.2f\n", employee.salary);
    printf("Department: %s\n", employee.department);

    printf("\nDo you want to update the details? (1-Yes / 0-No): ");
    scanf("%d", &option);

    if (option == 1)
    {
        printf("\nEnter New Name: ");
        scanf(" %[^\n]", employee.name);

        printf("Enter New Salary: ");
        scanf("%f", &employee.salary);

        printf("Enter New Department: ");
        scanf(" %[^\n]", employee.department);

        printf("\n--- Updated Employee Details ---\n");
        printf("ID: %d\n", employee.id);
        printf("Name: %s\n", employee.name);
        printf("Salary: %.2f\n", employee.salary);
        printf("Department: %s\n", employee.department);
    }

    return 0;
}

/* OUTPUT
Enter Employee ID: 102
Enter Employee Name: Nandha
Enter Salary: 42000
Enter Department: Computer Science

--- Employee Details ---
ID: 102
Name: Nandha
Salary: 42000.00
Department: Computer Science

Do you want to update the details? (1-Yes / 0-No): 0

*/    