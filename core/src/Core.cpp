//
// Core.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 14:18:37 2014 chauvo_t
// Last update Thu Apr  3 18:28:42 2014 bourge_i
//

#include "../include/Core.hh"

// Public

void	Core::startGame(int height, int width)
{

}

// Private

Core::Core(const std::vector<std::string> &libs)
  : _libs(libs)
{
  this->_libsIt = this->_libs.begin();
}

Core::~Core()
{
}

void	Core::openLib()
{
  char	*error;

  if (this->_libsIt == this->_libs.end())
    this->_libsIt = this->libs.begin();
  else
    ++this->_libsIt;

  this->_libHandle = dlopen((*(this->_libsIt)).c_str(), RTLD_LAZY);
  if (this->_libHandle == NULL)
    return ;
  dlerror();

  this->_init   = reinterpret_cast<void (*)(const GameBoard & game)>(dlsym(this->_libHandle, "init"));
  this->_update = reinterpret_cast<void (*)(const GameBoard & game)>(dlsym(this->_libHandle, "update"));
  this->_getKey = reinterpret_cast<IDisplay::eKey (*)()>(dlsym(this->_libHandle, "getKey"));
  this->_close  = reinterpret_cast<void (*)()>(dlsym(this->_libHandle, "close"));

  if ((error = dlerror()) != NULL)
    {
      std::cerr << error << std::endl;
      return ;
    }
}

void	Core::gameLoop()
{

}

void	Core::closeLib()
{
  this->_close();
  dlclose(this->_libHandle);
}
