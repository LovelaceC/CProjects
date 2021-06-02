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
 * This program (challenge 1) will display the perimeter and area of a
 * rectangle.
 *
 * Note: the width and height are passed as command line arguments by
 * the user
 */

#include <stdio.h>

int
main (int argc, char *argv[])
{
  double rectangle_width, rectangle_height, rectangle_perimeter,
      rectangle_area;

  rectangle_width = atoi (argv[1]);
  rectangle_height = atoi (argv[2]);

  rectangle_perimeter = 2.0 * (rectangle_height + rectangle_width);
  rectangle_area = rectangle_width * rectangle_height;

  printf ("Rectangle height: %f\nRectangle width: %f\nRectangle area: "
          "%f\nRectangle perimeter: %f\n",
          rectangle_width, rectangle_height, rectangle_area,
          rectangle_perimeter);

  return 0;
}
