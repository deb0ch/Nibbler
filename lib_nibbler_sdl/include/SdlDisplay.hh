#ifndef		SDL_H_
# define	SDL_H_

# include <iostream>
# include <string>
# include <fstream>
# include <SDL/SDL.h>
# include "../../interface/Exception.hh"
# include "../../interface/IDisplay.hh"

#define NB_PIX_X	50
#define NB_PIX_Y	50
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
  SDL_Rect		_snakePos;

  void			init(const GameBoard & game);
  void			initWindow(const GameBoard & game);
  void			background();
  void			snakePart();
  eKey			getKey() const;
  void			snakeIterator(const GameBoard & game);
  void			update(const GameBoard & game); // refresh full
  void			refreshBg();
  void			refreshSnake();
  void			close() const; // free & return esc
  int			setFps() const;

  SdlDisplay(const SdlDisplay &);
  SdlDisplay &operator=(const SdlDisplay &);
protected:

};

#endif /* !SDL_H_ */
