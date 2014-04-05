//
// Core.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 14:18:37 2014 chauvo_t
// Last update Sat Apr  5 15:41:32 2014 chauvo_t
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
  _keyHandlers[IDisplay::KEY_NONE] = &Core::keyNoneHandler;
  _keyHandlers[IDisplay::KEY_UP] = &Core::keyUpHandler;
  _keyHandlers[IDisplay::KEY_DOWN] = &Core::keyDownHandler;
  _keyHandlers[IDisplay::KEY_LEFT] = &Core::keyLeftHandler;
  _keyHandlers[IDisplay::KEY_RIGHT] = &Core::keyRightHandler;
  _keyHandlers[IDisplay::KEY_SPACE] = &Core::keySpaceHandler;
  _keyHandlers[IDisplay::KEY_ESC] = &Core::keyEscHandler;
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
}

void	Core::initGameBoard(int width, int height) // To do
{
  int	i;

  _gameBoard.setHeight(height);
  _gameBoard.setWidth(width);
  for (i = 0; i < SNAKE_INIT_SIZE; ++i)
    _gameBoard.snake().getSnake().push_back(SnakeRing((1/2)
						      * (_gameBoard.width() - SNAKE_INIT_SIZE)
						      + i,
						      _gameBoard.height() / 2));

  // To do: init first fruit
}

void			Core::gameLoop()
{
  IDisplay::eKey	key;

  _gameOver = false;
  key = IDisplay::KEY_NONE;
  while (_gameOver == false)
    {
      _currentTime = _timer.getMilliTime();
      if (_currentTime - _previousTime > 1.0 / (_snakeSpeed / 1000.0))
	{
	  key = _display->getKey();
	  (this->*_keyHandlers[key])();
	  this->moveSnake();
	  _previousTime = _currentTime;
	}
     _display->update(_gameBoard);
     _timer.milliSleep((1 / _fps * 1000) - (_currentTime - _previousTime));
    }
}

void				Core::endGame()		// To do
{
  std::list<Fruit>::iterator	it;

  for (it = _gameBoard.fruits().begin(); it != _gameBoard.fruits().end(); ++it)
    delete *it;
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

void	Core::moveSnake() // To do
{

}

AItem::eType	Core::checkCollision(int posx, int posy)
{
  std::list<AItem>::iterator	it;

  if (posx < 0 || posx > _gameBoard.width()
      || posy < 0 || posy > _gameBoard.height())
    return (AItem::WALL)
  for (it = _gameBoard.snake().begin();
       it != _gameBoard.snake().end();
       ++it)
    {
      if ((*it).posx() == posx && (*it).posy() == posy)
	return (AItem::SNAKE);
    }
  for (it = _gameBoard.fruits().begin();
       it != _gameBoard.fruits().end();
       ++it)
    {
      if ((*it).posx() == posx && (*it).posy() == posy)
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
{
  if (_snakeDir != DOWN)
    _snakeDir = UP;
}

void	Core::keyDownHandler()
{
  if (_snakeDir != UP)
    _snakeDir = DOWN;
}

void	Core::keyLeftHandler()
{
  if (_snakeDir != RIGHT)
    _snakeDir = LEFT;
}

void	Core::keyRightHandler()
{
  if (_snakeDir != LEFT)
    _snakeDir = RIGHT;
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
