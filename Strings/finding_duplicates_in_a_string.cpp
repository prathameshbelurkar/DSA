#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    /* 

    // ___________________________________________ USING HASH TABLES _________________________________________
    // NOTE: This Program only works for lowercase alphabets.
    char A[] = "finding";
    int H[26], i, j;

    // Setting all values in a Hash Table to 0.
    for (j=0; j < 26;j++)
        H[j] = 0;

    for (i=0; A[i] != '\0'; i++)
        H[A[i] - 97] += 1;

    //Scanning through Hash Table.
    for (i=0; i<26; i++)
    {
        if (H[i] > 1)
        {
            printf("%c: ", i + 97);
            printf("%d\n", H[i]);
        }
    }

    */

    // ___________________________________________ USING BITWISE OPERATORS _________________________________________
    char A[] = "finding";
    long int H = 0, x=0;
    int i;
    
    for (i=0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);
        int mask = x&H;
        if (mask > 0)
            printf("%c is Duplicate.\n", A[i]);
        else
            H = x | H;
    }

return 0;
}