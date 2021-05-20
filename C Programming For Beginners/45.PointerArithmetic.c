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
array_sum (int *array, const int size)
{
  int sum = 0;
  int *const array_end = array + size;

  for (; array < array_end; ++array)
    {
      sum += *array;
    }

  return sum;
}

int
main ()
{
  int values[10] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };

  printf ("The sum is %d\n", array_sum (values, 10));

  return 0;
}
