//
// openglDisplay.hh for nibbler in /home/max/e-wip/cpp_nibbler
//
// Made by bourge_i
// Login   <max@epitech.net>
//
// Started on  Sat Apr  5 21:20:19 2014 bourge_i
// Last update Sun Apr  6 22:48:16 2014 Maxime Bourgeois
//

#ifndef		OPENGLDISPLAY_H_
# define	OPENGLDISPLAY_H_

# define	BLOCKSIZE 0.05
# define	BLOCKPX 50

# include <iostream>
# include <list>
# include <unistd.h>

# include <GL/gl.h>
# include <GL/glut.h>
# include <GL/freeglut.h>
# include <GL/glu.h>

# include "../../interface/IDisplay.hh"
# include "../../interface/GameBoard.hh"
# include "../../interface/AItem.hh"
# include "../../interface/Fruit.hh"
# include "../../interface/Exception.hh"
# include "../../interface/SnakeRing.hh"

class OpenglDisplay : public IDisplay
{
public:
  virtual void			init(const GameBoard & game);
  virtual int			getFps() const;
  virtual void			update(const GameBoard & game);
  virtual IDisplay::eKey	getKey();
  virtual void			close() const;
  virtual int			getMaxWidth() const;
  virtual int			getMaxHeight() const;

public:
  OpenglDisplay();
  virtual ~OpenglDisplay() {}

private:
  void		displaySnake(const GameBoard & game);
  void		displayFruits(const GameBoard & game);

private:
  OpenglDisplay(const OpenglDisplay &);
  OpenglDisplay &operator=(const OpenglDisplay &);

private:
  IDisplay::eKey	key;

};

#endif /* !OPENGLDISPLAY_H_ */
