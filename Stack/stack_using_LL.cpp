#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

// _______________________________ STRUCTURE _________________________________________
struct Node{
    int data;
    struct Node *next;
}*top=NULL;

// _______________________________ FUNTIONS _________________________________________
void push(int x){
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

int pop(){
    struct Node *t;
    int x=-1;
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



// ######################################## MAIN #################################################
int main()
{
    // ________________________ VARIABLES ______________________________

    // _________________________________________________________________
    push(10);    
    push(20);    
    push(30);    

    Display();

    printf("%d \n", pop());

    Display();

return 0;
}