/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 13
DATE: 25-09-2026

**********Infix To Postfix Using Stacks**********

AIM: Conversion  of  an  infix  expression  to  the  postfix  form  using  stacks.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a stack and initialize "top = -1".
Step 3: Read the infix expression from the user.
Step 4: Scan the infix expression from left to right.
Step 5: If the character is an operand, append it to the postfix expression.
Step 6: If the character is an opening parenthesis "(", push it onto the stack.
Step 7: If the character is a closing parenthesis ")", pop operators and append them to the postfix expression until "(" is found. Remove the opening parenthesis from the stack.
Step 8: If the character is an operator, pop operators with higher precedence, or equal precedence when the current operator is not "^", and append them to the postfix expression. Then push the current operator onto the stack.
Step 9: Repeat steps 5 to 8 until the entire infix expression has been scanned.
Step 10: Pop all remaining operators from the stack and append them to the postfix expression.
Step 11: Add the null character "'\0'" at the end of the postfix expression.
Step 12: Display the postfix expression.
Step 13: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <ctype.h>

char operators[100];
int top = -1;

void push(char ch)
{
    operators[++top] = ch;
}

char pop()
{
    return operators[top--];
}

int getPriority(char ch)
{
    switch (ch)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main()
{
    char infix[100], postfix[100];
    int i, k = 0;
    char symbol;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];

        if (isalnum((unsigned char)symbol))
        {
            postfix[k++] = symbol;
        }
        else if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while (top != -1 && operators[top] != '(')
            {
                postfix[k++] = pop();
            }

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && operators[top] != '(' &&
                   (getPriority(operators[top]) > getPriority(symbol) ||
                   (getPriority(operators[top]) == getPriority(symbol)
                    && symbol != '^')))
            {
                postfix[k++] = pop();
            }

            push(symbol);
        }
    }

    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


/* **********OUTPUT**********

Enter infix expression: (A+B)*C-D/E
Postfix expression: AB+C*DE/-
*/ 