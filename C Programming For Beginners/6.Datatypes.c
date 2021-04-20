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
  /**
   * An int can only contain positive/negative integer numbers and zero
   */
  int a = 10;

  /**
   * A float can store positive/negative decimal values and zero
   */
  float b = 10.0f;

  /**
   * A double can store larger positive/negative decimal values and also zero
   */
  double c = 1000.62;

  /**
   * _Bool can only store zero or one, representing false and true respectively
   */
  _Bool d = 0;

  /**
   * Short is more lightweight and can store smaller integer numbers
   */
  short int e = 2;

  /**
   * Long is going to use more space and can store longer integer numbers
   */
  long int f = 10000L;

  /**
   * Unsigned will not allow you to use negative numbers, but the positive
   * maximum will be double
   */
  unsigned int g = 1000;

  /**
   * Signed explicitly declares that this number is going to be signed, that
   * is, use positive and/or negative numbers
   */
  signed int h = -10;

  // Print the size of each of these datatypes

  printf ("%lu %lu %lu %lu\n", sizeof (int), sizeof (float), sizeof (double),
          sizeof (_Bool));

  return 0;
}
