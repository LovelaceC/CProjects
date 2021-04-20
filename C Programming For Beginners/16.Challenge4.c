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
 * This program will print the size of the basic datatypes
 */

int
main ()
{

  printf ("Size of int: %zd\n", sizeof (int));
  printf ("Size of char: %zd\n", sizeof (char));
  printf ("Size of short: %zd\n", sizeof (short));
  printf ("Size of float: %zd\n", sizeof (float));
  printf ("Size of long: %zd\n", sizeof (long));
  printf ("Size of long long: %zd\n", sizeof (long long));
  printf ("Size of double: %zd\n", sizeof (double));
  printf ("Size of long double: %zd\n", sizeof (long double));

  return 0;
}
