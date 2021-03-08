#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

int Rcount(struct Node *p){
    if (p != NULL)
        return Rcount(p->next) + 1;
    return 0;
}

int GetMiddle1(struct Node *p){
    int i;
    struct Node *q;
    q = p = first;

    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if(q)
            p = p->next;
    }
    return p->data;
}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {7,8,9,5,4,8,5,4,21,25,25};


    // ___________________________________________________________
    Create(A, 11);
    Display(first);

    printf("Middle Value: %d\n", GetMiddle1(first));


return 0;
}