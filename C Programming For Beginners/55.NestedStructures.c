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

struct date
{
  int month;
  int day;
  int year;
};

struct time
{
  int hour;
  int minute;
  int second;
};

struct date_and_time
{
  struct date sdate;
  struct time stime;
};

int
main ()
{
  // Initialie even to 2/1/2021 3:30:00
  struct date_and_time event = { { 2, 1, 2021 }, { 3, 30, 0 } };

  struct date_and_time events[100];

  return 0;
}
