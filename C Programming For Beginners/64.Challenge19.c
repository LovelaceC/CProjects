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
  FILE *fd = fopen ("data/pos", "r");

  if (!fd)
    {
      fprintf (stderr, "Error opening the file.\n");
      return 1;
    }

  char c = 0;
  int lines = 1;

  while ((c = fgetc (fd)) != EOF)
    {
      if (c == '\n')
        {
          lines += 1;
        }
    }

  fclose (fd);
  fd = NULL;

  printf ("data/pos has a total of %d lines.\n", lines);

  return 0;
}
