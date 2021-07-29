#include <stdio.h>

typedef int *i_pointer;

int
main ()
{
  i_pointer p;            // Same as `int *p'
  i_pointer a, *b;        // Same as `int *a, **b'
  i_pointer my_array[10]; // Same as `int *my_array[10]'

  return 0;
}
