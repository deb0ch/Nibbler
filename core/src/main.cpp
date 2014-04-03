#include <iostream>
#include <dlfcn.h>
#include "../include/Core.hh"

int main(int ac, char** av)
{
  (void)ac;
  (void)av;
  if (ac < 2)
    {
      std::cerr << "Usage : " << av[0] << " [libXXX.so] ..." << std::endl;
      return(1);
    }


  return (0);
}
