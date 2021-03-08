#include "draw.h"
#include <stdio.h>
extern float centerPoint[2],scalePoint;

void drawStrings(float xStart,float yStart,char *string){
    xStart = centerPoint[0] + xStart*scalePoint;
    yStart = centerPoint[1] + yStart*scalePoint;
    glRasterPos2f(xStart,yStart);
    glutBitmapString(GLUT_BITMAP_9_BY_15,string);
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

