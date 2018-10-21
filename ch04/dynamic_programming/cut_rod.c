#include <stdio.h>

int max(int a, int b)
{
  return a > b ? a : b;
}
/*
Complexity Analysis
===================

Time:
Space:
*/
int cut_rod(int p[], int n)
{

  if (n == 0)
  {
    return 0;
  }

  int max_int = -9999999;
  for (int i = 1; i <= n; i++)
  {
    max_int = max(max_int, p[i] + cut_rod(p, n - i));
  }
  return max_int;
}

int main()
{
  //length 0,1,2....n, Prices are of p[i]. when length =0, price is 0, when lentgth is 1 price is 1, when lentgth is 2 price is 5 and so on.
  int prices[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

  printf("Max revenue %d ", cut_rod(prices, 4));
}