#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    char* s = "Welcome";
    int i = 0;
    for (i=0; s[i] != '\0'; i++){}
    printf("Length is %d", i);
return 0;
}