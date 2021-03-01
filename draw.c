#include "draw.h"
#include <stdio.h>

extern float centerPoint[2],scalePoint;

void drawStrings(float xStart,float yStart,char *string){
    xStart = centerPoint[0] + xStart*scalePoint;
    yStart = centerPoint[1] + yStart*scalePoint;
    glRasterPos2f(xStart,yStart);
    glutBitmapString(GLUT_BITMAP_9_BY_15,string);
}

void drawCircle(float xCenter,float yCenter,int r){
    int x,y;
    xCenter = centerPoint[0] + xCenter*scalePoint;
    yCenter = centerPoint[1] + yCenter*scalePoint;
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 360;i++){
        x = xCenter + r*cos(i);
        y = yCenter + r*sin(i);
        glVertex2i(x,y);
    }
    glEnd();
}