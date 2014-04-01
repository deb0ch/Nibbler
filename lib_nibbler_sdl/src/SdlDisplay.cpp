//
// lib_nibbler_sdl.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Tue Apr  1 21:22:02 2014 chauvo_t
// Last update Tue Apr  1 20:57:56 2014 
//

# include "../include/SdlDisplay.hh"

extern "C"
{
  IDisplay*	createDisplay()
  {
    return (new SdlDisplay);
  }

  void	print_hello()
  {
    std::cout << "Hello, World !" << std::endl;
  }
}

void		SdlDisplay::close()
{

}

void		SdlDisplay::update(const GameBoard & game)
{

}

void		SdlDisplay::getKey()
{

}

void		SdlDisplay::init(const GameBoard & game)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    std::cout << "[ERROR] : SDL_INIT_VIDEO failled" << std::endl;

  this->_screen = SDL_SetVideoMode(NB_PIX_X * game.width(), NB_PIX_Y * game.height(), COLOR, SDL_HWSURFACE);

  SDL_WM_SetCaption("Nibbler (SDL)" , NULL);
  SDL_FillRect(SDL_Surface *dst/*screen*/, NULL, SDL_MapRGB(const SDL_PixelFormat *const format, 0, 0, 0))
