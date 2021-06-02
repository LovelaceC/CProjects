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

enum primary_color
{
  red,
  yellow,
  blue
};

enum month
{
  january,
  february,
  march,
  april,
  may,
  june,
  july,
  august,
  september,
  october,
  november,
  december
};

enum direction
{
  up,
  down,
  left = 10,
  right
};

// characters definition
char a_character = 'A';
char another_character = 48;
char break_line = '\n';
char backspace_character = '\b';

int
main ()
{
  enum primary_color my_color;
  my_color = red;

  enum month current_month;
  current_month = april;

  enum direction some_direction;
  some_direction = left;
}
