#include <stdio.h>
#include <limits.h>

/* Macro definition */
#define MAX_INT 1<<(8*sizeof(int) - 1);

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int matrix_chain_order(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    // place parenthesis at different places between first
    // and last matrix, recursively calculate count of
    // multiplications for each parenthesis placement and
    // return the minimum count
    for (k = i; k < j; k++)
    {
        count = matrix_chain_order(p, i, k) +
                matrix_chain_order(p, k + 1, j) +
                p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    // Return minimum count
    return min;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int max1=INT_MAX;
    int max2=MAX_INT;
     printf("size int %d max1 %d max2 %d %d \n", sizeof(int),  max1 , ((1<<30)) );
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ", matrix_chain_order(arr, 1, n - 1));
    return 0;
}