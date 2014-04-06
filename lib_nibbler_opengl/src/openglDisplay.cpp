//
// openglDisplay.cpp for nibbler in /home/max/e-wip/cpp_nibbler
//
// Made by bourge_i
// Login   <max@epitech.net>
//
// Started on  Sat Apr  5 21:20:07 2014 bourge_i
// Last update Sun Apr  6 22:59:40 2014 Maxime Bourgeois
//

#include "../include/openglDisplay.hh"

static IDisplay::eKey	g_key;

extern "C"
{
  IDisplay*	createDisplay()
  {
    return (new OpenglDisplay);
  }
}

static void	manageKeyboard(unsigned char key, int x, int y)
{
  (void)x; (void)y;
  std::cout << "vous avez appuye sur " << key << std::endl;
  if (key == 27)
    g_key = IDisplay::NIB_KEY_ESC;
  if (key == '\n')
    g_key = IDisplay::NIB_KEY_ENTER;
  return ;
}

static void	square(double x, double y, double offsetX, double offsetY, int r, int v, int b)
{
  glBegin(GL_QUADS);
  glColor3ub(r, v, b);
  glVertex2d(-x + offsetX, -y + offsetY);
  glVertex2d(-x + offsetX, y + offsetY);
  glVertex2d(x + offsetX, y + offsetY);
  glVertex2d(x + offsetX, -y + offsetY);
  glEnd();
  return ;
}

static void	manageDirection(int key, int x, int y)
{
  (void)x; (void)y;
  std::cout << "vous avez appuye sur " << key << std::endl;
  if (key == GLUT_KEY_RIGHT)
    g_key = IDisplay::NIB_KEY_LEFT;
  if (key == GLUT_KEY_LEFT)
    g_key = IDisplay::NIB_KEY_RIGHT;
  if (key == GLUT_KEY_UP)
    g_key = IDisplay::NIB_KEY_UP;
  if (key == GLUT_KEY_DOWN)
    g_key = IDisplay::NIB_KEY_DOWN;
}

OpenglDisplay::OpenglDisplay()
{
  this->key = IDisplay::NIB_KEY_NONE;
}

void			OpenglDisplay::init(const GameBoard & game)
{
  int argc = 1;
  char *argv[1] = {(char*)"Something"};

  float r1;
  float r2;

  if (game.width() >= game.height())
    {
      r1 = (float)game.width() / game.height();
      r2 = 1;
    }
  else
    {
      r2 = (float)game.height() / game.width();
      r1 = 1;
    }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

  glutInitWindowSize((game.width() * BLOCKPX), (game.height() * BLOCKPX));

  glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - (game.width() * BLOCKPX) / 2,
  			 glutGet(GLUT_SCREEN_HEIGHT) / 2 - (game.height() * BLOCKPX) / 2);
  glutCreateWindow("NIBBLER OPENGL");

  glMatrixMode(GL_PROJECTION);
  glOrtho(0, game.height() / r2, 0, game.width() / r1, -1, 1); // -> origin
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutKeyboardFunc(&manageKeyboard);
  glutSpecialFunc(&manageDirection);
  glutMainLoopEvent();
}

int			OpenglDisplay::getFps() const
{
  return (50);
}

void			OpenglDisplay::update(const GameBoard & game)
{
  glClearColor(0, 0.1, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->displaySnake(game);
  this->displayFruits(game);

  glutSwapBuffers();
  return ;
}

void			OpenglDisplay::displaySnake(const GameBoard & game)
{
  std::list<SnakeRing*>::const_iterator it;
  float r1;
  float r2;

  if (game.width() >= game.height())
    {
      r1 = (float)game.width() / game.height();
      r2 = 1;
    }
  else
    {
      r2 = (float)game.height() / game.width();
      r1 = 1;
    }

  it = game.snake().begin();
  while (it != game.snake().end())
    {
      square(0.5 / r1, 0.5 / r2,
	     ((*it)->posx() / r1) + 0.5 / r1,
	     ((*it)->posy() / r2) + 0.5 / r2,
	     rand() % 255, rand() % 255, rand() % 255);
      it++;
    }
}

void			OpenglDisplay::displayFruits(const GameBoard & game)
{
  std::list<Fruit*>::const_iterator it;
  float r1;
  float r2;

  if (game.width() >= game.height())
    {
      r1 = (float)game.width() / game.height();
      r2 = 1;
    }
  else
    {
      r2 = (float)game.height() / game.width();
      r1 = 1;
    }
  it = game.fruits().begin();
  srand(time(NULL));
  while (it != game.fruits().end())
    {
      square(0.5 / r1, 0.5 / r2,
	     ((*it)->posx() / r1) + 0.5 / r1,
	     ((*it)->posy() / r2) + 0.5 / r2,
	     rand() % 255, rand() % 255, rand() % 255);
      it++;
    }
}

int			OpenglDisplay::getMaxWidth() const
{
  return (30);
}

int			OpenglDisplay::getMaxHeight() const
{
  return (20);
}

IDisplay::eKey		OpenglDisplay::getKey()
{
  glutMainLoopEvent();
  this->key = g_key;
  g_key = IDisplay::NIB_KEY_NONE;
  return (this->key);
}

void			OpenglDisplay::close() const
{
  glutLeaveMainLoop();
  return ;
}
