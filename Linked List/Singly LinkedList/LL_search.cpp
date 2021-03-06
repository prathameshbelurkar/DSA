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

struct Node * LSearch(struct Node *p, int key){
    while(p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node * ImprovedLSearch(struct Node *p, int key){
    struct Node *q = NULL;
    while(p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node * RLSearch(struct Node *p, int key){
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RLSearch(p->next, key);
}

// #################################### MAIN ######################################
int main()
{
    // _______________________ VARIABLES _________________________
    int A[] = {7,8,9,5,4};
    struct Node *temp;


    // ___________________________________________________________
    Create(A, 5);
    Display(first);

    // temp = LSearch(first, 9);
    // temp = RLSearch(first, 9);
    temp = ImprovedLSearch(first, 9);

    if (temp)
        printf("Element %d found.\n", temp->data);
    else 
        printf("Element Not Found!\n");
    
    Display(first);

    


return 0;
}