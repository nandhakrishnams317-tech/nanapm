/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 16
DATE: 

**********Employee Management System**********

AIM: Create an application to manage employee data using structures. The program should allow input, display, 
     and update employee details such as name, ID, salary, and department.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a structure Employee with members id, name, salary, and department.
Step 3: Declare a structure variable emp.
Step 4: Read the employee ID.
Step 5: Read the employee name.
Step 6: Read the employee salary.
Step 7: Read the employee department.
Step 8: Display all the employee details.
Step 9: Ask the user whether they want to update the employee details.
Step 10: If the user selects 1, read the new name, salary, and department.
Step 11: Update the employee details with the new values.
Step 12: Display the updated employee details.
Step 13: If the user selects 0, keep the existing details.
Step 14: Stop.

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
    struct Employee emp;
    int choice;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    printf("Enter Department: ");
    scanf(" %[^\n]", emp.department);

    // Display details
    printf("\n--- Employee Details ---\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    printf("Department: %s\n", emp.department);

    // Update employee details
    printf("\nDo you want to update the details? (1-Yes / 0-No): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nEnter New Name: ");
        scanf(" %[^\n]", emp.name);

        printf("Enter New Salary: ");
        scanf("%f", &emp.salary);

        printf("Enter New Department: ");
        scanf(" %[^\n]", emp.department);

        printf("\n--- Updated Employee Details ---\n");
        printf("ID: %d\n", emp.id);
        printf("Name: %s\n", emp.name);
        printf("Salary: %.2f\n", emp.salary);
        printf("Department: %s\n", emp.department);
    }

    return 0;
}

/* **********OUTPUT**********

Enter Employee ID: 101
Enter Employee Name: Anirudh
Enter Salary: 35000
Enter Department: Computer Science

--- Employee Details ---
ID: 101
Name: Anirudh
Salary: 35000.00
Department: Computer Science

Do you want to update the details? (1-Yes / 0-No): 0

*/    