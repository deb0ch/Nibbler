//
// Core.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 14:18:37 2014 chauvo_t
// Last update Fri Apr  4 20:00:37 2014 chauvo_t
//

#include "../include/Core.hh"

// Public

void	Core::startGame(int height, int width)
{
  _gameBoard.setHeight(height);
  _gameBoard.setWidth(width);
  // To do: init snake
  // To do: init first fruit
  try
    {
      this->openLib();
      this->gameLoop();
      this->closeLib();
    }
  catch (Exception e)
    {
      std::cerr << e.what() << std::endl;
    }
}

// To do: void	Core::switchLib();
// To do: void	Core::endGame();

Core::Core(const std::vector<std::string> &libs)
  : _libs(libs)
{
  _libsIt = _libs.begin();
  _keyHandlers[IDisplay::KEY_NONE] = &Core::keyNoneHandler;
  _keyHandlers[IDisplay::KEY_UP] = &Core::keyUpHandler;
  _keyHandlers[IDisplay::KEY_DOWN] = &Core::keyDownHandler;
  _keyHandlers[IDisplay::KEY_LEFT] = &Core::keyLeftHandler;
  _keyHandlers[IDisplay::KEY_RIGHT] = &Core::keyRightHandler;
  _keyHandlers[IDisplay::KEY_SPACE] = &Core::keySpaceHandler;
  _keyHandlers[IDisplay::KEY_ESC] = &Core::keyEscHandler;
  _currentTime = _timer.getMilliTime();
  _previousTime = _timer.getMilliTime();
  _fps = 50;
  _snakeSpeed = 2000;
}

// Private

void	Core::openLib()
{
  char	*error;

  _libHandle = dlopen((*(_libsIt)).c_str(), RTLD_LAZY);
  if (_libHandle == NULL)
    throw Exception("dlopen error opening " + *_libsIt + ": " + strerror(errno));
  dlerror();
  _display = reinterpret_cast<IDisplay*>(dlsym(_libHandle,
					       "createDisplay"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading library entry point: " + std::string(error));
}

void			Core::gameLoop()
{
  IDisplay::eKey	key;

  _exit = false;
  key = IDisplay::KEY_NONE;
  while (_exit == false)
    {
      _currentTime = _timer.getMilliTime();
      if (_currentTime - _previousTime > 1.0 / (_snakeSpeed / 1000.0))
	{
	  key = _display->getKey();
	  (this->*_keyHandlers[key])();
	  // Actions snake, update gameboard
	  // move_snake
	  // check_collision fruit or wall or snake itself
	  _previousTime = _currentTime;
	}
     _display->update(_gameBoard);
     _timer.milliSleep((1 / _fps * 1000) - (_currentTime - _previousTime));
    }
}

void	Core::closeLib()
{
  _display->close();
  dlclose(_libHandle);
  _libHandle = NULL;
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
  _exit = true;
}
