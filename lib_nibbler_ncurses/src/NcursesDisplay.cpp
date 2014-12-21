//
// NcursesDisplay.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 20:32:14 2014 chauvo_t
// Last update Sun Dec 21 16:06:05 2014 chauvo_t
//

#include "../include/NcursesDisplay.hh"

extern "C"
{
  IDisplay*	createDisplay()
  {
    return (new NcursesDisplay);
  }
}

void	NcursesDisplay::init(const GameBoard & game)
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
      init_pair(AItem::WALL, COLOR_WHITE, COLOR_BLUE);
      init_pair(AItem::BASIC_FRUIT, COLOR_RED, COLOR_MAGENTA);
      init_pair(AItem::MAXI_FRUIT, COLOR_YELLOW, COLOR_RED);
      init_pair(AItem::SPEED_FRUIT, COLOR_WHITE, COLOR_YELLOW);
      init_pair(AItem::SLOW_FRUIT, COLOR_BLUE, COLOR_CYAN);
      init_pair(AItem::REVERSE_FRUIT, COLOR_BLACK, COLOR_WHITE);
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
  return (50);
}

void	NcursesDisplay::update(const GameBoard & game)
{
  if (wclear(_win) == ERR)
    std::cerr << "ncurses: clear() error" << std::endl;
  this->putSnake(game);
  this->putFruits(game);
  this->putBorder();
  this->putScore(game);
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
	output = IDisplay::NIB_KEY_DASH;
      else if (ch == 27)
	output = IDisplay::NIB_KEY_ESC;
      else if (ch == '0' || ch == '\n')
	output = IDisplay::NIB_KEY_SWITCH;
      else if (ch == 'p' || ch == 'P')
	output = IDisplay::NIB_KEY_PAUSE;
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

void	NcursesDisplay::putSnake(const GameBoard & game) const
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
      std::cerr << "ncurses: attroff() error" << std::endl;
}

void	NcursesDisplay::putFruits(const GameBoard & game) const
{
  std::list<Fruit*>::const_iterator	fruitIt;

  for (fruitIt = game.fruits().begin(); fruitIt != game.fruits().end(); ++fruitIt)
    {
      if ((*fruitIt)->type() == AItem::BASIC_FRUIT)
	this->putBasicFruit(fruitIt);
      if ((*fruitIt)->type() == AItem::MAXI_FRUIT)
	this->putMaxiFruit(fruitIt);
      if ((*fruitIt)->type() == AItem::SPEED_FRUIT)
	this->putSpeedFruit(fruitIt);
      if ((*fruitIt)->type() == AItem::SLOW_FRUIT)
	this->putSlowFruit(fruitIt);
      if ((*fruitIt)->type() == AItem::REVERSE_FRUIT)
	this->putReverseFruit(fruitIt);
    }
}

void	NcursesDisplay::putBorder() const
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::WALL)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  wborder(_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::WALL)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
}

void	NcursesDisplay::putScore(const GameBoard & game) const
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::WALL)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  mvwprintw(_win, 0, 0, "Score: %d", game.score());
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::WALL)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
}

void	NcursesDisplay::putBasicFruit(const std::list<Fruit*>::const_iterator fruitIt) const
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::BASIC_FRUIT)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  mvwaddch(_win, (*fruitIt)->posy() + 1, (*fruitIt)->posx() + 1, ' ');
  if (_hasColors)
    if (attroff(COLOR_PAIR(AItem::BASIC_FRUIT)) == ERR)
      std::cerr << "ncurses: attroff() error" << std::endl;
}

void	NcursesDisplay::putMaxiFruit(const std::list<Fruit*>::const_iterator fruitIt) const
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::MAXI_FRUIT)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  mvwaddch(_win, (*fruitIt)->posy() + 1, (*fruitIt)->posx() + 1, 'm');
  if (_hasColors)
    if (attroff(COLOR_PAIR(AItem::MAXI_FRUIT)) == ERR)
      std::cerr << "ncurses: attroff() error" << std::endl;
}

void	NcursesDisplay::putSpeedFruit(const std::list<Fruit*>::const_iterator fruitIt) const
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::SPEED_FRUIT)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  mvwaddch(_win, (*fruitIt)->posy() + 1, (*fruitIt)->posx() + 1, 's');
  if (_hasColors)
    if (attroff(COLOR_PAIR(AItem::SPEED_FRUIT)) == ERR)
      std::cerr << "ncurses: attroff() error" << std::endl;
}

void	NcursesDisplay::putSlowFruit(const std::list<Fruit*>::const_iterator fruitIt) const
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::SLOW_FRUIT)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  mvwaddch(_win, (*fruitIt)->posy() + 1, (*fruitIt)->posx() + 1, 'l');
  if (_hasColors)
    if (attroff(COLOR_PAIR(AItem::SLOW_FRUIT)) == ERR)
      std::cerr << "ncurses: attroff() error" << std::endl;
}

void	NcursesDisplay::putReverseFruit(const std::list<Fruit*>::const_iterator fruitIt) const
{
  if (_hasColors)
    if (wattron(_win, COLOR_PAIR(AItem::REVERSE_FRUIT)) == ERR)
      std::cerr << "ncurses: attron() error" << std::endl;
  mvwaddch(_win, (*fruitIt)->posy() + 1, (*fruitIt)->posx() + 1, 'r');
  if (_hasColors)
    if (attroff(COLOR_PAIR(AItem::REVERSE_FRUIT)) == ERR)
      std::cerr << "ncurses: attroff() error" << std::endl;
}
