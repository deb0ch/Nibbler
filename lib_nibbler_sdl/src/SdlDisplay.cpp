//
// lib_nibbler_sdl.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by laguet_p
// Login   <laguet_p@epitech.net>
//
// Started on  Tue Apr  1 21:22:02 2014 laguet_p
// Last update Thu Apr  3 20:23:12 2014 
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
  snakeIterator(game);
  fruitIterator(game);
  SDL_Flip(this->_screen);
}

IDisplay::eKey		SdlDisplay::getKey()
{
  SDL_Event		event;
  IDisplay::eKey	output;

  output = IDisplay::NIB_KEY_NONE;
  event.type = SDL_NOEVENT;
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    output = IDisplay::NIB_KEY_ESC;
	  else if (event.key.keysym.sym == SDL_QUIT)
	    output = IDisplay::NIB_KEY_ESC;
	  else if (event.key.keysym.sym == SDLK_LEFT)
	    {
	      this->_leftRigth = -1;
	      orient();
	      output = IDisplay::NIB_KEY_LEFT;
	    }
	  else if (event.key.keysym.sym == SDLK_RIGHT)
	    {
	      this->_leftRigth = 1;
	      orient();
	      output = IDisplay::NIB_KEY_RIGHT;
	    }
	  else if (event.key.keysym.sym == SDLK_SPACE)
	    output = IDisplay::NIB_KEY_SPACE;
	  else if (event.key.keysym.sym == SDLK_RETURN)
	    output = IDisplay::NIB_KEY_ENTER;
	}
    }
  return (output);
}

void		SdlDisplay::orient()
{
  this->_sens = this->_sens + this->_leftRigth;
  if (this->_sens > 3)
    this->_sens = 0;
  if (this->_sens < 0)
    this->_sens = 3;
}

void		SdlDisplay::snakeIterator(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator it;

  it = game.snake().begin();
  while (it != game.snake().end())
    {
      if (it == game.snake().begin())
	snakeHead();
      else if ((*it) == game.snake().back())
	snakeEnd();
      else
	this->_snakeDisplay = this->_snakeBody;
      this->_snakePos.x = (*it)->posx() * NB_PIX_X;
      this->_snakePos.y = (*it)->posy() * NB_PIX_Y;
      snakePart();
      ++it;
    }
}

void		SdlDisplay::snakeHead()
{
  if (this->_sens == 0)
    this->_snakeDisplay = this->_snakeHead0;
  else if (this->_sens == 1)
    this->_snakeDisplay = this->_snakeHead1;
  else if (this->_sens == 2)
    this->_snakeDisplay = this->_snakeHead2;
  else if (this->_sens == 3)
    this->_snakeDisplay = this->_snakeHead3;
}

void		SdlDisplay::snakeEnd()
{
  if (this->_sens == 0 || this->_sens == 2)
    this->_snakeDisplay = this->_snakeEnd2;
  else if (this->_sens == 1 || this->_sens == 3)
    this->_snakeDisplay = this->_snakeEnd1;
}

void		SdlDisplay::fruitIterator(const GameBoard & game)
{
  std::list<Fruit*>::const_iterator it;

  it = game.fruits().begin();
  while (it != game.fruits().end())
    {
      this->_fruitsDisplay = this->_fruit;
      this->_fruitPos.x = (*it)->posx() * NB_PIX_X;
      this->_fruitPos.y = (*it)->posy() * NB_PIX_Y;
      fruitPart();
      ++it;
    }
}

void		SdlDisplay::snakeLoad(const GameBoard & game)
{
  this->_snakeHead0 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_head/snake_head0.bmp");
  if (this->_snakeHead0 == NULL)
    throw Exception("[ERROR] : Snake_head0 failed LoadBMP");
  this->_snakeHead1 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_head/snake_head1.bmp");
  if (this->_snakeHead1 == NULL)
    throw Exception("[ERROR] : Snake_head1 failed LoadBMP");
  this->_snakeHead2 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_head/snake_head2.bmp");
  if (this->_snakeHead2 == NULL)
    throw Exception("[ERROR] : Snake_head2 failed LoadBMP");
  this->_snakeHead3 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_head/snake_head3.bmp");
  if (this->_snakeHead3 == NULL)
    throw Exception("[ERROR] : Snake_head3 failed LoadBMP");
  this->_snakeEnd1 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_end/snake_end1.bmp");
  if (this->_snakeEnd1 == NULL)
    throw Exception("[ERROR] : Snake_end1 failed LoadBMP");
  this->_snakeEnd2 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_end/snake_end0.bmp");
  if (this->_snakeEnd2 == NULL)
    throw Exception("[ERROR] : Snake_end2 failed LoadBMP");
  this->_snakeBody = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake.bmp");
  if (this->_snakeBody == NULL)
    throw Exception("[ERROR] : Snake failed LoadBMP");
  snakeIterator(game);
}

void		SdlDisplay::fruitLoad(const GameBoard & game)
{
  this->_fruit = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/fruit.bmp");
  if (this->_fruit == NULL)
    throw Exception("[ERROR] : fruit failed LoadBMP");
  fruitIterator(game);
}

void		SdlDisplay::snakePart()
{
  SDL_SetColorKey(this->_snakeDisplay, SDL_SRCCOLORKEY, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  SDL_BlitSurface(this->_snakeDisplay, NULL, this->_screen, &(this->_snakePos));
}

void		SdlDisplay::fruitPart()
{
  SDL_SetColorKey(this->_fruitsDisplay, SDL_SRCCOLORKEY, SDL_MapRGB(this->_screen->format, 0, 0, 0));
  SDL_BlitSurface(this->_fruitsDisplay, NULL, this->_screen, &(this->_fruitPos));
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
  fruitLoad(game);
}
