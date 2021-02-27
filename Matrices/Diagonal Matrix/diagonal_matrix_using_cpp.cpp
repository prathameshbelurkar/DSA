#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


// ______________________________ CLASS DIAGONAL MATRIX ___________________________________
class Diagonal{
    private:
        int *A;
        int n;
    public:
        Diagonal()
        {
            n = 2;
            A = new int[n];
        }
        Diagonal(int n)
        {
            this->n = n;
            A = new int[this->n];
        }
        ~Diagonal()
        {
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
};

// _______________________________________ FUNCTIONS ___________________________________________
void Diagonal :: Set(int i, int j, int x){
    if (i == j)
        A[i - 1] = x;
}

int Diagonal :: Get(int i, int j){
    if (i == j)
        return A[i-1];
    return 0;
}

void Diagonal :: Display(){
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == j)
                cout<<A[i]<<" ";
            else    
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

// ############################################ MAIN ################################################
int main()
{
    // __________________ VARIABLES _____________________
    Diagonal d(4);

    // __________________________________________________
    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,7);
    d.Set(4,4,6);
    d.Display();
    

return 0;
}