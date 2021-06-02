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
main ()
{
  int int_variable = 10;
  float float_var = 331.79;
  double double_var = 8.44e+11;
  char char_var = 'W';
  _Bool bool_var = 0;

  short int short_int_var = 10;
  unsigned short int ushort_var = 100;
  unsigned int uint_var = 1000;
  long int long_int_var = 10L;
  unsigned long int ulong_int_var = 10000L;
  long long int llong_int_var = -1000L;
  unsigned long long int ullong_int_var = 1000000000L;

  printf ("The variables are:\n");
  printf ("Integer: %i\n", int_variable); //%i
  printf ("Floating: %f\n", float_var);   //%f
  printf ("Only two decimal numbers of our floating variable: %.2f\n",
          float_var);                                  //%.f
  printf ("Double: %f, %e\n", double_var, double_var); //%f %e
  printf ("Double: %g\n", double_var);                 //%g
  printf ("Char: %c\n", char_var);                     //%c
  printf ("Bool: %i\n", bool_var);                     //%i

  printf ("Short int: %hi, %hx, %ho\n", short_int_var, short_int_var,
          short_int_var); // %hi %hx %ho
  printf ("Unsigned short int: %hu, %hx, %ho\n", ushort_var, ushort_var,
          ushort_var); // %hu %hx %ho
  printf ("Unsigned int: %u %x %o\n", uint_var, uint_var,
          uint_var); // %u %x %o
  printf ("Long int: %li %lx %lo\n", long_int_var, long_int_var,
          long_int_var); // %li %lx %lo
  printf ("Unsigned long int: %lu %lx %lo\n", ulong_int_var, ulong_int_var,
          ulong_int_var); // %lu %lx %lo
  printf ("Long long int: %lli  %llx  %llo\n", llong_int_var, llong_int_var,
          llong_int_var); // %lli %llx %llo
  printf ("Unsigned long long int: %llu %llx %llo\n", ullong_int_var,
          ullong_int_var, ullong_int_var); // %llu %llx %llo

  return 0;
}
