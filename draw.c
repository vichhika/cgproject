#include "draw.h"
#include <stdio.h>
extern float centerPoint[2],scalePoint;

void drawStrings(float xStart,float yStart,char *string){
    xStart = centerPoint[0] + xStart*scalePoint;
    yStart = centerPoint[1] + yStart*scalePoint;
    glRasterPos2f(xStart,yStart);
    glutBitmapString(GLUT_BITMAP_8_BY_13,string);
}

void drawCircle(float xCenter,float yCenter,int r){
    int x,y;
    xCenter = centerPoint[0] + xCenter*scalePoint;
    yCenter = centerPoint[1] + yCenter*scalePoint;
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 360;i++){
        x = xCenter + r*cos(i);
        y = yCenter + r*sin(i);
        glVertex2i(x,y);
    }
    glEnd();
}

void drawSinWave(float amplitude,float frequency,float theta){
    int interval = centerPoint[0]*4;
    int yScale = centerPoint[0]/10;
    float unit,rand;
    glBegin(GL_LINE_STRIP);
    for (int i=0;i<interval;i++){
        unit = i/2;
        rand = (6.28 * frequency * unit) + theta;
        glVertex2i(
                    unit,
                    centerPoint[1]+((amplitude * sin(rand))*(centerPoint[0]/yScale))
                );
    }
    glEnd();

}

void drawStar(float CenterPoint,float r){

    CenterPoint += centerPoint[0];

    float starCos(int phase){
        return (CenterPoint + (float)(r*cos((0.94 + (phase*3.14)/5))));
    }

    float starSin(int phase){
        return (CenterPoint + (float)(r*sin((0.94 + (phase*3.14)/5))));
    }

    glBegin(GL_LINE_STRIP);
    glVertex2f(starCos(1),starSin(1));
    glVertex2f(starCos(7),starSin(7));
    glVertex2f(starCos(3),starSin(3));
    glVertex2f(starCos(9),starSin(9));
    glVertex2f(starCos(5),starSin(5));
    glVertex2f(starCos(1),starSin(1));
    glEnd();


}

void drawGraphPoint(ARRAY_2D *arr,int toggle){
    int a = 1, b = (centerPoint[0]/scalePoint)-1;
    int size = arr->rows;
    char labelY[12];
    float arrX[size];
    float arrY[size];
    for(int i=0;i<size;i++) {
        arrY[i] = arr->index[i][0];
        arrX[i] = i;
    }
    float minX = findMin(arrX,size),
          maxX = findMax(arrX,size),
          minY = findMin(arrY,size),
          maxY = findMax(arrY,size);
    for(int i = 0;i<size;i++){
        arrX[i] = featureScaling(a,b,arrX[i],minX,maxX,minX);
        arrY[i] = featureScaling(a,b,arrY[i],minY,maxY,minY);
        drawCircle(arrX[i],arrY[i],3);
    }
    for(int i = 0;i<size;i++){
        sprintf(labelY,"%g",arr->index[i][0]);
        if(toggle == 0) glColor3f(1,1,1);
        drawStrings(arrX[i]-0.35,-0.5,arr->label[i]);
        drawStrings(-1.5,arrY[i]-0.35,labelY);

    }
}
void drawGraphBar(ARRAY_2D *arr,int toggle){
    int a = 1, b = (centerPoint[0]/scalePoint)-1;
    int size = arr->rows;
    char labelY[12];
    float arrX[size];
    float arrY[size];
    for(int i=0;i<size;i++) {
        arrY[i] = arr->index[i][0];
        arrX[i] = i;
    }
    float minX = findMin(arrX,size),
          maxX = findMax(arrX,size),
          minY = findMin(arrY,size),
          maxY = findMax(arrY,size);
    for(int i = 0;i<size;i++){
        arrX[i] = featureScaling(a,b,arrX[i],minX,maxX,minX);
        arrY[i] = featureScaling(a,b,arrY[i],minY,maxY,minY);
        drawBar(arrX[i],arrY[i],3);
    }
    for(int i = 0;i<size;i++){
        sprintf(labelY,"%g",arr->index[i][0]);
        if(toggle == 0) glColor3f(1,1,1);
        drawStrings(arrX[i]-0.2,-0.5,arr->label[i]);
        drawStrings(-1.5,arrY[i]-0.35,labelY);

    }
}
void drawBar(float xCenter,float yCenter,int size){
    int x,y;
    xCenter = centerPoint[0] + xCenter*scalePoint;
    yCenter = centerPoint[1] + yCenter*scalePoint;
    glBegin(GL_POLYGON);
    glVertex2i(xCenter-size,centerPoint[0]);
    glVertex2i(xCenter-size,yCenter);
    glVertex2i(xCenter+size,yCenter);
    glVertex2i(xCenter+size,centerPoint[0]);
    glEnd();
}

void drawWindMill(ARRAY_2D *arr){
    
    glBegin(GL_POLYGON);
    glVertex2i(arr->index[0][0],arr->index[0][1]);
    glVertex2i(arr->index[1][0],arr->index[1][1]);
    glVertex2i(arr->index[2][0],arr->index[2][1]);
    glVertex2i(arr->index[3][0],arr->index[3][1]);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2i(arr->index[4][0],arr->index[4][1]);
    glVertex2i(arr->index[5][0],arr->index[5][1]);
    glVertex2i(arr->index[6][0],arr->index[6][1]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(arr->index[4][0],arr->index[4][1]);
    glVertex2i(arr->index[7][0],arr->index[7][1]);
    glVertex2i(arr->index[8][0],arr->index[8][1]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(arr->index[4][0],arr->index[4][1]);
    glVertex2i(arr->index[9][0],arr->index[9][1]);
    glVertex2i(arr->index[10][0],arr->index[10][1]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(arr->index[4][0],arr->index[4][1]);
    glVertex2i(arr->index[11][0],arr->index[11][1]);
    glVertex2i(arr->index[12][0],arr->index[12][1]);
    glEnd();
}