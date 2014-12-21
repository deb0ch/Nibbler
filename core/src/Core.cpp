//
// Core.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 14:18:37 2014 chauvo_t
// Last updateThu Apr  3 16:35:36 2014
//

#include "../include/Core.hh"

// Public

void	Core::startGame(int width, int height)
{
  this->initGame(width, height);
  this->gameLoop();
  this->endGame();
}

Core::Core(const std::vector<std::string> & libs)
  : _display(libs)
{
  _keyHandlers[IDisplay::NIB_KEY_NONE] = &Core::keyNoneHandler;
  _keyHandlers[IDisplay::NIB_KEY_UP] = &Core::keyUpHandler;
  _keyHandlers[IDisplay::NIB_KEY_DOWN] = &Core::keyDownHandler;
  _keyHandlers[IDisplay::NIB_KEY_LEFT] = &Core::keyLeftHandler;
  _keyHandlers[IDisplay::NIB_KEY_RIGHT] = &Core::keyRightHandler;
  _keyHandlers[IDisplay::NIB_KEY_DASH] = &Core::keyDashHandler;
  _keyHandlers[IDisplay::NIB_KEY_SWITCH] = &Core::keySwitchHandler;
  _keyHandlers[IDisplay::NIB_KEY_PAUSE] = &Core::keyPauseHandler;
  _keyHandlers[IDisplay::NIB_KEY_ESC] = &Core::keyEscHandler;
  _collisionEffects[AItem::NONE] = &Core::noneEffect;
  _collisionEffects[AItem::WALL] = &Core::wallEffect;
  _collisionEffects[AItem::BORDER] = &Core::borderEffect;
  _collisionEffects[AItem::SNAKE] = &Core::snakeEffect;
  _collisionEffects[AItem::BASIC_FRUIT] = &Core::basicFruitEffect;
  _collisionEffects[AItem::MAXI_FRUIT] = &Core::maxiFruitEffect;
  _collisionEffects[AItem::SPEED_FRUIT] = &Core::speedFruitEffect;
  _collisionEffects[AItem::SLOW_FRUIT] = &Core::slowFruitEffect;
  _collisionEffects[AItem::REVERSE_FRUIT] = &Core::reverseFruitEffect;
  _gameOver = false;
}

// Private

void	Core::initGame(int width, int height)
{
  this->initGameBoard(width, height);
  _display.openLib(_gameBoard);
  _fps = _display.getDisplay()->getFps();
  _gameBoard.setSnakeSpeed(SNAKE_INIT_SPEED);
  _growthCounter = 0;
  _snakeDir = SnakeRing::RIGHT;
}

void	Core::initGameBoard(int width, int height)
{
  int	i;

  _gameBoard.setHeight(height);
  _gameBoard.setWidth(width);
  for (i = 0; i < SNAKE_INIT_SIZE; ++i)
    _gameBoard.snake().push_front(new SnakeRing(SnakeRing::RIGHT,
						(_gameBoard.width() / 2 - SNAKE_INIT_SIZE / 2)
					       + i,
					       _gameBoard.height() / 2));
  this->spawnBasicFruit();
  _gameBoard.setScore(0);
}

void	Core::gameLoop()
{
  unsigned long	currentTime;
  unsigned long	prevFpsTime;
  unsigned long	prevSnkTime;

  currentTime = _timer.getMilliTime();
  prevFpsTime = _timer.getMilliTime();
  prevSnkTime = _timer.getMilliTime();
  _gameOver = false;
  while (_gameOver == false)
    {
      currentTime = _timer.getMilliTime();
      if (currentTime - prevSnkTime >= 1000.0 / (_gameBoard.snakeSpeed() / 1000.0))
	{
	  (this->*_keyHandlers[_display.getDisplay()->getKey()])();
	  this->moveSnake();
	  if (_randomizer.probaRand(1.0 / 30.0))
	    this->spawnSpecialFruit();
	  this->tickFruits();
	  prevSnkTime = currentTime;
	}
      if (currentTime - prevFpsTime >= 1000.0 / _fps)
	{
	  _display.getDisplay()->update(_gameBoard);
	  prevFpsTime = currentTime;
	}
      else
	_timer.milliSleep((1000.0 / _fps) - (currentTime - prevFpsTime));
    }
}

