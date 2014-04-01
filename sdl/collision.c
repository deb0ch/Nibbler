/*
** collision.c for Star Voyager in /home/laguet_p/star_pm/sdl
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 15:36:10 2014
** Last update Fri Mar 28 19:44:13 2014 
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "sdl.h"

void		sol_ship(t_chara *mob)
{
  if (mob->hero.pos_hero.y > 489)
    mob->hero.pos_hero.y = 489;
}

void		wall_ship_rc(t_chara *mob)
{
  if (mob->hero.pos_hero.y == 489 && mob->hero.pos_hero.x > 1360)
    mob->hero.pos_hero.x = 1360;
}

void		door_block(t_chara *mob, t_deco *door01)
{
  if (door01->door.open == 0)
    {
      if (mob->hero.pos_hero.y == 489 && mob->hero.pos_hero.x < 1215)
	mob->hero.pos_hero.x = 1215;
    }
}

void		meeting_object(t_chara *mob, t_deco *door01)
{
  if(mob->hero.pos_hero.x > 1235 && mob->hero.pos_hero.x < 1250)
    door01->door.zone = 1; // delock door
  else
    door01->door.zone = 0;
}

void		collision(t_chara *mob, t_deco *door01)
{
  sol_ship(mob);
  wall_ship_rc(mob);
  door_block(mob, door01);
  meeting_object(mob, door01);
}

void		gravity(t_chara *mob, t_window *window)
{
  while (mob->hero.pos_hero.y < 489)
    {
      mob->hero.pos_hero.y = mob->hero.pos_hero.y + 1;
      SDL_FillRect(window->screen, NULL, SDL_MapRGB(window->screen->format, 0, 0, 0));
      creat_fond(mob, window);
      SDL_BlitSurface(mob->hero.hero_display, NULL, window->screen, &mob->hero.pos_hero);
      creat_first_plan(window);
      SDL_Flip(window->screen);
    }
}
