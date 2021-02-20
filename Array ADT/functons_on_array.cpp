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

//Get the element from the index
int Get(struct Array arr, int index){
    if (index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

//Set the element on a given index
void Set(struct Array *arr, int index, int x){
    if (index>=0 && index<arr->length)
        arr->A[index] = x;
}

//Get the maximum element from an array
int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

//Get the maximum element from an array
int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

//Find the sum of all elements in an array
int Sum(struct Array arr){
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

//Find the avg of all elements in an array
float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}



// ###################################### MAIN ################################################
int main()
{

    // _________________________________VARIABLES_________________________________
    struct Array arr = {{1,2,14,4,25}, 10, 5};


    // ___________________________________________________________________________
    Display(arr);
    printf("________________________________________________________\n");

    // printf("%d\n", Get(arr, 9));

    // Set(&arr, 0, 15);
    // Display(arr);

    // printf("%d\n", Max(arr));

    // printf("%d\n", Min(arr));

    // printf("%d\n", Sum(arr));

    // printf("%f\n", Avg(arr));

return 0;
}