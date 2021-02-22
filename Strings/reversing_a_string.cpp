#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    /* 
    // ______________________________ METHOD 1 ______________________________________
    char A[] = "Python";
    char B[7];
    int i, j;

    printf("Original String: %s\n", A);

    for (i=0; A[i] != '\0'; i++){}
    i = i - 1;

    for (j=0; i>=0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';

    printf("Reverse String: %s\n", B);
 */

    // ______________________________ METHOD 2 (Required a Mutable String) ______________________________________
    char A[] = "Python";
    char temp;
    int i, j;

    printf("Original String: %s\n", A);

    for (j=0; A[j] != '\0'; j++){}
    j = j -1;

    for (i=0; i<j; i++, j--)
    {
        temp = A[j];
        A[j] = A[i];
        A[i] = temp;
    }

    printf("Reverse String: %s\n", A);


return 0;
}