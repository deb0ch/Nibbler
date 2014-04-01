/*
** display.c for star-voyager in /home/laguet_p/star_pm/sdl
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 00:43:54 2014
** Last update Wed Mar 12 16:35:08 2014 
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "sdl.h"

t_deco		*init_door01(t_deco *door01)
{
  if ((door01 = malloc(sizeof (t_deco))) == NULL) // Malloc de la porte
    printf("[ERROR] : malloc [door01] failled\n");
  sprit_deco(door01); // load bmp porte
  door01->door.open = 0;
  return (door01);
}

t_chara		*init_mob(t_chara *mob)
{
  if ((mob = malloc(sizeof (t_chara))) == NULL)
    printf("[ERROR] : malloc de [mob] failled");
  sprit_hero(mob); // load bmp hero
  return (mob);
}
