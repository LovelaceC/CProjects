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
  FILE *pfile;
  pfile = fopen ("data/text", "r");

  if (pfile == NULL)
    {
      printf ("Error opening file.\n");
      return 1;
    }

  // -----------------------------------
  // | Reading characters              |
  // -----------------------------------
  int c;
  while ((c = fgetc (pfile)) != EOF)
    {
      printf ("%c", c);
    }

  // Go back to the beginning of the file
  rewind (pfile);

  // -----------------------------------
  // | Reading strings                 |
  // -----------------------------------
  printf ("\n\n\n");
  char str[100];

  // This reads until 99 characters are read or it finds a newline character
  if (fgets (str, 100, pfile) != NULL)
    {
      printf ("%s\n", str);
    }

  fclose (pfile);
  pfile = NULL;

  // ---------------------------------------
  // | Reading formatted input from a file |
  // ---------------------------------------

  FILE *file2;
  file2 = fopen ("data/format", "r");

  if (file2 == NULL)
    {
      printf ("Error opening the second file.\n");
      return 0;
    }

  int format_int;
  char format_char;
  float format_float;

  fscanf (file2, "%d %c %f", &format_int, &format_char, &format_float);

  printf ("%d %c %f\n\n", format_int, format_char, format_float);

  fclose (file2);
  file2 = NULL;

  return 0;
}
