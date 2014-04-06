//
// NcursesDisplay.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 20:32:28 2014 chauvo_t
// Last update Sat Apr  5 22:56:39 2014 chauvo_t
//

#ifndef		NCURSESDISPLAY_H_
# define	NCURSESDISPLAY_H_

# include <ncurses.h>
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
  virtual ~NcursesDisplay() {}

private:
  NcursesDisplay(const NcursesDisplay & other);
  NcursesDisplay&	operator=(const NcursesDisplay & other);

private:

};

#endif /* !NCURSESDISPLAY_H_ */
