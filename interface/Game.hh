x//
// Game.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:15 2014 chauvo_t
// Last update Wed Apr  2 15:49:25 2014 bourge_i
//

#ifndef		GAME_H_
# define	GAME_H_

# include <list>
# include "Fruit.hh"
# include "Snake.hh"

class Game
{
public:
  Game(int width, int height);
  int	getWidth() const;
  int	getHeight() const;
  virtual ~Game();

private:
  Game(const Game &);
  Game &operator=(const Game &);

private:
  Snake			snake;
  std::list<Fruit>	fruits;
  int			width;
  int			height;

#endif /* !GAME_H_ */
