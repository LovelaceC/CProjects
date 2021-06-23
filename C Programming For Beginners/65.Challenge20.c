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
      fprintf (stderr, "Error opening file \"data/pos\"\n");
      return 1;
    }

  char ch = 0;

  FILE *f2 = fopen ("data/tmp", "w");
  if (!f2)
    {
      fprintf (stderr, "Error creating a temporary file.\n");
      return 1;
    }

  while ((ch = fgetc (fd)) != EOF)
    {
      /* If the current character is a lowecase letter. */
      if (ch >= 97 && ch <= 122)
        {
          ch = ch - 32;
        }

      /* If the current character is other than a lowercase letter. */
      fputc (ch, f2);
    }

  printf ("Converting lowercase to uppercase done.\n");

  // We close both the files and set them to NULL.
  fclose (fd);
  fclose (f2);

  fd = NULL;
  f2 = NULL;

  printf ("Renaming `data/tmp' to `data/pos'\n");

  if (rename ("data/tmp", "data/pos") != 0)
    {
      fprintf (stderr, "Error renaming the file.\n");
      return 1;
    }

  printf ("Finished.\n");

  char str[1024];

  fd = fopen ("data/pos", "r");
  printf ("The final content of the file is:\n\n");

  while (fgets (str, 1024, fd) != NULL)
    {
      printf ("%s", str);
    }

  fclose (fd);
  fd = NULL;

  return 0;
}
