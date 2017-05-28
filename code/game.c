#include "game.h"
#include <stdbool.h>
// main implementation of the game



bool gameInitialised = false;

Flappy flappy;
// we always have just two pipes. consider an array though?
Pipe leftPipe;
Pipe rightPipe;


int tickCount = 0;
void tick(){
    tickCount++;
    handleGameInput();
    updateState();
    drawGame();
}



void drawGame(){
    drawFlappy(&flappy);
    drawPipe(&leftPipe);
    drawFlappy(&flappy);
    drawPipe(&rightPipe);
    drawFlappy(&flappy);
}



void updateState(){
    if(gameInitialised == false){
        initGame();
        gameInitialised = true;
        return;
    }

    updateFlappy(&flappy);
    if(tickCount == 2){
        updatePipe(&leftPipe);
        updatePipe(&rightPipe);
        tickCount = 0;
    }
}

void initGame(){
    createFlappy(&flappy, 30, 10, 5);
    createPipe(&leftPipe,SCREEN_WIDTH - 100,20);
    createPipe(&rightPipe,SCREEN_WIDTH - 20,50);
}


void handleGameInput(){
    key_poll();
    if(key_is_down(KEY_A)){
        flappyAction(&flappy);
    }
}