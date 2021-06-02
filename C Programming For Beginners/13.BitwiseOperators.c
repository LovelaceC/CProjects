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
main ()
{
  unsigned int a = 60; // 0011 1100
  unsigned int b = 13; // 0000 1101
  int c = 0;           // 0000 0000

  // Turn on a bit if in both a and b it is turned on
  c = a & b; // Should return: 0000 1100
  printf ("The result is: %d\n", c);

  // Turns on a bit if in either a and b it is turned on
  c = a | b; // Should return: 0011 1101
  printf ("The result is: %d\n", c);

  // Turns on a bit if it is on in a or b but not both
  c = a ^ b; // Should return: 0011 0001
  printf ("The result is: %d\n", c);

  // This operator flips bits (turns 0's in 1's)
  c = ~a; // Should return 1100 0011
  printf ("The result is: %d\n", c);

  // Moves 2 bits to the left
  c = a << 2; // Should return 1111 0000
  printf ("The result is: %d\n", c);

  // Moves 2 bits to the right
  c = a >> 2; // Should return 0000 1111
  printf ("The result is: %d\n", c);

  return 0;
}