void	Core::endGame()
{
  std::list<Fruit*>::iterator		fruitIt;

  _timer.milliSleep(1000);
  while (!_gameBoard.snake().empty())
    {
      delete _gameBoard.snake().back();
      _gameBoard.snake().pop_back();
      _display.getDisplay()->update(_gameBoard);
      _timer.milliSleep(1000.0 / (_gameBoard.snakeSpeed() / 1000.0));
    }
  for (fruitIt = _gameBoard.fruits().begin(); fruitIt != _gameBoard.fruits().end(); ++fruitIt)
    delete *fruitIt;
  this->keyPauseHandler();
  _display.closeLib();
}

// Game actions

void		Core::moveSnake()
{
  std::list<Fruit*>::iterator	fruitIt;
  AItem::eType			collisionPosType;
  int				newPosx;
  int				newPosy;
  int				collisionPosx;
  int				collisionPosy;

  collisionPosx = _gameBoard.snake().front()->posx();
  collisionPosy = _gameBoard.snake().front()->posy();
  collisionPosx += (_snakeDir == SnakeRing::RIGHT) - (_snakeDir == SnakeRing::LEFT);
  collisionPosy += (_snakeDir == SnakeRing::DOWN) - (_snakeDir == SnakeRing::UP);
  collisionPosType = checkCollision(collisionPosx, collisionPosy);
  (this->*_collisionEffects[collisionPosType])();
  if (_gameOver)
    return ;
  newPosx = _gameBoard.snake().front()->posx();
  newPosy = _gameBoard.snake().front()->posy();
  newPosx += (_snakeDir == SnakeRing::RIGHT) - (_snakeDir == SnakeRing::LEFT);
  newPosy += (_snakeDir == SnakeRing::DOWN) - (_snakeDir == SnakeRing::UP);
  _gameBoard.snake().push_front(new SnakeRing(_snakeDir, newPosx, newPosy));
  if (_growthCounter == 0)
    {
      delete _gameBoard.snake().back();
      _gameBoard.snake().pop_back();
    }
  else
    _growthCounter -= 1;
  if (collisionPosType != AItem::NONE)
    {
      for (fruitIt = _gameBoard.fruits().begin();
	   fruitIt != _gameBoard.fruits().end();
	   ++fruitIt)
	{
	  if ((*fruitIt)->posx() == collisionPosx && (*fruitIt)->posy() == collisionPosy)
	    {
	      _gameBoard.fruits().erase(fruitIt);
	      break ;
	    }
	}
      if (collisionPosType == AItem::BASIC_FRUIT)
	this->spawnBasicFruit();
    }
}

AItem::eType	Core::checkCollision(int posx, int posy)
{
  std::list<SnakeRing*>::iterator	snakeIt;
  std::list<Fruit*>::iterator		fruitIt;

  if (posx < 0 || posx >= _gameBoard.width()
      || posy < 0 || posy >= _gameBoard.height())
    return (AItem::BORDER);
  for (snakeIt = _gameBoard.snake().begin();
       snakeIt != _gameBoard.snake().end();
       ++snakeIt)
    {
      if ((*snakeIt)->posx() == posx && (*snakeIt)->posy() == posy)
	return (AItem::SNAKE);
    }
  for (fruitIt = _gameBoard.fruits().begin();
       fruitIt != _gameBoard.fruits().end();
       ++fruitIt)
    {
      if ((*fruitIt)->posx() == posx && (*fruitIt)->posy() == posy)
	return ((*fruitIt)->type());
    }
  return (AItem::NONE);
}

void	Core::spawnPos(int* posx, int* posy)
{
  *posx = _randomizer.rangeRand(0, _gameBoard.width());
  *posy = _randomizer.rangeRand(0, _gameBoard.height());
  while (checkCollision(*posx, *posy) != AItem::NONE)
    {
      *posx = _randomizer.rangeRand(0, _gameBoard.width());
      *posy = _randomizer.rangeRand(0, _gameBoard.height());
    }
}

