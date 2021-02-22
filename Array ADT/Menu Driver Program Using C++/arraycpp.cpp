#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _________________________CLASS ARRAY_______________________________________
class Array
{
    private:
        int* A;
        int size;
        int length;
        void swap(int *x, int *y);
    public:
        Array()
        {
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array()
        {
            delete []A;
        }

    // _____________________________FUNCTION PROTOTYPES___________________________________

    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    void Reverse();


    // int RBinSearch(int a[], int l, int h, int key);
    void Set(int index, int x);
    float Avg();
    int Get(int index);
    int Max();
    int Sum();
    int Min();
    int LinearSearch(int key);
    void Reverse2();
    void Display();
    void Append(int x);
    int BinarySearch(int key);
    void Insert(int index, int x);
    int Delete(int index);
    Array* Difference(Array arr2);
    Array* Intersection(Array arr2);        
    Array* Union(Array arr2);
    Array* Merge(Array arr2);
};

// _____________________________ CLASS FUNCTIONS ___________________________________
void Array :: Display(){
    int i;  
    printf("\nElements are: \n");
    for (i = 0; i < length; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Array :: Append(int x){
    if (length < size)
    {
        A[length++] = x;
    }
}

void Array :: Insert(int index, int x){
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
    
}

int Array :: Delete(int index){
    int x = 0;
    int i;
    if (index>=0 && index<length)
    {
        x = A[index];
        for (i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--;
        return x;        
    }
    return 0;
}

int Array :: LinearSearch(int key){
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            return i;
        }
        
    }
    return -1;
}

int Array :: BinarySearch(int key){
    int l, h, mid;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l+h)/2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

// //Using Recursion
// int Array :: RBinSearch(int a[], int l, int h, int key){
//     int mid;
//     if (l <= h)
//     {
//         mid = (l+h)/2;
//         if (key == a[mid])
//             return mid;
//         else if (key < a[mid])
//             return RBinSearch(a, l, mid-1, key);
//         else
//             return RBinSearch(a, mid+1, h, key);
//     }
//     return -1;
// }

//Get the element from the index
int Array :: Get(int index){
    if (index>=0 && index<length)
        return A[index];
    return -1;
}

//Set the element on a given index
void Array :: Set(int index, int x){
    if (index>=0 && index<length)
        A[index] = x;
}

//Get the maximum element from an array
int Array :: Max(){
    int max = A[0];
    int i;
    for (i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

//Get the minimum element from an array
int Array :: Min(){
    int min = A[0];
    int i;
    for (i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

//Find the sum of all elements in an array
int Array :: Sum(){
    int s = 0;
    int i;
    for (i = 0; i < length; i++)
        s += A[i];
    return s;
}

//Find the avg of all elements in an array
float Array :: Avg(){
    return (float)Sum()/length;
}


void Array :: swap(int *x, int *y){
    int temp; 
    temp = *x;
    *x = *y;
    *y = temp;
}

//Insert an element in a sorted array.
void Array :: InsertSort(int x){
    int i = length-1;
    if (length == size)
        return;
    while (i>=0 && A[i]>x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

//Check whether array is sorted or not 
int Array :: isSorted(){
    int i;
    for(i=0; i<length-1; i++)
    {
        if (A[i] > A[i+1])
            return 0;
    }
    return 1;
}

//Rearrange +ve's and -ve's in an array
void Array :: Rearrange(){
    int i, j;
    i = 0;
    j = length - 1;

    while (i<j)
    {
        while(A[i] < 0)i++;
        while(A[i] >= 0)j--;
        if (i<j)
            swap(&A[i], &A[j]);
    }
}

//Using an auxillary array
void Array :: Reverse(){
    int *B;
    int i, j;

    B = new int[length];
    for(i=length-1, j=0; i>=0 ;i--, j++)
        B[j] = A[i];
    for(i=0; i<length; i++)
        A[i] = B[i];
}

//Using Interchanging of starting and ending elements of an array  
void Array :: Reverse2(){
    int i, j;
    for(i=0, j=length-1; i<j; i++, j--)
    {
       swap(&A[i], &A[j]);
    }
}



//Merging two sorted arrays
Array* Array :: Merge(Array arr2){
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i<length && j<arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++]; 
    }

    //copy remaining elements from any one array.
    for( ;i<length;i++)
        arr3->A[k++] = A[i];
    for( ;j<arr2.length;j++)
        arr3->A[k++] = arr2.A[j];
    
    //setting the lenght of arr3
    arr3->length = length + arr2.length;

    return arr3;
}

//Union of two sets. 
Array* Array :: Union(Array arr2){
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array();

    while (i<length && j<arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++]; 
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    //copy remaining elements from any one array.
    for( ;i<length;i++)
        arr3->A[k++] = A[i];
    for( ;j<arr2.length;j++)
        arr3->A[k++] = arr2.A[j];
    
    //setting the lenght of arr3
    arr3->length = k;
    //setting the size of arr3
    arr3->size = 10;    

    return arr3;
}


//Intersection of two sets. 
Array* Array :: Intersection(Array arr2){
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array();

    while (i<length && j<arr2.length)
    {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
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
Array* Array :: Difference(Array arr2){
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array();

    while (i<length && j<arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else if (A[i] == arr2.A[j])
        {
            i++;
            j++;
        }
    }

    //copying remaining elements from arr1
    for ( ;i<length;i++)
        arr3->A[k++] = A[i];
    
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
    int ch;
    int x, index, sz;
    Array *arr1;


    // ___________________________________________________________________________
    printf("Enter the size of an Array");
    scanf("%d", &sz);
    arr1 = new Array(sz);
    

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
                arr1->Insert(index, x);
                break;

        case 2: printf("Enter an Index");
                scanf("%d", &index);
                printf("Deleted Element is %d", arr1->Delete(index));
                break;

        case 3: printf("Enter an Element to Search");
                scanf("%d", &index);
                index = arr1->LinearSearch(x);
                printf("Element is at %d index", index);
                break;

        case 4: printf("Sum is %d", arr1->Sum());
                break;

        case 5: arr1->Display();
                break;

    }

}while(ch < 6);


return 0;
}