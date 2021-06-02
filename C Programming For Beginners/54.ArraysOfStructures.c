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

struct date
{
  int month, day, year;
};

int
main ()
{
  struct date dates[10];

  dates[1].month = 8;
  dates[1].day = 8;
  dates[1].year = 1986;

  // Initialising only the first three elements.
  struct date initialising[5]
      = { { 12, 10, 1975 }, { 12, 30, 1980 }, { 11, 15, 2005 } };

  // Initialise the third element.
  struct date third[5] = { [2] = { 12, 10, 1975 } };

  // Initialise only month and day.
  struct date dates1[5] = { [1].month = 12, [1].day = 30 };

  return 0;
}
