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
 * This is my attempt at completing this challenge. It is bad, as I used nested
 * if statements but I should have used if/elses so this is bad, the next
 * program is the version provided by the course instructor.
 */

#include <stdio.h>

int
main ()
{
  float worked_hours, gross_pay = 0.0f, taxes_calculation = 0.0f,
                      normal_hours = 0, overtime_hours = 0, total_taxes = 0,
                      net_pay = 0;
  int basic_pay_rate = 12, overtime_pay_rate = 18;

  printf ("Enter the number of hours worked this week: ");
  scanf ("%f", &worked_hours);

  printf ("The amount of worked hours entered is: %f\n", worked_hours);

  if (worked_hours > 40)
    {
      overtime_hours = (worked_hours - 40);
    }

  normal_hours = worked_hours - overtime_hours;

  gross_pay
      = (normal_hours * basic_pay_rate) + (overtime_hours * overtime_pay_rate);

  if (gross_pay > 300)
    {
      total_taxes += (gross_pay / 100) * 15;
      taxes_calculation = total_taxes - 300;

      if (taxes_calculation >= 150)
        {
          total_taxes += (gross_pay / 100) * 20;
          taxes_calculation = total_taxes - 150;

          if (taxes_calculation > 0)
            {
              total_taxes += (gross_pay / 100) * 25;
            }
        }
    }

  net_pay = gross_pay - total_taxes;

  printf ("Gross pay: %f\n", gross_pay);
  printf ("Taxes to pay :%f\n", total_taxes);
  printf ("Net pay: %f\n", net_pay);

  return 0;
}
