#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    char A[] = "How are you";
    printf("%s\n", A);

    // __________________________ COUNTING VOWELS AND CONSONENTS ________________________________
    int i, vcount = 0, ccount = 0;

    for (i=0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'A' || A[i] == 'e' || A[i] == 'E' || A[i] == 'i' || A[i] == 'I' || A[i] == 'o' || A[i] == 'O' || A[i] == 'u' || A[i] == 'U')
            vcount ++;
        else if (A[i]>=65 && A[i]<=90 || A[i]>=97 && A[i]<=122)
        ccount++;
    }

    printf("Vowels: %d\n", vcount);
    printf("Consonents: %d\n", ccount);
    // __________________________________________________________________________________________




    // __________________________ COUNTING WORDS IN A STRING ________________________________
    int spaces = 0;

    for (i=0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i-1] != ' ')
            spaces++;
    }
    int words = spaces + 1;
    printf("Words: %d\n", words);
    // __________________________________________________________________________________________





return 0;
}