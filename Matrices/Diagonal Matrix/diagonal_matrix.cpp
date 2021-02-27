#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


// ___________________________ STRUCTURE MATRIX ____________________________________
struct Matrix{
    int A[10];
    int n;
};

// _____________________________ FUNCTIONS ________________________________________
void Set(struct Matrix *m, int i, int j, int x){
    if (i == j)
        m->A[i - 1] = x;
}

int Get(struct Matrix m, int i, int j){
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct Matrix m){
    int i, j;
    for (i=0; i<m.n; i++)
    {
        for (j=0; j<m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}

// ############################### MAIN ###########################################
int main()
{
    // _________ VARIABLES __________
    struct Matrix m;
    m.n = 4;

    // ______________________________
    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 4);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 7);
    printf("%d \n", Get(m, 3, 3));
    Display(m);


    

return 0;
}