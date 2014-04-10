//
// NcursesDisplay.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 20:32:28 2014 chauvo_t
// Last update Fri Apr 11 00:36:54 2014 chauvo_t
//

#ifndef		NCURSESDISPLAY_H_
# define	NCURSESDISPLAY_H_

# include <iostream>
# include <ncurses.h>
# include "../../interface/ASpecialFruit.hh"
# include "../../interface/Exception.hh"
# include "../../interface/IDisplay.hh"

class NcursesDisplay : public IDisplay
{
public:
  virtual void		init(const GameBoard & game);
  virtual int		getFps() const;
  virtual int		getMaxWidth() const;
  virtual int		getMaxHeight() const;
  virtual void		update(const GameBoard & game);
  virtual eKey		getKey();
  virtual void		close() const;

public:
  NcursesDisplay();
  virtual ~NcursesDisplay();

private:
  NcursesDisplay(const NcursesDisplay & other);
  NcursesDisplay&	operator=(const NcursesDisplay & other);

private:
  WINDOW*		_win;
  bool			_hasColors;
  int			_maxHeight;
  int			_maxWidth;

private:
  void			putSnake(const GameBoard & game) const;
  void			putFruits(const GameBoard & game) const;
  void			putBorder() const;
  void			putScore(const GameBoard & game) const;
  void			putBasicFruit(const std::list<Fruit*>::const_iterator fruitIt) const;
  void			putMaxiFruit(const std::list<Fruit*>::const_iterator fruitIt) const;
  void			putSpeedFruit(const std::list<Fruit*>::const_iterator fruitIt) const;
  void			putSlowFruit(const std::list<Fruit*>::const_iterator fruitIt) const;
  void			putReverseFruit(const std::list<Fruit*>::const_iterator fruitIt) const;
};

#endif /* !NCURSESDISPLAY_H_ */
