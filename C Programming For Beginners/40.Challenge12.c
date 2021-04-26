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
main ()
{
  char str[50];
  printf ("This program will read a string from input and will print it in "
          "reverse order.\nPlease enter your string: ");
  scanf ("%s", str);

  int len = strlen (str);

  for (int i = len; i >= 0; i--)
    {
      printf ("%c", str[i]);
    }

  printf ("\n\n");

  char name[25][50];
  char temp[25];
  int n;

  printf ("\n\nSorts the strings of an array using bubble sort.\n");
  printf ("Input number of strings: ");
  scanf ("%d", &n);

  for (int i = 0; i <= n; i++)
    {
      printf ("Input string %d:\n", i);
      scanf ("%s", name[i]);
    }

  for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= n - i; j++)
        {
          if (strcmp (name[j], name[j + 1]) > 0)
            {
              strncpy (temp, name[j], sizeof (temp) - 1);
              strncpy (name[j], name[j + 1], sizeof (name[j]) - 1);
              strncpy (name[j + 1], temp, sizeof (name[j] + 1) - 1);
            }
        }
    }

  printf ("The strings after sorting: \n");

  for (int i = 0; i <= n; i++)
    {
      printf ("%s\n", name[i]);
    }

  return 0;
}
