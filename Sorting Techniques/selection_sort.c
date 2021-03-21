#include<stdio.h>

// _______________________________ FUNCTIONS ____________________________________
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[], int n){
    int i, j, k;

    for (i = 0; i < n-1; i++)
    {
        for (j=k=i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        } 
        swap(&A[i], &A[k]);
    }
}

// ################################ MAIN ###########################################
int main(){
    // ________________ VARIABLES ______________________
    int A[] = {17,12,5,4,36,18,22,9,24,14};
    int n = 10, i;

    // _________________________________________________
    SelectionSort(A, n);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");


    return 0;
}