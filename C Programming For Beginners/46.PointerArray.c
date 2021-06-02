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
#include <string.h>

int
main ()
{
  char multiple[] = "a string";
  char *p = multiple;

  for (int i = 0; i < strnlen (multiple, sizeof (multiple)); ++i)
    {
      printf ("multiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d = %p\n",
              i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
    }

  return 0;
}
