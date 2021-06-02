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

#include <stdio.h>

int
greatest_common_divisor (int x, int y)
{
  if (x <= 0 || y <= 0)
    {
      printf ("Error: Please enter two positive numbers\n");
      return -1;
    }

  while ((x % y) != 0)
    {
      if (x > y)
        {
          x = x % y;
          continue;
        }

      y = y % x;
    }

  return x == 0 ? x : y;
}

float
get_absolute_value (float x)
{
  if (x >= 0)
    {
      return x;
    }

  return x * -1.0f;
}

float
square_root (float x)
{
  const float epsilon = .00001;
  float guess = 1.0;

  if (x < 0)
    {
      printf ("Negative argument to square root.\n");
      return -1.0f;
    }

  while (get_absolute_value (guess * guess - x) >= epsilon)
    {
      guess = (x / guess + guess) / 2.0f;
    }

  return guess;
}

int
main ()
{
  int a = greatest_common_divisor (285, 741);
  printf ("Greatest common divisor: %d\n", a);

  float b = -10;
  printf ("The absolute of %.1f is %.1f\n", b, get_absolute_value (b));

  float sq = square_root (64);
  printf ("Sqrt = %f\n", sq);

  return 0;
}
