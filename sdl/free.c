/*
** display.c for star-voyager in /home/laguet_p/star_pm/sdl
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 00:43:54 2014
** Last update Mon Mar 31 12:08:37 2014 
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "sdl.h"

void		free_hero(t_chara *mob)
{
  int		i;

  i = 0;
  SDL_FreeSurface(mob->hero.hero_p);
  while (i < 20)
    {
      if (i < 8) // transition gun
	{
	  SDL_FreeSurface(mob->hero.hero_gmtd[i]);
	  SDL_FreeSurface(mob->hero.hero_gmtg[i]);
	}
      if (i < 12) // marche
	{
	  SDL_FreeSurface(mob->hero.hero_mg[i]);
	  SDL_FreeSurface(mob->hero.hero_md[i]);
	}
      if (i < 13) // gun out in
	{
	  SDL_FreeSurface(mob->hero.hero_god[i]);
	  SDL_FreeSurface(mob->hero.hero_gog[i]);
	}
      if (i < 15)
	{
	  SDL_FreeSurface(mob->hero.hero_gmd[i]);
	  SDL_FreeSurface(mob->hero.hero_gmg[i]);
	}
      if (i < 16)
	{
	  SDL_FreeSurface(mob->hero.hero_gpg[i]);
	  SDL_FreeSurface(mob->hero.hero_gpd[i]);
	}
      if (i < 17) // saut normal
	{
	  SDL_FreeSurface(mob->hero.hero_snd[i]);
	  SDL_FreeSurface(mob->hero.hero_sng[i]);
	}
      if (i < 18) // saut avant
	{
	  SDL_FreeSurface(mob->hero.hero_sad[i]);
	  SDL_FreeSurface(mob->hero.hero_sag[i]);
	}
      if (i < 20) // action
	SDL_FreeSurface(mob->hero.hero_a[i]);
      i = i + 1;
    }
}

void		free_door01(t_deco *door01)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      SDL_FreeSurface(door01->door.open_door[i]);
      i = i + 1;
    }
}

void		free_all(t_window window, t_chara *mob)
{
  SDL_FreeSurface(window.fond);
  free_hero(mob);
}
