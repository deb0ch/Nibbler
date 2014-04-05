//
// main.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 19:38:10 2014 chauvo_t
// Last update Sat Apr  5 11:32:21 2014 chauvo_t
//

#include <iostream>
#include <dlfcn.h>
#include "../include/Core.hh"
#include "../include/FruitFactory.hh"

FruitFactory	*FruitFactory::_fruitFactory = NULL;

int main(int ac, char** av)
{
  Core	core;

  if (ac < 2)
    {
      std::cerr << "Usage : " << av[0] << " [libXXX.so] ..." << std::endl;
      return(1);
    }

  return (0);
}
