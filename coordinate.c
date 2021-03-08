#include "coordinate.h"
#include "draw.h"

float centerPoint[2],scalePoint,axisLine[4];

void coordX(float xStart,float yStart,float xEnd,float yEnd,float scale){
    glBegin(GL_LINES);
    glVertex2f(xStart,yStart);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd-10,yEnd-5);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd-10,yEnd+5);
    glEnd();
    drawStrings(9.5,0.5,"X");
}

void coordY(float xStart,float yStart,float xEnd,float yEnd,float scale){
    glBegin(GL_LINES);
    glVertex2f(xStart,yStart);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd-5,yEnd-10);
    glVertex2f(xEnd,yEnd);
    glVertex2f(xEnd+5,yEnd-10);
    glEnd();
    drawStrings(0.5,9.5,"Y");
}

void unitScale(){
    float xStart = 0;
    float xEnd = axisLine[1];
    float yStart = axisLine[3]/2;
    float yEnd = axisLine[3]/2;
    glBegin(GL_LINES);
    for(float x = scalePoint;x < xEnd;x+=scalePoint){
        glVertex2f(x,yStart-5);
        glVertex2f(x,yEnd+5);
    }
    xStart = axisLine[1]/2;
    xEnd = axisLine[1]/2;
    yStart = 0;
    yEnd = axisLine[3];
    for(float y = scalePoint;y < yEnd;y+=scalePoint){
        glVertex2f(xStart-5,y);
        glVertex2f(xEnd+5,y);
    }
    glEnd();
}

void coord2D(int winX,int winY,float scale){
    float x = winX/2, y = winY/2;
    centerPoint[0] = x;
    centerPoint[1] = y;
    axisLine[0] = 0;
    axisLine[1] = winX;
    axisLine[2] = 0;
    axisLine[3] = winY;
    scalePoint = scale;
    coordX(0,y,winX,y,scale);
    coordY(y,0,x,winY,scale);
    unitScale();
}
