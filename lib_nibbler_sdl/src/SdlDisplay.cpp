//
// lib_nibbler_sdl.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Tue Apr  1 21:22:02 2014 chauvo_t
// Last update Tue Apr  1 22:07:34 2014 
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
  SDL_FreeSurface(this->_snakeDisplay);
  SDL_FreeSurface(this->_screen);
  SDL_FreeSurface(/*Fruits, wall, div items*/);
}

void		SdlDisplay::update(const GameBoard & game)
{

}

void		SdlDisplay::getKey()
{

}

void		SdlDisplay::initSnake(const GameBoard &game)
{
  this->_snakeDisplay = SDL_LoadBMP("sprit/bmp_sdl/snake.bmp");
  if (this->_snakeDisplay == NULL)
    throw Exception("[ERROR] : Snake failed LoadBMP");
  SDL_SetColorKey(this->_snakeDisplay, SDL_SRCCOLORKEYC, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  SDL_BlitSurface(this->_snakeDisplay, NULL, this->_screen, game.snake();
}

void		SdlDisplay::initBackground(const GameBoard &game)
{
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  this->_backgroundDisplay = SDL_LoadBMP("sprit/bmp_sdl/jungle.bmp");
  if (this->_backgroundDisplay == NULL)
    throw Exception("[ERROR] : Background failed LoadBMP");
  SDL_BlitSurface(this->_backgroundDisplay, NULL, this->_screen, &pos);
}

void		SdlDisplay::initWindow(const GameBoard & game)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    throw Exception("[ERROR] : SDL_INIT_VIDEO failled");

  this->_screen = SDL_SetVideoMode(NB_PIX_X * game.width(), NB_PIX_Y * game.height(),
				   COLOR, SDL_HWSURFACE);

  SDL_WM_SetCaption("Nibbler (SDL)" , NULL);
  SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  SDL_Flip(this->_screen);
}


void		SdlDisplay::init(const GameBoard & game)
{
  initWindow(&game);
  initBackground(&game);
  initSnake(&game);
}
