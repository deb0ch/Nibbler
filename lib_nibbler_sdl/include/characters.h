/*
** characters.h for star-voyager in /home/laguet_p/star_pm/characters
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 00:56:20 2014
** Last update Mon Mar 10 00:56:22 2014 
*/

#ifndef CHARACTERS_H_
# define CHARACTERS_H_

#include <SDL/SDL.h>
#include "hero.h"
#include "monster.h"

#define TRUE	1
#define FALSE	0

typedef struct	s_chara
{
  t_hero	hero;
  t_monster	monster;
}		t_chara;

#endif /* !CHARACTERS_H_ */
