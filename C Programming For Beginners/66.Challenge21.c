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
      fprintf (stderr, "Error opening `data/pos'\n");
      return 1;
    }

  fseek (fd, 0, SEEK_END);
  int count = ftell (fd);

  int i = 0;

  while (i < count)
    {
      i++;
      fseek (fd, -i, SEEK_END);

      printf ("%c", fgetc (fd));
    }

  fclose (fd);
  fd = NULL;

  return 0;
}