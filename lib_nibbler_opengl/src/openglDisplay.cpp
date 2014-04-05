//
// openglDisplay.cpp for nibbler in /home/max/e-wip/cpp_nibbler
//
// Made by bourge_i
// Login   <max@epitech.net>
//
// Started on  Sat Apr  5 21:20:07 2014 bourge_i
// Last update Sat Apr  5 22:55:28 2014 bourge_i
//

#include "../include/openglDisplay.hh"

OpenglDisplay *my;  // todo free

extern "C"
{
  IDisplay*	createDisplay()
  {
    return (new OpenglDisplay());
  }
}

void	manageKeyboard(unsigned char key, int x, int y)
{
  (void)x; (void)y;
  // printf("vous avez appuye sur %c ", key);
  // printf("position de la souris : ");
  // printf("%d,%d \n", x, y);
  if (key == 27)
    {
      my->key = IDisplay::KEY_ESC;
    }
  return ;
}

void	display()
{
  glClearColor(0,0,0,0); // selectionne la couleur noire (qui est celle par défaut)
  glClear(GL_COLOR_BUFFER_BIT); // efface le frame buffer
  glFlush(); // affichage de la scènex
  return ;
}

// member function ???
void	square(double x, double y, double offsetX, double offsetY, int r, int v, int b)
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

void	manageDirection(int key, int x, int y)
{
  (void)x; (void)y;
  if (key == GLUT_KEY_RIGHT)
    {
      my->key = IDisplay::KEY_RIGHT;
      my->direction = 6;
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_LEFT)
    {
      my->key = IDisplay::KEY_LEFT;
      my->direction = 4;
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_UP)
    {
      my->key = IDisplay::KEY_UP;
      my->direction = 8;
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_DOWN)
    {
      my->key = IDisplay::KEY_DOWN;
      my->direction = 2;
      glutSwapBuffers();
    }
}

void	timerCallback(int value)
{
  (void)value;
  /* maybe glutPostRedisplay(), if necessary */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clean the screen and the depth buffer
  glLoadIdentity();// Reset The Projection Matrix

  if (my->direction == 6)
    my->myoffX += BLOCKSIZE;
  if (my->direction == 4)
    my->myoffX -= BLOCKSIZE;
  if (my->direction == 8)
    my->myoffY += BLOCKSIZE;
  if (my->direction == 2)
    my->myoffY -= BLOCKSIZE;

  square(BLOCKSIZE * ((double) glutGet(GLUT_WINDOW_HEIGHT) /
		      (double) glutGet(GLUT_WINDOW_WIDTH)),
	 BLOCKSIZE, my->myoffX, my->myoffY, 100, 0, 100);

  glutSwapBuffers();
  glutTimerFunc(200, timerCallback, 0);
  return ;
}

OpenglDisplay::OpenglDisplay()
{
  this->myoffY = 0;
  this->myoffX = 0;
  this->direction = 0;
  my = this;
}

void			OpenglDisplay::init(const GameBoard & game)
{
  (void)game; //todo
  glutInit(NULL, NULL);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

  glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
  glutInitWindowPosition(0, 0);
  glutCreateWindow("NIBBLER OPENGL");

  glutKeyboardFunc(&manageKeyboard);
  glutDisplayFunc(&display);
  glutSpecialFunc(&manageDirection);
  glutTimerFunc(1, &timerCallback, 0);

  glutMainLoop();
}

int			OpenglDisplay::getFps() const
{
  // ????
  return (1);
}


// TODO gerer syncro donnees affichage
void			OpenglDisplay::update(const GameBoard & game)
{
  (void)game;
  timerCallback(0);
  return ;
}

IDisplay::eKey		OpenglDisplay::getKey()
{
  return (this->key);
}

void			OpenglDisplay::close() const
{
  return ;
}
