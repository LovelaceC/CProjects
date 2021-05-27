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
#include <stdlib.h>

int
main ()
{
  char *str = NULL;
  int max_bytes = 0;

  printf ("This program will let you input a string and store in memory\n");
  printf ("Enter the maximum amount of characters you are going to input: ");
  scanf ("%d", &max_bytes);

  str = (char *)malloc (max_bytes * sizeof (char));

  if (str == NULL)
    {
      printf ("There's been an error allocating memory.\n");
      exit (-1);
    }

  printf ("Enter a word please: ");
  scanf ("%s", str);

  printf ("The word you entered was: %s\n", str);

  free (str);
  str = NULL;

  return 0;
}
