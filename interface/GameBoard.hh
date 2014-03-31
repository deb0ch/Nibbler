//
// GameBoard.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:15 2014 chauvo_t
// Last update Wed Apr  2 17:30:14 2014 chauvo_t
//

#ifndef		GAMEBOARD_H_
# define	GAMEBOARD_H_

# include <list>
# include "Fruit.hh"
# include "Snake.hh"

class GameBoard
{
public:
  GameBoard(int width, int height);
  int	getWidth() const;
  int	getHeight() const;
  virtual ~GameBoard();

private:
  GameBoard(const GameBoard &);
  GameBoard &operator=(const GameBoard &);

private:
  Snake			snake;
  std::list<Fruit>	fruits;
  int			width;
  int			height;
};

#endif /* !GAMEBOARD_H_ */
