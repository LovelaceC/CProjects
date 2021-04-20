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

/**
 * This challenge meants to convert minutes to years and days
 */

int
main ()
{

  double minutes, days, years, minutes_in_year = (60 * 24) * 365;

  printf ("Enter the number of minutes: ");
  scanf ("%lf", &minutes);

  days = (minutes / 60) / 24;
  years = minutes / minutes_in_year;

  printf ("Number of days: %f\n", days);
  printf ("Number of years: %f\n", years);

  return 0;
}
