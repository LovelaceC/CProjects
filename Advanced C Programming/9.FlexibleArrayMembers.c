#include <stdio.h>
#include <stdlib.h>

struct s
{
  int array_size;

  // The flexible array member MUST be declared as the last member of the
  // struct.
  // A struct can ONLY have one flexible array member and it must have more
  // elements.
  int array[];
};

int
main ()
{
  int desired_size = 5;
  struct s *ptr;

  // sizeof doesn't take in account the flexible array members, that's why we
  // are adding desired_size * int, to allocate memory for `array'
  ptr = malloc (sizeof (struct s) + desired_size * sizeof (int));

  free (ptr);

  return 0;
}
