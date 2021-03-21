#include<stdio.h>

// _______________________________ FUNCTIONS ____________________________________
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void InsertionSort(int A[], int n){
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i -1;
        x = A[i];

        while (j>-1 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
    
}

// ################################ MAIN ###########################################
int main(){
    // ________________ VARIABLES ______________________
    int A[] = {17,12,5,4,36,18,22,9,24,14};
    int n = 10, i;

    // _________________________________________________
    InsertionSort(A, n);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");


    return 0;
}