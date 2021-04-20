/* Copyright (C) 2021 Jinx.
   This file is part of CProjects.
   Created by Jinx CGCO <HermadesCGCO@disroot.org>, 2021.

   CProjects is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License V3 as published by the
   Free Software Foundation.

   CProjects is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRAMTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License V3
   for more details.

   You should have received a copy of the GNU General Public License V3
   along with CProjects; if not, see
   <https://www.gnu.org/licenses/>. */

#include <stdio.h>

int
main ()
{
  int grades[10];       // Array storing 10 values
  int count = 10;       // Number of values to be read
  long sum = 0;         // Sum of the numbers
  float average = 0.0f; // Average of the numbers

  printf ("\nEnter the 10 grades:\n");

  // Read the ten numbers to be averaged
  int i;
  for (i = 0; i < count; i++)
    {
      printf ("%2u> ", i + 1);
      scanf ("%d", &grades[i]); // Read a grade and add it to the array
      sum = sum + grades[i];    // Add it to `sum`
    }

  average = (float)sum / count; // Average
  printf ("\nAverage of the ten grades entered is: %.2f\n", average);

  return 0;
}
