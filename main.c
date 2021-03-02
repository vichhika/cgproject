#include "coordinate.h"
#include "draw.h"
#include "struct.h"
#include "calculate.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
void create1vector();
void create2vector();

ARRAY_2D vector,matrix,result;

int WinSizeX = 500,WinSizeY = 500, scale = 25;

void initDisplay(void){
  glClearColor(1,1,1,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,500,0,500);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    coord2D(WinSizeX,WinSizeY,scale);
    sleep(1);
    glFlush(); //auto center coord
    glColor3f(0.3,0.7,0.5);
    int input = 1,r;
    float x,y,z;
    char text[256];
    while(input){
      printf("-----CG MENU-----\n");
      printf("1. Calculate\n");
      printf("2. Draw\n");
      printf("-----------------\n");
      printf("input : ");
      scanf("%d",&input);
      switch (input)
      {
      case 1:
        printf("1. preMultiply\n");
        printf("2. postMultiply\n");
        printf("3. negateVector\n");
        printf("4. multiplySclarWithVector\n");
        printf("5. addVector\n");
        printf("6. substractVector\n");
        printf("7. normalize\n");
        printf("8. dotProduct\n");
        printf("9. crossProduct\n");
        printf("10. transpose\n");
        printf("11. computeMagnitude\n");
        printf("-----------------\n");
        printf("input : ");
        scanf("%d", &input);
        switch(input){
          case 1:
            create2vector();
            preMultiply(&vector,&matrix,&result);
            printf("Result :\n");
            printArray2D(&result);
            break;
          case 2:
            create2vector();
            postMultiply(&vector,&matrix,&result);
            printf("Result :\n");
            printArray2D(&result);
            break;
          case 3:
            create1vector();
            negateVector(&vector);
            printf("Result :\n");
            printArray2D(&vector);
            break;
          case 4:
            create2vector();
            multiplySclarWithVector(&vector,&matrix,&result);
            printf("Result :\n");
            printArray2D(&result);
            break;
          case 5:
            create2vector();
            addVector(&vector,&matrix,&result);
            printf("Result :\n");
            printArray2D(&result);
            break;
          case 6:
            create2vector();
            substractVector(&vector,&matrix,&result);
            printf("Result :\n");
            printArray2D(&result);
            break;
          case 7:
            create1vector();
            normalize(&vector,&result);
            printf("Result :\n");
            printArray2D(&result);
            break;
          case 8:
            create2vector();
            int dot = dotProduct(&vector,&matrix);
            printf("Result :%0.2f\n",dot);
            break;
          case 9:
            create2vector();
            crossProduct(&vector,&matrix,&result);
            printf("Result :\n");
            printArray2D(&result);
            break;
          case 10:
            create1vector();
            transpose(&vector);
            printf("Result :\n");
            printArray2D(&vector);
            break;
          case 11:
            create1vector();
            float mag = computeMagnitude(&vector);
            printf("Result :%0.2f\n",mag);
            break;
          default:
            break;
        }
        break;
      case 2:
        printf("1. draw text\n");
        printf("2. draw circle\n");
        printf("3. draw sinwave\n");
        printf("4. clear screen\n");
        printf("-----------------\n");
        printf("input : ");
        scanf("%d", &input);
        switch(input){
          case 1:
            printf("x axis:");
            scanf("%f", &x);
            printf("y axis:");
            scanf("%f", &y);
            printf("text:");
            scanf ("%s", text);
            drawStrings(x,y,text);
            break;
          case 2:
            printf("x axis:");
            scanf("%f", &x);
            printf("y axis:");
            scanf("%f", &y);
            printf("r:");
            scanf("%d",&r);
            drawCircle(x,y,r);
            break;
          case 3:
            printf("amplitude:");
            scanf("%f", &x);
            printf("frequency:");
            scanf("%f", &y);
            printf("phase:");
            scanf("%f",&z);
            drawSinWave(x,y,z);
            break;
          case 4:
            glClear(GL_COLOR_BUFFER_BIT);
            coord2D(WinSizeX,WinSizeY,scale);
            break;
          default:
            break;
        }
        break;
      default:
        break;
      }

    glFlush();
    }
}

void create1vector(){
  int x,y;
  printf("Vector\n");
  printf("x:");
  scanf("%d", &x);
  printf("y:");
  scanf("%d",&y);
  setSizeArray2D(&vector,y,x);
  inputArray2D(&vector);
}
void create2vector(){
  int x,y;
  printf("Vector\n");
  printf("x:");
  scanf("%d", &x);
  printf("y:");
  scanf("%d",&y);
  setSizeArray2D(&vector,y,x);
  inputArray2D(&vector);
  printf("Matrix\n");
  printf("x:");
  scanf("%d", &x);
  printf("y:");
  scanf("%d",&y);
  setSizeArray2D(&matrix,y,x);
  inputArray2D(&matrix);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("CG Project");
    initDisplay();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
