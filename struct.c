#include "struct.h"

void setSizeArray2D(ARRAY_2D *arr,int rows,int cols){
    if(!(arr->rows+arr->cols)){
        arr->rows = rows;
        arr->cols = cols;
        arr->index = (float **)malloc(rows * sizeof(float *));
        arr->label = (char **)malloc(rows * sizeof(char *));
        for(int i=0;i<rows;i++) arr->index[i] = (float *)malloc(cols * sizeof(float));
        for(int i=0;i<rows;i++) arr->label[i] = (char *)malloc(cols * sizeof(char*));
    }else{
        arr->rows = rows;
        arr->cols = cols;
        arr->index = (float **)realloc(arr->index,rows * sizeof(float *));
        //arr->label = (char **)realloc(arr->label,rows * sizeof(char *));
        for(int i=0;i<rows;i++) arr->index[i] = (float *)realloc(arr->index[i],cols * sizeof(float));
        //or(int i=0;i<rows;i++) arr->label[i] = (char *)realloc(arr->label[i],cols * sizeof(char*));
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

void loadDataLabel(ARRAY_2D *arr,char *load_FILE){
    FILE *fp;
    char ch;
    char *text = NULL;
    char *rest = NULL;
    char *token;
    size_t len = 0;
    ssize_t textLength;
    int rows = 0;
    int cols = 0;

    fp = fopen(load_FILE,"r");
    if (fp == NULL){
        perror("fopen file not found !");
        exit(EXIT_FAILURE);
    }
    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch == '\n') rows++;
    }
    setSizeArray2D(arr,rows,1);
    rewind(fp);
    int i = 0;
    while((textLength = getline(&text,&len,fp)) != -1){
        int  j = 0;
        for(token =strtok_r(text,",",&rest);token != NULL;token = strtok_r(NULL,",",&rest)){
            if(j == 0){
                //printf("s:%s ",token);
                strncpy(arr->label[i],token,3);
                j++;
            }else {
                //printf("n:%0.2f\n",atof(token));
                arr->index[i][0] = atof(token);
            }
        }
        i++;
    }
    //printf("%d:%d ",arr->rows,arr->cols);

}