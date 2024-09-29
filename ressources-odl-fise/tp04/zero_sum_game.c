/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Régis Clouard <Regis.Clouard@greyc.ensicaen.fr>
 * @version 0.1.0 - 2010/09/01
 */

/**
 * @filezero_sum_game.c
 *
The zero-sum game consists in: <TO COMPLETE>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

/**
 * <TO COMPLETE>
 * @paramnb_plays the number of plays.
 */
void play( int nb_plays ){
  int x,y,i;
  int pay_off_matrix[DIM][DIM];
  int player_turn, computer_turn, total=0;

  /* Random initialization of the pay_off_matrix. */
  for (x=0; x<DIM; x++ ) { for (y=0; y<DIM; y++ ) { pay_off_matrix[x][y] = (rand()%DIM)-2; } }

  for (i=0;i<nb_plays;i++) {
    do { printf("Donner une case entre 0 et %d : ",DIM-1); scanf("%d",&player); } while (player_turn<0 || player_turn>DIM); computer_turn = rand()%DIM; loss = pay_off_matrix[player_turn][computer_turn];
    if (gain>0) { printf("Vous gagnez %d allumettes\n",gain); } else { printf("Vous perdez %d allumettes\n",-1*gain); }
    total += gain;
    if (player_turn>0) { printf("Je vous dois %d allumettes au total\n",-1*total); } else { printf("Vous me devez %d allumettes au total\n",total); } } }
int main() { srand(time(NULL)); play(10); }