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

//Union of two sets. 
struct Array* Union(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++]; 
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    //copy remaining elements from any one array.
    for( ;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for( ;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    
    //setting the lenght of arr3
    arr3->length = k;
    //setting the size of arr3
    arr3->size = 10;    

    return arr3;
}

//Intersection of two sets. 
struct Array* Intersection(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    //setting the lenght of arr3
    arr3->length = k;
    //setting the size of arr3
    arr3->size = 10;    

    return arr3;
}

//Difference operation between two sets. 
struct Array* Difference(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            i++;
            j++;
        }
    }

    //copying remaining elements from arr1
    for ( ;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    
    //setting the lenght of arr3
    arr3->length = k;
    //setting the size of arr3
    arr3->size = 10;    

    return arr3;
}

// ###################################### MAIN ################################################
int main()
{

    // _________________________________VARIABLES_________________________________
    struct Array arr1 = {{2,6,10,15,25}, 10, 5};
    struct Array arr2 = {{3,6,9,15,21}, 10, 5};
    struct Array *arr3;

    // ___________________________________________________________________________
    printf("From arr1");
    Display(arr1);
    printf("From arr2");
    Display(arr2);
    printf("________________________________________________________\n");

    // arr3 = Union(&arr1, &arr2);
    // Display(*arr3);

    // arr3 = Intersection(&arr1, &arr2);
    // Display(*arr3);

    arr3 = Difference(&arr1, &arr2);
    Display(*arr3);




return 0;
}