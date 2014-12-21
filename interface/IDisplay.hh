//
// IDisplay.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 12:06:04 2014 chauvo_t
// Last update Mon Apr  7 16:01:59 2014 chauvo_t
//

#ifndef		IDISPLAY_H_
# define	IDISPLAY_H_

# include "GameBoard.hh"

class IDisplay
{
public:
  enum	eKey
    {
      NIB_KEY_NONE,
      NIB_KEY_UP,
      NIB_KEY_DOWN,
      NIB_KEY_LEFT,
      NIB_KEY_RIGHT,
      NIB_KEY_DASH,
      NIB_KEY_ESC,
      NIB_KEY_SWITCH,
      NIB_KEY_PAUSE,
      NIB_KEY_HADOKEN,
      NIB_KEY_LAST
    };

  virtual void		init(const GameBoard & game) = 0;
  virtual int		getFps() const = 0;
  virtual int		getMaxWidth() const = 0;
  virtual int		getMaxHeight() const = 0;
  virtual void		update(const GameBoard & game) = 0;
  virtual eKey		getKey() = 0;
  virtual void		close() const  = 0;

public:
  virtual ~IDisplay() {}
};

#endif /* !IDISPLAY_H_ */
