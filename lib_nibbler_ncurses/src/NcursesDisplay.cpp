//
// NcursesDisplay.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 20:32:14 2014 chauvo_t
// Last update Sun Apr  6 16:21:46 2014 chauvo_t
//

#include "../include/NcursesDisplay.hh"

extern "C"
{
  IDisplay*	createDisplay()
  {
    return (new NcursesDisplay);
  }
}

void	NcursesDisplay::init(const GameBoard & game) // To do: check error return values
{
  (void)game;
  initscr();
  raw();
  noecho();
  // keypad(stdscr, TRUE);
  if(has_colors() != FALSE)
    {
      _hasColors = true;
      start_color();
      use_default_colors();
      init_pair(AItem::SNAKE, COLOR_RED, COLOR_YELLOW);
      init_pair(AItem::WALL, COLOR_CYAN, COLOR_BLUE);
      init_pair(AItem::FRUIT, COLOR_RED, COLOR_MAGENTA);
    }
  else
    _hasColors = false;
}

int	NcursesDisplay::getFps() const
{
  return (5);
}

void	NcursesDisplay::update(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator	snakeIt;
  std::list<Fruit*>::const_iterator	fruitIt;

  clear();
  if (_hasColors)
    attron(COLOR_PAIR(AItem::SNAKE));
  for (snakeIt = game.snake().begin(); snakeIt != game.snake().end(); ++snakeIt)
    mvwaddch(stdscr, (*snakeIt)->posy(), (*snakeIt)->posx(), ' ');
  if (_hasColors)
    attroff(COLOR_PAIR(AItem::SNAKE));
  if (_hasColors)
    attron(COLOR_PAIR(AItem::FRUIT));
  for (fruitIt = game.fruits().begin(); fruitIt != game.fruits().end(); ++fruitIt)
    mvwaddch(stdscr, (*fruitIt)->posy(), (*fruitIt)->posx(), ' ');
  if (_hasColors)
    attroff(COLOR_PAIR(AItem::FRUIT));
  refresh();
}

IDisplay::eKey	NcursesDisplay::getKey()
{
  return (IDisplay::NIB_KEY_NONE);
}

void	NcursesDisplay::close() const
{
  endwin();
}

NcursesDisplay::NcursesDisplay() {}

NcursesDisplay::~NcursesDisplay() {}
