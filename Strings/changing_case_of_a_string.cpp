#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int i;

    // _______________________________________________________________
    //   Changing UPPERCASE to lowercase
    char A[] = "WELCOME";
    for (i=0; A[i] != '\0'; i++)
        A[i] = A[i] + 32;  
    printf("%s\n", A);
    // _______________________________________________________________

    // Toggle the string and changing the cases
    char B[] = "wElCoME";
    for (i=0; B[i] != '\0'; i++)
    {
        if (B[i]>=65 && B[i]<=90)
            B[i] += 32;
        else if (B[i]>=97 && B[i]<=122)
            B[i] -= 32;
    }
    printf("%s\n", B);
    // _______________________________________________________________




return 0;
}