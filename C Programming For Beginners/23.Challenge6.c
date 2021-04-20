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
 * This program is a little game where the user should guess a number generated
 * randomly between 0 and 20.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main ()
{
  time_t time_seed;
  srand ((unsigned)time (&time_seed));

  int random_number = rand () % 21;
  int guessed_number = 0;
  int number_of_attempts = 0;

  printf ("This is a guessing game.\n");
  printf ("I have chosen a number between 0 and 20 which you must guess\n\n");

  for (number_of_attempts = 5; number_of_attempts > 0; number_of_attempts--)
    {
      printf ("You have %i tr%s left.\n", number_of_attempts,
              number_of_attempts == 1 ? "y" : "ies");
      printf ("Enter a guess: ");
      scanf ("%i", &guessed_number);

      if (guessed_number < 0 || guessed_number > 20)
        {
          while (guessed_number > 20)
            {
              printf ("Please enter a valid number between 0 and 20: ");
              scanf ("%i", &guessed_number);
            }
        }

      if (guessed_number < random_number)
        {
          printf ("Sorry, %i is wrong. My number is more than that.\n\n",
                  guessed_number);
        }
      else if (guessed_number > random_number)
        {
          printf ("Sorry, %i is wrong. My number is less than that.\n\n",
                  guessed_number);
        }
      else if (guessed_number == random_number)
        {
          printf ("Congratulations you guessed it\n\n");
          break;
        }
    }

  printf ("The number I generated is: %i\n\n", random_number);

  return 0;
}
