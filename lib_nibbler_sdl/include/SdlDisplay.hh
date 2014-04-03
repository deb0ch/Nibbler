//
// SdlDisplay.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by laguet_p
// Login   <laguet_p@epitech.net>
//
// Started on  Sat Apr  5 19:58:34 2014 laguet_p
// Last update Thu Apr  3 17:35:36 2014 
//

#ifndef		SDL_H_
# define	SDL_H_

# include <iostream>
# include <string>
# include <fstream>
# include <SDL/SDL.h>
# include "../../interface/Exception.hh"
# include "../../interface/IDisplay.hh"

# define NB_PIX_X	50
# define NB_PIX_Y	50
# define COLOR		32
# define MAX_X		32
# define MAX_Y		26

class	SdlDisplay : public IDisplay
{
public:
  SdlDisplay(){}
  virtual ~SdlDisplay(){}

private:
  SDL_Surface		*_screen;
  //  SDL_Surface		*_screenStart;
  SDL_Surface		*_backgroundDisplay;
  SDL_Surface		*_snakeDisplay;
  SDL_Surface		*_snakeHead;
  SDL_Surface		*_snakeBody;
  SDL_Surface		*_snakeEnd;
  int			_snakeBmp;
  int			_leftRigth;
  int			_sens;
  SDL_Rect		_snakePos;
  SDL_Rect		_backgroundPos;

  void			init(const GameBoard & game);
  void			initWindow(const GameBoard & game);
  void			background();
  void			snakePart();
  eKey			getKey();
  void			snakeIterator(const GameBoard & game);
  void			snakeLoad(const GameBoard & game);
  void			update(const GameBoard & game); // refresh full
  void			close() const; // free & return esc
  int			getFps() const;

  SdlDisplay(const SdlDisplay &);
  SdlDisplay &operator=(const SdlDisplay &);
};

#endif /* !SDL_H_ */
