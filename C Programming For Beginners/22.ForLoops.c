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
  unsigned long long sum = 0LL;
  unsigned int count = 0;

  printf ("Enter the number of integers you want to sum: ");
  scanf ("%u", &count);

  unsigned int i;
  for (i = 1; i <= count; i++)
    {
      sum += i;

      printf ("Inside loop\n");
    }

  printf ("Total of the first %u numbers is %llu\n", count, sum);

  return 0;
}
