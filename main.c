#include "coordinate.h"
#include "draw.h"
#include "struct.h"
#include "calculate.h"

ARRAY_2D vector,matrix,result;

int WinSizeX = 500,WinSizeY = 500, scale = 100;

void initDisplay(void){
  glClearColor(1,1,1,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,500,0,500);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    //draw pic
    
    //coordinate
    coord2D(WinSizeX,WinSizeY,scale); //auto center coord
    //coordinate
    
    glColor3f(0.3,0.7,0.5);
    drawSinWave(1,10,0.1);
    // drawCircle(5,5,50);
    // drawCircle(-5,5,50);
    // drawCircle(-5,-5,50);
    // drawCircle(5,-5,50);
    // //draw pic

    // //text
    // glColor3f(0,0,0);
    // drawStrings(3,5,"Quadrant I");
    // drawStrings(-7,5,"Quadrant II");
    // drawStrings(-7,-5,"Quadrant III");
    // drawStrings(3,-5,"Quadrant IV");
    //text

    glFlush();
}

int main(int argc, char **argv)
{
    // setSizeArray2D(&vector,1,3);
    // for (int i=0;i<vector.rows;i++){
    //     for(int j=0;j<vector.cols;j++){
    //         vector.index[i][j] = 1;
    //     }
    // }
    // setSizeArray2D(&matrix,1,3);
    // for (int i=0;i<matrix.rows;i++){
    //     for(int j=0;j<matrix.cols;j++){
    //         matrix.index[i][j] = j+1;
    //     }
    // }
    // //negateVector(&vector);
    // //multiplySclarWithVector(&vector,&matrix,&result);
    // //preMultiply(&vector,&matrix,&result);
    // //postMultiply(&vector,&matrix,&result);
    // //addVector(&vector,&matrix,&result);
    // //normalize(&vector,&result);
    // //transpose(&vector);
    // crossProduct(&vector,&matrix,&result);
    // for (int i=0;i<result.rows;i++){
    //     for(int j=0;j<result.cols;j++){
    //         printf("%.2f ",result.index[i][j]);
    //     }
    //     printf("\n");
    // }

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("CG Project");
    initDisplay();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
