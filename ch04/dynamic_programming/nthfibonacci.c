#include <stdio.h>

/*
Complexity Analysis
===================

Time: O(n)
Space: O(1)
*/
int fib(int n)
{

  int a = 0, b = 1, c;

  for (int i = 2; i <= n; i++)
  {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main()
{
  int n = 9;
  printf("nth(%d) fibonacci %d ", n, fib(n));
}