//
// main.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 19:38:10 2014 chauvo_t
// Last update Sat Apr  5 23:08:59 2014 bourge_i
//

#include <iostream>
#include <dlfcn.h>
#include "../include/Core.hh"
#include "../include/FruitFactory.hh"
#include "../include/Commute.hpp"

FruitFactory	*FruitFactory::_fruitFactory = NULL;

int				main(int ac, char** av)
{
  Core				core;
  std::vector<std::string>	libs;
  int				mapWidth;
  int				mapHeight;
  int				i;

  if (ac < 4
      || (mapWidth = commute<int>(av[1])) < 6
      || (mapHeight = commute<int>(av[2])) < 6)
    {
      std::cerr << "Usage : " << av[0] << "[6 < width] [6 < height] [libXXX.so] ..."
		<< std::endl;
      return(1);
    }
  i = 3;
  while (i < ac)
    {
      libs.push_back(av[i]);
      ++i;
    }
  try
    {
      core.startGame(libs, mapWidth, mapHeight);
      FruitFactory::deleteInstance();
    }
  catch (Exception e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
