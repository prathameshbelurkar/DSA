#include<stdio.h>
#include<stdlib.h>

// ____________________________________ STRUCTURE _____________________________________________
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

// ____________________________________ FUNCTIONS _____________________________________________
void Create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x){
    if ((q->rear + 1)%q->size  == q->front)
        printf("Queue is Full.\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q){
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is Empty.\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q){
    int i = q.front + 1;
    do
    {   
        printf("%d ", q.Q[i]);
        i = (i+1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    
    printf("\n");
}

// ###################################### MAIN ############################################
int main(){
    // __________________________________ VARIABLES ____________________________________
    struct Queue q;
    // _________________________________________________________________________________
    Create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    Display(q);

    printf("%d is Deleted.\n", dequeue(&q));
    Display(q);

    return 0;
}          
   