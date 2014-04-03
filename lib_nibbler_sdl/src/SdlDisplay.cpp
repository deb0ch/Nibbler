//
// lib_nibbler_sdl.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by laguet_p
// Login   <laguet_p@epitech.net>
//
// Started on  Tue Apr  1 21:22:02 2014 laguet_p
// Last update Thu Apr  3 23:42:40 2014 
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
  SDL_FreeSurface(this->_snakeHead0);
  SDL_FreeSurface(this->_snakeHead1);
  SDL_FreeSurface(this->_snakeHead2);
  SDL_FreeSurface(this->_snakeHead3);
  SDL_FreeSurface(this->_snakeEnd1);
  SDL_FreeSurface(this->_snakeEnd2);
  SDL_FreeSurface(this->_snakeBody0);
  SDL_FreeSurface(this->_snakeBody1);
  SDL_FreeSurface(this->_snakeBody2);
  SDL_FreeSurface(this->_snakeBody3);

  SDL_FreeSurface(this->_backgroundDisplay);

  SDL_FreeSurface(this->_fruit);
  SDL_FreeSurface(this->_fruit2);

  SDL_FreeSurface(this->_screen);
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
	    output = IDisplay::NIB_KEY_LEFT;
	  else if (event.key.keysym.sym == SDLK_RIGHT)
	    output = IDisplay::NIB_KEY_RIGHT;
	  else if (event.key.keysym.sym == SDLK_SPACE)
	    output = IDisplay::NIB_KEY_SPACE;
	  else if (event.key.keysym.sym == SDLK_RETURN)
	    output = IDisplay::NIB_KEY_ENTER;
	}
    }
  return (output);
}

void		SdlDisplay::snakeIterator(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator it;

  it = game.snake().begin();
  while (it != game.snake().end())
    {
      if (it == game.snake().begin())
	snakeHead(game);
      else if ((*it) == game.snake().back())
	snakeEnd(game);
      else
	snakeBody(it);
      this->_snakePos.x = (*it)->posx() * NB_PIX_X;
      this->_snakePos.y = (*it)->posy() * NB_PIX_Y;
      snakePart();
      ++it;
    }
}

void		SdlDisplay::snakeHead(const GameBoard & game)
{
  if (game.snake().front()->direction() == SnakeRing::UP)
    this->_snakeDisplay = this->_snakeHead1;
  if (game.snake().front()->direction() == SnakeRing::DOWN)
    this->_snakeDisplay = this->_snakeHead3;
  if (game.snake().front()->direction() == SnakeRing::LEFT)
    this->_snakeDisplay = this->_snakeHead0;
  if (game.snake().front()->direction() == SnakeRing::RIGHT)
    this->_snakeDisplay = this->_snakeHead2;
}

void		SdlDisplay::snakeBody(std::list<SnakeRing*>::const_iterator it)
{
  if ((*it)->direction() == SnakeRing::UP)
    this->_snakeDisplay = this->_snakeBody1;
  if ((*it)->direction() == SnakeRing::DOWN)
    this->_snakeDisplay = this->_snakeBody3;
  if ((*it)->direction() == SnakeRing::LEFT)
    this->_snakeDisplay = this->_snakeBody0;
  if ((*it)->direction() == SnakeRing::RIGHT)
    this->_snakeDisplay = this->_snakeBody2;
}

void		SdlDisplay::snakeEnd(const GameBoard & game)
{
  if (game.snake().back()->direction() == SnakeRing::UP ||
      game.snake().back()->direction() == SnakeRing::DOWN)
    this->_snakeDisplay = this->_snakeEnd1;
  else if (game.snake().back()->direction() == SnakeRing::LEFT ||
      game.snake().back()->direction() == SnakeRing::RIGHT)
    this->_snakeDisplay = this->_snakeEnd2;
}

void		SdlDisplay::fruitIterator(const GameBoard & game)
{
  std::list<Fruit*>::const_iterator it;

  it = game.fruits().begin();
  while (it != game.fruits().end())
    {
      if (this->_compt % 2 == 0)
	this->_fruitsDisplay = this->_fruit;
      if (this->_compt % 2 == 1)
	this->_fruitsDisplay = this->_fruit2;
      this->_fruitPos.x = (*it)->posx() * NB_PIX_X;
      this->_fruitPos.y = (*it)->posy() * NB_PIX_Y;
      fruitPart();
      ++it;
    }
  this->_compt = this->_compt + 1;
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
  this->_snakeBody0 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_body/snakeBody00.bmp");
  if (this->_snakeBody0 == NULL)
    throw Exception("[ERROR] : SnakeBody0 failed LoadBMP");
  this->_snakeBody1 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_body/snakeBody01.bmp");
  if (this->_snakeBody1 == NULL)
    throw Exception("[ERROR] : SnakeBody1 failed LoadBMP");
  this->_snakeBody2 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_body/snakeBody02.bmp");
  if (this->_snakeBody2 == NULL)
    throw Exception("[ERROR] : SnakeBody2  failed LoadBMP");
  this->_snakeBody3 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/snake_body/snakeBody03.bmp");
  if (this->_snakeBody3 == NULL)
    throw Exception("[ERROR] : SnakeBody3 failed LoadBMP");
  snakeIterator(game);
}

void		SdlDisplay::fruitLoad(const GameBoard & game)
{
  this->_fruit = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/fruit.bmp");
  if (this->_fruit == NULL)
    throw Exception("[ERROR] : fruit failed LoadBMP");
  this->_fruit2 = SDL_LoadBMP("lib_nibbler_sdl/sprit/bmp_sdl/fruit02.bmp");
  if (this->_fruit2 == NULL)
    throw Exception("[ERROR] : fruit02 failed LoadBMP");
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

int		SdlDisplay::getMaxWidth() const
{
  return (MAX_X);
}

int		SdlDisplay::getMaxHeight() const
{
  return (MAX_Y);
}

void		SdlDisplay::init(const GameBoard & game)
{
  this->_compt = 0;
  initWindow(game);
  background();
  snakeLoad(game);
  fruitLoad(game);
}
