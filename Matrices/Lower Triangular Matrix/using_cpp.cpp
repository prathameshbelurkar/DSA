#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


// ___________________________ CLASS LOWERTRIANGULAR ________________________________

/*
NOTE:
For Conversion of Row Major to Column Major Formulae is (n*(j-1)-(j-2)*(j-1)/2+i-j).
*/

class LowerTriangular{
    private:
        int *A;
        int n;
    public:
        LowerTriangular()
        {
            n = 2;
            A = new int[2*(2+1)/2];
        }
        LowerTriangular(int n)
        {
            this->n = n;
            A = new int[n*(n+1)/2];
        }
        ~LowerTriangular()
        {
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        int GetDimension(){return n;}
};

// _________________________________ FUNCTIONS _________________________________________
void LowerTriangular :: Set(int i, int j, int x){
    if (i >= j)
        A[i*(i-1)/2+j-1] = x;
}

int LowerTriangular :: Get(int i, int j){
    if (i >= j)
        return A[i*(i-1)/2+j-1];
    else 
        return 0;
}

void LowerTriangular :: Display(){
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i >= j)
                cout<<A[i*(i-1)/2+j-1]<<" ";
            else 
                cout<<"0 ";
        }
        cout<<endl;
    }
}


// ################################### MAIN ########################################
int main()
{

    // ___________________ VARIABLES _____________________
    int d, x, i, j;


    // ___________________________________________________
    cout<<"Enter Dimensions: ";
    cin>>d;

    LowerTriangular lm(d);
    
    cout<<"Enter all Elements: "<<endl;
    for (i=0; i<=d; i++)
    {
        for (j=0; j<=d; j++)
        {
            cout<<"Enter Now: "; 
            cin>>x;
            lm.Set(i, j, x);
            cout<<endl;
        }
    }

    lm.Display();


return 0;
}