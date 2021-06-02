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

/* Pass by value. */
void
swap_by_value (int x, int y)
{
  int temp;

  temp = x;
  x = y;
  x = temp;
}

/* Pass by reference. */
void
swap_by_reference (int *x, int *y)
{
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

int
main ()
{
  int a = 100, b = 200;

  printf ("a before swap (passing by value): %d\n", a);
  printf ("b before swap (passing by value): %d\n", b);

  swap_by_value (a, b);

  printf ("a after swap (passing by value): %d\n", a);
  printf ("b after swap (passing by value): %d\n", b);

  printf ("Passing by reference.\n");

  swap_by_reference (&a, &b);

  printf ("a after swap (passing by reference): %d\n", a);
  printf ("b after swap (passing by reference): %d\n", b);

  return 0;
}
