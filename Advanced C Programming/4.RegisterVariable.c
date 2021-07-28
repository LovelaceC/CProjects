#include <stdio.h>

// A register variable is a variable stored in a CPU register instead of RAM.
// You cannot obtain the address of a register variable using pointers, as it
// does not have a memory location.
// Registers cannot be declared in global scope.

int
main ()
{
  register int x; // A register variable

  for (x = 1; x < 15; x++)
    {
      printf ("%d\n", x);
    }

  return 0;
}
