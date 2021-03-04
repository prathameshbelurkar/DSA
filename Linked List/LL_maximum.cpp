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

int Max(struct Node *p){
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
    
}

int RMax(struct Node *p){
    int x = 0;
    if (p == 0)
        return INT32_MIN;
    x = RMax(p->next);
    return x > p->data ? x : p->data;
}

// #################################### MAIN ######################################
int main()
{ 
    // _______________________ VARIABLES _________________________
    int A[] = {7,8,9,5,4};


    // ___________________________________________________________
    Create(A, 5);
    Display(first);

    // printf("Maximum Element: %d\n", Max(first));

    printf("Maximum Element: %d\n", RMax(first));


return 0;
}