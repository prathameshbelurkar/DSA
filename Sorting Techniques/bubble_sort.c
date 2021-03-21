#include<stdio.h>

// _______________________________ FUNCTIONS ____________________________________
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n){
    int i, j, flag;
    for (i = 0; i < n-1; i++)
    {
        flag = 0;
        for (j = 0; j < n-i-1; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
            if (flag == 0)
                break;
        }
    }
    printf("\n");
}

// ################################ MAIN ###########################################
int main(){
    // ________________ VARIABLES ______________________
    int A[] = {17,12,5,4,36,18,22,9,24,14};
    int n = 10, i;

    // _________________________________________________
    BubbleSort(A, n);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");


    return 0;
}