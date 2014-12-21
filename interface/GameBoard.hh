//
// GameBoard.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:15 2014 chauvo_t
// Last update Tue Apr  8 22:01:30 2014 chauvo_t
//

#ifndef		GAMEBOARD_H_
# define	GAMEBOARD_H_

# include <list>
# include "SnakeRing.hh"
# include "Fruit.hh"

class GameBoard
{
public:
  int				width() const;
  int				height() const;
  int				score() const;
  int				snakeSpeed() const;
  void				setWidth(int width);
  void				setHeight(int height);
  void				setScore(int score);
  void				addScore(int score);
  void				setSnakeSpeed(int speed);
  void				addSnakeSpeed(int speed);
  const std::list<SnakeRing*>&	snake() const;
  std::list<SnakeRing*>&	snake();
  const std::list<Fruit*>&	fruits() const;
  std::list<Fruit*>&		fruits();

public:
  GameBoard() {}
  ~GameBoard() {}

private:
  GameBoard(const GameBoard &);
  GameBoard&			operator=(const GameBoard &);

private:
  std::list<SnakeRing*>		_snake;
  std::list<Fruit*>		_fruits;
  int				_width;
  int				_height;
  int				_score;
  int				_snakeSpeed; // unit: 1000 * tile per second
};

#endif /* !GAMEBOARD_H_ */
