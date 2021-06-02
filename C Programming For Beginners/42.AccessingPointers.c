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
  int number = 15;
  int *ptr = &number;
  int result = 0;

  result = *ptr + 5;

  printf ("The value of result is: %d\n", result);

  printf ("Number's address: %p\n", &number);
  printf ("Ptr's address: %p\n", (void *)&ptr);

  printf ("Ptr's size: %d bytes\n", (int)sizeof (ptr));

  return 0;
}
