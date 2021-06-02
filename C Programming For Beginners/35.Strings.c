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
  char str1[] = "To be or not to be";
  char str2[] = ", that is the question";
  unsigned int count = 0; /* String length */

  while (str1[count] != '\0')
    {
      count++;
    }

  printf ("The length of the string \"%s\" is %d characters.\n", str1, count);

  count = 0; /* Reset count for str2 */
  while (str2[count] != '\0')
    {
      count++;
    }

  printf ("The length of the string \"%s\" is %d characters.\n", str2, count);

  return 0;
}
