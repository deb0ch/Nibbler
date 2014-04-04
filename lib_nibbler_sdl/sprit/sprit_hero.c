/*
** sprit_hero.c for star_pm in /home/laguet_p/star_pm/load_sprit
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 00:18:53 2014
** Last update Fri Mar 28 19:11:32 2014 
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../sdl/sdl.h"


void		hero_pause(t_chara *mob)
{
  if (!(mob->hero.hero_p = SDL_LoadBMP("sprit/bmp/hero/pause/p.bmp")))
    fprintf(stderr, "bad load of hero_pause");
}

void		hero_marche(t_chara *mob)
{
  mob->hero.hero_md[0] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md01.bmp");
  mob->hero.hero_md[1] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md02.bmp");
  mob->hero.hero_md[2] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md03.bmp");
  mob->hero.hero_md[3] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md04.bmp");
  mob->hero.hero_md[4] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md05.bmp");
  mob->hero.hero_md[5] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md06.bmp");
  mob->hero.hero_md[6] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md07.bmp");
  mob->hero.hero_md[7] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md08.bmp");
  mob->hero.hero_md[8] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md09.bmp");
  mob->hero.hero_md[9] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md10.bmp");
  mob->hero.hero_md[10] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md11.bmp");
  mob->hero.hero_md[11] = SDL_LoadBMP("sprit/bmp/hero/marche/md/md12.bmp");

  mob->hero.hero_mg[0] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg01.bmp");
  mob->hero.hero_mg[1] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg02.bmp");
  mob->hero.hero_mg[2] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg03.bmp");
  mob->hero.hero_mg[3] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg04.bmp");
  mob->hero.hero_mg[4] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg05.bmp");
  mob->hero.hero_mg[5] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg06.bmp");
  mob->hero.hero_mg[6] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg07.bmp");
  mob->hero.hero_mg[7] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg08.bmp");
  mob->hero.hero_mg[8] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg09.bmp");
  mob->hero.hero_mg[9] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg10.bmp");
  mob->hero.hero_mg[10] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg11.bmp");
  mob->hero.hero_mg[11] = SDL_LoadBMP("sprit/bmp/hero/marche/mg/mg12.bmp");

}

void		hero_actiond(t_chara *mob)
{
  mob->hero.hero_a[0] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad01.bmp");
  mob->hero.hero_a[1] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad02.bmp");
  mob->hero.hero_a[2] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad03.bmp");
  mob->hero.hero_a[3] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad04.bmp");
  mob->hero.hero_a[4] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad05.bmp");
  mob->hero.hero_a[5] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad06.bmp");
  mob->hero.hero_a[6] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad07.bmp");
  mob->hero.hero_a[7] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad08.bmp");
  mob->hero.hero_a[8] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad09.bmp");
  mob->hero.hero_a[9] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad10.bmp");
  mob->hero.hero_a[10] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad11.bmp");
  mob->hero.hero_a[11] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad12.bmp");
  mob->hero.hero_a[12] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad13.bmp");
  mob->hero.hero_a[13] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad14.bmp");
  mob->hero.hero_a[14] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad15.bmp");
  mob->hero.hero_a[15] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad16.bmp");
  mob->hero.hero_a[16] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad17.bmp");
  mob->hero.hero_a[17] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad18.bmp");
  mob->hero.hero_a[18] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad19.bmp");
  mob->hero.hero_a[19] = SDL_LoadBMP("sprit/bmp/hero/action/ad/ad20.bmp");

}

void		hero_jump(t_chara *mob)
{
  mob->hero.hero_snd[0] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd01.bmp");
  mob->hero.hero_snd[1] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd02.bmp");
  mob->hero.hero_snd[2] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd03.bmp");
  mob->hero.hero_snd[3] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd04.bmp");
  mob->hero.hero_snd[4] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd05.bmp");
  mob->hero.hero_snd[5] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd06.bmp");
  mob->hero.hero_snd[6] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd07.bmp");
  mob->hero.hero_snd[7] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd08.bmp");
  mob->hero.hero_snd[8] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd09.bmp");
  mob->hero.hero_snd[9] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd10.bmp");
  mob->hero.hero_snd[10] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd11.bmp");
  mob->hero.hero_snd[11] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd12.bmp");
  mob->hero.hero_snd[12] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd13.bmp");
  mob->hero.hero_snd[13] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd14.bmp");
  mob->hero.hero_snd[14] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd15.bmp");
  mob->hero.hero_snd[15] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd16.bmp");
  mob->hero.hero_snd[16] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/snd/snd17.bmp");

  mob->hero.hero_sng[0] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng01.bmp");
  mob->hero.hero_sng[1] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng02.bmp");
  mob->hero.hero_sng[2] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng03.bmp");
  mob->hero.hero_sng[3] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng04.bmp");
  mob->hero.hero_sng[4] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng05.bmp");
  mob->hero.hero_sng[5] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng06.bmp");
  mob->hero.hero_sng[6] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng07.bmp");
  mob->hero.hero_sng[7] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng08.bmp");
  mob->hero.hero_sng[8] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng09.bmp");
  mob->hero.hero_sng[9] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng10.bmp");
  mob->hero.hero_sng[10] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng11.bmp");
  mob->hero.hero_sng[11] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng12.bmp");
  mob->hero.hero_sng[12] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng13.bmp");
  mob->hero.hero_sng[13] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng14.bmp");
  mob->hero.hero_sng[14] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng15.bmp");
  mob->hero.hero_sng[15] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng16.bmp");
  mob->hero.hero_sng[16] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_n/sng/sng17.bmp");

  mob->hero.hero_sad[0] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad01.bmp");
  mob->hero.hero_sad[1] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad02.bmp");
  mob->hero.hero_sad[2] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad03.bmp");
  mob->hero.hero_sad[3] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad04.bmp");
  mob->hero.hero_sad[4] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad05.bmp");
  mob->hero.hero_sad[5] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad06.bmp");
  mob->hero.hero_sad[6] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad07.bmp");
  mob->hero.hero_sad[7] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad08.bmp");
  mob->hero.hero_sad[8] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad09.bmp");
  mob->hero.hero_sad[9] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad10.bmp");
  mob->hero.hero_sad[10] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad11.bmp");
  mob->hero.hero_sad[11] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad12.bmp");
  mob->hero.hero_sad[12] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad13.bmp");
  mob->hero.hero_sad[13] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad14.bmp");
  mob->hero.hero_sad[14] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad15.bmp");
  mob->hero.hero_sad[15] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad16.bmp");
  mob->hero.hero_sad[16] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad17.bmp");
  mob->hero.hero_sad[17] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sad/sad18.bmp");

  mob->hero.hero_sag[0] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag01.bmp");
  mob->hero.hero_sag[1] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag02.bmp");
  mob->hero.hero_sag[2] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag03.bmp");
  mob->hero.hero_sag[3] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag04.bmp");
  mob->hero.hero_sag[4] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag05.bmp");
  mob->hero.hero_sag[5] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag06.bmp");
  mob->hero.hero_sag[6] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag07.bmp");
  mob->hero.hero_sag[7] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag08.bmp");
  mob->hero.hero_sag[8] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag09.bmp");
  mob->hero.hero_sag[9] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag10.bmp");
  mob->hero.hero_sag[10] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag11.bmp");
  mob->hero.hero_sag[11] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag12.bmp");
  mob->hero.hero_sag[12] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag13.bmp");
  mob->hero.hero_sag[13] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag14.bmp");
  mob->hero.hero_sag[14] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag15.bmp");
  mob->hero.hero_sag[15] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag16.bmp");
  mob->hero.hero_sag[16] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag17.bmp");
  mob->hero.hero_sag[17] = SDL_LoadBMP("sprit/bmp/hero/marche/saut/saut_avant/sag/sag18.bmp");
}

void		sprit_hero(t_chara *mob)
{
  hero_pause(mob);
  hero_marche(mob);
  hero_actiond(mob);
  hero_jump(mob);
}
