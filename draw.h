#ifndef DRAW_H
#define DRAW_H

#include <GL/freeglut.h>
#include "struct.h"
#include "calculate.h"
#include <math.h>

void drawStrings(float xStart,float yStart,char *string);
void drawCircle(float xCenter,float yCenter,int r);
void drawSinWave(float amplitude,float frequency,float theta);
void drawStar(float CenterPoint,float r);
void drawGraphPoint(ARRAY_2D *arr,int toggle);
void drawGraphBar(ARRAY_2D *arr,int toggle);
void drawBar(float xCenter,float yCenter,int size);
void drawWindMill(ARRAY_2D *arr);
#endif