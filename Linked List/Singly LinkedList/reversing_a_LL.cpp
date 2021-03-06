#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _______________________________ STRUCTURE ______________________________________
struct Node{
    int data;
    struct Node *next;
}*first = NULL;


// _______________________________ FUNCTIONS ______________________________________
void Create(int A[], int n){
        int i;
        struct Node *t, *last;
        first = (struct Node *)malloc(sizeof(struct Node));
        first->data = A[0];
        first->next = NULL;
        last = first;

        for(i=1; i<n; i++)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
}

void Display(struct Node *p){
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p){
    int l=0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
    
}

//Using an Auxillary Array.
void Reverse1(struct Node *p){
    int *A, i = 0;
    struct Node *q;
    q = p;

    A = (int *)malloc(count(p) * sizeof(int));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;

    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }

}

//Using Pointer Sliding (i.e: By Using Three Pointers).
void Reverse2(struct Node *p){
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    
    first = q;

}

//Using Recursion.
void Reverse3(struct Node *q, struct Node *p){

    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else 
        first = q;

}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {7,8,9,5,4};


    // ___________________________________________________________
    Create(A, 5);
    Display(first);

    // Reverse1(first);
    // Display(first);

    // Reverse2(first);
    // Display(first);

    Reverse3(NULL, first);
    Display(first);




return 0;
}