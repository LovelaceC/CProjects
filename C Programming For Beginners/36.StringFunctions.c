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
  /* Get the length of a string. */
  char str1[35] = "String number one.";
  int str1_len = strlen (str1);

  printf ("The length of the string %s is %d\n\n", str1, str1_len);

  /* Copying an string to another. */
  strcpy (str1, "String number one modified");
  printf ("I changed the value of str1, its value now is: %s\n\n", str1);

  /* Copying only the maximum quantity of characters allowed based on the
   * str1's size.. */
  strncpy (str1, "This string's maximum length is 30 characters.",
           sizeof (str1) - 1);
  printf ("In order to prevent errors, I used strncpy to copy a maximum of 30 "
          "characters into str1, this is the result: %s\n\n",
          str1);

  /* Concatenates two strings. */
  strcpy (str1, "String number one,");
  char str2[] = " and number two.";
  printf ("Concatenating str1 and str2. The result is: %s\n\n",
          strcat (str1, str2));

  /* Concatenating a string with a maximum number of characters. */
  strcpy (str1, "String number one, ");
  char str3[100] = "together with a string whose size could be more than 100 "
                   "characters, lmao how crazy.";
  printf ("Concatenating \"%s\" to \"%s\" by only %lx bytes. The result is: ",
          str3, str1, sizeof (str1));
  printf ("%s\n\n", strncat (str1, str3, sizeof (str1) - 1));

  /* Compare two strings. */
  strcpy (str1, "A string");
  strcpy (str2, "A string");

  if (strcmp (str1, str2) == 0)
    {
      /* strcmp returns zero if both strings are equals, < 0 is str1 is less
       * than str2 and > 0 if str2 if less than str1. */
      printf ("Str1 and str2 are equals.\n\n");
    }

  /* Compare just a number of characters in two arrays. */
  strcpy (str1, "defun a");
  strcpy (str2, "defun b");

  if (strncmp (str1, str2, 5) == 0)
    {
      printf ("Both str1 and str2 start with \"defun\".\n\n");
    }

  return 0;
}
