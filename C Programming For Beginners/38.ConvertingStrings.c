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
#include <string.h>

int
main (void)
{
  char text[100];
  char substring[40];

  printf ("Enter the string to be searched (less than %lu characters):\n",
          sizeof (text) - 1);
  scanf ("%s", text);

  printf ("Enter the string sought (less than %lu characters):\n",
          sizeof (substring) - 1);
  scanf ("%s", substring);

  printf ("\n\nFirst string entered: \n%s\n\n", text);
  printf ("\n\nSecond string entered: \n%s\n\n", substring);

  /* Convert both text and susbtring to uppercase. */
  for (int i = 0; (text[i] = (char)toupper (text[i])) != '\0'; ++i)
    ;
  for (int i = 0; (substring[i] = (char)toupper (substring[i])) != '\0'; ++i)
    ;

  printf ("The second string %s found in the first.\n",
          ((strstr (text, substring) == NULL) ? "was not" : "was"));

  /* More conversion functions:
   * atof: Converts a string into a double.
   * atoi: Converts a string into an int.
   * atol: Converts a string into a long.
   * atoll: Convertts a string into a long long. */

  return 0;
}
