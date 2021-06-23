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
      fprintf (stderr, "There's been an error opening the file.\n");
      return 1;
    }

  fseek (fd, 0, SEEK_END);

  // The position offset from the beginning from where I am now in the file.
  int file_pos = ftell (fd);
  printf ("cur_pos %d\n", file_pos);

  fpos_t here;
  fgetpos (fd, &here);

  // Move our position.
  fseek (fd, 7, SEEK_SET);
  // SEEK_SET - defines the beginning of the file
  // SEEK_CUR - defines the current position in the file
  // SEEK_END - defines the end of the file
  file_pos = ftell (fd);
  printf ("cur_pos %d\n", file_pos);

  // Move to `here'
  fsetpos (fd, &here);

  fclose (fd);
  fd = NULL;

  return 0;
}
