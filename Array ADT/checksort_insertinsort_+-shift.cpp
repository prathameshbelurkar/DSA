#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _________________________STRUCTURE ARRAY_______________________________________
struct Array
{
    int A[10];
    int size;
    int length;
};

// _____________________________FUNCTIONS___________________________________
void Display(struct Array arr){
    int i;
    printf("\nElements are: \n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void swap(int *x, int *y){
    int temp; 
    temp = *x;
    *x = *y;
    *y = temp;
}

//Insert an element in a sorted array.
void InsertSort(struct Array *arr, int x){
    int i = arr->length-1;
    if (arr->length == arr->size)
        return;
    while (i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

//Check whether array is sorted or not 
int isSorted(struct Array arr){
    int i;
    for(i=0; i<arr.length-1; i++)
    {
        if (arr.A[i] > arr.A[i+1])
            return 0;
    }
    return 1;
}

//Rearrange +ve's and -ve's in an array
void Rearrange(struct Array *arr){
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i<j)
    {
        while(arr->A[i] < 0)i++;
        while(arr->A[i] >= 0)j--;
        if (i<j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

// ###################################### MAIN ################################################
int main()
{

    // _________________________________VARIABLES_________________________________
    struct Array arr = {{1,-2,3,-4,5,-7}, 10, 6};
    Display(arr);


    // ___________________________________________________________________________
    printf("___________________________________________________________________________\n");

    // InsertSort(&arr, 6);
    // Display(arr);

    // printf("Array is Sorted or not: %d", isSorted(arr));

    Rearrange(&arr);
    Display(arr);

return 0;
}