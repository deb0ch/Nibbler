//
// IDisplay.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 12:06:04 2014 chauvo_t
// Last update Thu Apr  3 17:32:43 2014 bourge_i
//

#ifndef		IDISPLAY_H_
# define	IDISPLAY_H_

# include "./Game.hh"
# include "GameBoard.hh"

class IDisplay
{
public:
  typedef enum
    {
      KEY_NONE,
      KEY_UP,
      KEY_DOWN,
      KEY_RIGHT,
      KEY_LEFT,
      KEY_ESC,
      KEY_LAST
    }		eKey;

  void		init(const GameBoard & game);
  void		update(const GameBoard & game);
  eKey		getKey();
  void		close();
};

#endif /* !IDISPLAY_H_ */
