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
#include <stdlib.h>
#include <string.h>

struct date
{
  int month;
  int day;
  int year;
};

struct int_ptr
{
  int *p1;
  int *p2;
};

struct names
{
  char first[20];
  char last[20];
};

struct pnames
{
  char *first;
  char *last;
};

int
main ()
{
  struct date today;

  // Declaring a struct as a pointer
  // ===============================

  struct date *dateptr = &today;
  dateptr->day = 4;
  dateptr->month = 6;
  dateptr->year = 2021;

  if (dateptr->year > 2010)
    {
      printf ("Wow, the year is now greater than 2010.\n");
    }

  printf ("Day: %d, Month: %d\n", today.day, today.month);

  // Structures containing pointers
  // ==============================

  struct int_ptr pointers;
  int i1 = 100, i2;

  pointers.p1 = &i1;
  pointers.p2 = &i2;
  *pointers.p2 = -97;

  printf ("i1 = %d, *pointers.p1 = %d\n", i1, *pointers.p1);
  printf ("i2 = %d, *pointers.p2 = %d\n", i2, *pointers.p2);

  // Character arrays/character pointers
  // ===================================

  struct names veep = { "Talia", "Summers" };
  struct pnames treas = { "Brad", "Fallingjaw" }; // DON'T DO IT THIS WAY
  printf ("%s and %s\n", veep.first, treas.first);

  struct pnames pnames_ins;
  pnames_ins.first = (char *)malloc (sizeof (char) * 7);
  strncpy (pnames_ins.first, "Albert", 6);
  pnames_ins.last = (char *)malloc (sizeof (char) * 11);
  strncpy (pnames_ins.last, "Fallingjaw", 10);

  printf ("%s %s\n", pnames_ins.first, pnames_ins.last);

  return 0;
}
