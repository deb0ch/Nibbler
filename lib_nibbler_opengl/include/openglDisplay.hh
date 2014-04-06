//
// openglDisplay.hh for nibbler in /home/max/e-wip/cpp_nibbler
//
// Made by bourge_i
// Login   <max@epitech.net>
//
// Started on  Sat Apr  5 21:20:19 2014 bourge_i
// Last update Sun Apr  6 13:38:02 2014 bourge_i
//

#ifndef		OPENGLDISPLAY_H_
# define	OPENGLDISPLAY_H_

# define	BLOCKSIZE 0.05

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

public:
  OpenglDisplay();
  virtual ~OpenglDisplay() {}

private:
  // void	display();
  // void	square(double x, double y, double offsetX, double offsetY,
  // 	       int r, int v, int b); // todo creer structure
  // void	manageKeyboard(unsigned char key, int x, int y);
  // void	manageDirection(int key, int x, int y);
  // void	timerCallback(int value);

private:
  OpenglDisplay(const OpenglDisplay &);
  OpenglDisplay &operator=(const OpenglDisplay &);

public:
  double		myoffX;
  double		myoffY;
  int			direction;
  IDisplay::eKey	key;

};

#endif /* !OPENGLDISPLAY_H_ */
