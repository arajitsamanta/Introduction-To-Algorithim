#include <stdio.h>
#include <limits.h>
#include <time.h>

/* Function prototype */
int max(int a, int b);
int cut_rod(int p[], int n);
int cut_rod_memoized_aux(int p[], int n, int r[]);
int cut_rod_memoized(int p[], int n);
int cut_rod_bottom_up(int p[], int n);

/* Macro definition */
#define MIN_INT (-1 << sizeof(int)) - 1;

/* Max of two numbers */
int max(int a, int b)
{
  return a > b ? a : b;
}

/*
Complexity Analysis
===================
Exponential time.

Time: 2^n
Space: No extra space apart from stack activation frame.
*/
int cut_rod(int p[], int n)
{

  if (n == 0)
  {
    return 0;
  }

  int max_int = MIN_INT;
  for (int i = 1; i <= n; i++)
  {
    max_int = max(max_int, p[i] + cut_rod(p, n - i));
  }
  return max_int;
}

/*
Complexity Analysis
===================
Exponential time.

Time: O(n^2)
Space: O(n).
*/
int cut_rod_memoized_aux(int p[], int n, int r[])
{

  if (r[n] >= 0)
  {
    return r[n];
  }

  int max_int = MIN_INT;
  if (n == 0)
  {
    max_int = 0;
  }
  else
  {
    for (int i = 1; i <= n; i++)
    {
      max_int = max(max_int, p[i] + cut_rod_memoized_aux(p, n - i, r));
    }
  }
  r[n] = max_int;
  return max_int;
}

int cut_rod_memoized(int p[], int n)
{
  int r[n + 1];
  for (int i = 0; i <= n + 1; i++)
  {
    r[i] = MIN_INT;
  }
  return cut_rod_memoized_aux(p, n, r);
}

/*
Complexity Analysis
===================
Exponential time.

Time: O(n^2)
Space: O(n).
*/
int cut_rod_bottom_up(int p[], int n)
{
  int arr_size = n + 1;
  int r[arr_size];
  r[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    int max_int = MIN_INT;
    for (int j = 1; j <= i; j++)
    {
      max_int = max(max_int, p[j] + r[i - j]);
    }
    r[i] = max_int;
  }
  return r[n];
}

int cut_rod_bottom_up_extended(int p[], int n,int* s)
{
  int arr_size = n + 1;
  int r[arr_size];
  r[0] = 0;
  int temp;
  for (int i = 1; i <= n; i++)
  {
    int max_int = MIN_INT;
    for (int j = 1; j <= i; j++)
    {
      temp=p[j] + r[i - j];
      if( max_int < temp){
         max_int = temp;
         s[i]=j;
      }
    }
    r[i] = max_int;
  }
  return r[n];
}

int main()
{
  //length 0,1,2....n, Prices are of p[i]. when length =0, price is 0, when lentgth is 1 price is 1, when lentgth is 2 price is 5 and so on.
  int prices[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  int cut_length=31;

  clock_t begin = clock();
  printf("Max revenue %d ", cut_rod(prices, cut_length));
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time taken: %f", time_spent);

  begin = clock();
  printf("\nMax revenue(memoized) %d ", cut_rod_memoized(prices, cut_length));
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time taken: %f", time_spent);

  begin = clock();
  printf("\nMax revenue(bottom-up) %d ", cut_rod_bottom_up(prices, cut_length));
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time taken: %f", time_spent);

  int price_arr_size=sizeof(prices)/sizeof(prices[0]);
  int cut_points[price_arr_size];
  begin = clock();
  printf("\nMax revenue(bottom-up - returns cutting sizes) %d ", cut_rod_bottom_up_extended(prices, cut_length,cut_points));
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time taken: %f", time_spent);

  printf("\nRod optimal cutting sizes are..\n");
  while(cut_length>0){
    printf("%d ", cut_points[cut_length]);
    cut_length=cut_length-cut_points[cut_length];
  }
  printf("\n");
  return 0;
}