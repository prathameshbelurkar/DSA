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

//Using an auxillary array
void Reverse(struct Array *arr){
    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));
    for(i=arr->length-1, j=0; i>=0 ;i--, j++)
        B[j] = arr->A[i];
    for(i=0; i<arr->length; i++)
        arr->A[i] = B[i];
}

//Using Interchanging of starting and ending elements of an array  
void Reverse2(struct Array *arr){
    int i, j;
    for(i=0, j=arr->length-1; i<j; i++, j--)
    {
       swap(&arr->A[i], &arr->A[j]);
    }
}

void LeftRotate(struct Array *arr){
    int temp = arr->A[0];
    int i;
    for(i=0; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->A[arr->length-1] = temp;
}

void RightRotate(struct Array *arr){
    int temp = arr->A[arr->length-1];
    int i;
    for(i=arr->length;i>=1 ;i--)
        arr->A[i] = arr->A[i-1];
    arr->A[0] = temp;
}


// ###################################### MAIN ################################################
int main()
{

    // _________________________________VARIABLES_________________________________
    struct Array arr = {{1,2,14,4,25}, 10, 5};


    // ___________________________________________________________________________
    Display(arr);
    printf("________________________________________________________\n");

    // Reverse(&arr);
    // Display(arr);

    // Reverse2(&arr);
    // Display(arr);

    // LeftRotate(&arr);
    // Display(arr);

    RightRotate(&arr);
    Display(arr);


return 0;
}