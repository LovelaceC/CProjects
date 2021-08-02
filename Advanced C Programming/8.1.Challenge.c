#include <stdio.h>

int
main ()
{
  int elms = 0;

  printf ("Enter number of elements: ");
  scanf ("%d", &elms);

  int arr[elms];
  int sum = 0;

  for (int i = 0; i < elms; i++)
    {
      printf ("Enter the value of element %d: ", i);
      scanf ("%d", &arr[i]);

      sum += arr[i];
    }

  printf ("The sum of the array is: %d\n", sum);

  return 0;
}
