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

int Rcount(struct Node *p){
    if (p != NULL)
        return Rcount(p->next) + 1;
    return 0;
}

int Sum(struct Node *p){
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
    
}

int RSum(struct Node *p){
    if (p)
        return Sum(p->next) + p->data;
    return 0;
}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {7,8,9,5,4};


    // ___________________________________________________________
    Create(A, 5);
    Display(first);

    // printf("Length is %d\n", count(first));

    // printf("Length is %d\n", Rcount(first));

    printf("Sum is %d\n", Sum(first));

    // printf("Sum is %d\n", RSum(first));


return 0;
}