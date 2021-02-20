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

int LinearSearch(struct Array arr, int key){
    int i = 0;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
        
    }
    return -1;
}

//Using Transposition
int ImprovedLinearSearch1(struct Array *arr, int key){
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return (i-1);
        }
    }
    return -1;
}

//Using key to head
int ImprovedLinearSearch2(struct Array *arr, int key){
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

// ###################################### MAIN ################################################
int main()
{

    // _________________________________VARIABLES_________________________________
    struct Array arr = {{1,2,3,4,5}, 10, 5};
    



    // ___________________________________________________________________________
    Display(arr);
    // printf("%d", LinearSearch(arr, 3));
    // printf("%d", ImprovedLinearSearch1(&arr, 3));
    printf("%d", ImprovedLinearSearch2(&arr, 3));
    Display(arr);

return 0;
}