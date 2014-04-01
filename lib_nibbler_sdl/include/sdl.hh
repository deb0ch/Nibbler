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
  void		init(); // malloc & load bmp
  void		main_loop();
  void		update(); // refresh full
  void		background();
  void		snake();
  void		close(); // free & return esc

  sdl(const sdl &);
  sdl &operator=(const sdl &);
protected:

};

#endif /* !SDL_H_ */
