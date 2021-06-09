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
#include <stdlib.h>

struct item
{
  char *item_name;
  int quantity;
  float price;
  float amount;
};

void
read_item (struct item *it)
{
  printf ("Item name> ");
  fgets (it->item_name, 30, stdin);
  printf ("Quantity> ");
  scanf ("%d", &it->quantity);
  printf ("Price> ");
  scanf ("%f", &it->price);

  it->amount = it->quantity * it->price;
}

void
print_item (const struct item *it)
{
  printf ("\nProduct: %s\n", it->item_name);
  printf ("Quantity: %d\n", it->quantity);
  printf ("Price: %f\n", it->price);
  printf ("Total amount: %f\n", it->amount);
}

int
main ()
{
  struct item it;
  it.item_name = malloc (sizeof (char) * 30);

  struct item *pit = &it;

  read_item (pit);
  print_item (pit);

  free (it.item_name);

  return 0;
}
