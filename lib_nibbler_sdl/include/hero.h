/*
** astek.h for kong in /home/laguet_p/rendu/rush+KONG/etape_2_V3/characters
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Sat Mar  8 13:11:36 2014
** Last update Sat Apr  5 19:59:13 2014 chauvo_t
*/

#ifndef		HERO_H_
# define	HERO_H_

#include "characters.h"

typedef struct	s_hero
{
  SDL_Surface		*hero_display;
  SDL_Surface		*hero_md[12]; // marche droite
  SDL_Surface		*hero_mg[12]; // marche gauche
  SDL_Surface		*hero_a[20]; // action
  SDL_Surface		*hero_p; // pause
  SDL_Surface		*hero_god[13]; // gun out
  SDL_Surface		*hero_gog[13]; // gun out
  SDL_Surface		*hero_gmd[15]; // marche gun droite
  SDL_Surface		*hero_gmg[15]; // marche gun gauche
  SDL_Surface		*hero_gmtd[8]; // transition droite gauche gun
  SDL_Surface		*hero_gmtg[8]; // transition gauche droite gun
  SDL_Surface		*hero_gpg[16]; // pos gauche gun
  SDL_Surface		*hero_gpd[16]; // pos droite gun
  SDL_Surface		*hero_snd[17];
  SDL_Surface		*hero_sng[17];
  SDL_Surface		*hero_sad[18];
  SDL_Surface		*hero_sag[18];

  SDL_Rect		pos_hero;
  int			orient;
  int			gun_out;
  int			shoot_pos;
  int			jump;
}		t_hero;

#endif /* !HERO_H_ */
