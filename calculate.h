#ifndef CALCULATE_H
#define CALCULATE_H

#include <math.h>
#include <stdio.h>
#include "struct.h"

void preMultiply(ARRAY_2D *vector,ARRAY_2D *matrix,ARRAY_2D *result);
void postMultiply(ARRAY_2D *vector,ARRAY_2D *matrix,ARRAY_2D *result);
void negateVector(ARRAY_2D *vector);
void multiplySclarWithVector(ARRAY_2D *vector,ARRAY_2D *matrix,ARRAY_2D *result);
void addVector(ARRAY_2D *vector,ARRAY_2D *matrix,ARRAY_2D *result);
void substractVector(ARRAY_2D *vector,ARRAY_2D *matrix,ARRAY_2D *result);
void normalize(ARRAY_2D *vector,ARRAY_2D *result);
float dotProduct(ARRAY_2D *vector1,ARRAY_2D *vector2);
void crossProduct(ARRAY_2D *vector1,ARRAY_2D *vector2,ARRAY_2D *result);
void transpose(ARRAY_2D *matrix);
float computeMagnitude(ARRAY_2D *vector);

#endif