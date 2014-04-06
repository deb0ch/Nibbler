//
// NcursesDisplay.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 20:32:14 2014 chauvo_t
// Last update Sun Apr  6 14:59:13 2014 chauvo_t
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
  std::cout << "1Salaud !" << std::endl;
  initscr();
  std::cout << "2Salaud !" << std::endl;
  raw();
  std::cout << "3Salaud !" << std::endl;
  noecho();
  std::cout << "4Salaud !" << std::endl;
  // keypad(stdscr, TRUE);
  std::cout << "5Salaud !" << std::endl;
  if(has_colors() != FALSE)
    {
      std::cout << "6Salaud !" << std::endl;
      _hasColors = true;
      start_color();
      use_default_colors();
      init_pair(AItem::SNAKE, COLOR_RED, COLOR_YELLOW);
      init_pair(AItem::WALL, COLOR_CYAN, COLOR_BLUE);
      init_pair(AItem::FRUIT, COLOR_RED, COLOR_MAGENTA);
    }
  else
    _hasColors = false;
  std::cout << "7Salaud !" << std::endl;
}

int	NcursesDisplay::getFps() const
{
  return (30);
}

void	NcursesDisplay::update(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator	snakeIt;
  std::list<Fruit*>::const_iterator	fruitIt;

  if (_hasColors)
    attron(COLOR_PAIR(AItem::SNAKE));
  std::cout << "0Connasse !" << std::endl;
  for (snakeIt = game.snake().begin(); snakeIt != game.snake().end(); ++snakeIt)
    mvwaddch(stdscr, (*snakeIt)->posy(), (*snakeIt)->posx(), ' ');
  std::cout << "1Connasse !" << std::endl;
  if (_hasColors)
    attroff(COLOR_PAIR(AItem::SNAKE));
  std::cout << "2Connasse !" << std::endl;
  if (_hasColors)
    attron(COLOR_PAIR(AItem::FRUIT));
  std::cout << "3Connasse !" << std::endl;
  for (fruitIt = game.fruits().begin(); fruitIt != game.fruits().end(); ++fruitIt)
    mvwaddch(stdscr, (*fruitIt)->posy(), (*fruitIt)->posx(), ' ');
  std::cout << "4Connasse !" << std::endl;
  if (_hasColors)
    attroff(COLOR_PAIR(AItem::FRUIT));
  std::cout << "5Connasse !" << std::endl;
  refresh();
  std::cout << "6Connasse !" << std::endl;
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
