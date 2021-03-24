#include<stdio.h>
#include<stdlib.h>

// _______________________________ FUNCTIONS ____________________________________
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int findMax(int A[], int n){
    int max = -1;
    int i;

    for (i=0; i<n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }

    return max;
}

void CountSort(int A[], int n){
    int i, j, max, *C;

    max = findMax(A, n);
    C = (int *)malloc((max+1) * sizeof(int));

    for (i = 0; i < max+1; i++)
        C[i] = 0;
    for (i = 0; i < n; i++)
        C[A[i]]++;
    
    i=0, j=0;
    while (j < max+1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}

// ################################ MAIN ###########################################
int main(){
    // ________________ VARIABLES ______________________
    int A[] = {17,12,5,4,36,18,22,9,24,14};
    int n = 10, i;

    // _________________________________________________
    CountSort(A, n);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");


    return 0;
}