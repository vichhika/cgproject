#include "coordinate.h"
#include "draw.h"
#include "struct.h"
#include "calculate.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void create1vector();
void create2vector();

ARRAY_2D vector, matrix, result;
ARRAY_2D *arr;

int winSizeX = 700, winSizeY = 700, scale = 35, axisColor = 0,color = 0,draw = 0,graph = 0,toggle= 0,tmpGraph = 0;
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
    else if(choose>=11 && choose<=14) color = choose;
    else if(choose>=21 && choose<=23) draw = choose;
    else if(choose>=31 && choose<=32) graph = choose;
    else if(choose>=41 && choose<=42) toggle = choose;
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
  glutAddMenuEntry("Black", 14);

  draw = glutCreateMenu(cgMenu);
  glutAddMenuEntry("Circle", 21);
  glutAddMenuEntry("SinWave", 22);
  glutAddMenuEntry("Star", 23);

  graphs = glutCreateMenu(cgMenu);
  glutAddMenuEntry("Point", 31);
  glutAddMenuEntry("Bar Chart", 32);
  
  toggle = glutCreateMenu(cgMenu);
  glutAddMenuEntry("ON", 42);
  glutAddMenuEntry("OFF", 41);
  
  glutCreateMenu(cgMenu);
  glutAddSubMenu("Axis Color", axisColor);
  glutAddSubMenu("Color",colors);
  glutAddSubMenu("Draw",draw);
  glutAddSubMenu("Graph",graphs);
  glutAddSubMenu("Toggle Label",toggle);

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
  else if(color == 14) glColor3f(0,0,0);

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
  else if(graph == 31){
    tmpGraph = 1;
    drawGraphPoint(&vector,(41-toggle));
  }
  else if(graph == 32){
    tmpGraph = 2;
    drawGraphBar(&vector,(41-toggle));
  }
  else if(toggle == 41 || toggle == 42){
    if(tmpGraph == 1) drawGraphPoint(&vector,(41-toggle));
    else if(tmpGraph == 2) drawGraphBar(&vector,(41-toggle));
  }
  draw = 0;
  graph = 0;

  drawWindMill(&vector);
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

void skeyMenu(int key,int xmouse, int ymouse){
  
  switch(key){
    case GLUT_KEY_LEFT:
      createTranslationMatrix(&vector,-scale);
      printf("Move to the left 1 step\n");
      break;
    case GLUT_KEY_RIGHT:
      createTranslationMatrix(&vector,scale);
      printf("Move to the right 1 step\n");
      break;
    default:
      break;

  }
  glutPostRedisplay(); 
}
void keyMenu(unsigned char key,int xmouse, int ymouse){
  
  switch(key){
    case '+':
      createScalingMatrix(&vector,1.1);
      printf("Zoom in 10\%\n");
      break;
    case '-':
      createScalingMatrix(&vector,0.9);
      printf("Zoom out 10\%\n");
      break;
    case 'l':
      createRotationMatrix(&vector,0.0174533);
      printf("Rotate 1 degree of anticlock\n");
      break;
    case 'r':
      createRotationMatrix(&vector,-0.0174533);
      printf("Rotate 1 degree of clock\n");
      break;
    case 'q':
      exit(1);
      break;
    default:
      break;

  }
  glutPostRedisplay(); 
}

int main(int argc, char **argv)
{
  //data loading
  loadDataLabel(&vector,"./data/lab5_expense.txt");

  float xCenter = winSizeX/2;
  float yCenter = winSizeY/2;
  setSizeArray2D(&vector,13,2);
  vector.index[0][0] = xCenter-3*scale;
  vector.index[0][1] = yCenter+3*scale;
  vector.index[1][0] = xCenter+3*scale;
  vector.index[1][1] = yCenter+3*scale;
  vector.index[2][0] = xCenter+3*scale;
  vector.index[2][1] = yCenter-3*scale;
  vector.index[3][0] = xCenter-3*scale;
  vector.index[3][1] = yCenter-3*scale;
  vector.index[4][0] = xCenter;
  vector.index[4][1] = yCenter;
  vector.index[5][0] = xCenter-3*scale;
  vector.index[5][1] = yCenter+3*scale;
  vector.index[6][0] = xCenter;
  vector.index[6][1] = yCenter+3*2*scale;
  vector.index[7][0] = xCenter+3*scale;
  vector.index[7][1] = yCenter+3*scale;
  vector.index[8][0] = xCenter+3*2*scale;
  vector.index[8][1] = yCenter;
  vector.index[9][0] = xCenter+3*scale;
  vector.index[9][1] = yCenter-3*scale;
  vector.index[10][0] = xCenter;
  vector.index[10][1] = yCenter-3*2*scale;
  vector.index[11][0] = xCenter-3*scale;
  vector.index[11][1] = yCenter-3*scale;
  vector.index[12][0] = xCenter-3*2*scale;
  vector.index[12][1] = yCenter;

  glutInit(&argc, argv);
  glutInitWindowSize(winSizeX, winSizeY);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("CG Project");
  initDisplay();
  cgCreateMenu();
  glutSpecialFunc(skeyMenu);
  glutKeyboardFunc(keyMenu);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
