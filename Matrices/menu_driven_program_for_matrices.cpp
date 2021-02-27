#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    // ______________________ VARIABLES AND OBJECTS ________________________________
    int *A, n, ch, x, i, j;

    // _____________________________________________________________________________
    printf("Enter the Dimension: ");
    scanf("%d", &n);

    /*
    n = n * (n+1)/2 //Lower Triangular Matrix
    */
    A = (int *)malloc(n * sizeof(int));

    //For Diagonal Matrix
    do
    {
        //Display Menu
        printf("Menu: \n");
        printf("1. Create \n");
        printf("2. Get \n");
        printf("3. Set \n");
        printf("4. Display \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the Values For Non-Zero Diagonal Elements: \n");
            for (int i=1; i <= n; i++)
                scanf("%d", &A[i-1]);
            break;

        case 2:
            printf("Enter Indices: \n");
            scanf("%d%d", &i, &j);
            printf("\n");
            if (i == j)
                printf("%d", A[i - 1]);
            else 
                printf("%d\n", 0);
            break;
        
        case 3:
            printf("Enter Indices and Element: \n");
            scanf("%d%d%d", &i, &j, &x);
            if (i == j)
                A[i - 1] = x;
            break;
        
        case 4:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i == j)
                        printf("%d ", A[i-  1]);
                    else 
                        printf("%d ", 0);
                }
                printf("\n");
            }
            
            break; 

        default:
            break;
        }

    } while (ch < 5);
    

return 0;
}