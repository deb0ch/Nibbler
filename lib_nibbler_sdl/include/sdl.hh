#ifndef		SDL_H_
# define	SDL_H_

#include <iostream>
#include <string>
#include <fstream>
#include <SDL/SDL.h>>

class sdl
{
public:
  sdl();
  virtual ~sdl();

private:
  void		sdl_init(); // malloc & load bmp
  void		sdl_main_loop();
  void		sdl_refresh(); // refresh full
  void		sdl_background();
  void		sdl_snake();
  void		sdl_close(); // free & return esc

  sdl(const sdl &);
  sdl &operator=(const sdl &);
protected:

};

#endif /* !SDL_H_ */
