#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
NOTE: 
Formulas
To Get Index For Row Major : ((i-1)*n - (i-2)(i-1)/2) + j -1
To Get Index For Column Major : (j*(j-1)/2) + i - 1
*/

struct UpperTriangular{
    int *A;
    int n;
};

void Set(struct UpperTriangular *m, int i, int j, int x){
    if (i <= j)
        m->A[((i-1)*m.n - (i-2)(i-1)/2) + j -1] = x;
}

int Get(struct UpperTriangular m, int i, int j){
    if (i <= j)
        return m.A[((i-1)*m.n - (i-2)(i-1)/2) + j -1];
    else    
        return 0;
}

void Display(struct UpperTriangular m){
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j)
                printf("%d ", m.A[((i-1)*m.n - (i-2)(i-1)/2) + j -1]);   
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
    struct UpperTriangular m;
    int i, j, x;
    
    // _______________________________________
    printf("Enter Dimensions: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int));

    printf("Enter all Elements: ");
    for (i = 0; i <= m.n; i++)
    {
        for (j = 0; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);   
        }
    }

    printf("\n\n");
    Display(m);

return 0;
}