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
  FILE *fd = fopen ("data/write", "w");
  if (!fd)
    {
      fprintf (stderr, "Error opening the file to write.\n");
      goto out;
    }

  // Write a single character
  if (fputc ('A', fd) == EOF)
    {
      fprintf (stderr, "Error putting character 'A' to the file.\n");
      goto out;
    }

  printf ("'A' written successfully.\n");

  // Writing a string to a file
  if (fputs ("Written a string.\n", fd) == EOF)
    {
      fprintf (stderr, "Error writing a string to file.\n");
      goto out;
    }

  printf ("String written to file successfully.\n");

  // Printing formatted output
  int var_a = 10;
  if (fprintf (fd, "\nvar_a=%d\n", var_a) < 0)
    {
      fprintf (stderr, "Error writing a formatted string to the file.\n");
      goto out;
    }

  printf ("Formatted output added successfully to the file.\n");

out:
  fclose (fd);
  fd = NULL;

  return 0;
}
