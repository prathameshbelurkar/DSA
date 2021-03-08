#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _________________________________ STRUCTURE ______________________________________
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

// _________________________________ FUNCTIONS ______________________________________
void create(int A[], int n){
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node *p){
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// ######################################### MAIN ###############################################
int main()
{
    // ____________________________________ VARIABLES _________________________________________
    int A[] = {10,20,30,40,50};

    // ________________________________________________________________________________________
    create(A, 5);
    printf("Length is : %d\n", Length(first));
    Display(first);

return 0;
}