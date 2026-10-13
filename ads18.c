/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 18
DATE: 18-07-2026

**********Priority Queue********** 
AIM: Implementation of Priority Queue.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize the queue size to -1 and define the maximum capacity as 100.
Step 3: Display the menu with Enqueue, Dequeue, Display, and Exit options.
Step 4: Read the user's choice.
Step 5: If the choice is 1, read the value and its priority. Check whether the queue is full. If space is available, insert the value and priority into the queue and increase the size.
Step 6: If the choice is 2, check whether the queue is empty. If empty, display an underflow message.
Step 7: Otherwise, find the element with the highest priority. If two elements have the same priority, select the element with the larger value.
Step 8: Display and delete the selected element. Shift the remaining elements and decrease the queue size.
Step 9: If the choice is 3, display all values and their priorities. If the queue is empty, display an empty message.
Step 10: If the choice is 4, terminate the program.
Step 11: If the choice is invalid, display an error message.
Step 12: Repeat Steps 3 to 11 until the user chooses to exit.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */


#include <stdio.h>
#define MAX 100

struct Item
{
    int value;
    int priority;
};

struct Item queue[MAX];
int count = -1;

void insertItem(int value, int priority)
{
    if (count >= MAX - 1)
    {
        printf("Priority Queue Overflow!\n");
        return;
    }

    count++;
    queue[count].value = value;
    queue[count].priority = priority;
}

int findHighest()
{
    int high = -1089203;
    int index = -1;

    for (int i = 0; i <= count; i++)
    {
        if (queue[i].priority == high &&
            index != -1 &&
            queue[i].value > queue[index].value)
        {
            high = queue[i].priority;
            index = i;
        }
        else if (queue[i].priority > high)
        {
            high = queue[i].priority;
            index = i;
        }
    }

    return index;
}

void removeItem()
{
    if (count < 0)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    int index = findHighest();

    printf("Deleted element: %d\n", queue[index].value);

    for (int i = index; i < count; i++)
    {
        queue[i] = queue[i + 1];
    }

    count--;
}

void showQueue()
{
    if (count < 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    for (int i = 0; i <= count; i++)
    {
        printf("Value: %d, Priority: %d\n",
               queue[i].value, queue[i].priority);
    }
}

int main()
{
    int choice, num, pri;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &num, &pri);
                insertItem(num, pri);
                break;

            case 2:
                removeItem();
                break;

            case 3:
                showQueue();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


/* **********OUTPUT**********

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 40 3

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 60 5

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 25 2

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 80 4

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Value: 40, Priority: 3
Value: 60, Priority: 5
Value: 25, Priority: 2
Value: 80, Priority: 4

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 2
Deleted element: 60

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Value: 40, Priority: 3
Value: 25, Priority: 2
Value: 80, Priority: 4

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 4

*/    