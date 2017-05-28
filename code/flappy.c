#include "flappy.h"

#define MAX_SPEED 2

int oldX;
int oldY;
int gravity = 1;


void drawFlappy(Flappy* flappy){
    drawCircle(flappy->x,oldY,7,BLACK);
    drawCircle(flappy->x,flappy->y,5,YELLOW);
}



void adjustVelY(Flappy* flappy){
    if(flappy->velY < MAX_SPEED){
        flappy->velY += gravity;
    }
}

void updateFlappy(Flappy* flappy){
    adjustVelY(flappy);
    if(flappy->y + flappy->velY < SCREEN_HEIGHT){
        oldY = flappy->y;
        flappy->y += flappy->velY;
    }
    if(flappy->y + flappy->velY < 0){
        flappy->y = 0+flappy->size;
    }
}

void createFlappy(Flappy* flappy, int posx, int posy, int size){
    flappy->x = posx;
    flappy->y = posy;
    flappy->velY = 1;
    flappy->size = size;
}

void flappyAction(Flappy* flappy){
    flappy->velY = -4;
}