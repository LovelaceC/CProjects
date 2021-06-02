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
  int matrix[4][5] = { { 0, 1, 2, 3, 4 },
                       { 5, 6, 7, 8, 9 },
                       { 10, 11, 12, 13, 14 },
                       { 15, 16, 17, 18, 19 } };

  printf ("[ \n");
  for (int i = 0; i < 4; ++i)
    {
      printf ("\t[ ");
      for (int j = 0; j < 5; ++j)
        {
          printf ("%d, ", matrix[i][j]);
        }
      printf ("]\n");
    }
  printf ("]\n");

  printf ("Sizeof matrix: %lx\n", sizeof (matrix));

  return 0;
}
