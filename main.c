#include "coordinate.h"
#include "draw.h"
#include "struct.h"
#include "calculate.h"
#include "menu.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void create1vector();
void create2vector();

ARRAY_2D vector, matrix, result;

int winSizeX = 700, winSizeY = 700, scale = 35, axisColor = 0,color = 0,draw = 0,graph = 0;
int x,y,z,r;

void initDisplay(void)
{
  glClearColor(1, 1, 1, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, winSizeX, 0, winSizeY);

}

void cgMenu(int choose)
{
  if (choose == 0)
  {
    exit(0);
  }
  else
    if(choose>=1 && choose<=3) axisColor = choose;
    else if(choose>=11 && choose<=13) color = choose;
    else if(choose>=21 && choose<=23) draw = choose;
    else if(choose>=31 && choose<=32) graph = choose;
    glutPostRedisplay();
}

void cgCreateMenu(void)
{
  int axisColor,colors,draw,graphs; 

  axisColor = glutCreateMenu(cgMenu);
  glutAddMenuEntry("Blue", 1);
  glutAddMenuEntry("green", 2);
  glutAddMenuEntry("yellow", 3);

  colors = glutCreateMenu(cgMenu);
  glutAddMenuEntry("Brown", 11);
  glutAddMenuEntry("Cyan", 12);
  glutAddMenuEntry("Pink", 13);

  draw = glutCreateMenu(cgMenu);
  glutAddMenuEntry("Circle", 21);
  glutAddMenuEntry("SinWave", 22);
  glutAddMenuEntry("Star", 23);

  graphs = glutCreateMenu(cgMenu);
  glutAddMenuEntry("Point", 31);
  glutAddMenuEntry("Bar Chart", 32);
  
  glutCreateMenu(cgMenu);
  glutAddSubMenu("Axis Color", axisColor);
  glutAddSubMenu("Color",colors);
  glutAddSubMenu("Draw",draw);
  glutAddSubMenu("Graph",graphs);

  glutAddMenuEntry("Exit", 0);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  if(axisColor == 1) glColor3f(0,0,1);
  else if(axisColor == 2) glColor3f(0,1,0);
  else if(axisColor == 3) glColor3f(1,1,0);
  else glColor3f(0,0,0);
  coord2D(winSizeX, winSizeY, scale);
  
  if(color == 11) glColor3f(0.65,0.16,0.16);
  else if(color == 12) glColor3f(0,1,1);
  else if(color == 13) glColor3f(1,0.75,0.80);

  if(draw == 21){
    x = 0;
    y = 0;
    r = 100;
    drawCircle(x,y,r);
  }
  else if(draw == 22){
    x = 25;
    y = 10;
    z = 0;
    drawSinWave(x,y,z);
  }
  else if(draw == 23){
    x = 0;
    r = 100;
    drawStar(x,r);
  }

  draw = 0;
  loadDataLabel(&vector,"./data/lab5_expense.txt");
  glColor3f(0,1,1);
  drawGraphPoint(&vector);
  glFlush();

}

void create1vector()
{
  int x, y;
  printf("Vector\n");
  printf("x:");
  scanf("%d", &x);
  printf("y:");
  scanf("%d", &y);
  setSizeArray2D(&vector, y, x);
  inputArray2D(&vector);
}
void create2vector()
{
  int x, y;
  printf("Vector\n");
  printf("x:");
  scanf("%d", &x);
  printf("y:");
  scanf("%d", &y);
  setSizeArray2D(&vector, y, x);
  inputArray2D(&vector);
  printf("Matrix\n");
  printf("x:");
  scanf("%d", &x);
  printf("y:");
  scanf("%d", &y);
  setSizeArray2D(&matrix, y, x);
  inputArray2D(&matrix);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(winSizeX, winSizeY);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("CG Project");
  initDisplay();
  cgCreateMenu();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
