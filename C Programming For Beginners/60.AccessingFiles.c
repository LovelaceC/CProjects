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
  // Creating a file pointer and accessing the file
  FILE *file = NULL;
  file = fopen ("data/text", "r");

  /**
   * List of modes (the "r" thingy)
   *
   * "w": Open a text file for write operations. If the file exists, its
   * current contents are discarded.
   * "a": Open a text file for append operations. All writes are to the end of
   * the file.
   * "r": Open a text file for read reasons.
   * "w+": Open a text file for update (reading and writing), first truncating
   * the file to zero length if it exists or creating the file if it does not
   * exist.
   * "a+": Open a text file for update (reading and writing) appending to the
   * end of the existing file, or creating the file if it does not exist yet.
   * "r+": Open a text file for update (for both reading and writing)
   */

  if (file == NULL)
    {
      printf ("There's been an error trying to open the file.\n");
      return 1;
    }

  fclose (file); // Closing the file
  file = NULL;

  // Renaming a file
  if (rename ("data/text", "data/text.txt") != 0)
    {
      printf ("There's been an error trying to rename the file.\n");
      return 1;
    }

  // Deleting a file
  remove ("data/text.txt");

  return 0;
}
