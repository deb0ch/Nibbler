//
// NcursesDisplay.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 20:32:14 2014 chauvo_t
// Last update Sun Apr  6 23:35:09 2014 chauvo_t
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
  if (initscr() == NULL)
    throw Exception("ncurses: initscr() error");
  if (raw() == ERR)
    std::cerr << "ncurses: raw() error" << std::endl;
  if (noecho() == ERR)
    std::cerr << "ncurses: noecho() error" << std::endl;
  if (curs_set(0) == ERR)
    std::cerr << "ncurses: curs_set() error" << std::endl;
  if (has_colors() != FALSE)
    {
      _hasColors = true;
      start_color();
      if (use_default_colors() == ERR)
	std::cerr << "ncurses: use_default_colors() error" << std::endl;
      init_pair(AItem::SNAKE, COLOR_RED, COLOR_YELLOW);
      init_pair(AItem::WALL, COLOR_CYAN, COLOR_BLUE);
      init_pair(AItem::FRUIT, COLOR_RED, COLOR_MAGENTA);
    }
  else
    _hasColors = false;
  getmaxyx(stdscr, _maxHeight, _maxWidth);
  if ((_win = newwin(game.height() + 2, game.width() + 2,
		     (_maxHeight / 2) - (game.height() / 2),
		     (_maxWidth / 2) - (game.width() / 2))) == NULL)
    {
      endwin();
      throw Exception("ncurses: newwin() error");
    }
  if (nodelay(_win, TRUE) == ERR)
    throw Exception("ncurses: nodelay() error");
  if (keypad(_win, TRUE) == ERR)
    std::cerr << "ncurses: keypad() error" << std::endl;
}

int	NcursesDisplay::getFps() const
{
  return (10);
}

void	NcursesDisplay::update(const GameBoard & game)
{
  if (wclear(_win) == ERR)
    std::cerr << "ncurses: clear() error" << std::endl;
  this->putSnake(game);
  this->putFruits(game);
  this->putBorder();
  if (wrefresh(_win) == ERR)
    throw Exception("ncurses: refresh() error");
}

int	NcursesDisplay::getMaxWidth() const
{
  return (200);
}

int	NcursesDisplay::getMaxHeight() const
{
  return (50);
}

IDisplay::eKey	NcursesDisplay::getKey()
{
  int			ch;
  IDisplay::eKey	output;

  output = IDisplay::NIB_KEY_NONE;
  while ((ch = wgetch(_win)) != ERR)
    {
      if (ch == KEY_UP)
	output = IDisplay::NIB_KEY_UP;
      else if (ch == KEY_DOWN)
	output = IDisplay::NIB_KEY_DOWN;
      else if (ch == KEY_LEFT)
	output = IDisplay::NIB_KEY_LEFT;
      else if (ch == KEY_RIGHT)
	output = IDisplay::NIB_KEY_RIGHT;
      else if (ch == ' ')
	output = IDisplay::NIB_KEY_SPACE;
      else if (ch == KEY_ENTER)
	output = IDisplay::NIB_KEY_ENTER;
    }
  return (output);
}

void	NcursesDisplay::close() const
{
  if (delwin(_win) == ERR)
    std::cerr << "ncurses: delwin() error" << std::endl;
  if (endwin() == ERR)
    throw Exception("ncurses: endwin() error");
  if (curs_set(0) == ERR)
    std::cerr << "ncurses: curs_set() error" << std::endl;
}

NcursesDisplay::NcursesDisplay() {}

NcursesDisplay::~NcursesDisplay() {}

// Private

void	NcursesDisplay::putSnake(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator	snakeIt;

  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::SNAKE)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  for (snakeIt = game.snake().begin(); snakeIt != game.snake().end(); ++snakeIt)
    mvwaddch(_win, (*snakeIt)->posy() + 1, (*snakeIt)->posx() + 1, ' ');
  mvwaddch(_win, game.snake().front()->posy() + 1, game.snake().front()->posx() + 1, '"');
  if (_hasColors)
    if (attroff(COLOR_PAIR(AItem::SNAKE)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
}

void	NcursesDisplay::putFruits(const GameBoard & game)
{
  std::list<Fruit*>::const_iterator	fruitIt;

  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::FRUIT)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  for (fruitIt = game.fruits().begin(); fruitIt != game.fruits().end(); ++fruitIt)
    mvwaddch(_win, (*fruitIt)->posy() + 1, (*fruitIt)->posx() + 1, ' ');
  if (_hasColors)
    if (attroff(COLOR_PAIR(AItem::FRUIT)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
}

void	NcursesDisplay::putBorder()
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::WALL)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  wborder(_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::WALL)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
}
