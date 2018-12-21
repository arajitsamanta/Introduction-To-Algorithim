#include <stdio.h>
#include <limits.h>
#include <time.h>
#include<stdlib.h>

/*
Matrix Mi has dimension p[i-1] x p[i] for i = 1..n

Complexity Analysis
===================
Exponential time.

Time: 2^n
Space: No extra space apart from stack activation frame.
*/
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

/*
Complexity Analysis
===================
Time: O(n^3)
Auxiliary Space: O(n^2)
*/
void matrix_chain_order_memoized(int p[], int n, int **m, int **s)
{
    /* For simplicity of the program, one extra row and one 
       extra column are allocated in m[][].  0th row and 0th 
       column of m[][] are not used */
    //int m[n][n];

    /* s records which index of k achieved the optimal cost in computing
        m[i,j]. We shall use the table s to construct an optimal solution. */
    //int s[n-1][n-1];

    int i, j, k, L, q;

    /* m[i,j] = Minimum number of scalar multiplications needed 
       to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where 
       dimension of A[i] is p[i-1] x p[i] */

    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
                s[i][j] = k;
            }
        }
    }

    //return m[1][n - 1];
}

int main()
{
    // Matrix is M1=30*35, M2=35*15 M3=15*5 M4=5*10 M5=10*20 M6=20*25
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int i, n = sizeof(arr) / sizeof(arr[0]);
    int **m, **s;

    clock_t begin = clock();
    printf("Minimum number of multiplications(Recursive): %d\n", matrix_chain_order(arr, 1, n - 1));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);

    /* allocate the rows */
    m = malloc(n * sizeof(int *));
    s = malloc((n - 1) * sizeof(int *));

    /* allocate columns */
    for (i = 0; i < n; i++)
    {
        m[i] = malloc(n * sizeof(*m[i]));
        s[i] = malloc((n - 1) * sizeof(*s[i]));
    }

    begin = clock();
    matrix_chain_order_memoized(arr, n, m, s);
    printf("Minimum number of multiplications(Memoized): %d\n", m[1][n - 1]);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f", time_spent);

    return 0;
}