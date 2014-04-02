//
// Game.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:15 2014 chauvo_t
// Last update Wed Apr  2 14:16:22 2014 chauvo_t
//

#ifndef		GAME_H_
# define	GAME_H_

class Game
{
public:
  Game(int width, int height);
  virtual ~Game();

private:
  Game(const Game &);
  Game &operator=(const Game &);
protected:

};

#endif /* !GAME_H_ */
