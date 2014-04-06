//
// openglDisplay.cpp for nibbler in /home/max/e-wip/cpp_nibbler
//
// Made by bourge_i
// Login   <max@epitech.net>
//
// Started on  Sat Apr  5 21:20:07 2014 bourge_i
// Last update Sun Apr  6 15:49:36 2014 bourge_i
//

#include "../include/openglDisplay.hh"

static int	g_key;
static int	g_direction;
static double	g_myoffX = 0;
static double	g_myoffY = 0;

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
  g_key = key;
  if (key == 27)
    glutLeaveMainLoop();
  return ;
}

static void	display()
{
  glClearColor(0,0,0,0); // selectionne la couleur noire (qui est celle par défaut)
  glClear(GL_COLOR_BUFFER_BIT); // efface le frame buffer
  glFlush(); // affichage de la scènex
  return ;
}

// member function ???
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
    {
      g_key = IDisplay::NIB_KEY_RIGHT;
      g_direction = 6;
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_LEFT)
    {
      g_key = IDisplay::NIB_KEY_LEFT;
      g_direction = 4;
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_UP)
    {
      g_key = IDisplay::NIB_KEY_UP;
      g_direction = 8;
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_DOWN)
    {
      g_key = IDisplay::NIB_KEY_DOWN;
      g_direction = 2;
      glutSwapBuffers();
    }
  g_key = key;
}

static void	timerCallback(int value)
{
  (void)value;
  /* maybe glutPostRedisplay(), if necessary */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clean the screen and the depth buffer
  glLoadIdentity();// Reset The Projection Matrix

  if (g_direction == 6)
    g_myoffX += BLOCKSIZE;
  if (g_direction == 4)
    g_myoffX -= BLOCKSIZE;
  if (g_direction == 8)
    g_myoffY += BLOCKSIZE;
  if (g_direction == 2)
    g_myoffY -= BLOCKSIZE;

  std::cout << "g_myoffY -> " << g_direction << std::endl;
  std::cout << "g_myoffY -> " << g_myoffX << std::endl;
  std::cout << "g_myoffY -> " << g_myoffY << std::endl;

  square(BLOCKSIZE * ((double) glutGet(GLUT_WINDOW_HEIGHT) /
  		      (double) glutGet(GLUT_WINDOW_WIDTH)),
  	 BLOCKSIZE, g_myoffX, g_myoffY, 100, 0, 100);

  glutSwapBuffers();
  glFlush();
  glutTimerFunc(200, timerCallback, 0);
  return ;
}

OpenglDisplay::OpenglDisplay()
{
  this->myoffY = 0;
  this->myoffX = 0;
  this->direction = 0;
}

void			OpenglDisplay::init(const GameBoard & game)
{
  (void)game; //todo
  int argc = 1;
  char *argv[1] = {(char*)"Something"};
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

  glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
  std::cout << "game.height() " << game.width() << std::endl;
  std::cout << "game.height() " << game.height() << std::endl;
  //glutInitWindowSize(game.width() * 100, game.height() * 100);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("NIBBLER OPENGL");

  glutKeyboardFunc(&manageKeyboard);
  glutDisplayFunc(&display);
  glutSpecialFunc(&manageDirection);
  glutTimerFunc(1, &timerCallback, 0);
  //timerCallback(0);
  glutMainLoop();
  //glutMainLoopEvent();
}

int			OpenglDisplay::getFps() const
{
  // ????
  return (50);
}


// TODO gerer syncro donnees affichage
void			OpenglDisplay::update(const GameBoard & game)
{
  (void)game;
  std::cout << "UPDATE CALLED !!!" << std::endl;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clean the screen and the depth buffer
  glLoadIdentity();// Reset The Projection Matrix

  if (this->direction == 6)
    this->myoffX += BLOCKSIZE;
  if (this->direction == 4)
    this->myoffX -= BLOCKSIZE;
  if (this->direction == 8)
    this->myoffY += BLOCKSIZE;
  if (this->direction == 2)
    this->myoffY -= BLOCKSIZE;

  square(BLOCKSIZE * ((double) glutGet(GLUT_WINDOW_HEIGHT) /
  		      (double) glutGet(GLUT_WINDOW_WIDTH)),
  	 BLOCKSIZE, this->myoffX, this->myoffY, 100, 0, 100);

  glutSwapBuffers();
  glFlush();
  return ;
}

IDisplay::eKey		OpenglDisplay::getKey()
{
  return (IDisplay::NIB_KEY_ESC);
}

void			OpenglDisplay::close() const
{
  glutLeaveMainLoop();
  return ;
}
