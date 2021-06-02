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

/**
 * This is the correct execution of the challenge 5.
 */

#include <stdio.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int
main ()
{
  int hours = 0;
  double gross_pay = 0.0;
  double taxes = 0.0;
  double net_pay = 0.0;

  printf ("Enter the total of worked hours this week: ");
  scanf ("%d", &hours);

  // Calculate the gross pay
  if (hours <= 40)
    {
      gross_pay = hours * PAYRATE;
    }
  else
    {
      gross_pay = 40 * PAYRATE;

      double overtime_pay = (hours - 40) * (PAYRATE * 1.5);
      gross_pay = gross_pay + overtime_pay;
    }

  // Taxes calculation
  if (gross_pay <= 300)
    {
      taxes = gross_pay * TAXRATE_300;
    }
  else if (gross_pay > 300 && gross_pay <= 450)
    {
      taxes = 300 * TAXRATE_300;
      taxes = taxes + ((gross_pay - 300) * TAXRATE_150);
    }
  else if (gross_pay > 450)
    {
      taxes = 300 * TAXRATE_300;
      taxes = taxes + (150 * TAXRATE_150);
      taxes = taxes + ((gross_pay - 450) * TAXRATE_REST);
    }

  net_pay = gross_pay - taxes;

  printf ("Gross pay: %.2f\n", gross_pay);
  printf ("Taxes: %.2f\n", taxes);
  printf ("Net pay: %.2f\n", net_pay);

  return 0;
}