void	Core::spawnBasicFruit()
{
  int	posx;
  int	posy;

  if (_gameBoard.fruits().size() // Check if there is enough space for our fruit
      >= _gameBoard.width() * _gameBoard.height() - _gameBoard.snake().size())
    return ;
  this->spawnPos(&posx, &posy);
  _gameBoard.fruits().push_front(_factory.createFruit(AItem::BASIC_FRUIT, posx, posy));
}

void	Core::spawnSpecialFruit()
{
  int	posx;
  int	posy;

  if (_gameBoard.fruits().size() // Check if there is enough space for our fruit
      >= _gameBoard.width() * _gameBoard.height() - _gameBoard.snake().size())
    return ;
  this->spawnPos(&posx, &posy);
  _gameBoard.fruits().push_front(_factory.createRandomFruit(posx, posy));
}

void	Core::tickFruits()
{
  std::list<Fruit*>::iterator	fruitIt;

  for (fruitIt = _gameBoard.fruits().begin();
       fruitIt != _gameBoard.fruits().end(); ++fruitIt)
    {
      if (dynamic_cast<ASpecialFruit*>(*fruitIt) != NULL)
	{
	  if (dynamic_cast<ASpecialFruit*>(*fruitIt)->getTimer() == 0)
	    fruitIt = _gameBoard.fruits().erase(fruitIt);
	  else
	    dynamic_cast<ASpecialFruit*>(*fruitIt)->tick();
	}
    }
}

// Key handlers

void	Core::keyUpHandler()
{}

void	Core::keyDownHandler()
{}

void	Core::keyLeftHandler()
{
  _snakeDir = static_cast<SnakeRing::eDirection>
    (_snakeDir != 0 ? (_snakeDir - 1) : SnakeRing::LEFT);
}

void	Core::keyRightHandler()
{
  _snakeDir = static_cast<SnakeRing::eDirection>((_snakeDir + 1) % 4);
}

void	Core::keyDashHandler()
{
  // To do
}

void	Core::keyEscHandler()
{
  _gameOver = true;
}

void	Core::keySwitchHandler()
{
  _display.switchLib(_gameBoard);
}

void	Core::keyPauseHandler()
{
  IDisplay::eKey	key;

  while ((key = _display.getDisplay()->getKey()) != IDisplay::NIB_KEY_PAUSE)
    {
      if (key == IDisplay::NIB_KEY_ESC)
	{
	  _gameOver = true;
	  break ;
	}
      _timer.milliSleep(1000.0 / _fps);
    }
}

void	Core::keyHadokenHandler()
{
  // To do
}

// Fruits effects

void	Core::wallEffect()
{
  _gameOver = true;
}

void	Core::borderEffect()
{
  _gameOver = true;
}

void	Core::snakeEffect()
{
  _gameOver = true;
}

void	Core::basicFruitEffect()
{
  _growthCounter += 1;
  _gameBoard.addScore(10);
  _gameBoard.addSnakeSpeed(100);
}

void	Core::maxiFruitEffect()
{
  _growthCounter += 3;
  _gameBoard.addScore(50);
  _gameBoard.addSnakeSpeed(250);
}

void	Core::speedFruitEffect()
{
  _gameBoard.addSnakeSpeed(1500);
}

void	Core::slowFruitEffect()
{
  if (_gameBoard.snakeSpeed() - 1500 > SNAKE_MIN_SPEED)
    _gameBoard.addSnakeSpeed(-1500);
  else
    _gameBoard.setSnakeSpeed(SNAKE_MIN_SPEED);
}

void	Core::reverseFruitEffect()
{
  std::list<SnakeRing*>::iterator	snakeIt;

  _gameBoard.snake().reverse();
  for (snakeIt = _gameBoard.snake().begin();
       snakeIt != _gameBoard.snake().end();
       ++snakeIt)
    {
      (*snakeIt)->setDirection(static_cast<SnakeRing::eDirection>
			       (((*snakeIt)->direction() + 2) % 4));
    }
  _snakeDir = _gameBoard.snake().front()->direction();
  _gameBoard.addScore(75);
}
