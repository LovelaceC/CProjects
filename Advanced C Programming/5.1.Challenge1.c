#include <stdio.h>

int
sum (int num)
{
  static int prev_sum = 0;
  int sum = prev_sum + num;
  prev_sum = sum;

  return sum;
}

int
main ()
{
  printf ("%d\n", sum (25));
  printf ("%d\n", sum (15));
  printf ("%d\n", sum (30));

  return 0;
}
