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

int
main ()
{
  int counters[5] = { 0, 1, 2, 3, 4 };

  int i;
  for (i = 0; i < 5; ++i)
    {
      printf ("counters[%i] = %i\n", i, counters[i]);
    }

  // Only the first three elements (0 - 2) will be initialised, the other
  // values will be set to 0.
  float sample_data[500] = { 100.0, 300.0, 500.0 };

  // Only the elements 3/6/9 (fourth, seventh and tenth//// ) will be
  // initialised.
  double double_data[100] = { [3] = 100, [6] = 200, [9] = 900 };

  int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  for (i = 0; i < 12; ++i)
    {
      printf ("Month %d has %2d days\n", i + 1, days[i]);
    }

  return 0;
}
