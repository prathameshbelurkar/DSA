#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{

    
    /*
        NOTE:
        If Two String are like this👇
                    str1 = "python";
                    str2 = "Python";
        Then, they will be treated as a two different strings. To Avoid that 
        Convert two strings either into lowercase or into UPPERCASE. 
    */
/* 
    // _________________________ COMPARING WHETHER TWO STRINGS ARE EQUAL, SMALLER OR GREATER __________________________

    

    char A[] = "Painter";
    char B[] = "Painting";
    int i, j;

    for (i=0, j=0; A[i]!='\0' || B[j]!='\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }

    if (A[i] == B[j])
        printf("Strings are Equal.\n");
    else if (A[i] < B[j])
        printf("%s String is Smaller than %s String.\n", A, B);
    else    
   
        printf("%s String is Smaller than %s String.\n", B, A);

    */


    // _____________________________ CHECKING WHETHER A STRING IS A PALINDROME OR NOT __________________________

    /* 
        // ___________ METHOD 1___________
        char A[] = "Python";
        char temp;
        int i, j;

        printf("Original String: %s\n", A);

        for (j=0; A[j] != '\0'; j++){}
        j = j -1;

        for (i=0; i<j; i++, j--)
        {
            if (A[i] != A[j])
                printf("String is not a Palindrome.");
                break;
        }
        printf("String is not a Palindrome.");
    */
    
    
    // ___________ METHOD 2___________
    char A[] = "madam";
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
    for (i=0; A[i] != '\0'; i++)
    {
        if (A[i] != B[i])
            printf("String is not a Palindrome\n");
            break;
            
    }
    printf("String is a Palindrome\n");
   
return 0;
}