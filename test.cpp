//
// test.cpp for lol in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 11:54:33 2014 chauvo_t
// Last update Sat Apr  5 11:55:09 2014 chauvo_t
//

#include <iostream>
#include "core/include/Commute.hpp"

int	main(int ac, char **av)
{
  std::cout << commute<int>(av[1]) * 2 << std::endl;
  return (0);
}
