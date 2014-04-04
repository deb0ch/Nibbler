//
// Core.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 14:18:37 2014 chauvo_t
// Last update Fri Apr  4 16:15:57 2014 chauvo_t
//

#include "../include/Core.hh"

// Public

void	Core::startGame(int height, int width)
{
  this->_gameBoard.setHeight(height);
  this->_gameBoard.setWidth(width);
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
  this->_libsIt = this->_libs.begin();
  this->_keyHandlers[IDisplay::KEY_UP] = &Core::keyUpHandler;
  this->_keyHandlers[IDisplay::KEY_DOWN] = &Core::keyDownHandler;
  this->_keyHandlers[IDisplay::KEY_LEFT] = &Core::keyLeftHandler;
  this->_keyHandlers[IDisplay::KEY_RIGHT] = &Core::keyRightHandler;
  this->_keyHandlers[IDisplay::KEY_SPACE] = &Core::keySpaceHandler;
  this->_keyHandlers[IDisplay::KEY_ESC] = &Core::keyEscHandler;
}

// Private

void	Core::openLib()
{
  char	*error;

  this->_libHandle = dlopen((*(this->_libsIt)).c_str(), RTLD_LAZY);
  if (this->_libHandle == NULL)
    throw Exception("dlopen error opening " + *this->_libsIt + ": " + strerror(errno));
  dlerror();
  this->_display = reinterpret_cast<IDisplay*>(dlsym(this->_libHandle,
						     "createDisplay"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading library entry point: " + std::string(error));
}

void			Core::gameLoop()
{
  IDisplay::eKey	key;
  bool			exit = false;

  key = IDisplay::KEY_LAST;
  while (exit == false)
    {
      key = this->_display->getKey();
      this->_display->update(this->_gameBoard);
      this->_timer.milliSleep(/**/);
    }
}

void	Core::closeLib()
{
  this->_display->close();
  dlclose(this->_libHandle);
  this->_libHandle = NULL;
}
