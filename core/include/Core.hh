//
// Core.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:25:33 2014 chauvo_t
// Last update Sat Apr  5 15:32:14 2014 chauvo_t
//

#ifndef		CORE_H_
# define	CORE_H_

# include <cstdlib>
# include <dlfcn.h>
# include <iostream>
# include <string>
# include <time.h>
# include <vector>
# include "../include/FruitFactory.hh"
# include "../include/Timer.hh"
# include "../../interface/Exception.hh"
# include "../../interface/GameBoard.hh"
# include "../../interface/IDisplay.hh"

# define SNAKE_INIT_SIZE	4

class	Core
{
public:
  void			startGame(const std::vector<std::string> & libs, int width, int height);

public:
  Core();
  ~Core() {}

private:
  Core(const Core &);
  Core			&operator=(const Core &);

private:
  GameBoard					_gameBoard;
  void						(Core::*_keyHandlers[IDisplay::KEY_LAST])();
  std::vector<std::string>			_libs;
  std::vector<std::string>::const_iterator	_libsIt;
  void						*_libHandle;
  IDisplay					*_display;
  Timer						_timer;
  unsigned long					_currentTime;
  unsigned long					_previousTime;
  int						_fps; // unit: frame per second
  int						_snakeSpeed; // unit: 1000 * tile per second
  bool						_gameOver;
  typedef enum
    {
      UP,
      DOWN,
      RIGHT,
      LEFT
    } direction;
  direction					_snakeDir;

private:			// Main private functions
  void			openLib();
  void			switchLib(); // To do
  void			closeLib();
  void			initGame(const std::vector<std::string> & libs, int width, int height);
  void			initGameBoard(int width, int height); // To do
  void			gameLoop();
  void			endGame(); // To do

private:			// Utils
  int			rangeRand(int from, int to);

private:			// Game actions
  void			moveSnake(); // To do
  AItem::eType		checkCollision(int posx, int posy);
  void			spawnBasicFruit();
  void			spawnSpecialFruit(); // To do

private:			// Key handlers
  void			keyNoneHandler() {}
  void			keyUpHandler();
  void			keyDownHandler();
  void			keyLeftHandler();
  void			keyRightHandler();
  void			keySpaceHandler();
  void			keyEscHandler();

private:			// Fruits effects
  void			fruitEffect(); // To do
};

#endif /* !CORE_H_ */
