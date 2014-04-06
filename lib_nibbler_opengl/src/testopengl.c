#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut_std.h>
#include <GL/glu.h>

#define WIDTH  700
#define HEIGHT 700

#define BLOCKSIZE 0.05

void Display();
void snake(double x, double y, double offsetX, double offsetY, int r, int v, int b);
void GestionClavier(unsigned char key, int x, int y);
void GestionDirection(int key, int x, int y);
void timerCallback (int value);
void Reshape(int,int);
void vBitmapOutput(int x, int y, char *string, void *font);
void vStrokeOutput(GLfloat x, GLfloat y, char *string, void *font);

double	myoffX = 0;
double	myoffY = 0;
int	direction;
int	tick;

int main( int argc, char *argv[ ])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

  glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
  glutInitWindowPosition(200, 200);
  glutCreateWindow("NIBBLER");

  glutKeyboardFunc(GestionClavier);
  glutDisplayFunc(Display);
  glutSpecialFunc(GestionDirection);
  //glutReshapeFunc(Reshape);
  glutTimerFunc(3, timerCallback, 0);

  glutMainLoop(); // lance le gestionnaire glut
  return 0;
}

void timerCallback (int value)
{
  /* maybe glutPostRedisplay(), if necessary */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clean the screen and the depth buffer
  glLoadIdentity();// Reset The Projection Matrix
  printf("TICK!\n");
  if (direction == 6)
    myoffX += BLOCKSIZE;
  if (direction == 4)
    myoffX -= BLOCKSIZE;
  if (direction == 8)
    myoffY += BLOCKSIZE;
  if (direction == 2)
    myoffY -= BLOCKSIZE;

  snake(BLOCKSIZE * ((double) glutGet(GLUT_WINDOW_HEIGHT) / (double) glutGet(GLUT_WINDOW_WIDTH)), BLOCKSIZE, myoffX, myoffY, 100, 0, 100);
  glutSwapBuffers();
  /* call back again after elapsedUSecs have passed */
  //glutTimerFunc (elapsedUSecs, timerCallback, value);
  glutTimerFunc(200, timerCallback, 0);
}

void GestionDirection(int key, int x, int y)
{
  if (key == GLUT_KEY_RIGHT)
    {
      direction = 6;
      printf("key RIGH pressed ! %f\n", myoffX);
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_LEFT)
    {
      direction = 4;
      printf("key RIGH pressed ! %f\n", myoffX);
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_UP)
    {
      direction = 8;
      printf("key RIGH pressed ! %f\n", myoffX);
      glutSwapBuffers();
    }
  if (key == GLUT_KEY_DOWN)
    {
      direction = 2;
      printf("key RIGH pressed ! %f\n", myoffX);
      glutSwapBuffers();
    }
}


void vBitmapOutput(int x, int y, char *string, void *font)
{
  int len,i; // len donne la longueur de la chaîne de caractères

  glRasterPos2f(x,y); // Positionne le premier caractère de la chaîne
  len = (int) strlen(string); // Calcule la longueur de la chaîne
  for (i = 0; i < len; i++) glutBitmapCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
}

void vStrokeOutput(GLfloat x, GLfloat y, char *string, void *font)
{
  char *p;

  glPushMatrix();// glPushMatrix et glPopMatrix sont utilisées pour sauvegarder
  // et restaurer les systèmes de coordonnées non translatés
  glTranslatef(x, y, 0); // Positionne le premier caractère de la chaîne
  for (p = string; *p; p++) glutStrokeCharacter(font, *p); // Affiche chaque caractère de la chaîne
  glPopMatrix();
}


void GestionClavier(unsigned char key, int x, int y)
{
  printf("vous avez appuye sur %c ", key);
  printf("position de la souris : ");
  printf("%d,%d \n", x, y);
  if (key == 27)
    exit(0);
  if (key == 'a')
    {
      vBitmapOutput(1,1,"TEXTE ECRIT EN VERT",GLUT_BITMAP_TIMES_ROMAN_24);
      glutSwapBuffers();
      //glFlush();
    }
}

void Display()
{
  glClearColor(0,0,0,0); // selectionne la couleur noire (qui est celle par défaut)
  glClear(GL_COLOR_BUFFER_BIT); // efface le frame buffer

  printf("%f\n", (double) glutGet(GLUT_WINDOW_HEIGHT) / (double) glutGet(GLUT_WINDOW_WIDTH));
  glFlush(); // affichage de la scènex
}

void    snake(double x, double y, double offsetX, double offsetY, int r, int v, int b)
{
  glBegin(GL_QUADS);
  glColor3ub(r, v, b);
  glVertex2d(-x + offsetX, -y + offsetY);
  glVertex2d(-x + offsetX, y + offsetY);
  glVertex2d(x + offsetX, y + offsetY);
  glVertex2d(x + offsetX, -y + offsetY);
  glEnd();
}

void Reshape(int w,int h)
{
  //todo
}
