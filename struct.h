#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char **label;
    float **index;
    int rows;
    int cols;
}ARRAY_2D;

void setSizeArray2D(ARRAY_2D *arr,int rows,int cols);
void inputArray2D(ARRAY_2D *arr);
void printArray2D(ARRAY_2D *arr);
void loadDataLabel(ARRAY_2D *arr,char *Load_FILE);
#endif