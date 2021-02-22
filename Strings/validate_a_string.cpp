#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
Validating a String means Checking Whether a String Contains only 
Numbers and Alphabets.
eg. Pratham*545 -> Invalid 
    Pratham545  -> Valid
*/
// _______________ FUNCTION TO VALIDATE A STRING _______________________

int validate(char *name){
    int i;
    for (i=0; name[i] != '\0' ;i++)
    {
        if ( !(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57) )
            return 0;
    }
    return 1;
}


int main()
{
    char *name = "Anil321";

    if (validate(name))
        printf("Valid String\n");
    else    
        printf("Invalid String\n");

return 0;
}