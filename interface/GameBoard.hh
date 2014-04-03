//
// GameBoard.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:15 2014 chauvo_t
// Last update Thu Apr  3 17:34:26 2014 chauvo_t
//

#ifndef		GAMEBOARD_H_
# define	GAMEBOARD_H_

# include <list>
# include "Fruit.hh"
# include "Snake.hh"

class GameBoard
{
public:
  int			width() const;
  int			height() const;
  void			setWidth(int width);
  void			setHeight(int height);
  Snake			&snake();
  std::list<Fruit>	&fruits();

public:
  GameBoard();
  ~GameBoard();

private:
  GameBoard(const GameBoard &);
  GameBoard &operator=(const GameBoard &);

private:
  Snake			_snake;
  std::list<Fruit>	_fruits;
  int			_width;
  int			_height;
};

#endif /* !GAMEBOARD_H_ */
