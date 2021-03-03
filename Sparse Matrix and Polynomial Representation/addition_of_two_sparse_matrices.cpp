#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// _____________________________ STRUCTURES ___________________________________
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


// ______________________________ FUNCTIONS ___________________________________

// Create a Sparse Matrix.
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

// Display a Sparse Matrix.
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

//Addition Of Two Sparse Matrices.
struct Sparse * add(struct Sparse *s1, struct Sparse *s2){

    int i, j, k;
    i=j=k=0;
    struct Sparse *sum;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num+s2->num) * sizeof(struct Element));

    if (s1->m != s2->m || s1->n != s2->n)
        return NULL;
    while(i<s1->num && j<s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s2->ele[j].i < s1->ele[i].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s2->ele[i++];
            else if (s2->ele[j].j < s1->ele[i].j)
                sum->ele[k++] = s2->ele[j++];
            else 
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }

    }

    // Copying the Remaining Elements.
    for ( ;i<s1->num;i++)
        sum->ele[k++] = s1->ele[i];

    for ( ;j<s2->num;j++)
        sum->ele[k++] = s2->ele[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;

}


// ############################### MAIN #######################################
int main()
{
    // ______________________________ VARIABLES ___________________________________
    struct Sparse s1, s2, *s3;


    // ____________________________________________________________________________
    Create(&s1);
    Create(&s2);
    s3 = add(&s1, &s2);

    printf("First Matrix\n");
    Display(s1);
    printf("\n");

    printf("Second Matrix\n");
    Display(s2);
    printf("\n");

    printf("Sum of First And Second Matrices\n");
    Display(*s3);
    printf("\n");

return 0;
}