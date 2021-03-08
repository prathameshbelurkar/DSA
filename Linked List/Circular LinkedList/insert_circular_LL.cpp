#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _______________________________ STRUCTURE ______________________________________
struct Node{
    int data;
    struct Node *next;
}*Head;

// _______________________________ FUNCTIONS ______________________________________
void Create(int A[], int n){
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Using do while loop.
void Display(struct Node *h){
    do
    {
        printf("%d ", h->data);
        h = h->next;

    } while (h != Head);
    printf("\n");
}

// Using Recursion
void RDisplay(struct Node *h){
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(struct Node *p){
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);

    return len;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;

    // Checking Whether the Index is Valid or Not.
    if (index<0 || index>Length(Head))
        return ;

    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else 
        {
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else 
    {
        for (i=0; i<index-1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }

}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {2,3,4,5,6};

    // ___________________________________________________________
    Create(A, 5);
    Display(Head);


    Insert(Head, 2, 10);
    Display(Head);


return 0;
}