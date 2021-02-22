#include<iostream>
using namespace std;

// __________________________________ CLASS ARRAY _______________________________________
template<class T>
class Array
{
    private:
        T *A;
        int size;
        int length;
    public:
        Array()
        {
            size = 10;
            A = new T[10];
            length = 0;
        }

        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new T[size];
        }

        ~Array()
        {
            delete []A;
        }

        // _______ FUNCTION PROTOTYPES _____
        void Display();
        void Insert(int index, T x);
        T Delete(int index);
};

// __________________________________ FUNCTIONS _______________________________________
template<class T>
void Array<T> :: Display(){
    cout<<"Elements are: ";
    for (int i=0; i<length; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}


template<class T>
void Array<T> :: Insert(int index, T x){
    if (index>=0 && index<=length)
    {
        for(int i = length-1; i >= index; i--)
            A[i+1] = A[i];
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T> :: Delete(int index){
    T x = 0;
    if (index>=0 && index<=length)
    {
        x = A[index];
        for(int i = index; i<length-1 ;i++)
            A[i] = A[i+1];
        length--;
        return x;
    }
    return -1;
}

// ############################## MAIN #####################################
int main()
{
    // __________________ VARIABLES AND OBJECTS ______________________
    Array<int> arr(10);

    // _______________________________________________________________
    arr.Insert(0, 2);
    arr.Insert(1, 4);
    arr.Insert(2, 5);
    arr.Insert(3, 7);
    arr.Display();
    cout<<arr.Delete(2)<<" is Deleted."<<endl;
    arr.Display();



return 0;
}