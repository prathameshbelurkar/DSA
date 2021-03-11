#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// ______________________________________________ CLASS ____________________________________________________
class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){top = NULL;}
        void push(int x);
        int pop();
        void Display();
};
// ___________________________________________ FUNCTIONS ___________________________________________________

void Stack :: push(int x){
    Node *t = new Node;
    if (t == NULL)
        cout<<"Stack Overflow"<<endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack :: pop(){
    int x=-1;
    if (top == NULL)
        cout<<"Stack Underflow."<<endl;
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack :: Display(){
    Node *p = top;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

// ############################################# MAIN ######################################################
int main()
{
    // __________________________ VARIABLES AND OBJECTS __________________________
    Stack stk;

    // ___________________________________________________________________________
    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.Display();

    cout<<stk.pop()<<endl;
    stk.Display();

return 0;
}