//
// lib_nibbler_sdl.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by laguet_p
// Login   <laguet_p@epitech.net>
//
// Started on  Tue Apr  1 21:22:02 2014 laguet_p
// Last update Thu Apr  3 15:37:09 2014 
//

# include "../include/SdlDisplay.hh"

extern "C"
{
  IDisplay*	createDisplay()
  {
    return (new SdlDisplay);
  }
}

void		SdlDisplay::close() const
{
  SDL_FreeSurface(this->_snakeDisplay);
  SDL_FreeSurface(this->_screen);
  //  SDL_FreeSurface(/*Fruits, wall, div items*/);
}

void		SdlDisplay::update(const GameBoard & game)
{
  SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  background();
  snakeIterator(game);
  SDL_Flip(this->_screen);
}

IDisplay::eKey		SdlDisplay::getKey()
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (NIB_KEY_ESC);
      else if (event.key.keysym.sym == SDL_QUIT)
	return (NIB_KEY_ESC);
      else if (event.key.keysym.sym == SDLK_LEFT)
	return (NIB_KEY_LEFT);
      else if (event.key.keysym.sym == SDLK_RIGHT)
	return (NIB_KEY_RIGHT);
      else if (event.key.keysym.sym == SDLK_UP)
	return (NIB_KEY_UP);
      else if (event.key.keysym.sym == SDLK_DOWN)
	return (NIB_KEY_DOWN);
      else if (event.key.keysym.sym == SDLK_SPACE)
	return (NIB_KEY_SPACE);
    }
  return (NIB_KEY_NONE);
}

void		SdlDisplay::snakeIterator(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator it;

  it = game.snake().begin();
  while (it != game.snake().end())
    {
      if (it != game.snake().begin() && (*it) != game.snake().back())
	this->_snakeBmp = 2;
      else
	{
	  if (it == game.snake().begin())
	    this->_snakeBmp = 1;
	  if ((*it) == game.snake().front())
	    this->_snakeBmp = 3;
	}
      this->_snakePos.x = (*it)->posx() * NB_PIX_X;
      this->_snakePos.y = (*it)->posy() * NB_PIX_Y;
      snakePart();
      ++it;
    }
}

void		SdlDisplay::snakePart()
{
  if (this->_snakeBmp == 1)
    this->_snakeDisplay = SDL_LoadBMP("sprit/bmp_sdl/snake_head.bmp");
  else if (this->_snakeBmp == 2)
    this->_snakeDisplay = SDL_LoadBMP("sprit/bmp_sdl/snake.bmp");
  else if (this->_snakeBmp == 3)
    this->_snakeDisplay = SDL_LoadBMP("sprit/bmp_sdl/snake_end.bmp");
  if (this->_snakeDisplay == NULL)
    throw Exception("[ERROR] : Snake failed LoadBMP");
  SDL_SetColorKey(this->_snakeDisplay, SDL_SRCCOLORKEY, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  SDL_BlitSurface(this->_snakeDisplay, NULL, this->_screen, &(this->_snakePos));
}

void		SdlDisplay::background()
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
  if (game.width() <= MAX_X && game.height() <= MAX_Y)
    this->_screen = SDL_SetVideoMode((NB_PIX_X * game.width()), (NB_PIX_Y * game.height()), COLOR, SDL_HWSURFACE);
  else
    throw Exception("[ERROR] : Window too high, [MAX width = 32] [MAX height = 26]");
  SDL_WM_SetCaption("Nibbler (SDL)" , NULL);
  SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  SDL_Flip(this->_screen);
}

int		SdlDisplay::setFps() const
{
  return (50);
}

void		SdlDisplay::init(const GameBoard & game)
{
  initWindow(game);
  background();
  snakeIterator(game);
}
