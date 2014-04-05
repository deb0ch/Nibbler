//
// IDisplay.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 12:06:04 2014 chauvo_t
// Last update Sat Apr  5 11:28:26 2014 chauvo_t
//

#ifndef		IDISPLAY_H_
# define	IDISPLAY_H_

# include "GameBoard.hh"

class IDisplay
{
public:
  typedef enum
    {
      KEY_NONE,
      KEY_UP,
      KEY_DOWN,
      KEY_LEFT,
      KEY_RIGHT,
      KEY_SPACE,
      KEY_ESC,
      KEY_LAST
    }		eKey;

  virtual void		init(const GameBoard & game) = 0;
  virtual int		getFps() const;
  virtual void		update(const GameBoard & game) = 0;
  virtual eKey		getKey() = 0;
  virtual void		close() const  = 0;
};

#endif /* !IDISPLAY_H_ */
