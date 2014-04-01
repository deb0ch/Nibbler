/*
** creat_func.c for Star Voyager in /home/laguet_p/star_pm/sdl
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 04:15:30 2014
** Last update Fri Mar 14 17:33:11 2014 
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "../sdl.h"


void		start_hero(t_chara *mob, t_window *window)
{
  mob->hero.pos_hero.x = 1350;
  mob->hero.pos_hero.y = 489;
  hero_stand_by(mob, window);
}

void		creat_first_plan(t_window *window)
{
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  window->first_plan = SDL_LoadBMP("sprit/bmp/starship/starship_first_plan.bmp");
  SDL_SetColorKey(window->first_plan, SDL_SRCCOLORKEY, SDL_MapRGB(window->screen->format, 0, 0, 0));
  if (window->first_plan == NULL)
    printf("Error: 1st plan : SDL_LoadBMP failed");
  SDL_BlitSurface(window->first_plan, NULL, window->screen, &pos);
}

void		creat_fond(t_chara *mob, t_window *window)
{
  SDL_Rect	pos;
  if (window->start == 0)
    {
      start_hero(mob, window);
      window->start = 1;
    }
  pos.x = 0;
  pos.y = 0;
  window->fond = SDL_LoadBMP("sprit/bmp/starship/starship.bmp");
  if (window->fond == NULL)
    printf("Error: fond : SDL_LoadBMP failed");
  SDL_BlitSurface(window->fond, NULL, window->screen, &pos);
}
