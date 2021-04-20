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

int
main ()
{
  // Shows the number - in bytes - that is occupied in memory by an int
  printf ("%lx\n", sizeof (int));

  float x = 10.2;
  int y = 10;

  // This converts "y" into a float
  float result = (float)y + x;

  // If true display 100 else display 10
  printf ("%d\n", (1) ? 100 : 10);

  return 0;
}
