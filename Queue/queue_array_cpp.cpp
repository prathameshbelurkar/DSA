#include<iostream>
using namespace std;
// __________________________________ CLASS __________________________________________
class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue(){
            front = rear = -1;
            size = 10;
            Q = new int[size];
        }
        Queue(int size){
            front = rear = -1;
            this->size = size;
            Q = new int[this->size];
        }
        void enqueue(int x);
        int dequeue();
        void Display();
};

// ________________________________ FUNCTIONS __________________________________________
void Queue :: enqueue(int x){
    if (rear == size-1)
        cout<<"Queue is Full."<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue :: dequeue(){
    int x = -1;
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

// ######################################## MAIN ############################################
int main()
{
    // _______________________________ VARIABLES AND OBJECTS ______________________________
    Queue q(5);

    // ____________________________________________________________________________________
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();

    cout<<q.dequeue()<<" is Deleted."<<endl;;
    q.Display();

return 0;
}