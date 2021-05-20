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
main (void)
{
  long num = 9999L;
  long num1 = 199L;

  /* The value `ptr_num` is pointing to cannot change. */
  const long *ptr_num = &num;

  /* For example, *ptr_num = 100L; is not valid. */
  /* We can change the address ptr_num is pointing to. */
  ptr_num = &num1;

  /* The value of `ptr_num1` cannot change. */
  long *const ptr_num1 = &num1;

  /* If we do, for example, ptr_num1 = &num; is not valid. */

  /* The value of the variable that `ptr_num1` points to can change. */
  *ptr_num1 = 9000L;

  /* Create a pointer whose value and its pointed to value cannot change. */
  const long *const ptr = &num;

  return 0;
}
