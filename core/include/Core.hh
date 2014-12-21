//
// Core.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:25:33 2014 chauvo_t
// Last update Fri Apr 11 22:39:39 2014 chauvo_t
//

#ifndef		CORE_H_
# define	CORE_H_

# include <cstdlib>
# include <iostream>
# include <string>
# include <time.h>
# include <vector>
# include "../include/FruitFactory.hh"
# include "../include/Randomizer.hh"
# include "../include/Timer.hh"
# include "../include/DlLoader.hh"
# include "../../interface/Exception.hh"
# include "../../interface/GameBoard.hh"
# include "../../interface/IDisplay.hh"

# define SNAKE_INIT_SIZE 4

class	Core
{
public:
  void			startGame(int width, int height);

public:
  Core(const std::vector<std::string> & libs);

public:
  ~Core() {}

private:
  Core();
  Core(const Core &);
  Core			&operator=(const Core &);

private:
  FruitFactory					_factory;
  Randomizer					_randomizer;
  GameBoard					_gameBoard;
  DlLoader					_display;
  void						(Core::*_keyHandlers[IDisplay::NIB_KEY_LAST])();
  void						(Core::*_collisionEffects[AItem::TYPE_LAST])();
  Timer						_timer;
  int						_fps; // unit: frame per second
  int						_snakeSpeed; // unit: 1000 * tile per second
  bool						_gameOver;
  SnakeRing::eDirection				_snakeDir;
  unsigned int					_growthCounter;

private:			// Main private functions
  void			initGame(int width, int height);
  void			initGameBoard(int width, int height);
  void			gameLoop();
  void			endGame();

private:			// Game actions
  void			moveSnake();
  AItem::eType		checkCollision(int posx, int posy);
  void			spawnPos(int* posx, int* posy);
  void			spawnBasicFruit();
  void			spawnSpecialFruit();
  void			tickFruits();

private:			// Key handlers
  void			keyNoneHandler() {}
  void			keyUpHandler();
  void			keyDownHandler();
  void			keyLeftHandler();
  void			keyRightHandler();
  void			keyDashHandler();
  void			keyEscHandler();
  void			keySwitchHandler();
  void			keyPauseHandler();
  void			keyHadokenHandler();

private:			// Collision effects
  void			noneEffect() {}
  void			wallEffect();
  void			borderEffect();
  void			snakeEffect();
  void			basicFruitEffect();
  void			maxiFruitEffect();
  void			speedFruitEffect();
  void			slowFruitEffect();
  void			reverseFruitEffect();
};

#endif /* !CORE_H_ */
