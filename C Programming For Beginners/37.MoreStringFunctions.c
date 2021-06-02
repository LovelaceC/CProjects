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
main (void)
{
  /* Search for a character in a string. */
  char character[] = "The quick brown fox";
  char sought_character = 'q';
  char *c_found = NULL;
  c_found = strchr (character,
                    sought_character); /* Should return `quick brown fox`. */
  printf ("%s\n\n", c_found);

  /* Search for a substring in a string. */
  char text[] = "Every dog has his day";
  char sought_word[] = "dog";
  char *w_found = NULL;
  w_found = strstr (text, sought_word); /* Should return `dog has his day`. */
  printf ("%s\n\n", w_found);

  /* Tokenize a string. */
  char prog[] = "(defun a-function (list)"
                "(if (null list)"
                "0"
                "(+ 1 (a-function (cdr list)))))";
  const char s[2] = "("; /* Delimiter. */
  char *token;

  token = strtok (prog, s); /* Tokenize the string. */

  while (token != NULL)
    {
      /* Print each token */
      printf (" %s\n", token);

      token = strtok (NULL, s);
    }

  return 0;
}
