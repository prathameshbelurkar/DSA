#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _________________________STRUCTURE ARRAY_______________________________________
struct Array
{
    int* A;
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
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
    
}

int Delete(struct Array *arr, int index){
    int x = 0;
    int i;
    if (index>=0 && index<arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;        
    }
    return 0;
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

int BinarySearch(struct Array arr, int key){
    int l, h, mid;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l+h)/2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

//Using Recursion
int RBinSearch(int a[], int l, int h, int key){
    int mid;
    if (l <= h)
    {
        mid = (l+h)/2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid-1, key);
        else
            return RBinSearch(a, mid+1, h, key);
    }
    return -1;
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



//Merging two sorted arrays
struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++]; 
    }

    //copy remaining elements from any one array.
    for( ;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for( ;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    
    //setting the lenght of arr3
    arr3->length = arr1->length + arr2->length;
    //setting the size of arr3
    arr3->size = 10;    

    return arr3;
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
    struct Array arr1;
    arr1.length = 0;
    int ch;
    int x, index;


    // ___________________________________________________________________________
    printf("Enter the size of an Array");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));

    do
    {

    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("enter you Choice");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1: printf("Enter an Element and Index");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index, x);
                break;

        case 2: printf("Enter an Index");
                scanf("%d", &index);
                Delete(&arr1, index);
                break;

        case 3: printf("Enter an Element to Search");
                scanf("%d", &x);
                x = LinearSearch(arr1, x);
                printf("Deleted Element is %d", x);
                break;

        case 4: printf("Sum is %d", Sum(arr1));
                break;

        case 5: Display(arr1);
                break;

    }

}while(ch < 6);


return 0;
}