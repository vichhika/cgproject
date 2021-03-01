#ifndef DRAW_H
#define DRAW_H

#include <GL/freeglut.h>
#include "struct.h"
#include "calculate.h"
#include <math.h>

void drawStrings(float xStart,float yStart,char *string);
void drawCircle(float xCenter,float yCenter,int r);
void drawSinWave(float amplitude,float frequency,float theta);
#endif