#include "coordinate.h"
#include "draw.h"

float centerPoint[2],scalePoint;

void coordX(float xStart,float yStart,float xEnd,float yEnd,float scale){
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(xStart,yStart);
    glVertex2f(xEnd,yEnd);
    if(scale <= 0) scale = xEnd;
    for(float x = scale;x < xEnd;x+=scale){
        glVertex2f(x,yStart-5);
        glVertex2f(x,yEnd+5);
    }
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd-10,yEnd-5);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd-10,yEnd+5);
    glEnd();
    drawStrings(xEnd-10,yEnd+10,"X");
}

void coordY(float xStart,float yStart,float xEnd,float yEnd,float scale){
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(xStart,yStart);
    glVertex2f(xEnd,yEnd);
    if(scale <= 0) scale = 1;
    for(float y = scale;y < yEnd;y+=scale){
        glVertex2f(xStart-5,y);
        glVertex2f(xEnd+5,y);
    }
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd-5,yEnd-10);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd+5,yEnd-10);
    glEnd();
    drawStrings(xEnd+10,yEnd-11,"Y");
}

void coord2D(int winX,int winY,float scale){
    float x = winX/2, y = winY/2;
    centerPoint[0] = x;
    centerPoint[1] = y;
    scalePoint = scale;
    coordX(0,y,winX,y,scale);
    coordY(y,0,x,winY,scale);
}