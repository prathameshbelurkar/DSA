#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void swap(char* c1, char* c2){
    char temp;
    temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}


// __________________________________ FUNCTION FOR PERMUTATION OF A STRING _________________________________

//___________ METHOD 1 ( USING RESCURSION AND BACKTRACKING )_________________________
void Perm1(char s[], int k){
    static int A[10] = {0};
    static char res[10];
    int i;

    if (s[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
    }
    else
    {
        for (i=0; A[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = s[i];
                A[i] = 1;
                Perm1(s, k+1);
                A[i] = 0;
            }
        }
    }
}

//_________________ METHOD 2 _________________________
void Perm2(char s[], int l, int h){
    int i;

    if (l == h)
    {
        printf("%s\n", s);
    }
    else
    {
        for (i=l; l <= h; i++)
        {
            swap(&s[l], &s[i]);
            Perm2(s, l+1, h);
            swap(&s[i], &s[l]);
        }

    }

}





int main()
{
    char s[] = "ABC";
    Perm1(s, 0); 
    Perm2(s, 0, 2);  

return 0;
}