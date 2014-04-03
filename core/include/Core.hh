//
// Core.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:25:33 2014 chauvo_t
// Last update Thu Apr  3 16:27:09 2014 chauvo_t
//

#ifndef		CORE_H_
# define	CORE_H_

# include <string>
# include <vector>
# include "../include/Exception.hh"
# include "../include/Timer.hh"
# include "../../interface/GameBoard.hh"

class Core
{
public:
  void			startGame(int height, int width, const std::vector<std::string> & libs);

public:
  Core();
  ~Core();

private:
  Core(const Core &);
  Core &operator=(const Core &);

private:
  Timer			_timer;
  GameBoard		_game;

private:
  void			openLib();
  void			gameLoop();
  void			closeLib();
};

#endif /* !CORE_H_ */
