#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
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

char pop()
{
    struct Node *t;
    char x = -1;

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

// Infix To Postfix.
char * InToPost(char *infix){
    // i = For Traversal in Infix String, j = vice-versa in Postfix String.
    int i=0, j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len+2) * sizeof(char));
    
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    // To copy all the remaining elements from the Stack to Postfix.
    while(top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0'; // adding null character to the last pos in postfix string.

    return postfix;

}

// ########################################### MAIN #############################################################################
int main()
{
    // ____________________________ VARIABLES ____________________________________
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix;

    // ___________________________________________________________________________
    postfix = InToPost(infix);
    printf("Postfix: %s", postfix);



    return 0;
}