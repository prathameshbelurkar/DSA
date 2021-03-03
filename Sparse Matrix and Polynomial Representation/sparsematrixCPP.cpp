#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

// ______________________________ CLASS ____________________________________
class Element{
    public: 
        int i;
        int j;
        int x;
};

class Sparse{
    private:
        int m;
        int n;
        int num;
        Element *ele;

    public:
        Sparse(int m, int n, int num){
            this->m = m;
            this->n = n;
            this->num = num;
            ele = new Element[this->num];
        }

        ~Sparse(){
            delete []ele;
        }

        void read(){
            cout<<"Enter the Non-Zero Elements: "<<endl;
            for (int i=0; i<num; i++)
                cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }

        void Display(){
            int k=0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (ele[k].i==i && ele[k].j==j)
                        cout<<ele[k++].x<<" ";
                    else 
                        cout<<"0 ";
                }
                cout<<endl;
            }
            
        }


};






// ################################ MAIN #######################################
int main()
{
    // ________________________ VARIABLES AND OBJECTS ______________________________
    Sparse s1(5, 5, 5);


    // _____________________________________________________________________________
    s1.read();
    s1.Display();
    

return 0;
}