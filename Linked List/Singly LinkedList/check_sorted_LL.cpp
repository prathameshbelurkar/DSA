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

int isSorted (struct Node *p){
    int x = -65536;

    while(p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {2,4,6,8,10};


    // ___________________________________________________________
    Create(A, 5);
    Display(first);

    if (isSorted(first))
    {
        printf("Sorted.\n");
    }
    else 
    {
        printf("Not Sorted.\n");
    }

return 0;
}