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

void	Core::startGame(const std::vector<std::string> & libs, int width, int height)
{
  this->initGame(libs, width, height);
  this->gameLoop();
  this->endGame();
}

Core::Core()
{
  _keyHandlers[IDisplay::NIB_KEY_NONE] = &Core::keyNoneHandler;
  _keyHandlers[IDisplay::NIB_KEY_UP] = &Core::keyUpHandler;
  _keyHandlers[IDisplay::NIB_KEY_DOWN] = &Core::keyDownHandler;
  _keyHandlers[IDisplay::NIB_KEY_LEFT] = &Core::keyLeftHandler;
  _keyHandlers[IDisplay::NIB_KEY_RIGHT] = &Core::keyRightHandler;
  _keyHandlers[IDisplay::NIB_KEY_SPACE] = &Core::keySpaceHandler;
  _keyHandlers[IDisplay::NIB_KEY_ESC] = &Core::keyEscHandler;
  _libHandle = NULL;
  _display = NULL;
  _currentTime = _timer.getMilliTime();
  _previousTime = _timer.getMilliTime();
  _snakeSpeed = 2000;
  _gameOver = false;
  srand(time(NULL));
}

// Private

void	Core::openLib()
{
  IDisplay*	(*createDisplay)();
  char	*error;

  _libHandle = dlopen((*(_libsIt)).c_str(), RTLD_LAZY);
  if (_libHandle == NULL)
    throw Exception("dlopen error: " + std::string(dlerror()));
  dlerror();
  createDisplay = reinterpret_cast<IDisplay* (*)()>(dlsym(_libHandle,
							  "createDisplay"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading library entry point: " + std::string(error));
  _display = createDisplay();
}

void	Core::switchLib()	// To do
{

}

void	Core::closeLib()
{
  _display->close();
  delete _display;
  _display = NULL;
  dlclose(_libHandle);
  _libHandle = NULL;
}

void	Core::initGame(const std::vector<std::string> & libs, int width, int height)
{
  _libs = libs;
  _libsIt = _libs.begin();
  this->openLib();
  _fps = _display->getFps();
  this->initGameBoard(width, height);
  _display->init(_gameBoard);
}

void	Core::initGameBoard(int width, int height)
{
  int	i;

  _gameBoard.setHeight(height);
  _gameBoard.setWidth(width);
  for (i = 0; i < SNAKE_INIT_SIZE; ++i)
    _gameBoard.snake().push_back(new SnakeRing((_gameBoard.width() / 2 - SNAKE_INIT_SIZE / 2)
					       + i,
					       _gameBoard.height() / 2));
  this->spawnBasicFruit();
}

void			Core::gameLoop()
{
  IDisplay::eKey	key;

  _gameOver = false;
  key = IDisplay::NIB_KEY_NONE;
  while (_gameOver == false)
    {
      _currentTime = _timer.getMilliTime();
      if (_currentTime - _previousTime > 1000.0 / (_snakeSpeed / 1000.0))
	{
	  key = _display->getKey();
	  (this->*_keyHandlers[key])();
	  this->moveSnake();
	  _previousTime = _currentTime;
	  _display->update(_gameBoard);
	}
      else
	_timer.milliSleep(1000.0 / (_snakeSpeed / 1000.0) - (_currentTime - _previousTime));
     // std::cout << "Diff: " << (_currentTime - _previousTime) << std::endl;
     // std::cout << "fps: " << ((1.0 / _fps) * 1000.0) << std::endl;
     // std::cout << "Calcul: " << ((1.0 / _fps) * 1000.0) - (_currentTime - _previousTime) << std::endl;
    }
}

void	Core::endGame()
{
  std::list<SnakeRing*>::iterator	snakeIt;
  std::list<Fruit*>::iterator		fruitIt;

  for (fruitIt = _gameBoard.fruits().begin(); fruitIt != _gameBoard.fruits().end(); ++fruitIt)
    delete *fruitIt;
  for (snakeIt = _gameBoard.snake().begin(); snakeIt != _gameBoard.snake().end(); ++snakeIt)
    delete *snakeIt;
  this->closeLib();
}

// Utils

int	Core::rangeRand(int from, int to)
{
  if (from >= to)
    return (0);
  return (rand() % (to - from + 1) + from);
}

// Game actions

void		Core::moveSnake()
{
  std::list<Fruit*>::iterator	fruitIt;
  AItem::eType			newPosType;
  int				newPosx;
  int				newPosy;

  newPosx = _gameBoard.snake().front()->posx();
  newPosy = _gameBoard.snake().front()->posy();
  newPosx += (_snakeDir == RIGHT) - (_snakeDir == LEFT);
  newPosy += (_snakeDir == DOWN) - (_snakeDir == UP);
  newPosType = checkCollision(newPosx, newPosy);
  if (newPosType == AItem::WALL || newPosType == AItem::SNAKE)
    {
      _gameOver = true;
      return ;
    }
  _gameBoard.snake().push_front(new SnakeRing(newPosx, newPosy));
  if (newPosType == AItem::NONE)
    {
      delete _gameBoard.snake().back();
      _gameBoard.snake().pop_back();
    }
  if (newPosType == AItem::FRUIT)
    {
      for (fruitIt = _gameBoard.fruits().begin();
	   fruitIt != _gameBoard.fruits().end();
	   ++fruitIt)
	{
	  if ((*fruitIt)->posx() == newPosx && (*fruitIt)->posy() == newPosy)
	    {
	      _gameBoard.fruits().erase(fruitIt);
	      break ;
	    }
	}
      this->spawnBasicFruit();
    }
}

AItem::eType	Core::checkCollision(int posx, int posy)
{
  std::list<SnakeRing*>::iterator	snakeIt;
  std::list<Fruit*>::iterator		fruitIt;

  if (posx < 0 || posx > _gameBoard.width()
      || posy < 0 || posy > _gameBoard.height())
    return (AItem::WALL);
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
	return (AItem::FRUIT);
    }
  return (AItem::NONE);
}

void	Core::spawnBasicFruit()
{
  int	posx;
  int	posy;

  if (_gameBoard.fruits().size() // Check if there is enough space for our fruit
      >= _gameBoard.width() * _gameBoard.height() - _gameBoard.snake().size())
    return ;
  posx = rangeRand(0, _gameBoard.width());
  posy = rangeRand(0, _gameBoard.height());
  while (checkCollision(posx, posy) != AItem::NONE)
    {
      posx = rangeRand(0, _gameBoard.width());
      posy = rangeRand(0, _gameBoard.height());
    }
  _gameBoard.fruits().push_front(FruitFactory::getInstance()->
				 createFruit(AItem::FRUIT, posx, posy));
}

void	Core::spawnSpecialFruit() // To do
{

}

// Key handlers

void	Core::keyUpHandler()
{}

void	Core::keyDownHandler()
{}

void	Core::keyLeftHandler()
{
  _snakeDir = static_cast<eDirection>((_snakeDir - 1) % 4);
}

void	Core::keyRightHandler()
{
  _snakeDir = static_cast<eDirection>((_snakeDir + 1) % 4);
}

void	Core::keySpaceHandler()
{
}

void	Core::keyEscHandler()
{
  _gameOver = true;
}

// Fruits effects

void	Core::fruitEffect()	// To do
{

}
