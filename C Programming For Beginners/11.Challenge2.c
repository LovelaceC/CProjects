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

/**
 * This challenge is to learn how to use enums
 */

int
main ()
{

  enum companies
  {
    GOOGLE,
    FACEBOOK,
    XEROX,
    YAHOO,
    EBAY,
    MICROSOFT
  };

  enum companies company_xerox = XEROX;
  enum companies company_google = GOOGLE;
  enum companies company_ebay = EBAY;

  printf ("%i\n%i\n%i\n", company_xerox, company_google, company_ebay);

  return 0;
}
