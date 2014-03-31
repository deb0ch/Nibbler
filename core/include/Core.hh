//
// Core.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:25:33 2014 chauvo_t
// Last update Wed Apr  2 17:37:20 2014 chauvo_t
//

#ifndef		CORE_H_
# define	CORE_H_

# include <string>
# include "../../interface/GameBoard.hh"

class Core
{
public:
  Core(std::string lib_path, int width, int height);
  void	openLib();
  void	gameLoop();
  void	closeLib();
  virtual ~Core();

private:
  Core(const Core &);
  Core &operator=(const Core &);

private:
  GameBoard	game;
};

#endif /* !CORE_H_ */
