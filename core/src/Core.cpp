//
// Core.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 14:18:37 2014 chauvo_t
// Last update Thu Apr  3 18:48:02 2014 bourge_i
//

#include "../include/Core.hh"

// Public

void	Core::startGame(int height, int width)
{
  try
    {
      this->openLib();
    }
  catch (Exception e)
    {
      std::cerr << e.what() << std::endl;
    }
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
    this->_libsIt = this->_libs.begin();
  else
    ++this->_libsIt;

  this->_libHandle = dlopen((*(this->_libsIt)).c_str(), RTLD_LAZY);
  if (this->_libHandle == NULL)
    throw Exception("dlopen error");

  dlerror();
  this->_init   = reinterpret_cast<void (*)(const GameBoard & game)>(dlsym(this->_libHandle, "init"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading init symbol: " + std::string(error));
  dlerror();
  this->_update = reinterpret_cast<void (*)(const GameBoard & game)>(dlsym(this->_libHandle, "update"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading init symbol: " + std::string(error));
  dlerror();
  this->_getKey = reinterpret_cast<IDisplay::eKey (*)()>(dlsym(this->_libHandle, "getKey"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading init symbol: " + std::string(error));
  dlerror();
  this->_close  = reinterpret_cast<void (*)()>(dlsym(this->_libHandle, "close"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading init symbol: " + std::string(error));
}

void	Core::gameLoop()
{

}

void	Core::closeLib()
{
  this->_close();
  dlclose(this->_libHandle);
}
