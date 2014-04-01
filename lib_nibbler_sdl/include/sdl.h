/*
** sdl.h for Star Voyager in /home/laguet_p/star_pm/sdl
**
** Made by
** Login   <laguet_p@epitech.net>
**
** Started on  Mon Mar 10 03:57:49 2014
** Last update Mon Mar 31 11:09:32 2014 
*/

#ifndef		SDL_H_
# define	SDL_H_

#include <SDL/SDL.h>
#include "../characters/characters.h"
#include "../deco/deco.h"

#define BLOCK	40
#define X	40
#define	Y	21
#define	COLOR	32
#define INTERX	1520
#define INTERY	15

typedef struct	s_window
{
  SDL_Surface	*screen;
  SDL_Surface  	*fond;
  SDL_Surface	*first_plan;
  int		start;
  int		abscisse;
  int		ordone;
}		t_window;


/*		/sdl/			*/
// collision.c
void		sol_ship(t_chara *);
void		gravity(t_chara *, t_window *);
void		collision(t_chara *, t_deco *);

// display.c
int		refresh(t_chara *, t_window *, t_deco *, int);
int		timer_pause(t_chara *, int);
void		pause(t_chara *, t_window *);
void		load_sdl();

// init.c
t_deco		*init_door01(t_deco *);
t_chara		*init_mob(t_chara *);

// free.c
void		free_all(t_window, t_chara *);
void		free_hero(t_chara *);
void		free_door01(t_deco *);


/*		/sdl/creat_plan/	*/
// creat_plan.c
void		creat_fond(t_chara *, t_window *);
void		creat_first_plan(t_window *);
void		start_hero(t_chara *, t_window *);

// creat_second_plan.c
void		display_door_fixe(t_deco *, t_window *);
int		interaction_door(t_deco *, t_window *, int);
void		interaction_icone(t_deco *, t_window *);
int		creat_second_plan(t_deco */*, t_chara **/, t_window *, int);


/*		sprit/load_sprit/	*/
// sprit_hero.c
void		sprit_hero(t_chara *);
void		hero_pause(t_chara *);
void		hero_marche(t_chara *);
void		hero_jump(t_chara *);

// sprit_hero_gun.c
void		sprit_hero_gun(t_chara *);
void		hero_gun_out(t_chara *);
void		hero_gun_marche(t_chara *);
void		hero_gun_transition(t_chara *);
void		gun_shoot_pos(t_chara *);

// sprit_deco.c
void		sprit_deco(t_deco *);


/*		/event/			*/
// basic_mode.c
int		basic_hero_move(SDLKey event, t_chara *, t_window *, int, t_deco *);
int		hero_action(t_chara *, t_window *, int, t_deco *);
int		hero_left(t_chara *, t_window *, int);
int		hero_right(t_chara *, t_window *, int);
void		hero_stand_by(t_chara *, t_window *);
int		basic_mode(SDLKey event, t_chara *, t_window *,t_deco *, int);
// hero_jump.c
int		display_jump(t_chara *, t_window *, int);
int		jump_up(t_chara *, t_window *,t_deco *, int);
int		jump_gauche(t_chara *, t_window *,t_deco *, int);
int		jump_droite(t_chara *, t_window *,t_deco *, int);
int		jump_filter(SDLKey event, t_chara *, t_window *,t_deco *, int);

/*		/event/gun_mode/	*/
// gun_mode.c
int		hero_gun_left(t_chara *, t_window *, int);
int		hero_gun_right(t_chara *, t_window *, int);
int		gun_hero_move(SDLKey event, t_chara *, t_window *, int);
int		gun_mode(SDLKey event, t_chara *, t_window *,t_deco *, int);

// launch_gun.c
int		display_start_close(t_chara *, t_window *, int);
int		gun_start(t_chara *, t_window *, t_deco *, int);
int		gun_close(t_chara *, t_window *, t_deco *, int);
int		gun_filter(t_chara *, t_window *,t_deco *, int);


/*		/deco/			*/
// creat_deco.c //
void		open_door(t_deco *, t_chara *, t_window *);

#endif /* !SDL_H_ */
