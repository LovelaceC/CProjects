#include <stdio.h>

int
func ()
{
  // A local-static variable will retain its value, regardless of how many
  // times it has been called, its value is not reinitialised.
  static int count = 0;
  count += 1;

  int local_var = 0;
  printf ("`local_var': %d\n", local_var); // It will always print 0
  local_var++;

  return count;
}

int
main ()
{
  printf ("%d\n", func ()); // count is equals to one
  printf ("%d\n", func ()); // count is equals to two

  return 0;
}
