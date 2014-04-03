//
// lib_nibbler_sdl.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by laguet_p
// Login   <laguet_p@epitech.net>
//
// Started on  Tue Apr  1 21:22:02 2014 laguet_p
// Last update Thu Apr  3 17:39:01 2014 
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
  SDL_BlitSurface(this->_backgroundDisplay, NULL, this->_screen, &(this->_backgroundPos));
  //  background();
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
	{
	  this->_leftRigth = -1;
	  return (NIB_KEY_LEFT);
	}
      else if (event.key.keysym.sym == SDLK_RIGHT)
	{
	  this->_leftRigth = 1;
	  return (NIB_KEY_RIGHT);
	}
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
      if (it == game.snake().begin())
	this->_snakeDisplay = this->_snakeHead;
      else if ((*it) == game.snake().back())
	this->_snakeDisplay = this->_snakeEnd;
      else
	this->_snakeDisplay = this->_snakeBody;
      this->_snakePos.x = (*it)->posx() * NB_PIX_X;
      this->_snakePos.y = (*it)->posy() * NB_PIX_Y;
      snakePart();
      ++it;
    }
}

void		SdlDisplay::snakeLoad(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator it;

  it = game.snake().begin();
  while (it != game.snake().end())
    {
      if (it == game.snake().begin())
	{
	  this->_snakeHead = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_head.bmp");
	  if (this->_snakeDisplay == NULL)
	    throw Exception("[ERROR] : Snake_head failed LoadBMP");
	}
      else if ((*it) == game.snake().back())
	{
	  this->_snakeEnd = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_end.bmp");
	  if (this->_snakeDisplay == NULL)
	    throw Exception("[ERROR] : Snake_end failed LoadBMP");
	}
      else
	{
	  this->_snakeBody = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake.bmp");
	  if (this->_snakeDisplay == NULL)
	    throw Exception("[ERROR] : Snake failed LoadBMP");
	}
      this->_snakePos.x = (*it)->posx() * NB_PIX_X;
      this->_snakePos.y = (*it)->posy() * NB_PIX_Y;
      snakeIterator(game);
      ++it;
    }
}

void		SdlDisplay::snakePart()
{
  SDL_SetColorKey(this->_snakeDisplay, SDL_SRCCOLORKEY, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  SDL_BlitSurface(this->_snakeDisplay, NULL, this->_screen, &(this->_snakePos));
}

void		SdlDisplay::background()
{

  this->_backgroundPos.x = 0;
  this->_backgroundPos.y = 0;
  this->_backgroundDisplay = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/jungle.bmp");
  if (this->_backgroundDisplay == NULL)
    throw Exception("[ERROR] : Background failed LoadBMP");
  SDL_BlitSurface(this->_backgroundDisplay, NULL, this->_screen, &(this->_backgroundPos));
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

int		SdlDisplay::getFps() const
{
  return (50);
}

void		SdlDisplay::init(const GameBoard & game)
{
  this->_sens = 2;
  initWindow(game);
  background();
  snakeLoad(game);
}
