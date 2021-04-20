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
  int number, sign;

  printf ("Please type in a number: ");
  scanf ("%d", &number);

  if (number < 0)
    {
      sign = -1;
    }
  else if (number == 0)
    {
      sign = 0;
    }
  else
    {
      sign = 1;
    }

  printf ("Sign = %d\n", sign);

  return 0;
}
