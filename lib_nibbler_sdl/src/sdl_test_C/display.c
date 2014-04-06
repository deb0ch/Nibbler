/*
** display.c for star-voyager in /home/laguet_p/star_pm/sdl
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 00:43:54 2014
** Last update Tue Apr  1 20:03:41 2014 
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "sdl.h"

int		refresh(t_chara *mob, t_window *window, t_deco *door01, int y)
{
  //      gravity(mob, window); // ?????
  SDL_FillRect(window->screen, NULL, SDL_MapRGB(window->screen->format, 0, 0, 0));
  creat_fond(mob, window);
  SDL_BlitSurface(mob->hero.hero_display, NULL, window->screen, &mob->hero.pos_hero);
  creat_first_plan(window);
  SDL_Flip(window->screen);
  return (y);
}

void		pause(t_chara *mob, t_window *window) // main while
{
  SDL_Event	event;
  t_deco	*door01 = NULL;
  int		i;
  int		y;
  int		timer;

  i = y = timer = 0;
  window->start = 0;
  SDL_EnableKeyRepeat(50, 50);
  while (i != -1)
    {
      SDL_WaitEvent(&event);
      if (event.type  && (mob->hero.gun_out == 0 || mob->hero.gun_out == 5) &&
	  mob->hero.jump == 0) // basic mode
        {
	  if (SDL_KEYDOWN)
	    i = basic_mode(event.key.keysym.sym, mob, window, door01, i);
	  timer = timer_pause(mob, timer);
        }
      else if (mob->hero.jump == 1) // jump mode
	y = jump_filter(event.key.keysym.sym, mob, window, door01, y); // filtre IN du jump
      else if (event.type  && (mob->hero.gun_out == 1 || mob->hero.gun_out == 2 ||
			       mob->hero.gun_out == 3) && mob->hero.jump == 0) // gun mode
        {
	  if (SDL_KEYDOWN)
	    i = gun_mode(event.key.keysym.sym, mob, window, door01, i); //
	  y = gun_filter(mob, window, door01, y); // filtre IN ou OUT du gun
	  timer = timer_pause(mob, timer);
        }
      y = refresh(mob, window, door01, y); // Refresh toute l'image
    }
  free_door01(door01);
}

void		load_sdl()
{
  t_chara	*mob = NULL;
  t_window	window;

  mob = init_mob(mob); // Init le Héro

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    printf("[ERROR] : SDL_INIT_VIDEO failled\n");
  window.screen = SDL_SetVideoMode(X * BLOCK, Y * BLOCK, COLOR, SDL_HWSURFACE);
  SDL_WM_SetCaption("Star Voyager", NULL);
  SDL_FillRect(window.screen, NULL, SDL_MapRGB(window.screen->format, 0, 0, 0));
  SDL_Flip(window.screen);

  pause(mob, &window); // Boucle pricinpale !

  free_all(window, mob); // Free mob et ecran !
  SDL_Quit();
}
