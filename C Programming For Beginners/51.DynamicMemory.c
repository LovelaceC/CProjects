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
#include <string.h>

int
main ()
{
  char *str = NULL;

  /* Initial memory allocation. */
  str = (char *)malloc (sizeof (char) * 15);
  strcpy (str, "zeabanger");
  printf ("String = %s\nAddress = %p\n", str, str);

  /* Reallocating memory. */
  str = (char *)realloc (str, sizeof (char) * 15);
  strcat (str, ".gq");
  printf ("String = %s\nAddress = %p\n", str, str);

  free (str);

  return 0;
}
