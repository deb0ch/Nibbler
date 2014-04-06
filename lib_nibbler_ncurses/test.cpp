#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int main(int argc, char *argv[])
{
  initscr();/* Start curses mode */
  if(has_colors() == FALSE)
    {
      endwin();
      printf("Your terminal does not support color\n");
      exit(1);
    }
  start_color();/* Start color */
  use_default_colors();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  write(1, "\033[36m", strlen("\033[36m"));
  attron(COLOR_PAIR(1));
  while (42)
    {
      print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
      usleep(1.0 / 50.0 * 1000000.0);
    }
  attroff(COLOR_PAIR(1));
  write(1, "\033[0m", strlen("\033[0m"));
  getch();
  endwin();
  std::cout << "\033[36mViola !!! In color ...\033[0m" << std::endl;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{
  int length, x, y;
  float temp;

  if(win == NULL)
    win = stdscr;
  getyx(win, y, x);
  if(startx != 0)
    x = startx;
  if(starty != 0)
    y = starty;
  if(width == 0)
    width = 80;
  length = strlen(string);
  temp = (width - length)/ 2;
  x = startx + (int)temp;
  mvwprintw(win, y, x, "%s", string);
  refresh();
}

#include <ncurses.h>

#include <ncurses.h>
int main()
{
  initscr();
  start_color(); /* Be sure not to forget this, it will enable colors */
  init_pair(1, COLOR_RED, COLOR_CYAN); /* You can make as much color pairs as you want, be sure to change the ID number */
  init_pair(2, COLOR_YELLOW, COLOR_GREEN);
  attron(A_UNDERLINE | COLOR_PAIR(1)); /* This turns on the underlined text and color pair 1 */
  printw("This is underlined red text with cyan background\n");
  attroff(A_UNDERLINE | COLOR_PAIR(1));
  attron(A_BOLD | COLOR_PAIR(2));
  printw("This is bold yellow text with green background");
  attroff(A_BOLD | COLOR_PAIR(2));
  refresh();
  getch();
  endwin();
  return 0;
}

int main()
{
  int ch;

  initscr();/* Start curses mode */
  raw();/* Line buffering disabled*/
  start_color(); /* Be sure not to forget this, it will enable colors */
  keypad(stdscr, TRUE);/* We get F1, F2 etc..*/
  noecho();/* Don't echo() while we do getch */

  printw("Type any character to see it in bold\n");
  ch = getch();/* If raw() hadn't been called
		* we have to press enter before it
		* gets to the program */
  if(ch == KEY_F(2))/* Without keypad enabled this will */
    printw("F2 Key pressed");/*  not get to us either*/
  /* Without noecho() some ugly escape
   * charachters might have been printed
   * on screen*/
  else
    {
      printw("The pressed key is ");
      attron(A_BOLD);
      printw("%c", ch);
      attroff(A_BOLD);
    }
  refresh();/* Print it on to the real screen */
  getch();/* Wait for user input */
  endwin();/* End curses mode  */

  return 0;
}
