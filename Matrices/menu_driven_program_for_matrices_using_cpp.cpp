#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

// ___________________________ CLASS _________________________________
class Diagonal{
    private:
        int *A;
        int n;
    public:
        Diagonal(int n);
        void Create();
        int Get(int i, int j);
        void Set(int i, int j, int x);
        void Display();
        ~Diagonal();
};

// ___________________________ FUNCTIONS _________________________________
Diagonal :: Diagonal(int n){
    this->n = n;
    /*
    - For Lower/Upper Triangualar Matrices
        A = new int[n*(n+1)/2];
    - For Diagonal Matrix
        A = new int[n];
    */
    A = new int[n];
}

Diagonal :: ~Diagonal(){
    delete []A;
}

void Diagonal :: Create(){
    int i, j, x;
    for (j = 1; j <= n; j++)
    {
        for (j = 1; j <= n; j++)
        {
            cout<<"Enter Now: ";
            cin>>x;
            /*
            - For Diagonal Matrix
                if (i == j)
                    A[i-1]=x;

            - For Lower Triangular Matrices(Row Major/Column Major)
                if (i>=j)
                    A[i*(i-1)/2+j-1]=x;   OR   A[(j-1)*n-((j-2)*(j-1))/2+i-j]=x;

            - For Upper Triangular Matrices(Row Major/Column Major)
                if (i>=j)
                    A[(i-1)*n-((i-2)*(i-1))/2+j-i]=x;   OR   A[j*(j-1)/2+i-1]=x;

            */
            if (i == j)
                A[i - 1] = x;
        }
    }

}

void Diagonal :: Display(){
    int i, j, x;
    for (j = 1; j <= n; j++)
    {
        for (j = 1; j <= n; j++)
        {
           if (i == j)
                cout<<A[i-1]<<" ";
           else 
                cout<<"0 ";
        }
        cout<<endl;
    }

}



int main()
{
    // Will Get Updated Soon.
    

return 0;
}