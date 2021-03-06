#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _______________________________ STRUCTURE ______________________________________
struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;


// _______________________________ FUNCTIONS ______________________________________

//Creating a First LL
void Create1(int A[], int n){
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

//Creating a Second LL
void Create2(int A[], int n){
        int i;
        struct Node *t, *last;
        second = (struct Node *)malloc(sizeof(struct Node));
        second->data = A[0];
        second->next = NULL;
        last = second;

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

void Concat(struct Node *p, struct Node *q){
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;

}

// Merging of Two Sorted LL
void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else 
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else 
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    
    // Linking remaining LL Nodes in either p or q.
    if (p) 
        last->next = p;
    if (q) 
        last->next = q;

}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {2,4,6,8,10};
    int B[] = {1,3,5,7,9};


    // ___________________________________________________________
    Create1(A, 5);
    Create2(B, 5);

    /*
    // Concatenation of two LL

    printf("First LL: \n");
    Display(first);
    printf("Second LL: \n");
    Display(second);
    printf("\n\n");

    printf("Concatenated LL: \n");
    Concat(first, second);
    Display(third);
    printf("\n\n");
    */

    
    // Merging of two Sorted LL.

    printf("First LL: \n");
    Display(first);
    printf("Second LL: \n");
    Display(second);
    printf("\n\n");

    printf("Merged LL: \n");
    Merge(first, second);
    Display(third);
    printf("\n\n");
   





return 0;
}