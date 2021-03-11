// #include<iostream>
#include<stdio.h>
#include<stdlib.h>
// using namespace std;

// _______________________________ STRUCTURE _________________________________________
struct Node{
    char *data;
    struct Node *next;
}*top=NULL;

// _______________________________ FUNTIONS _________________________________________
void push(char x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("Stack Overflow.\n");
    else 
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop(){
    struct Node *t;
    char x=-1;
    if (top == NULL)
        printf("Stack Underflow. \n");
    else 
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(char *exp){
    int i;
    for(i=1; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
        
    }

    if (top == NULL)
        return 0;
    else 
        return 1;
}


// ######################################## MAIN #################################################
int main()
{
    // ________________________ VARIABLES ______________________________
    char *exp = "((a + b) * (c - d))";




    // _________________________________________________________________
    printf("Parenthesis match: %d", isBalanced(exp));



return 0;
}