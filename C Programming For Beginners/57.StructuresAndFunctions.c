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

struct family
{
  char name[20];
  int age;
  char father[20];
  char mother[20];
};

_Bool
are_siblings (struct family *member1, struct family *member2)
{
  if (strcmp (member1->mother, member2->mother) == 0)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int
main ()
{
  struct family ben
      = { .name = "Ben", .age = 20, .father = "Dennis", .mother = "Sarah" };
  struct family lucy
      = { .name = "Lucy", .age = 18, .father = "Dennis", .mother = "Sarah" };

  if (are_siblings (&ben, &lucy))
    {
      printf ("Ben and Lucy are siblings!\n");
    }
}
