//
// lib_nibbler_sdl.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Tue Apr  1 21:22:02 2014 chauvo_t
// Last update Tue Apr  1 19:41:08 2014 
//

#include "../include/sdl.hh"

extern "C"
{
  void	print_hello()
  {
    std::cout << "Hello, World !" << std::endl;
  }
}

void		sdl::sdl_close()
{

}

void		sdl::sdl_refresh()
{

}

void		sdl::sdl_main_loop()
{

}

void		sdl::sdl_init()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    std::cout << "[ERROR] : SDL_INIT_VIDEO failled" << std::endl;

  //init le screen ?????

  SDL_WM_SetCaption("Nibbler (SDL)" , NULL);
  SDL_FillRect(SDL_Surface *dst/*screen*/, NULL, Uint32 color)
}
