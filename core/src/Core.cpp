//
// Core.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 14:18:37 2014 chauvo_t
// Last update Thu Apr  3 17:27:56 2014 bourge_i
//

#include "../include/Core.hh"

// Public

void	Core::startGame(int height, int width)
{

}

// Private

Core::Core(const std::vector<std::string> &libs)
{
  this->_libs = libs;
  this->_libsIt = this->_libs.begin();
}

Core::~Core()
{
}

void	Core::openLib()
{
  // char	*error;

  // this->_libHandle = dlopen(av[1], RTLD_LAZY);
  // if (dlhandle == NULL)
  //   return(1);
  // dlerror();
  // external_creator = reinterpret_cast<IAssistant* (*)()>(dlsym(dlhandle, "create_assistant"));
  // if ((error = dlerror()) != NULL)
  //   {
  //     std::cerr << error << std::endl;
  //     return(1);
  //   }

  // IAssistant* bob = external_creator();
  // bob->talk();
}

void	Core::gameLoop()
{

}

void	Core::closeLib()
{
  dlclose(dlhandle);
}
