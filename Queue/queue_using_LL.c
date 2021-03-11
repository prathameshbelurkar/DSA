#include<stdio.h>
#include<stdlib.h>

// ______________________________ STRUCTURE ________________________________
struct Node{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

// _____________________________ FUNCTIONS _________________________________
void enqueue(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    
    if (t == NULL)
        printf("Queue is Full.\n");
    else 
    {
        t->data = x;
        t->next = NULL;

        if (front == NULL)
            front = rear = t; 
        else
        {
            rear->next = t;
            rear = t;
        }
    }
    
}

int dequeue(){
    int x=-1;
    struct node *t;

    if (front == NULL)
        printf("Queue is Empty.\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *t;
    t = front;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

// ################################ MAIN #####################################
int main(){
    // __________________________ VARIABLES _____________________________


    // __________________________________________________________________
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();


    printf("%d is Deleted.\n", dequeue());
    printf("%d is Deleted.\n", dequeue());
    printf("%d is Deleted.\nzz", dequeue());
    Display();


    return 0;
}