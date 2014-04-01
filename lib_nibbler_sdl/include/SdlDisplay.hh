#ifndef		SDL_H_
# define	SDL_H_

# include <iostream>
# include <string>
# include <fstream>
# include <SDL/SDL.h>>
# include "../../interface/Exception.hh"
# include "../../interface/IDisplay.hh"

#define NB_PIX_X	20
#define NB_PIX_X	20
#define COLOR		32

class	SdlDisplay : public IDisplay
{
public:
  SdlDisplay();
  virtual ~SdlDisplay();

private:
  SDL_Surface		*_screen;
  //  SDL_Surface		*_screenStart;
  SDL_Surface		*_backgroundDisplay;
  SDL_Surface		*_snakeDisplay;

  void			init(const GameBoard & game);
  void			initWindow(const GameBoard & game);
  void			background(const GameBoard & game);
  void			snake(const GameBoard & game);
  void			getKey() const;
  void			update(const GameBoard & game); // refresh full
  void			refreshBg();
  void			refreshSnake();
  void			close() const; // free & return esc

  SdlDisplay(const SdlDisplay &);
  SdlDisplay &operator=(const SdlDisplay &);
protected:

};

#endif /* !SDL_H_ */
