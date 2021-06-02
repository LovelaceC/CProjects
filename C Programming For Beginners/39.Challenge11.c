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

/* Returns the length of `string`. */
int
check_length (char *string)
{
  int i = 0;
  while (string[i] != '\0')
    {
      i++;
    }

  return i;
}

/* Concatenates the values of `str1` and `str2` into `dest`. */
void
concatenate_strings (char *dest, char *str1, char *str2)
{
  int i = 0;
  int offset = check_length (str1);
  int len2 = check_length (str2);

  for (i = 0; i < offset; i++)
    {
      dest[i] = str1[i];
    }

  for (i = 0; i < len2; i++)
    {
      dest[offset + i] = str2[i];
    }

  /* The way jason (The instructor) did it.
   *
   * int i, j;
   *
   * for (i = 0; str1[i] != '\0'; ++i)
   *   {
   *      dest[i] = str1[i];
   *   }
   *
   * for (j = 0; str2[j] != '\0'; j++)
   *   {
   *     dest[i + j] = str2[j];
   *   }
   *
   * */
}

/* Returns true if `str1` is equals to `str2`. */
_Bool
string_equals (char *str1, char *str2)
{
  for (int i = 0; str1[i] == str2[i]; i++)
    {
      if (str1[i] == '\0')
        {
          return 1;
        }
    }

  return 0;
}

int
main ()
{
  char str[] = "I will check the length of this string without using strlen.";
  printf ("%d\n", check_length (str));

  char result[100];
  const char str1[] = "I will put together this string,";
  const char str2[] = " with this.";

  concatenate_strings (result, str1, str2);

  printf ("Concatenated: %s\n", result);

  if (string_equals ("Equals", "Equals"))
    {
      printf ("\nThe two specified arrays are equals.\n");
    }

  return 0;
}
