//
// NcursesDisplay.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 20:32:28 2014 chauvo_t
// Last update Sun Apr  6 14:34:13 2014 chauvo_t
//

#ifndef		NCURSESDISPLAY_H_
# define	NCURSESDISPLAY_H_

# include <iostream>
# include <ncurses.h>
# include "../../interface/Exception.hh"
# include "../../interface/IDisplay.hh"

class NcursesDisplay : public IDisplay
{
public:
  virtual void		init(const GameBoard & game);
  virtual int		getFps() const;
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
  bool			_hasColors;
};

#endif /* !NCURSESDISPLAY_H_ */
