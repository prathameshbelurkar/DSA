#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _________________________ STRUCTURE _________________________________
struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};

// _________________________ FUNCTIONS _________________________________
void Create(struct Sparse *s){
    int i;
    printf("Enter Dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter Number of Non-Zero Elements: ");
    scanf("%d", &s->num);

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
    printf("Enter all Non-Zero Elements: ");
    for (i = 0; i < s->num; i++)
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);

}

void Display(struct Sparse s){
    int i, j, k=0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i==s.ele[k].i && j==s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}

// ############################ MAIN ###################################
int main()
{
    // _________________________ VARIABLES _________________________________
    struct Sparse s;

    // _____________________________________________________________________
    Create(&s);
    Display(s);



return 0;
}