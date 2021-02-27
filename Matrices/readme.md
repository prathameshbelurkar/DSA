# Formulas:

## For Diagonal Matrix
>if (i == j)
>>A[i-1]=x;

---

## For Lower Triangular Matrices(Row Major/Column Major)
> if (i>=j)
>>A[i*(i-1)/2+j-1]=x;   OR   A[(j-1)*n-((j-2)*(j-1))/2+i-j]=x;

---

## For Upper Triangular Matrices(Row Major/Column Major)
>if (i>=j)
>>A[(i-1)*n-((i-2)*(i-1))/2+j-i]=x;   OR   A[j*(j-1)/2+i-1]=x;           

---

 ## Tridiagonal Matrix👇
 - *Non Zero Elements are present at*
 - *Main Diagonal: i - j = 0*
 - *Lower Diagonal: i - j = 1*
 - *Lower Diagonal: i - j = -1*
> - **M[i, j] = non-zero if |i-j| <= 1**
> - **M[i, j] = 0 if |i-j| > 1**
> - **Number Of Non-Zero Elements: 3n-1,  where: 'n' is number of number of diagonal elements.**

---

 ## Toeplitz Matrix👇
 *All elements aligned with the Main Diagonal including Main Diagonal are equal.*
 - ***M[i][j] = M[i-1][j-1]***
 - Elements to be stored in an Array: n + n - 1
 > Accessing Upper Triangular Elements 
 > If i <= j
 > - Index = j - i  
 > Accessing Lower Triangular Elements 
 > If i > j 
 > - Index = n + i - j - 1 
















