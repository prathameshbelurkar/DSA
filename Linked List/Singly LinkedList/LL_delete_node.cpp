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

int Delete(struct Node *p, int index){
    struct Node *q = NULL;
    int x = -1, i;

    if (index<0 || index>count(first))
        return -1;
    if (index == 1) 
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else 
    {
        for(i=0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }

}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {7,8,9,5,4};


    // ___________________________________________________________
    Create(A, 5);
    Display(first);

    printf("Deleted Element: %d\n", Delete(first, 1));
    Display(first);



return 0;
}