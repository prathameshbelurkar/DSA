#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x){
    if (i >= j)
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;
}

int Get(struct Matrix m, int i, int j){
    if (i >= j)
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    else    
        return 0;
}

void Display(struct Matrix m){
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);   
            else 
                printf("%d ", 0);   
        }
        printf("\n");
    }
}

// ################################## MAIN ##########################################
int main()
{
    // _____________VARIABLES ____________________
    struct Matrix m;
    int i, j, x;
    
    // _______________________________________
    printf("Enter Dimensions: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int));

    printf("Enter all Elements: ");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);   
        }
    }

    printf("\n\n");
    Display(m);






return 0;
}