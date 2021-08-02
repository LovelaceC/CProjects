#include <stdio.h>

// Variable Length Arrays

int
main ()
{
  size_t size = 0;

  printf ("Enter the number of elements you want to store: ");
  scanf ("%zd", &size);

  float values[size];

  if (values[0])
    {
      // This is just used because I use -Wall and -Werror
    }

  size_t rows = 0;
  size_t columns = 0;

  printf ("Enter the number of rows and columns: ");
  scanf ("%zd %zd", &rows, &columns);

  float matrix[rows][columns];

  if (matrix[0][0])
    {
      // Again, just because of my compilation flags
    }

  return 0;
}
