#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _________________________STRUCTURE ARRAY_______________________________________
struct Array
{
    int *A;
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


// ###################################### MAIN ################################################
int main()
{

    // _________________________________VARIABLES_________________________________
    struct Array arr;
    int n, i;


    // ___________________________________________________________________________
    printf("Enter the size of an Array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0;

    printf("Enter the Number of Numbers: ");
    scanf("%d", &n);

    printf("Enter all the Elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    Display(arr);

    





return 0;
}