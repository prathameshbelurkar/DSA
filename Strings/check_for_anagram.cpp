#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    // NOTE: This Program only works for lowercase alphabets.
    char A[] = "decimal";
    char B[] = "medica";
    int H[26], i;

    for (i=0; A[i] != '\0'; i++)
        H[A[i] - 97] += 1;

    for (i=0; B[i] != '\0'; i++)
    {
        H[A[i] - 97] -= 1;
        if (H[A[i] -97] < 0)
        {
            printf("String is not an Anagram\n");
            break;
        }
    }
    if (B[i] == '\0')
        printf("String is Anagram\n");

return 0;
}