#ifndef QueueCpp_h
#define QueueCpp_h
#include<iostream>
#include<stdio.h>
using namespace std;

// ___________________________ TREE NODE ______________________________________
class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};


// _____________________________ QUEUE _____________________________________
class Queue{
    private:
        int size;
        int front;
        int rear;
        Node **Q;
    public:
        Queue(){
            front = rear = -1;
            size = 10;
            Q = new Node*[size];
        }
        Queue(int size){
            front = rear = -1;
            this->size = size;
            Q = new Node*[this->size];
        }
        void Create(int size);
        int isEmpty();
        void enqueue(Node* x);
        Node* dequeue();
        void Display();
};

// ________________________________ FUNCTIONS __________________________________________
void Queue :: Create(int size){
    size = size;
    front = rear = 0;
    *Q = new Node;
}

int Queue :: isEmpty(){
    return front == rear;
}

void Queue :: enqueue(Node* x){
    if (rear == size-1)
        cout<<"Queue is Full."<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue :: dequeue(){
    Node* x = NULL;
    if (rear == front)
        cout<<"Queue is Empty."<<endl;
    else
    {
        x = Q[front + 1];
        front++;
    } 
    return x;
}

void Queue :: Display(){
    int i=0;
    for (i=front+1; i<=rear; i++)    
        cout<<Q[i]<<" ";
    cout<<endl;
}

#endif