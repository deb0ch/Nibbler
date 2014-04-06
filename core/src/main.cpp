//
// main.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 19:38:10 2014 chauvo_t
// Last update Sun Apr  6 22:25:22 2014 chauvo_t
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
      // || (mapWidth = commute<int>(av[1])) > 32
      || (mapHeight = commute<int>(av[2])) < 6
      // || (mapHeight = commute<int>(av[2])) > 26)
      )
    {
      std::cerr << "Usage : " << av[0] << "[6 < width < 32] [6 < height < 26] [libXXX.so] ..."
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
