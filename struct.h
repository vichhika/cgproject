#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>

typedef struct{
    float **index;
    int rows;
    int cols;
}ARRAY_2D;

void setSizeArray2D(ARRAY_2D *arr,int rows,int cols);

#endif