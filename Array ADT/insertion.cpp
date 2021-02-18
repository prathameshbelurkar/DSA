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

void Append(struct Array *arr, int x){
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x){

    if (index > 0 && index <= arr->length)
    {
        int i;
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
    
}

// ###################################### MAIN ################################################
int main()
{

    // _________________________________VARIABLES_________________________________
    struct Array arr = {{1,2,3,4,5}, 10, 5};
    



    // ___________________________________________________________________________
    Display(arr);
    // Append(&arr, 6);
    Insert(&arr, 2, 10);
    Display(arr);



    





return 0;
}