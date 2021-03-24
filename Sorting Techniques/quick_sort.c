#include<stdio.h>

// _______________________________ FUNCTIONS ____________________________________
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l, j = h;

    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    }while(i < j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h){
    int j;

    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A ,l, j);
        QuickSort(A, j+1, h);
    }
}



// ################################ MAIN ###########################################
int main(){
    // ________________ VARIABLES ______________________
    int A[] = {17,12,5,4,36,18,22,9,24,14, __INT_MAX__};
    int n = 11, i;

    // _________________________________________________
    QuickSort(A, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");


    return 0;
}