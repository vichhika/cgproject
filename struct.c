#include "struct.h"

void setSizeArray2D(ARRAY_2D *arr,int rows,int cols){
    if(!(arr->rows+arr->cols)){
        arr->rows = rows;
        arr->cols = cols;
        arr->index = (float **)malloc(rows * sizeof(float *));
        for(int i=0;i<rows;i++) arr->index[i] = (float *)malloc(cols * sizeof(float));
    }else{
        arr->rows = rows;
        arr->cols = cols;
        arr->index = (float **)realloc(arr->index,rows * sizeof(float *));
        for(int i=0;i<rows;i++) arr->index[i] = (float *)realloc(arr->index[i],cols * sizeof(float));
    }
}

void inputArray2D(ARRAY_2D *arr){
    for(int i=0;i<arr->rows;i++)
        for(int j=0;j<arr->cols;j++){
            printf("index[%d][%d] = ",i,j);
            scanf("%f",&arr->index[i][j]);
        }
}

void printArray2D(ARRAY_2D *arr){
    for(int i=0;i<arr->rows;i++){
        for(int j=0;j<arr->cols;j++){
            printf("%0.2f ",arr->index[i][j]);
        }
        printf("\n");
    }
}