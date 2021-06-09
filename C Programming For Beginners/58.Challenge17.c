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

struct employee
{
  char name[20];
  int hire_date;
  float salary;
};

int
main ()
{
  struct employee bassara = { "Bassara", 2021, 800.0f };
  struct employee anonymous;

  printf ("Please enter the following data following this style:\n");
  printf ("   Name    Hire Date (year)    Salary\n");
  printf ("h>");
  scanf ("%s %d %f", anonymous.name, &anonymous.hire_date, &anonymous.salary);

  printf ("Bassara:\n");
  printf ("Name: %s\nHire Date: %d\nSalary: %f\n", bassara.name,
          bassara.hire_date, bassara.salary);
  printf ("\n\nAnonymous:\n");
  printf ("Name: %s\nHire Date: %d\nSalary: %f\n", anonymous.name,
          anonymous.hire_date, anonymous.salary);

  return 0;
}
