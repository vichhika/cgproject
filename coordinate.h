#ifndef COORDINATE_H
#define COORDINATE_H

#include <GL/freeglut.h>

extern float centerPoint[2],scalePoint;

void coord2D(int winX,int winY,float scale);
void coordX(float xStart,float yStart,float xEnd,float yEnd,float scale);
void coordY(float xStart,float yStart,float xEnd,float yEnd,float scale);
void unitScale();

#endif