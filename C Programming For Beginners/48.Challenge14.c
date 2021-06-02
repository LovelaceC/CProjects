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
string_length (const char *str)
{
  const char *end;
  const char *start = str;

  while (*str)
    {
      end = ++str;
    }

  return end - start;
}

/* This is the function that the instructor wrote :3 */
int
string_length_jason (const char *str)
{
  const char *last_address = str;

  while (*last_address)
    {
      last_address++;
    }

  return last_address - str;
}

int
main ()
{
  char str[] = "A very cool and neat string :333.";

  printf ("%d\n", string_length (str));
  printf ("%d\n", string_length_jason ("Helouda!"));

  return 0;
}
