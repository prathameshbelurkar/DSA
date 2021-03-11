#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}


void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// To Calculate Precedence.
int pre(char x){
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// To Check Whether the Given Character is Operand or Not.
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

//To Evaluate Postfix Expression.
int Eval(char *postfix){
    int i=0;
    int x1, x2, r;

    for (i = 0;  postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            x2 = pop();
            x1 = pop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            
            case '-':
                r = x1 - x2;
                break;
            
            case '/':
                r = x1 / x2;
                break;
            
            case '*':
                r = x1 * x2;
                break;
            }
            
            push(r);
        }
    }
    
    return top->data;
}

// ########################################### MAIN #############################################################################
int main()
{
    // ____________________________ VARIABLES ____________________________________
    char *postfix = "234*+82/-";


    // ___________________________________________________________________________
    printf("Result is %d", Eval(postfix));


    return 0;
}