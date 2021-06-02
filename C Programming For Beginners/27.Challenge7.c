/* Copyright (C) 2021 Bassara.
   This file is part of CProjects.
   Created by Bassara <HermadesCGCO@disroot.org>, 2021.

   CProjects is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License V3 as published by the
   Free Software Foundation.

   CProjects is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License V3
   for more details.

   You should have received a copy of the GNU General Public License V3
   along with CProjects; if not, see
   <https://www.gnu.org/licenses/>. */

/**
 * This challenge's objective, is to generate prime numbers and save it in an
 * array.
 */

#include <stdio.h>

int
main ()
{
  int prime_numbers[100] = { 2, 3 };

  int i;
  int j;
  for (j = 5, i = 2; j < 100; j += 2, i++)
    {
      if (j % 1 == 0 && j % j == 0)
        {
          prime_numbers[i] = j;
        }
    }

  printf ("The generated prime numbers are: \n");

  int k;
  for (k = 0; k < 100; k++)
    {
      printf ("%d ", prime_numbers[k]);
    }

  return 0;
}
