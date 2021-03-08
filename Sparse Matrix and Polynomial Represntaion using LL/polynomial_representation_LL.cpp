#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

// __________________________________ STRUCTURE _______________________________________
struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly;

// __________________________________ FUNCTIONS ______________________________________
void create(){
    struct Node *t, *last;
    int num, i;

    printf("Enter the Number of Terms: ");
    scanf("%d", &num);
    
    printf("Enter the each term coefficient and exponent: \n");
    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", t->coeff, t->exp);
        t->next = NULL;
        if (poly == NULL)
            poly = last = t;
        else 
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p){
    while(p)
    {
        printf("%dx%d + ", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x){
    long val;

    while (p)
    {
        val += p->coeff*pow(x, p->exp);
        p = p->next;
    }

    return val;
}

// #################################### MAIN #######################################
int main()
{
    // ______________________________ VARIABLES ____________________________

    // _____________________________________________________________________
    create();
    Display(poly);
    printf("Evaluation of Polynomial: %ld\n", Eval(poly, 2));

return 0;
}