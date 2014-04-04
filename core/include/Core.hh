//
// Core.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:25:33 2014 chauvo_t
// Last update Fri Apr  4 21:13:05 2014 chauvo_t
//

#ifndef		CORE_H_
# define	CORE_H_

# include <string>
# include <vector>
# include <iostream>
# include <dlfcn.h>
# include "../include/Exception.hh"
# include "../include/Timer.hh"
# include "../../interface/GameBoard.hh"
# include "../../interface/IDisplay.hh"

class Core
{
public:
  void			startGame(int height, int width);
  void			switchLib();
  void			endGame();

public:
  Core(const std::vector<std::string> & libs);
  ~Core() {}

private:
  Core(const Core &);
  Core			&operator=(const Core &);

private:
  GameBoard					_gameBoard;
  void						(Core::*_keyHandlers[IDisplay::KEY_LAST])();
  const std::vector<std::string>		_libs;
  std::vector<std::string>::const_iterator	_libsIt;
  void						*_libHandle;
  IDisplay					*_display;
  Timer						_timer;
  unsigned long					_currentTime;
  unsigned long					_previousTime;
  int						_fps; // unit: frame per second
  int						_snakeSpeed; // unit: 1000 * tile per second
  bool						_exit;
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
  void			closeLib();
  void			gameLoop();
  // To do: void			endGame();

private:			// Snake actions
  void			gameTick();
  void			moveSnake();
  AItem::eType		checkCollision();

private:			// Key handlers
  void			keyNoneHandler() {}
  void			keyUpHandler();
  void			keyDownHandler();
  void			keyLeftHandler();
  void			keyRightHandler();
  void			keySpaceHandler();
  void			keyEscHandler();

private:			// Fruits effects
  void			fruitEffect();
};

#endif /* !CORE_H_ */
