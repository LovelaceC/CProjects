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
 *
 * This is the right version of doing this challenge, as shown in the course.
 */

#include <stdio.h>

int
main ()
{
  int prime_numbers[50] = { 0 };

  int p, i;
  int prime_index = 2;

  _Bool is_prime;

  // hardcode first two prime numbers
  prime_numbers[0] = 2;
  prime_numbers[1] = 3;

  for (p = 5; p <= 100; p = p + 2)
    {
      is_prime = 1;

      for (i = 1; is_prime && p / prime_numbers[i] >= prime_numbers[i]; i++)
        {
          if (p % prime_numbers[i] == 0)
            {
              is_prime = 0;
            }
        }

      if (is_prime == 1)
        {
          prime_numbers[prime_index] = p;
          ++prime_index;
        }
    }

  for (i = 0; i < prime_index; i++)
    {
      printf ("%d ", prime_numbers[i]);
    }

  printf ("\n");

  return 0;
}
