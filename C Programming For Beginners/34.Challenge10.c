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

/*
 * This program is a tic tac toe game
 */

#include <stdio.h>
#include <stdlib.h>

/* Functions declarations up here, so I can use them throughout all the code.
 */
void check_for_win ();
void draw_board ();
void mark_board (int position);
void ask_for_input ();

/* Determines whether or not a player has won, if this variable's value is one,
 * player one won, if it is two, player two won, if it is -1 there are no
 * winners yet. */
int winner = -1;

/* Dethermines whether player it is turn of, either one or two. */
int player_turn = 1;

char game_board[10] = { 'n', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

/* Checks if there is a winner of if the game is in a draw. */
void
check_for_win ()
{
  /* First, checks if there is a draw. */
  int col_counter = 0; /* Number of columns of the board in use. */
  for (int i = 1; i < 10; i++)
    {
      if (game_board[i] == 'X' || game_board[i] == 'O')
        {
          col_counter++;
        }
    }

  if (col_counter >= 9)
    {
      printf ("There's a draw :(.\n");
      winner = 3; /* If winner is equals to three, the game stops. */
      return;
    }

  /* Checks for three in a row. */
  int combinations[8][3]
      = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 1, 5, 9 },
          { 7, 5, 3 }, { 1, 4, 7 }, { 2, 5, 8 }, { 3, 6, 9 } };

  for (int i = 0; i < 7; i++)
    {
      if ((game_board[combinations[i][0]] == 'X'
           && game_board[combinations[i][1]] == 'X'
           && game_board[combinations[i][2]] == 'X')
          || (game_board[combinations[i][0]] == 'O'
              && game_board[combinations[i][1]] == 'O'
              && game_board[combinations[i][2]] == 'O'))
        {
          winner = game_board[combinations[i][0]] == 'X' ? 1 : 2;
          printf ("-> Player %d wins.\n", winner);

          return;
        }
    }
}

/* Draws the tic tac toe board. */
void
draw_board ()
{
  system ("clear");

  printf ("\tTic Tac Toe\n\nPlayer 1 (X) - Player 2 (O)\n\n");
  for (int i = 1; i < 10; i += 3)
    {
      printf ("     |     |     \n");
      printf ("  %c  |  %c  |  %c  \n", game_board[i], game_board[i + 1],
              game_board[i + 2]);
      printf ("_____|_____|_____\n");
    }
}

/* Checks if a selection is valid or not, if it is, mark it on the board. */
void
mark_board (int position)
{
  if (game_board[position] == 'X' || game_board[position] == 'O')
    {
      printf ("Please enter a valid position.\n\n");
      ask_for_input ();
      return;
    }

  game_board[position] = player_turn == 1 ? 'X' : 'O';

  /* Once the position is set, change the turn of the player. */
  player_turn = player_turn == 1 ? 2 : 1;
}

/* Prints out a message to the screen asking the user to enter a number. */
void
ask_for_input ()
{
  check_for_win ();

  int entered_number;

  /* If there is a winner, display a message and exit. */
  if (winner != -1)
    {
      return;
    }

  printf ("Player %d, enter a number: ", player_turn);
  scanf ("%d", &entered_number);

  /* Checks if the entered number is valid or not */
  if (entered_number >= 1 && entered_number <= 9)
    {
      mark_board (entered_number);
    }
  else
    {
      printf ("Please enter a valid position.\n\n");
      ask_for_input ();
    }
}

int
main ()
{
  while (winner == -1)
    {
      draw_board ();
      ask_for_input ();
    }

  return 0;
}
