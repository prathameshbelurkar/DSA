#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// ____________________________ CLASS __________________________________
class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    private:
        Node *first;
    public:
        LinkedList(){ first = NULL; }
        LinkedList(int A[], int n);
        ~LinkedList();

        void Display();
        int Insert(int index, int x);        
        int Delete(int index);
        int Length();
};

// ____________________________ FUNCTIONS __________________________________
LinkedList :: LinkedList(int A[], int n){
    Node *last, *t;
    int i=0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 0; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last =t;
    }
    
}

LinkedList :: ~LinkedList(){
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
    
}

void LinkedList :: Display(){
    Node *p = first;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int LinkedList :: Length(){
    Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len; 
}

int LinkedList :: Insert(int index, int x){
    Node *t, *p = first;

    if (index < 0 || index > Length())
        return 0;
    
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
        first = t;
    else 
    {
        for (int i = 0; i < index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    return 1;
}

int LinkedList :: Delete(int index){
    Node *p, *q = NULL;
    int x = -1;

    if (index < 0 || index > Length())
        return x;
    
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;

}


// ################################## MAIN ###################################### 
int main()
{
    // _________________ VARIABLES AND OBJECTS _____________________
    int A[] = {1,2,3,4,5};
    LinkedList l(A, 5);

    // _____________________________________________________________
    l.Display();

return 0;
}