//
// main.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 19:38:10 2014 chauvo_t
// Last update Sat Apr  5 12:04:23 2014 chauvo_t
//

#include <iostream>
#include <dlfcn.h>
#include "../include/Core.hh"
#include "../include/FruitFactory.hh"
#include "../include/Commute.hpp"

FruitFactory	*FruitFactory::_fruitFactory = NULL;

int	main(int ac, char** av)
{
  Core	core;
  int	mapWidth;
  int	mapHeight;

  if (ac < 3
      || (mapWidth = commute<int>(av[1])) < 5
      || (mapHeight = commute<int>(av[2])) < 5)
    {
      std::cerr << "Usage : " << av[0] << "[width] [height] [libXXX.so] ..." << std::endl;
      return(1);
    }

  return (0);
}
