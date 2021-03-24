#include<stdio.h>

// _______________________________ FUNCTIONS ____________________________________
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void ShellSort(int A[], int n){
    int gap, i, j, temp;

    for (gap=n/2; gap>=1 ; gap/=2)
    {
        for (i=gap ; i<n; i++)
        {
            temp = A[i];
            j = i - gap;

            while (j>=0 && A[j]>temp)
            {
                A[j+gap] = A[j];
                j = j - gap;
            }

            A[j+gap] = temp;
        }
    }
}

// ################################ MAIN ###########################################
int main(){
    // ________________ VARIABLES ______________________
    int A[] = {17,12,5,4,36,18,22,9,24,14};
    int n = 10, i;

    // _________________________________________________
    ShellSort(A, n); 
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");


    return 0;
}