#include <stdio.h>
#include <stdlib.h>

struct my_array
{
  int length;
  int array[];
};

int
main ()
{
  int desired_size = 0;
  printf ("Enter the number of elements you want the flexible array member to "
          "have: ");
  scanf ("%d", &desired_size);

  struct my_array *ptr = NULL;
  ptr = malloc (sizeof (struct my_array) + desired_size * sizeof (int));

  printf ("The elements of the array are: \n");

  for (int i = 0; i < desired_size; i++)
    {
      ptr->array[i] = i * 100;
      printf ("%d ", ptr->array[i]);
    }

  printf ("\n");

  free (ptr);

  return 0;
}
